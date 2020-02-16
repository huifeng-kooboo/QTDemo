from django.shortcuts import render
from django.http import HttpResponse
from .models import QQUsers
from rest_framework import viewsets,mixins,status
from .serializers import UserSerializer,UserIconSerializer
from rest_framework.views import APIView
from rest_framework.response import Response
from .utils import *

class UserViewSet(viewsets.ModelViewSet):
    queryset = QQUsers.objects.all().order_by('username') # 根据用户名降序
    serializer_class = UserSerializer

class UserRegisterViewSet(viewsets.GenericViewSet,mixins.CreateModelMixin):
    '''
    用户注册功能
    '''
    queryset = QQUsers.objects.all()
    serializer_class = UserSerializer

class UserIconViewSet(APIView):
    '''
    获取用户头像功能
    '''
    def post(self,request,*args,**kwargs):
        '''
        :param request:
        :param args:
        :param kwargs:
        :return:
        '''
        username_str = request.data.get('username')
        print(username_str)
        userdata = QQUsers.objects.filter(username=username_str)
        dict_Result = {}
        dict_Result['request_type'] = ResType.RES_USERICON.value
        print(len(userdata))
        if len(userdata) < 1:
            '''
            用户数据
            '''
            dict_Result['icon_state'] = UserIconState.ICON_STATE_NOUSERNAME.value
            return Response(dict_Result, status=status.HTTP_200_OK)
        dict_Result['icon_state'] = UserIconState.ICON_STATE_NORMAL.value
        dict_Result['icon_url'] = userdata[0].user_icon.url
        print(dict_Result['icon_url'])
        return Response(dict_Result, status=status.HTTP_200_OK)

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
        # 获取用户名和密码
        username_str = request.data.get('username')
        password_str = request.data.get('password')
        json_Result = checkUserLoginInfo(username_str,password_str)
        print(type(json.loads(json_Result)))
        if json.loads(json_Result)['OK'] == 0:
            json_ = json.loads(json_Result)
            json_.update({'login_state': LoginState.LOGIN_ERROR_USERNAME.value})
            return Response(json_, status=status.HTTP_200_OK)  # 由前端做数据处理
        # 对比数据库 获取是否有该登录名
        userdata = QQUsers.objects.filter(username=username_str)
        if len(userdata) < 1:
            json_ = json.loads(json_Result)
            json_.update({'login_state': LoginState.LOGIN_ERROR_USERNAME.value})
            return Response(json_, status=status.HTTP_200_OK)  # 由前端做数据处理
        cur_password_str = userdata[0].password
        b_password = checkSecurityPassword(password_str, cur_password_str)  # compare the password
        # 密码错误
        if b_password == False:
            json_ = json.loads(json_Result)
            json_.update({'login_state': LoginState.LOGIN_ERROR_PASSWORD.value})
            return Response(json_, status=status.HTTP_200_OK)
        json_ = json.loads(json_Result)
        json_.update({'login_state': LoginState.LOGIN_SUCCESS.value})
        return Response(json_, status=status.HTTP_200_OK)  # 由前端做数据处理 userdata.values[0]会直接转成json格
