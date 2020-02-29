/********************************************************************************
** Form generated from reading UI file 'YQMain.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YQMAIN_H
#define UI_YQMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YQMain
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *YQMain)
    {
        if (YQMain->objectName().isEmpty())
            YQMain->setObjectName(QString::fromUtf8("YQMain"));
        YQMain->resize(800, 600);
        centralwidget = new QWidget(YQMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        YQMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(YQMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        YQMain->setMenuBar(menubar);
        statusbar = new QStatusBar(YQMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        YQMain->setStatusBar(statusbar);

        retranslateUi(YQMain);

        QMetaObject::connectSlotsByName(YQMain);
    } // setupUi

    void retranslateUi(QMainWindow *YQMain)
    {
        YQMain->setWindowTitle(QCoreApplication::translate("YQMain", "YQMain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YQMain: public Ui_YQMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YQMAIN_H
