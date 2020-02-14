#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#endif // GLOBALDATA_H


//全局变量区
#define GET_REPEAT_LOGIN_STR(s) QString("    您已登录"+s+",不能重复登录.")  //获取重复登录提示

#define BASE_URL "http://127.0.0.1:8000"

#define REGISTER_ACCOUNT_URL  "https://ssl.zc.qq.com/v3/index-chs.html?from=client&pt_clientver=5603&pt_src=1&client=tim&regkey=EFB8C0068D611967765955AC4EB6A95EF03D4521CD3ED91FB3DFF22006ADCAA1&ADUIN=0&ADSESSION=0&ADTAG=CLIENT.QQ.5603_NewAccount_Btn.0&ADPUBNO=26933"

#define FORGET_PASSWORD_URL  "https://aq.qq.com/v2/uv_aq/html/reset_pwd/pc_reset_pwd_input_account.html?v=3.0" //忘记密码

#define TEST_GET_URL "http://127.0.0.1:8000/login/login/"   //测试getdata功能

#define GITHUB_URL  "http://github.com/"

#define LOGIN_URL   "http://127.0.0.1:8000/users/login/"      //登录URL

#define REGISTER_URL "http://127.0.0.1:8000/users/register/"  //注册URL

//文件版本
#define FILE_VERSION_URL "http://127.0.0.1:8000/media/configs/QQVersion.ini"  //文件版本URL

#define FILE_VERSION_NAME "QQVesion.ini"  //版本文件名

//获取用户头像
#define USER_ICON_URL  "http://127.0.0.1:8000/users/usericon/"

//用户本地配置
#define LOCAL_CONFIG_FOLDER "configs/"
#define LOCAL_CONFIG_FILE "configs/user.ini"

// 本地配置相关常量存放 ：全都保存在ini文件中
#define CUR_ACCOUNT "cur_account"  // 当前账号
#define CUR_PASSWORD "cur_password"  //当前密码
#define CUR_USERICON_URL "cur_usericon" //当前头像URL:方式加载
#define IS_REMEMBER_PASSWORD "is_remember_password" // 是否记住密码
#define IS_AUTO_LOGIN "is_auto_login" //是否自动登录

