# 序列化模型

from .models import QQUsers
from rest_framework import serializers

# 用户信息序列化
class UserSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = QQUsers
        fields = ['username','password']

class UserIconSerializer(serializers.HyperlinkedModelSerializer):
    '''
    用户头像序列化
    '''
    class Meta:
        model = QQUsers
        fields = ['username','user_icon']