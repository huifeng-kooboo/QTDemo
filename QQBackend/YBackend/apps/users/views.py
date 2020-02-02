from django.shortcuts import render
from django.http import HttpResponse
from .models import QQUsers
from rest_framework import viewsets,mixins,status
from .serializers import UserSerializer
from rest_framework.views import APIView
from rest_framework.response import Response

class UserViewSet(viewsets.ModelViewSet):
    queryset = QQUsers.objects.all().order_by('username') # 根据用户名降序
    serializer_class = UserSerializer

class UserRegisterViewSet(viewsets.GenericViewSet,mixins.CreateModelMixin):
    '''
    用户注册功能
    '''
    queryset = QQUsers.objects.all()
    serializer_class = UserSerializer

class UserLoginViewSet(APIView):
    '''
    用户登录功能
    '''
    def post(self,request,*args,**kwargs):
        '''
        :param request:
        :param args:
        :param kwargs:
        :return:
        '''
        username_str = request.data.get('username')
        password_str = request.data.get('password')
        print(username_str)
        return Response(username_str, status=status.HTTP_200_OK)

