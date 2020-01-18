#include "YLogin.h"
#include "ui_YLogin.h"

YLogin::YLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YLogin)
{
   // this->setWindowFlags(Qt::Widget);

    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
}

YLogin::~YLogin()
{
    delete ui;
}

void YLogin::mousePressEvent(QMouseEvent *e)
{
last=e->globalPos();
}

void YLogin::mouseMoveEvent(QMouseEvent *e)
{
int dx = e->globalX() - last.x();
int dy = e->globalY() - last.y();
last = e->globalPos();
move(x()+dx, y()+dy);
}

void YLogin::mouseReleaseEvent(QMouseEvent *e)
{
int dx = e->globalX() - last.x();
int dy = e->globalY() - last.y();
move(x()+dx, y()+dy);
}
