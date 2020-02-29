#include "YQMain.h"
#include "ui_YQMain.h"

YQMain::YQMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YQMain)
{
    ui->setupUi(this);
}

YQMain::~YQMain()
{
    delete ui;
}

