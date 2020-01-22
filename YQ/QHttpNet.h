//导入相关网络库
// 封装基于QT的网络库
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QFile>

class QHttpNet:public QObject{
    Q_OBJECT
public:
    QHttpNet();
    ~QHttpNet();
    void getUrl(QString url_);
    bool DownloadFile(QString url_,QString file_name); //下载文件
    bool CreateDownloadFile(QString filename); //创建下载的文件名，用于写入

private slots:
    void Slots_Reply();
    void Slots_WriteFile();//写入文件
    void Slots_ShowProgress(qint64 data_1,qint64 data_2); //显示进度
    void Slots_DownloadFinish(); //下载完成

private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply; //响应
    QFile * m_file; //用于保存文件
    QString m_filename; //用于创建文件,进行写入操作
};
