from django.shortcuts import render
from django.http import HttpResponse
from .models import QQUsers
from rest_framework import viewsets,mixins
from .serializers import UserSerializer

class UserViewSet(viewsets.ModelViewSet):
    queryset = QQUsers.objects.all().order_by('username') # 根据用户名降序
    serializer_class = UserSerializer

class UserRegisterViewSet(viewsets.GenericViewSet,mixins.CreateModelMixin):
    '''
    用户注册功能
    '''
    queryset = QQUsers.objects.all()
    serializer_class = UserSerializer

class UserLoginViewSet(viewsets.ModelViewSet,mixins.ListModelMixin):
    '''
    用户登录功能
    '''
    queryset = QQUsers.objects.all()
    serializer_class = UserSerializer
