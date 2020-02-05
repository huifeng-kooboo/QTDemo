#include "QHttpNet.h"

QHttpNet::QHttpNet(QMainWindow *parent_)
{
    m_parent_window = parent_;
    m_manager = new QNetworkAccessManager(this); //初始化
    m_reply = nullptr;
    m_timer = nullptr;
    m_cur_download_size = 0;
    m_all_download_size = 0;
    m_progress_value = 0;
    m_timer_state = 0;
    m_list_cookie = nullptr;
    QUrl url_;
    url_.setUrl("");
    m_request.setUrl(url_); //初始化设为空;
    connect(this,SIGNAL(LoginSignal(LOGIN_ERROR)),parent_,SLOT(Slots_UI_LoginResponse(LOGIN_ERROR)));
    connect(this,SIGNAL(DownloadFileSignal(QString)),parent_,SLOT(Slots_HandleURL(QString)));
    connect(this,SIGNAL(UserIconSignal(QString)),parent_,SLOT(Slots_HandleUserIcon(QString)));
}

QHttpNet::~QHttpNet()
{
    delete m_manager;
    delete m_reply;
    delete m_file;
    delete m_timer;
    delete m_list_cookie;
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
    //添加到url_和file_name到集合中
    m_vec_download_url.append(url_); //添加到下载集合中
    m_vec_file_name.append(file_name); //添加到用户名集合中
    if(!m_timer)
    {
        m_timer = new QTimer(this);  // 初始化定时器
        m_timer->setSingleShot(false); //false:多次触发,true:单次触发
        m_timer->start(2000);//设置两秒后开始
        connect(m_timer,SIGNAL(timeout()),this,SLOT(Slots_TimerCheckRes())); //触发下载资源
    }

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
           m_request.setUrl(url_);
           //下载请求
           m_reply = m_manager->get(m_request);
           // 第一次需要绑定信号与槽
           connect(m_reply,SIGNAL(readyRead()),this,SLOT(Slots_WriteFile()));//数据写入
           connect(m_reply,SIGNAL(finished()),this,SLOT(Slots_DownloadFinish()));//下载完成
           connect(m_reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(Slots_ShowProgress(qint64,qint64))); //获取下载进度
           m_vec_file_name.remove(0); //移除
           m_vec_download_url.remove(0); //移除
           return;
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
       //下载请求：判断是否有东西正在下载
       QString cur_url_str = m_request.url().toString();
       // 说明暂时没有下载任务
       if(cur_url_str.size() == 0)
       {
           CreateDownloadFile(down_filename);
           QUrl url_ = QUrl(down_url);
           m_request.setUrl(url_);
           m_reply = m_manager->get(m_request);
           m_vec_file_name.remove(0); //移除
           m_vec_download_url.remove(0); //移除
       }
       return;
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
    QUrl download_url_ = m_request.url(); //获取下载链接
    QString url_str_ = download_url_.toString();
    Business_HandleDownloadUrl(url_str_);
    m_request.setUrl(QUrl("")); //设置为空URL :以便可以执行多次下载
}

void QHttpNet::Business_HandleDownloadUrl(QString& url_)
{
    if (url_ == FILE_VERSION_URL)
    {
        qDebug() << "文件版本下载到本地完成" ;
        emit DownloadFileSignal(url_);
    }
}

void QHttpNet::Business_LoginResponse(const QJsonObject& json_)
{
    QJsonValue login_state_json = json_.value("login_state");
    int state_ = login_state_json.toInt(); //转int
    switch(state_)
    {
    case LOGIN_SUCCESS:
        //传递给前端
        qDebug() << "登录成功";
        emit LoginSignal(LOGIN_SUCCESS);
        break;
    case LOGIN_ERROR_PASSWORD:
        qDebug() << "密码错误";
        emit LoginSignal(LOGIN_ERROR_PASSWORD);
        break;
    case LOGIN_ERROR_USERNAME:
        qDebug() << "用户名错误" ;
        emit LoginSignal(LOGIN_ERROR_USERNAME);
        break;
    default:
        break;
    }
}

