#ifndef YLOGIN_H
#define YLOGIN_H
#include <QFileInfo>

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>

//QJson引用相关库
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//提示框
#include <QToolTip>
#include <QPushButton>

//QTableView相关
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QHeaderView>

//网络相关库
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

//系统托盘
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
//重写鼠标点击事件
#include <QMouseEvent>

//重绘界面
#include <QPainter>
#include <QDesktopServices>

#include "QHttpNet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class YLogin; }
QT_END_NAMESPACE

//用户登录状态
enum LOGIN_STATE{
    ONLINE = 2, //在线
    LEAVELINE, //离线
};

//用户信息结构体
typedef struct{
    QString user_account;//用户账号
    QString user_name; //用户名
    LOGIN_STATE user_state; //用户登录状态
} UserInfo;


class YLogin : public QMainWindow
{
    Q_OBJECT

public:
    YLogin(QWidget *parent = nullptr);
    ~YLogin();

    void InitUserConfig();   //初始化用户信息配置
    void InitServerConfig(); //向服务器请求初始化配置信息
    void InitSignalAndSlots(); //初始化信号与槽
    bool BasicInfoCheck();
    void InitTrayMenu();//初始化托盘功能
    void Init();

    //业务方法
    bool SendLoginReqToServer(QString send_data); //发送登录请求给服务器
    void ShowRepeatLoginTip(QString tip_);    //显示重复登录提示
    bool GetLocalUsersAccount();  // 获取本地用户账号显示在框中


    //展示提示框
    //@param1:pos：点位置
    //@params:tips_:提示内容
    void ShowPromptTip(const QPoint & pos,QString tips_);

    //
    QString GetCurrentVersionNum();   //获取当前文件版本号
    QString GetUserIcon();            //获取用户头像
private:
    void WriteToLocalConfig(QString json_config); //将相应信息写入本地配置文件中
    void WriteToLocalConfig(QString key_,QString value_);
    void ReadLocalConfig(QString local_config);

private slots:
    //相关槽函数存放在这
    void Slots_CloseWindow();  //关闭窗体
    void Slots_LoginQQ(); //登录qq
    void Slots_MinsizeProgress(); //最小化
    void Slots_ShowNormal();//正常显示
    void Slots_TrayMsg(QSystemTrayIcon::ActivationReason reason); //托盘消息触发
    void Slots_HideTips();//隐藏提示框
    void Slots_ShowLoginQrcodePage();//显示登录二维码页面
    void Slots_ShowLoginPage(); //显示登录界面
    void Slots_ShowUserTableView(); //显示下拉框用户列表框
    void Slots_OpenLink(QString str_link); //打开链接
    void Slots_ShowAddQQAccount(); //添加QQ账号界面
    void Slots_AddQQAccount();//添加QQ账号
    void Slots_SingleLogin(); //单账号登录
    void Slots_Login();  //登录

    void Slots_UI_LoginResponse(LOGIN_ERROR);
    void Slots_HandleURL(QString); //处理下载信息信号
    void Slots_HandleUserIcon(QString);

protected:
    //重写方法 设置去掉标题栏可移动
    void mousePressEvent(QMouseEvent *e); //鼠标单击事件
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent* event);
    //重写事件过滤方法
    bool eventFilter(QObject* watched,QEvent * event);



private:
    Ui::YLogin *ui;
    QPoint last;
    QSystemTrayIcon * m_systemTray; //系统托盘
    QMenu* m_TrayMenu;//托盘右键菜单
    QAction* m_Exit;//退出
    QAction* m_OpenPanel;//打开面板
    //二维码框相关
    QPushButton * m_btn_return;//返回到原先界面
    QLabel * m_qrcode_; //二维码展示框

    //点击显示账号功能
    int m_show_state; //显示账号状态 0:当前未显示 1：当前显示
    int m_show_init ;// 判断是否初始化
    QTableView * m_AccountView; //点击显示或者哪个好
    QStandardItemModel* m_AccountItemModel;
    QPushButton * m_DeleteAccount;

    //登录账号
    UserInfo m_login_user; //用户信息
    QHttpNet* m_http;

    //添加账号界面
    QWidget * m_widget_register_account; //添加登录账号窗体
    QPushButton * m_btn_AddAccount; //添加账号按钮
    QPushButton * m_btn_SingleLogin; //单账号登录按钮
    QPushButton * m_btn_loginQQ; //登录按钮

    //
    QString m_version_num; //当前QQ版本号
    QString m_icon_url;  // 用户头像url

    // 本地配置目录
    QString m_local_config_path;
    QFile * m_ini_config_file;  // 配置文件写入
 };
#endif // YLOGIN_H
