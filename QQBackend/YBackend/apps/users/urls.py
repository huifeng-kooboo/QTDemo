from django.urls import path,include
from . import views
from rest_framework import routers
from .views import UserViewSet

# 注册路由
router = routers.DefaultRouter()
router.register(r'users',UserViewSet)


urlpatterns = [
    path('',include(router.urls))
]