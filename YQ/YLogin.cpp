#include "YLogin.h"
#include "ui_YLogin.h"
#include "GlobalData.h"
#include <QTextCodec>
#include "Utils.h"

YLogin::YLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YLogin)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8")); //设置编码格式 处理乱码情况
    ui->setupUi(this);
    ui->widget_qrcode->setVisible(false);
    ui->lbl_Tips->setVisible(false);
    ui->btn_pull->setVisible(false);
    ui->lbl_warning_ico->setVisible(false);

    Init();
    InitTrayMenu();
    InitSignalAndSlots();
    InitServerConfig();
    setAttribute(Qt::WA_TranslucentBackground, true); //不绘制界面 通过QPainter重绘
}

YLogin::~YLogin()
{
    //释放相关内存
    //防止内存泄漏
    delete m_systemTray;
    delete m_TrayMenu;
    delete m_btn_return;
    delete m_AccountView;
    delete m_AccountItemModel;
    delete m_DeleteAccount;
    delete m_OpenPanel;
    delete m_Exit;
    delete m_qrcode_;
    delete m_btn_AddAccount;
    delete m_btn_loginQQ;
    delete m_btn_SingleLogin;
    delete m_widget_register_account;
    delete ui;
}

void YLogin::InitServerConfig()
{
    //向服务器请求配置信息
    //获取当前版本
    m_http->DownloadFile(FILE_VERSION_URL,FILE_VERSION_NAME);
    QJsonObject user_jsons;//用户数据
    user_jsons.insert("username","coder");
    QString send_data = Utils::QJsonObjectToQString(user_jsons);
    m_http->PostData(USER_ICON_URL,send_data);
}

//重绘界面
void YLogin::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    p.setBrush(QColor(234, 241, 248));
    int x = 0;
    int y = 179;
    int width = 425;
    int height =158;
    p.drawRect(x, y, width, height);
}

void YLogin::Init()
{
    //1.初始化登录用户信息结构体
    m_login_user.user_name = "";
    m_login_user.user_account = "";
    m_login_user.user_state = LEAVELINE; //默认为离线状态

    //初始化显示账号状态
    m_show_state = 0;
    m_show_init = 0;

    //2. 初始化相关指针
    m_AccountView = nullptr; //初始化设置空
    m_AccountItemModel = nullptr;
    m_DeleteAccount = nullptr;

    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password); //设置密码模式
    ui->lineEdit_Account->setPlaceholderText("QQ号码/手机/邮箱");
    ui->lineEdit_Password->setPlaceholderText("密码");
    ui->btn_addaccount->setToolTip("多账号登录");
    ui->btn_qrcode->setToolTip("二维码登录");
    //测试下载功能
    m_http = new QHttpNet(this); //初始化
    //按钮
    m_btn_AddAccount = nullptr; //设为空按钮
    //
    m_widget_register_account = nullptr;
    m_btn_SingleLogin = nullptr;
    m_btn_loginQQ = nullptr;
}

void YLogin::InitTrayMenu()
{
    m_systemTray = new QSystemTrayIcon(this);
    m_systemTray->setIcon(QIcon(":/login/src/styles/tim_icon.png"));
    m_systemTray->setToolTip("TIM");
    //
    m_TrayMenu = new QMenu(this);
    m_Exit = new QAction("  退出QQ",this);
    m_OpenPanel = new QAction("  打开面板",this);
    m_systemTray->setContextMenu(m_TrayMenu); //添加右键菜单
    m_TrayMenu->addAction(m_OpenPanel);
    m_TrayMenu->addAction(m_Exit);
    m_TrayMenu->setWindowFlag(Qt::NoDropShadowWindowHint);//去除阴影
    m_TrayMenu->setStyleSheet("QMenu{ width:226px;background-color:rgb(255,255,255);color:rgb(123,123,123);font-size:13px;}QMenu::item{color:rgb(123,123,123);background-color:rgb(255,255,255);width:224px; height:40px;padding-left:20px;border:1px solid rgb(243,243,243);}QMenu::item:selected{background-color:rgb(230,233,237);}");

    m_systemTray->show();
    connect(m_systemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(Slots_TrayMsg(QSystemTrayIcon::ActivationReason)));
    connect(m_Exit, SIGNAL(triggered()), this, SLOT(Slots_CloseWindow()));
    connect(m_OpenPanel, SIGNAL(triggered()), this, SLOT(Slots_ShowNormal()));
}

