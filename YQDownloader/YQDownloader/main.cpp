#include "YQDownloader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YQDownloader w;
    w.show();
    return a.exec();
}
