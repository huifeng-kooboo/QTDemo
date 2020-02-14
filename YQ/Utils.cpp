#include "Utils.h"
#include <QDebug>
// 判断是否未纯数字
bool Utils::isPureNums(QString num_)
{
        QByteArray ba = num_.toLocal8Bit();  //分开写是为了防止乱码
        char* s = ba.data();
        while (*s && *s >= '0' && *s <= '9')
        {
            s++;
        }
        return !bool(*s);
}

bool Utils::StringJudgeAccount(QString string_)
{
    //1.判断位数>6 < 12
    if (string_.size() <6 || string_.size() > 12)
    {
        //提示框显示错
        QString err_ = "err _ nums";
        return false;
    }
    //2.判断是否只包含数字
    if(isPureNums(string_))
    {
        return true;
    }
    return false;
}

bool Utils::StringJudgePassword(QString string_)
{
    //1.判断位数>6 < 12
    if (string_.size() <6 || string_.size() > 12)
    {
        //提示框显示错
        QString err_ = "err _ nums";
        return false;
    }
    return true;
}

QString Utils::QJsonObjectToQString(QJsonObject& json_object)
{
   return QString(QJsonDocument(json_object).toJson(QJsonDocument::Compact));
}

bool Utils::IsFileExist(QString filename)
{
    //1.判断文件名
    if(filename.size()<1)
    {
        return false;
    }
    //2.判断文件是否存在
    QFileInfo fileInfo(filename);
    if(fileInfo.isFile())
    {
        return true;
    }
    return false;
}

QString Utils::GetFileMd5(QString& file_name)
{
    //获取文件md5码
    QFile file(file_name);
    file.open(QFile::ReadOnly);
    QByteArray fileMsg = file.readAll();
    QByteArray md5_val = QCryptographicHash::hash(fileMsg , QCryptographicHash::Md5).toHex();
    file.close();
    QString md5_str = md5_val;
    return md5_str;
}

bool  Utils::QStringToQJsonObject(QString& str_,QJsonObject&json_)
{
      QJsonDocument jsonDocument = QJsonDocument::fromJson(str_.toLocal8Bit().data());
      if( jsonDocument.isNull() ){
          return false;
      }
      json_ = jsonDocument.object();
      return true;
}

// 创建文件夹
bool Utils::CreateDirectory_(QString& folder_path)
{
    QDir dir;
    if(dir.exists(folder_path))
    {
        qDebug() << "当前文件夹已存在" ;
        return false;
    }
    dir.mkpath(folder_path);
    return true;
}

// 创建文件
bool Utils::CreateFile_(QString& file_name)
{
    if(Utils::IsFileExist(file_name))
    {
        qDebug() << "该文件已存在";
        return false;
    }
    QFile *m_file = new QFile(file_name);
    if(m_file->open(QIODevice::WriteOnly))
    {
        m_file->close();
        return true;
    }
    qDebug() << "文件创建失败" ;
    delete m_file;
    m_file = nullptr;
    return false;
}

bool Utils::DeleteDirectory_(QString& folder_path)
{
    if (folder_path.isEmpty()){
        return false;
    }
    QDir dir(folder_path);
    if(!dir.exists()){
        qDebug() << "文件夹为空";
        return true;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
    QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
    foreach (QFileInfo file, fileList){ //遍历文件信息
        if (file.isFile()){ // 是文件，删除
            file.dir().remove(file.fileName());
        }else{ // 递归删除
           dir.remove(file.absoluteFilePath());
        }
    }
    return dir.rmpath(dir.absolutePath()); // 删除文件夹
}

bool Utils::DeleteFile_(QString& file_name)
{
    return QFile::remove(file_name);
}

QByteArray Utils::QStringToQByteArray(QString str_)
{
    return str_.toUtf8(); // 转成UTF-8格式的 可以避免乱码
}

QString Utils::QByteArrayToQString(QByteArray array_)
{
    QString str_ = array_;
    return str_;
}