//业务方法处理
//发送登录数据给服务器
bool YLogin::SendLoginReqToServer(QString send_data)
{
    return true;
}

void YLogin::ShowRepeatLoginTip(QString tip_)
{
    ui->lbl_Tips->setText(GET_REPEAT_LOGIN_STR( tip_));
    ui->lbl_Tips->setVisible(true);
    ui->btn_pull->setVisible(true);
    ui->lbl_warning_ico->setVisible(true);
}

void YLogin::ShowPromptTip(const QPoint & pos,QString tips_)
{
    QToolTip::showText(pos,tips_);
}

bool YLogin::GetLocalUsersAccount()
{
    return false;
}

//初始化信号与槽接口
void YLogin::InitSignalAndSlots()
{
    connect(ui->btn_close,SIGNAL(clicked()),this,SLOT(Slots_CloseWindow()));
    connect(ui->btn_Login,SIGNAL(clicked()),this,SLOT(Slots_LoginQQ()));
    connect(ui->btn_Min,SIGNAL(clicked()),this,SLOT(Slots_MinsizeProgress()));
    connect(ui->btn_pull,SIGNAL(clicked()),this,SLOT(Slots_HideTips()));
    connect(ui->lineEdit_Account,SIGNAL(textChanged( const QString)),this,SLOT(Slots_HideTips()));
    connect(ui->btn_qrcode,SIGNAL(clicked()),this,SLOT(Slots_ShowLoginQrcodePage()));
    connect(ui->btn_choose,SIGNAL(clicked()),this,SLOT(Slots_ShowUserTableView()));
    //绑定忘记密码
    connect(ui->lbl_reg_num,SIGNAL(linkActivated(QString)), this, SLOT(Slots_OpenLink(QString)));
    connect(ui->lbl_find_password,SIGNAL(linkActivated(QString)), this, SLOT(Slots_OpenLink(QString)));
    connect(ui->btn_addaccount,SIGNAL(clicked()),this,SLOT(Slots_ShowAddQQAccount()));
}

void YLogin::Slots_UI_LoginResponse(LOGIN_ERROR state_)
{
    switch (state_) {
    case LOGIN_SUCCESS:
    {
        qDebug() << "QQ登录成功";
        break;
    }
    case LOGIN_ERROR_USERNAME:
    {
        qDebug() << "QQ用户名错误";
        QPoint cur_account_pos  = this->mapToGlobal(ui->lineEdit_Account->pos());
        ShowPromptTip(cur_account_pos,"账号错误");
        break;
    }
    case LOGIN_ERROR_PASSWORD:
    {
        qDebug() << "QQ密码错误";
        QPoint cur_password_pos  = this->mapToGlobal(ui->lineEdit_Password->pos());
        ShowPromptTip(cur_password_pos,"密码错误");
        break;
    }
    case LOGIN_ERROR_HTTP:
    {
        qDebug() << "HTTP错误";
        break;
    }
    default:
        break;
    }
}

