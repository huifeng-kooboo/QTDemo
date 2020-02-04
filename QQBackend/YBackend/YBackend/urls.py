"""YBackend URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.conf.urls import url, include
from rest_framework.documentation import include_docs_urls
from django.conf.urls.static import static
from django.conf import settings

# Wire up our API using automatic URL routing.
# Additionally, we include login URLs for the browsable API.
urlpatterns = [
    path('users/',include('users.urls')),
    path('admin/', admin.site.urls), # 管理员入口
    url(r'^api-auth/', include('rest_framework.urls', namespace='rest_framework')),
    url(r'docs/',include_docs_urls(title='接口文档')) #自动生成api文档
] + static(settings.MEDIA_URL,document_root=settings.MEDIA_ROOT) # 作用，提供客户端可以访问进行下载到本地