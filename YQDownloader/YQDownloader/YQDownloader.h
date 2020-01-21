#ifndef YQDOWNLOADER_H
#define YQDOWNLOADER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class YQDownloader; }
QT_END_NAMESPACE

class YQDownloader : public QWidget
{
    Q_OBJECT

public:
    YQDownloader(QWidget *parent = nullptr);
    ~YQDownloader();

private:
    Ui::YQDownloader *ui;
};
#endif // YQDOWNLOADER_H
