#include "QHttpNet.h"


QHttpNet::QHttpNet()
{
    m_manager = new QNetworkAccessManager(this); //初始化
    m_reply = nullptr;
    m_timer = nullptr;
    m_cur_download_size = 0;
    m_all_download_size = 0;
    m_progress_value = 0;
    m_timer_state = 0;
}

QHttpNet::~QHttpNet()
{
    delete m_manager;
    delete m_reply;
    delete m_file;
    delete m_timer;
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
    if(!m_timer)
    {
        m_timer = new QTimer(this);  // 初始化定时器
        m_timer->setSingleShot(false); //false:多次触发,true:单次触发
        m_timer->start(2000);//设置两秒后开始
        connect(m_timer,SIGNAL(timeout()),this,SLOT(Slots_TimerCheckRes())); //触发下载资源
    }
    //添加到url_和file_name到集合中
    m_vec_download_url.append(url_); //添加到下载集合中
    m_vec_file_name.append(file_name); //添加到用户名集合中
    return true;
}

// 检查下载资源
void QHttpNet::Slots_TimerCheckRes()
{
    // 第一次启动定时器操作
    if(m_timer_state == 0)
    {
        int need_count = m_vec_download_url.size();
        if(need_count<1)
        {
            return ;
        }
        // 进行下载
        for(int i = 0; i < need_count ; i++)
        {
           QString down_url = m_vec_download_url[i];
           QString down_filename = m_vec_file_name[i];
           CreateDownloadFile(down_filename);
           QUrl url_ = QUrl(down_url);
           //下载请求
           m_reply = m_manager->get(QNetworkRequest(url_));
           // 第一次需要绑定信号与槽
           connect(m_reply,SIGNAL(readyRead()),this,SLOT(Slots_WriteFile()));//数据写入
           connect(m_reply,SIGNAL(finished()),this,SLOT(Slots_DownloadFinish()));//下载完成
           connect(m_reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Slots_ShowProgress(qint64,qint64))); //获取下载进度
           m_vec_file_name.remove(0); //移除
           m_vec_download_url.remove(0); //移除
        }
        m_timer_state = 1;
        return;
    }

    //  后续启动定时器操作 则不需要添加信号功能
    int need_count = m_vec_download_url.size();
    if(need_count<1)
    {
        return ;
    }
    // 进行下载
    for(int i = 0; i < need_count ; i++)
    {
       QString down_url = m_vec_download_url[i];
       QString down_filename = m_vec_file_name[i];
       CreateDownloadFile(down_filename);
       QUrl url_ = QUrl(down_url);
       //下载请求
       m_reply = m_manager->get(QNetworkRequest(url_));
    }
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
      m_file->write(m_reply->readAll()); // 写入读取的数据
   }
}

void QHttpNet::Slots_Reply()
{
    QString demo = m_reply->readAll();
    QMessageBox::about(NULL,demo,demo);
    //m_file->flush();
    //m_file->close();
    //m_file = nullptr;
}

void QHttpNet::Slots_DownloadFinish()
{
    m_file->flush();
    m_file->close();
    m_file = nullptr;
    m_timer->stop(); //停止
    QMessageBox::about(NULL,"文件下载完成","文件");
    //下载完成:清空下载

}

//处理Post请求完成响应
void QHttpNet::Slots_PostRequestFinished(QNetworkReply* reply_)
{
    QByteArray qba =reply_->readAll();
    QString str_ = qba;//QString //获取转换的数据
}

// 处理get请求
void QHttpNet::Slots_GetRequestFinished(QNetworkReply* reply)
{
    //1.获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute); // 获取Http协议请求
    QVariant str_ResourceType = reply->attribute(QNetworkRequest::ResourceTypeAttribute);
    qDebug() << str_ResourceType.toUrl();
    int status_code = statusCode.toInt(); //获取状态码

    switch(status_code){
    case HTTP_ERROR:
        qDebug() << "通信失败";
        return; //返回 不进行处理
        break;
    case HTTP_OK:
        qDebug() << "通信正常";
        break;
    case HTTP_NOT_FOUND:
        qDebug() << "Http 404错误";
        break;
    default:
        break;
    };

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {
        // 获取返回内容
        qDebug() << reply->readAll();
    }
}

int  QHttpNet::GetCurrentProgress()
{
    m_progress_value = int((double(m_cur_download_size)/double(m_all_download_size))*100);
    return m_progress_value; //获取当前进度
}

//测试Post功能
bool QHttpNet::PostData(QString url_, QString datas)
{
    QNetworkRequest req;
    req.setUrl(url_); //设置URL访问
    // 绑定多个槽函数
    QMetaObject::Connection connRet = QObject::connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slots_PostRequestFinished(QNetworkReply*))); // 绑定结束的信号与槽
    m_manager->post(req,datas.toUtf8()); //发送post请求
    return true;
}

//测试Get功能
bool QHttpNet::GetData(QString url_)
{
    QNetworkRequest request;
    QMetaObject::Connection connRet = QObject::connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slots_GetRequestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

    request.setUrl(QUrl(url_));
    m_reply = m_manager->get(request);
    return true;
}