//处理Post请求完成响应
void QHttpNet::Slots_PostRequestFinished(QNetworkReply* reply)
{
    //1.获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute); // 获取Http协议请求
    QVariant str_ResourceType = reply->attribute(QNetworkRequest::ResourceTypeAttribute); //获取资源类型属性
    int status_code = statusCode.toInt(); //获取状态码

    switch(status_code){
    case HTTP_ERROR:
        qDebug() << "通信失败";
        emit LoginSignal(LOGIN_ERROR_HTTP);
        return; //返回 不进行处理
        break;
    case HTTP_OK:
        qDebug() << "通信正常";
        break;
    case HTTP_CREATE:
        qDebug() << "通信增加字段";
        break;
    case HTTP_NOT_FOUND:
        qDebug() << "Http 404错误";
        emit LoginSignal(LOGIN_ERROR_HTTP);
        return; //不进行处理
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
        QByteArray bya = reply->readAll();
        qDebug() << bya;
        QString str_reply = bya;// 所有响应的字符串
        QJsonObject json_;
        bool is_Convert = Utils::QStringToQJsonObject(str_reply,json_);
        if(!is_Convert)
        {
            qDebug() << "ERROR_JSON" ;
            return ;
        }
        else
        {
          // 解析响应数据
          QJsonValue res_type = json_.value("request_type");
          int type_ = res_type.toInt();
          switch(type_){
          case RES_LOGIN:
          {
              qDebug() << "登录信号" ;
              //交给业务方法中进行处理
              Business_LoginResponse(json_);
              break;
          }
          case RES_REGISTER:
          {
              qDebug() << "注册信号";
              //处理注册
              break;
          }
          case RES_USERICON:
          {
              qDebug() << "获取用户头像信号";
              Business_IconResponse(json_);
              break;
          }
          default:
          {
              qDebug() << "其他信号，不进行处理";
              break;
          }
          };
        }
    }
}

// 处理get请求
void QHttpNet::Slots_GetRequestFinished(QNetworkReply* reply)
{
    //1.获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute); // 获取Http协议请求
    QVariant str_ResourceType = reply->attribute(QNetworkRequest::ResourceTypeAttribute); //获取资源类型属性
    int status_code = statusCode.toInt(); //获取状态码

    switch(status_code){
    case HTTP_ERROR:
        qDebug() << "通信失败";
        return; //返回 不进行处理
        break;
    case HTTP_OK:
        qDebug() << "通信正常";
        break;
    case HTTP_CREATE:
        qDebug() << "通信Post增加";
        break;
    case HTTP_NOT_FOUND:
        qDebug() << "Http 404错误";
        return; //不进行处理
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
        QByteArray bya = reply->readAll();
        qDebug() << bya;
        QString str_reply = bya;// 所有响应的字符串
        QJsonObject json_;
        bool is_Convert = Utils::QStringToQJsonObject(str_reply,json_);
        if(!is_Convert)
        {
            qDebug() << "ERROR_JSON" ;
            return ;
        }
        else
        {
          QJsonValue res_type = json_.value("request_type");
          int type_ = res_type.toInt();
          switch(type_){
          case RES_LOGIN:
              qDebug() << "登录信号";
              break;
          case RES_REGISTER:
              qDebug() << "注册信号";
              break;
          case RES_USERICON:
              qDebug() << "获取用户头像信号";
              break;
          default:
              qDebug() << "其他信号，不进行处理";
              break;
          };
        }
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
    m_request.setUrl(url_); //设置URL访问
    m_request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json")); /*传递Json字符串*/
    // 绑定多个槽函数
    QMetaObject::Connection connRet = QObject::connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slots_PostRequestFinished(QNetworkReply*))); // 绑定结束的信号与槽
    m_manager->post(m_request,datas.toUtf8()); //发送post请求
    return true;
}

//测试Get功能
bool QHttpNet::GetData(QString url_)
{
    QMetaObject::Connection connRet = QObject::connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(Slots_GetRequestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

    m_request.setUrl(QUrl(url_));
    m_reply = m_manager->get(m_request);
    return true;
}

//设置Cookie
void QHttpNet::SetCookie(QString cookies_str)
{
    QVariant var;
    var.setValue(cookies_str); //设置Cookie
    m_request.setHeader(QNetworkRequest::CookieHeader,var);
}

void QHttpNet::Business_IconResponse(const QJsonObject &json_)
{
    QJsonValue icon_state_json = json_.value("icon_state");
    int state_ = icon_state_json.toInt(); //转int
    switch(state_)
    {
    case ICON_STATE_NOICON:
    {
        qDebug() << "获取头像失败,没有头像";
        break;
    }
    case ICON_STATE_NOUSERNAME:
    {
        qDebug() << "获取头像失败,没有用户名";
        break;
    }
    case ICON_STATE_NORMAL:
    {
        qDebug() << "获取头像正常" ;
        QString icon_url_ = BASE_URL + json_.value("icon_url").toString(); //头像地址
        emit UserIconSignal(icon_url_); //发射用户头像信号
        break;
    }
    default:
    {
        break;
    }
    }
}
