from django.shortcuts import render
from django.http import HttpResponse
from .models import QQUsers
from rest_framework import viewsets
from .serializers import UserSerializer

class UserViewSet(viewsets.ModelViewSet):
    queryset = QQUsers.objects.all().order_by('username') # 根据用户名降序
    serializer_class = UserSerializer