//导入相关网络库
// 封装基于QT的网络库
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <QVariant>
#include <QMessageBox>
#include <QTimer>
#include <QFile>
#include <QMainWindow>
#include "Utils.h"
#include "GlobalData.h"

typedef struct{
    QString file_name; //文件名
    int file_size; //文件大小
    QString file_md5; //文件md5值，用于验证文件是否下载正确
} FILE_INFO;

enum FILE_STATE{
  FILE_NONE, //未下载
  FILE_DOWNLOADING, //文件正在下载
  FILE_FINISHED, //文件下载完成
  FILE_DOWNLOAD_ERROR, //文件下载出错
};

enum SLOTS_STATE{
  SLOTS_CONNECTED = 3, //已经连接
  SLOTS_UNCONNECTED, //未连接槽函数
};


// 状态码
enum StatusCode{
    HTTP_ERROR = 0, //访问失败
    HTTP_OK = 200, //正常获取请求
    HTTP_CREATE = 201, // POST:201增加
    HTTP_NOT_FOUND = 404, //没有找到地址
};

enum RequestType{
  RES_LOGIN = 100, //用户登录
  RES_REGISTER = 101,  //用户注册
  RES_USERICON = 102, //用户头像
};

enum UserIconState{
    ICON_STATE_NOUSERNAME = 1, //没有用户头像
    ICON_STATE_NOICON = 2, //没有图标
    ICON_STATE_NORMAL = 3, //正常头像
};

enum LOGIN_ERROR{
    LOGIN_SUCCESS = 1,//登录成功
    LOGIN_ERROR_USERNAME = 2, //用户名错误
    LOGIN_ERROR_PASSWORD = 3, //密码错误
    LOGIN_ERROR_HTTP = 4, //网络故障
};

class QHttpNet:public QObject{

    Q_OBJECT
public:
    QHttpNet(QMainWindow *parent_);
    ~QHttpNet();

    //
    void SetCookie(QString cookies_str);
    void getUrl(QString url_);
    bool PostData(QString url_,QString datas); //使用Post发送数据
    bool GetData(QString url_); //使用get发送数据
    bool DownloadFile(QString url_,QString file_name); //下载文件
    bool CreateDownloadFile(QString filename); //创建下载的文件名，用于写入
    int  GetCurrentProgress(); //获取当前的下载进度0-100

signals:
    void LoginSignal(LOGIN_ERROR login_state_);//登录信号
    void DownloadFileSignal(QString file_url); //下载文件信号
    void UserIconSignal(QString icon_url); //用户头像信号

private:
    //处理业务逻辑事件在这进行处理
    void Business_LoginResponse(const QJsonObject& json_);
    void Business_IconResponse(const QJsonObject& json_);
    void Business_HandleDownloadUrl(QString& url_); //处理下载链接

private slots:
    virtual void Slots_Reply();    //设置为可继承重载
    virtual void Slots_WriteFile();//写入文件
    virtual void Slots_ShowProgress(qint64 data_1,qint64 data_2); //显示进度
    virtual void Slots_DownloadFinish(); //下载完成
    virtual void Slots_PostRequestFinished(QNetworkReply* reply_); //Post请求处理数据
    virtual void Slots_GetRequestFinished(QNetworkReply* reply_);
    void Slots_TimerCheckRes(); // 定时检查资源

private:
    QList<QNetworkCookie> * m_list_cookie;//设置cookie
    int m_timer_state; //定时器状态 0：未初始化 1：初始化
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply; //响应
    QFile * m_file; //用于保存文件
    QString m_filename; //用于创建文件,进行写入操作
    QVector<QString> m_vec_download_url;  //设置下载的链接集合 //用于执行下载进程，实现可以下载多个文件的功能
    QVector<QString> m_vec_file_name; //需要下载的文件名集合;
    FILE_INFO m_file_info; //下载的文件信息
    int  m_cur_download_size; //当前下载大小
    int  m_all_download_size; //总的下载大小
    int  m_progress_value; //下载进度
    QTimer* m_timer; // 定时器下载
    QNetworkRequest m_request;
    QMainWindow * m_parent_window; // 用于绑定父窗口
};
