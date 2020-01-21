#include "YQDownloader.h"
#include "ui_YQDownloader.h"

YQDownloader::YQDownloader(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::YQDownloader)
{
    ui->setupUi(this);
}

YQDownloader::~YQDownloader()
{
    delete ui;
}

