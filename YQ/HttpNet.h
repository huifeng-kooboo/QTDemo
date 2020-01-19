#include "YLogin.h"

class HttpNet{
public:
    HttpNet();
    ~HttpNet();

    //下载文件
    //@params:url_:文件下载url
    //@params:path_:保存路径
    //@return：是否下载完成
    bool DownloadFile(QString url_,QString path_);
};
