from django.urls import path,include
from django.conf.urls import url
from . import views
from rest_framework import routers
from .views import UserViewSet,UserRegisterViewSet,UserLoginViewSet

# 注册路由
router = routers.DefaultRouter()
router.register(r'users',UserViewSet)
router.register(r'register',UserRegisterViewSet) #注册


urlpatterns = [
    path('',include(router.urls)),
    url(r'^login/',UserLoginViewSet.as_view(),name='login'),
]