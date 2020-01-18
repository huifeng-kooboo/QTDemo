#include "YLogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YLogin w;
    w.show();
    return a.exec();
}