// 显示QQ添加账号界面
void YLogin::Slots_ShowAddQQAccount()
{
    if(!m_widget_register_account)
    {
        m_widget_register_account = new QWidget(this);
    }
    m_widget_register_account->setStyleSheet("background-color:rgb(235,242,249);"); //背景色
    //
    if(!m_btn_AddAccount)
    {
        m_btn_AddAccount = new QPushButton(m_widget_register_account);
    }
    m_btn_AddAccount->setText("");
    m_btn_AddAccount->setGeometry(143,50,118,33);
    m_btn_AddAccount->setProperty("objectName","m_btn_AddAccount");
    m_btn_AddAccount->setStyleSheet("QPushButton#m_btn_AddAccount{image:url(':/login/src/styles/add_qqaccount.png');}QPushButton#m_btn_AddAccount::hover{image:url(':/login/src/styles/add_qqaccount_hover.png');}");
    m_btn_AddAccount->setToolTip("添加待登录QQ账号");
    connect(m_btn_AddAccount,SIGNAL(clicked()),this,SLOT(Slots_AddQQAccount()));

    // 单账号登录按钮
    if(!m_btn_SingleLogin)
    {
        m_btn_SingleLogin = new QPushButton(m_widget_register_account);
    }
    m_btn_SingleLogin->setText("");
    m_btn_SingleLogin->setGeometry(7,120,29,29);
    m_btn_SingleLogin->setProperty("objectName","m_btn_SingleLogin");
    m_btn_SingleLogin->setStyleSheet("QPushButton#m_btn_SingleLogin{background-color:rgb(244,244,244);background-image:url(':/login/src/styles/single_account.png');}QPushButton#m_btn_SingleLogin::hover{background-image:url(':/login/src/styles/single_account_hover.png');}");//此处需要修改样式
    m_btn_SingleLogin->setToolTip("单账号登录");
    connect(m_btn_SingleLogin,SIGNAL(clicked()),this,SLOT(Slots_SingleLogin()));

    // 登录按钮控件
    if(!m_btn_loginQQ)
    {
        m_btn_loginQQ = new QPushButton(m_widget_register_account);
    }
    m_btn_loginQQ->setText("登 录");
    m_btn_loginQQ->setGeometry(110,115,197,31);
    m_btn_loginQQ->setProperty("objectName","m_btn_loginQQ");
    m_btn_loginQQ->setStyleSheet("QPushButton#m_btn_loginQQ{color:rgb(212,242,253);background-color:rgb(0,163,255);border:1px solid rgb(203,209,215);border-radius:1px;}QPushButton#m_btn_loginQQ::hover{background-color:rgb(60,195,245);}");
    connect(m_btn_loginQQ,SIGNAL(clicked()),this,SLOT(Slots_Login()));

    m_widget_register_account->setGeometry(0,179,426,157);
    m_widget_register_account->setVisible(true);
    m_widget_register_account->show();
}

void YLogin::Slots_Login()
{
    //登录功能 -- 添加账号界面中使用
    //根据cookie 进行登录
}

void YLogin::Slots_SingleLogin()
{
    m_widget_register_account->setVisible(false);
}

void YLogin::Slots_AddQQAccount()
{
   // QMessageBox::about(NULL,"TEST","TEST");
}

void YLogin::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void YLogin::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void YLogin::mousePressEvent(QMouseEvent *e)
{
    last =e->globalPos();
    //进行隐藏
    if(m_AccountView!=nullptr)
    {
        m_AccountView->setVisible(false);
    }
}

//重写事件过滤方法
bool YLogin::eventFilter(QObject* watched,QEvent * event)
{
    //注册账号点击
    if(watched == ui->lbl_reg_num &&event->type() == QEvent::MouseButtonPress)
    {
        QMessageBox::about(nullptr,"测试","测试");
      //默认浏览器的打开
    }
    return true;
}

//基础用户名密码检查
bool YLogin::BasicInfoCheck()
{
    return false;
}

//打开注册/忘记密码链接
void YLogin::Slots_OpenLink(QString str_link)
{
    //使用默认浏览器打开指定链接
    QDesktopServices::openUrl(str_link);
}

//槽函数实现
// 关闭窗体
void YLogin::Slots_CloseWindow()
{
    this->close();//关闭窗体
}

