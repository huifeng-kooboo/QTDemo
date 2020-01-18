#include "YLogin.h"
#include <iostream>
#include <string>

// 公共方法存放
namespace Utils {

//1.字符串处理部分
bool StringJudgeAccount(QString string_); //字符串判断用户账号
bool StringJudgePassword(QString string_); //字符串判断用户账号
bool isPureNums(QString num_); // 判断是否为纯数字
QString QJsonObjectToQString(QJsonObject& json_object); //QJsonObject转QString

//2.
}
