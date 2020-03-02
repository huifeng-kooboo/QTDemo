#include "QLog.h"
#include "Utils.h"
#include <QDebug>

QLog::QLog()
{
    m_file = nullptr;
}

QLog::~QLog()
{
    m_file->close();
    delete m_file;
    m_file = nullptr;
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
    m_log_path = log_file_name;
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

bool QLog::WriteLog(QString str_)
{
    if(!m_file)
    {
        m_file = new QFile(m_log_path);
    }
    m_file->open(QIODevice::WriteOnly);
    m_file->write(Utils::QStringToQByteArray(str_));
    return true;
}
