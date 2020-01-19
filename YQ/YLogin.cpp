#include "YLogin.h"
#include "ui_YLogin.h"
#include "Utils.h"
#include "GlobalData.h"
#include "HttpNet.h"

YLogin::YLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YLogin)
{

    ui->setupUi(this);
    Init();
    InitSignalAndSlots();
}

YLogin::~YLogin()
{
    delete ui;
}

void YLogin::Init()
{
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password); //设置密码模式
    ui->lineEdit_Account->setPlaceholderText("QQ号码/手机/邮箱");
    ui->lineEdit_Password->setPlaceholderText("密码");
}

//业务方法处理
//发送登录数据给服务器
bool YLogin::SendLoginReqToServer(QString send_data)
{
    //验证是否数据异常
    //QMessageBox::about(NULL,send_data,send_data);
    //发送
    return true;
}

void YLogin::ShowPromptTip(const QPoint & pos,QString tips_)
{
    QToolTip::showText(pos,tips_);
}

//初始化信号与槽接口
void YLogin::InitSignalAndSlots()
{
    connect(ui->btn_close,SIGNAL(clicked()),this,SLOT(Slots_CloseWindow()));
    connect(ui->btn_Login,SIGNAL(clicked()),this,SLOT(Slots_LoginQQ()));
    connect(ui->btn_Min,SIGNAL(clicked()),this,SLOT(Slots_MinsizeProgress()));
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
    last=e->globalPos();
}

//基础用户名密码检查
bool YLogin::BasicInfoCheck()
{
    return false;
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
    BasicInfoCheck();
    //1.判断用户名
    QString account_ = ui->lineEdit_Account->text(); //获取账号信息
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
    SendLoginReqToServer(send_data);
}

//最小化窗体
void YLogin::Slots_MinsizeProgress()
{
    //显示最小化
    this->showMinimized();
}
