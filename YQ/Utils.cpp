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
    return true;
}

// 创建文件
bool Utils::CreateFile_(QString& file_name)
{
    return true;
}
