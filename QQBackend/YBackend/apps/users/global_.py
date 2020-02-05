# 公共变量区
from enum import Enum

# 定义资源类型，用于返回数据格式
class ResType(Enum):
    RES_LOGIN = 100
    RES_REGISTER = 101
    RES_USERICON = 102 #获取用户头像
    RES_ERROR = 10000

# 定义登录状态枚举类型
class LoginState(Enum):
    LOGIN_SUCCESS = 1
    LOGIN_ERROR_USERNAME = 2
    LOGIN_ERROR_PASSWORD = 3
    LOGIN_ERROR_HTTP = 4

# 定义用户头像枚举类型
class UserIconState(Enum):
    ICON_STATE_NOUSERNAME = 1 #用户名不存在
    ICON_STATE_NOICON = 2  # 没有图标
    ICON_STATE_NORMAL = 3  # 正常
