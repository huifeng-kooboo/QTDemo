#ifndef YLOGIN_H
#define YLOGIN_H

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

QT_BEGIN_NAMESPACE
namespace Ui { class YLogin; }
QT_END_NAMESPACE

class YLogin : public QMainWindow
{
    Q_OBJECT

public:
    YLogin(QWidget *parent = nullptr);
    ~YLogin();

    void InitSignalAndSlots(); //初始化信号与槽
    bool BasicInfoCheck();
    void Init();

    //业务方法
    bool SendLoginReqToServer(QString send_data); //发送登录请求给服务器

    //展示提示框
    //@param1:pos：点位置
    //@params:tips_:提示内容
    void ShowPromptTip(const QPoint & pos,QString tips_);

private slots:
    //相关槽函数存放在这
    void Slots_CloseWindow();  //关闭窗体
    void Slots_LoginQQ(); //登录qq
    void Slots_MinsizeProgress(); //最小化

protected:
    //重写方法 设置去掉标题栏可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::YLogin *ui;
    QPoint last;
};
#endif // YLOGIN_H