//登录QQ功能
void YLogin::Slots_LoginQQ()
{
    //1.判断用户名
    QString account_ = ui->lineEdit_Account->text(); //获取账号信息
    //ShowRepeatLoginTip(account_); //显示重复登录提示框
    bool result_ = Utils::StringJudgeAccount(account_); //判断账号是否符合要求
    //匹配失败
    if(!result_)
    {
      QPoint cur_pos  = this->mapToGlobal(ui->lineEdit_Account->pos());
      ShowPromptTip(cur_pos,"请您输入账号后再登录");
      return;
    }
    //2. 判断密码
    QString password_ = ui->lineEdit_Password->text();
    bool result_pwd = Utils::StringJudgePassword(password_);
    if(!result_pwd)
    {
        QPoint cur_pos  = this->mapToGlobal(ui->lineEdit_Password->pos());
        ShowPromptTip(cur_pos,"请您输入密码后再登录");
        return;
    }

    //3.发送登录请求(采用异步方式/传递Json数据)
    QJsonObject user_jsons;//用户数据
    user_jsons.insert("username",account_);
    user_jsons.insert("password",password_);
    QString send_data = Utils::QJsonObjectToQString(user_jsons);
    m_http->PostData(LOGIN_URL,send_data); //发送登录请求
}

//最小化窗体
void YLogin::Slots_MinsizeProgress()
{
    //显示最小化
    this->showMinimized();
}

void YLogin::Slots_ShowNormal()
{
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    this->showNormal();
}

void YLogin::Slots_TrayMsg(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
       {
       //左键点击
       case QSystemTrayIcon::Trigger:
        {
          showNormal();
          break;
        }
       //双击托盘显示窗口
       case QSystemTrayIcon::DoubleClick:
       {
         showNormal();
         break;
       }
       default:
        break;
       }
}

void YLogin::Slots_HideTips()
{
    ui->lbl_Tips->setVisible(false);
    ui->btn_pull->setVisible(false);
    ui->lbl_warning_ico->setVisible(false);
    //隐藏下拉框菜单显示
    if(m_AccountView)
    {
        m_AccountView->setVisible(false);
    }
}

void YLogin::Slots_ShowLoginPage()
{
    ui->widget_qrcode->setVisible(false);
}

void YLogin::Slots_ShowLoginQrcodePage()
{
    // 设置Get请求

    // 判断是否重复登录提示框去掉
    if(ui->lbl_Tips->isVisible())
    {
        ui->lbl_Tips->setVisible(false);
        ui->btn_pull->setVisible(false);
        ui->lbl_warning_ico->setVisible(false);
    }
    ui->widget_qrcode->setStyleSheet("background-color:rgb(235,242,249)");

    //1.添加返回按钮
    m_btn_return = new QPushButton(ui->widget_qrcode);
    m_btn_return->setProperty("objectName","m_btn_return");
    //60,195,245
    m_btn_return->setStyleSheet("QPushButton#m_btn_return{width:194px;height:31px;border-radius:4px;background-color:rgb(0,163,255);color:rgb(255,255,255);} QPushButton#m_btn_return:hover{background-color:rgb(60,195,245)}");
    m_btn_return->setGeometry(116,260,194,31);
    m_btn_return->setText("返回");
    //绑定
    connect(m_btn_return,SIGNAL(clicked()),this,SLOT(Slots_ShowLoginPage()));
    m_btn_return->show();

    //2.添加二维码
    m_qrcode_ = new QLabel(ui->widget_qrcode);
    m_qrcode_->setText("");
    m_qrcode_->setGeometry(155,102,127,127);
    m_qrcode_->setStyleSheet("image: url(':/login/src/styles/tim_qrcode.png');");
    m_qrcode_->show();

    //3.添加上方字段

    ui->widget_qrcode->setVisible(true);
}

