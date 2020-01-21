#include "YLogin.h"

enum DownloadState{
    DOWNLOAD_BEGIN, //开始下载
    DOWNLOADING, //下载中
    FINISHED, //下载完成
    DOWNLOAD_COLLAPSE, //下载崩溃
};


typedef struct{
    QString file_name; //文件名
    QString download_url; //文件下载地址
    int file_size; //文件大小(M为单位)
    int progress_value; //下载进度0-100
    DownloadState file_state; //当前文件的下载状态
} DownloadFileInfo;

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
