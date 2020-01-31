from django.db import models
from django.contrib.auth.models import AbstractUser

'''
QQ用户模型 :继承自带User模型
'''
class QQUsers(AbstractUser):
    # 用户名 设置为主键
    username = models.CharField(help_text='QQ账号',verbose_name='用户名',primary_key=True,max_length=12,unique=True,blank=False)
    # 是否Vip会员
    is_Vip = models.BooleanField(help_text='VIP会员：充值即得',verbose_name='VIP会员',default=False) #是否为Vip会员
    class Meta:
        ordering = ['username'] #列表按照用户名排序
        db_table = 'QQUsers'
        verbose_name = 'QQ用户表'
        verbose_name_plural = verbose_name