
#include <QFile>
#include <QString>

class QLog{
public:
    QLog();
    ~QLog();

    bool InitLog(QString log_name); // 初始化Log日志
    static QLog* GetInstance();   //获取实例
    bool WriteLog(QString str_);

private:
    QFile* m_file;
    QString m_log_path;
    static QLog* m_log;
};
