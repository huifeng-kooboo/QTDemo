#include "Utils.h"

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
    //1.判断该文件是否存在

    //2.获取文件MD5值

    //3.进行判断
    return "";
}
