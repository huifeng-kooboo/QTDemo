# Generated by Django 3.0.2 on 2020-01-31 13:22

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('users', '0002_auto_20200131_2120'),
    ]

    operations = [
        migrations.AlterField(
            model_name='qqusers',
            name='password',
            field=models.CharField(help_text='密码', max_length=50, verbose_name='密码'),
        ),
    ]
