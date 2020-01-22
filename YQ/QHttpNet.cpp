#include "QHttpNet.h"


QHttpNet::QHttpNet()
{
    m_manager = new QNetworkAccessManager(this); //初始化
    m_reply = nullptr;
    m_cur_download_size = 0;
    m_all_download_size = 0;
    m_progress_value = 0;
}

QHttpNet::~QHttpNet()
{
    delete m_manager;
    delete m_reply;
    delete m_file;
}

bool QHttpNet::CreateDownloadFile(QString filename)
{
    m_filename = filename;
    m_file = new QFile(m_filename);
    if(m_file->open(QIODevice::WriteOnly))
    {
        return true;
    }
    delete m_file;
    m_file = nullptr;
    return false;
}

bool QHttpNet::DownloadFile(QString url_, QString file_name)
{
    CreateDownloadFile(file_name);
    QUrl download_url = QUrl(url_);
    m_reply = m_manager->get(QNetworkRequest(download_url));
    connect(m_reply,SIGNAL(readyRead()),this,SLOT(Slots_WriteFile()));//数据写入
    connect(m_reply,SIGNAL(finished()),this,SLOT(Slots_DownloadFinish()));//下载完成
    connect(m_reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Slots_ShowProgress(qint64,qint64))); //获取下载进度
    return true;
}

//显示下载进度
void QHttpNet::Slots_ShowProgress(qint64 cur_size,qint64 all_size)
{
    m_cur_download_size = cur_size;
    m_all_download_size = all_size;
}

void QHttpNet::getUrl(QString url_)
{
    if(m_manager == nullptr)
    {
        m_manager = new  QNetworkAccessManager(this);
    }
    connect(m_manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(Slots_Reply()));
    m_manager->get(QNetworkRequest(QUrl("http://chuantu.xyz/t6/713/1579659159x989559068.png")));
}

void QHttpNet::Slots_WriteFile()
{
   if(m_file)
   {
      m_file->write(m_reply->readAll());
   }
}

void QHttpNet::Slots_Reply()
{
    m_file->flush();
    m_file->close();
    m_file = nullptr;
}

void QHttpNet::Slots_DownloadFinish()
{
    //下载完成:清空下载
    m_file->flush();
    m_file->close();
    m_file = nullptr;
}

int  QHttpNet::GetCurrentProgress()
{
    m_progress_value = int((double(m_cur_download_size)/double(m_all_download_size))*100);
    return m_progress_value; //获取当前进度
}
