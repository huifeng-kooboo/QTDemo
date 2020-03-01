#ifndef QLOG_H
#define QLOG_H

#endif // QLOG_H

#include <QFile>
#include <QString>

class QLog{
public:
    QLog();
    ~QLog();

    bool InitLog(QString log_name); // 初始化Log日志
    static QLog* GetInstance();   //获取实例

private:
    QFile* m_file;
    static QLog* m_log;
};
