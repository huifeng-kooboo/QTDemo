#include "YQMain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YQMain w;
    w.show();
    return a.exec();
}
