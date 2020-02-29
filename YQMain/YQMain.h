#ifndef YQMAIN_H
#define YQMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class YQMain; }
QT_END_NAMESPACE

class YQMain : public QMainWindow
{
    Q_OBJECT

public:
    YQMain(QWidget *parent = nullptr);
    ~YQMain();

private:
    Ui::YQMain *ui;
};
#endif // YQMAIN_H
