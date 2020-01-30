//导入相关网络库
// 封装基于QT的网络库
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

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

//请求类型,用于处理服务端返回数据
enum Request_Type{
    USER_LOGIN = 100, //用户登录
    USER_REGISTER, //用户注册
    USER_DEEPIN,
};

// 状态码
enum StatusCode{
    HTTP_ERROR = 0, //访问失败
    HTTP_OK = 200, //正常获取请求
    HTTP_NOT_FOUND = 404, //没有找到地址
};

typedef struct{
    QString file_name; //文件名
    int file_size; //文件大小
    QString file_md5; //文件md5值，用于验证文件是否下载正确
} FILE_INFO;

class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;
class QHttpNet:public QObject{
    Q_OBJECT
public:
    QHttpNet();
    ~QHttpNet();

    //
    void getUrl(QString url_);
    bool PostData(QString url_,QString datas); //使用Post发送数据
    bool GetData(QString url_); //使用get发送数据
    bool DownloadFile(QString url_,QString file_name); //下载文件
    bool CreateDownloadFile(QString filename); //创建下载的文件名，用于写入
    int  GetCurrentProgress(); //获取当前的下载进度0-100

private slots:
    virtual void Slots_Reply();    //设置为可继承重载
    virtual void Slots_WriteFile();//写入文件
    virtual void Slots_ShowProgress(qint64 data_1,qint64 data_2); //显示进度
    virtual void Slots_DownloadFinish(); //下载完成
    virtual void Slots_PostRequestFinished(QNetworkReply* reply_); //Post请求处理数据
    virtual void Slots_GetRequestFinished(QNetworkReply* reply_);
    void Slots_TimerCheckRes(); // 定时检查资源

private:
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
};
