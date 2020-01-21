/********************************************************************************
** Form generated from reading UI file 'YQDownloader.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YQDOWNLOADER_H
#define UI_YQDOWNLOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YQDownloader
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QProgressBar *progressBar;

    void setupUi(QWidget *YQDownloader)
    {
        if (YQDownloader->objectName().isEmpty())
            YQDownloader->setObjectName(QString::fromUtf8("YQDownloader"));
        YQDownloader->resize(400, 300);
        YQDownloader->setMinimumSize(QSize(400, 300));
        YQDownloader->setMaximumSize(QSize(400, 300));
        label = new QLabel(YQDownloader);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 81, 31));
        lineEdit = new QLineEdit(YQDownloader);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 231, 31));
        label_2 = new QLabel(YQDownloader);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 61, 16));
        lineEdit_2 = new QLineEdit(YQDownloader);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 69, 231, 31));
        progressBar = new QProgressBar(YQDownloader);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 170, 341, 23));
        progressBar->setValue(24);

        retranslateUi(YQDownloader);

        QMetaObject::connectSlotsByName(YQDownloader);
    } // setupUi

    void retranslateUi(QWidget *YQDownloader)
    {
        YQDownloader->setWindowTitle(QCoreApplication::translate("YQDownloader", "YQDownloader", nullptr));
        label->setText(QCoreApplication::translate("YQDownloader", "\344\270\213\350\275\275\351\223\276\346\216\245\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("YQDownloader", "\344\277\235\345\255\230\344\275\215\347\275\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YQDownloader: public Ui_YQDownloader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YQDOWNLOADER_H
