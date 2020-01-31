#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QFileInfo>
#include <qcryptographichash.h>
#include <iostream>
#include <string>

// 公共方法存放
namespace Utils {

//1.字符串处理部分
bool StringJudgeAccount(QString string_); //字符串判断用户账号
bool StringJudgePassword(QString string_); //字符串判断用户账号
bool isPureNums(QString num_); // 判断是否为纯数字
QString QJsonObjectToQString(QJsonObject& json_object); //QJsonObject转QString
bool  QStringToQJsonObject(QString& str_,QJsonObject&json_); //QString转QJsonObject

//2.文件处理部分
QString GetFileMd5(QString &file_name); //获取文件md5值
bool IsFileExist(QString filename);//判断是否文件存在

//3.
}
