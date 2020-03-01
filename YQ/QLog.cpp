#include "QLog.h"
#include "Utils.h"
#include <QDebug>

QLog::QLog()
{
    m_file = nullptr;
}

QLog::~QLog()
{

}

QLog* QLog::GetInstance()
{
    if(m_log==nullptr)
    {
        m_log = new QLog();
        return m_log;
    }
    return m_log;
}

QLog* QLog::m_log = nullptr;

bool QLog::InitLog(QString log_name)
{
    QString log_file_name = Utils::GetCurrentDay() + log_name; // 拼接字符串
    if(Utils::IsFileExist(log_file_name))
    {
        qDebug() << "log文件已存在，不再创建";
        return false;
    }
    else{
        m_file = new QFile(log_file_name);
        if(m_file==nullptr)
        {
            qDebug() << "创建文件失败";
            return false;
        }
        else{
            return true;
        }
    }
}