void YLogin::Slots_ShowUserTableView()
{
    if(m_show_state == 0)
    {
      if(m_show_init == 1)
      {
         //只要显示就够了
          m_AccountView->show();
          m_AccountView->setVisible(true);
          return;
      }
    //判断是否为空
    if(m_AccountView == nullptr)
    {
        m_AccountView = new QTableView(this);
        m_AccountView->setProperty("objectName","m_AccountView");
    }
    if( m_AccountItemModel == nullptr)
    {
        m_AccountItemModel = new QStandardItemModel();
    }

    //添加三个空的控件 //用于存放 头像 、 账号信息、 按钮
    m_AccountItemModel->setItem(0, 0, new QStandardItem(""));
    m_AccountItemModel->setItem(0, 1, new QStandardItem(""));
    m_AccountItemModel->setItem(0, 2, new QStandardItem(""));
    m_AccountView->setModel(m_AccountItemModel);
    //
    m_AccountView->verticalHeader()->setDefaultSectionSize(44);
    //1.放置头像
    QLabel * avator_ = new QLabel("");
    avator_->setProperty("objectName","avator_");
    avator_->setStyleSheet("QLabel#avator_{border:0px;width:44px;height:44px;background-image:url(':/login/src/styles/small_avator.png');}");
    m_AccountView->horizontalHeader()->setDefaultSectionSize(44);
    m_AccountView->setIndexWidget(m_AccountItemModel->index(0,0),avator_);
    m_AccountView->setStyleSheet("QTableView#m_AccountView::item{background-color:rgb(60,150,214)}");
    m_AccountView->setStyleSheet("QTableView#m_AccountView{border:1px solid rgb(255,255,255);background-color:rgb(60,150,214)}");
    //2.放置账号信息
    QLabel * user_tag = new QLabel(" 942840260");
    user_tag->setProperty("objectName","user_tag");
    user_tag->setStyleSheet("QLabel#user_tag{color:rgb(255,255,255)}");
    m_AccountView->setColumnWidth(1,126);
    m_AccountView->setIndexWidget(m_AccountItemModel->index(0,1),user_tag);

    //3.放置删除小号按钮
    m_DeleteAccount = new QPushButton();
    m_DeleteAccount->setProperty("objectName","btn_deleteAccount");
    m_DeleteAccount->setStyleSheet("QPushButton#btn_deleteAccount{width:16px;height:16px;background-color:rgb(60,150,214);image:url(':/login/src/styles/small_close.png');}QPushButton#btn_deleteAccount::hover{background-color:rgb(60,150,214);width:16px;height:16px;image:url(':/login/src/styles/small_close_hover.png');}");
    m_DeleteAccount->setText("");
    m_AccountView->setColumnWidth(2,30);
    //绑定槽函数
    m_AccountView->setIndexWidget(m_AccountItemModel->index(0,2),m_DeleteAccount);
    avator_->show();

    // 去掉行头和列头
    m_AccountView->horizontalHeader()->setVisible(false);
    m_AccountView->verticalHeader()->setVisible(false);
    m_AccountView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //关闭滚动条

    //设置TableView大小
    m_AccountView->setGeometry(113,226,200,45);
    m_AccountView->setShowGrid(false); //设置不显示网格~
    //设置样式
    m_AccountView->show();
    m_show_state = 1;
    m_show_init = 0;
    }
    else{
        m_show_state = 0;
        m_AccountView->hide();
        m_AccountView->setVisible(false); //不显示
    }
}

QString YLogin::GetCurrentVersionNum()
{
    QFile file(FILE_VERSION_NAME);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray t_ = file.readAll();
    QString version_str = QString(t_);
    QStringList ver_list =version_str.split("= ");
    m_version_num = ver_list[1]; // 获取当前版本号
    qDebug() << m_version_num;
    file.close();//需要关闭 防止内存泄露
    return m_version_num;
}

void YLogin::Slots_HandleURL(QString url_)
{
    if(url_ == FILE_VERSION_URL)
    {
        GetCurrentVersionNum();
        qDebug() << "客户端接收成功" ;
    }
}

QString YLogin::GetUserIcon()
{
    return m_icon_url;
}

void YLogin::Slots_HandleUserIcon(QString icon_url_)
{
    m_icon_url = icon_url_;
    return ;
}
