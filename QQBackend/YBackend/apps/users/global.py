# 公共变量区
from enum import Enum

# 定义资源类型，用于返回数据格式
class ResType(Enum):
    RES_LOGIN = 100
    RES_REGISTER = 101
    RES_ERROR = 10000