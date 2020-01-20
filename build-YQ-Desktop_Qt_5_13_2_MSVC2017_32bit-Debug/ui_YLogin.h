/********************************************************************************
** Form generated from reading UI file 'YLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YLOGIN_H
#define UI_YLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YLogin
{
public:
    QWidget *centralwidget;
    QPushButton *btn_Login;
    QCheckBox *cb_pwd;
    QCheckBox *cb_autologin;
    QLabel *lbl_back;
    QLabel *lbl_reg_num;
    QLabel *lbl_find_password;
    QLineEdit *lineEdit_Account;
    QLineEdit *lineEdit_Password;
    QLabel *lbl_avator;
    QPushButton *btn_Min;
    QPushButton *btn_close;
    QPushButton *btn_drop;
    QPushButton *btn_addaccount;
    QPushButton *btn_qrcode;
    QLabel *lbl_Tips;
    QPushButton *btn_pull;
    QLabel *lbl_warning_ico;
    QWidget *widget_qrcode;
    QPushButton *btn_choose;

    void setupUi(QMainWindow *YLogin)
    {
        if (YLogin->objectName().isEmpty())
            YLogin->setObjectName(QString::fromUtf8("YLogin"));
        YLogin->resize(426, 366);
        YLogin->setMinimumSize(QSize(426, 337));
        YLogin->setMaximumSize(QSize(426, 366));
        YLogin->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:rgb(235,242,249);\n"
"border-bottom-right-radius:4px;\n"
"border-bottom-left-radius:4px;\n"
"}\n"
"QWidget{\n"
"border-bottom-right-radius:4px;\n"
"border-bottom-left-radius:4px;\n"
"}\n"
""));
        centralwidget = new QWidget(YLogin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_Login = new QPushButton(centralwidget);
        btn_Login->setObjectName(QString::fromUtf8("btn_Login"));
        btn_Login->setGeometry(QRect(115, 292, 196, 30));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_Login->sizePolicy().hasHeightForWidth());
        btn_Login->setSizePolicy(sizePolicy);
        btn_Login->setMinimumSize(QSize(196, 30));
        btn_Login->setMaximumSize(QSize(196, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(9);
        btn_Login->setFont(font);
        btn_Login->setStyleSheet(QString::fromUtf8("QPushButton#btn_Login{       /*\350\256\276\347\275\256\345\261\236\346\200\247\346\226\271\346\263\225\357\274\232\346\216\247\344\273\266\345\220\215+ #\345\261\236\346\200\247\345\200\274*/\n"
"    border:1px solid rgb(0,163,255);\n"
"    /*\350\256\276\347\275\256\345\234\206\350\247\222*/\n"
"    border-top-left-radius:4px;\n"
"    border-top-right-radius:4px;\n"
"    border-bottom-right-radius:4px;\n"
"    border-bottom-left-radius:4px;\n"
"    /*\350\256\276\347\275\256\350\203\214\346\231\257\350\211\262*/\n"
"    background:rgb(0,163,255);\n"
"    /*\350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    color:rgb(212,242,253);\n"
"}\n"
"QPushButton#btn_Login:hover{       /*\350\256\276\347\275\256\345\261\236\346\200\247\346\226\271\346\263\225\357\274\232\346\216\247\344\273\266\345\220\215+ #\345\261\236\346\200\247\345\200\274*/\n"
"    border:1px solid rgb(60,195,245);\n"
"    /*\350\256\276\347\275\256\345\234\206\350\247\222*/\n"
"    border-top-left-radius:4px;\n"
" "
                        "   border-top-right-radius:4px;\n"
"    border-bottom-right-radius:4px;\n"
"    border-bottom-left-radius:4px;\n"
"    /*\350\256\276\347\275\256\350\203\214\346\231\257\350\211\262*/\n"
"    background:rgb(60,195,245);\n"
"    /*\350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    color:rgb(212,242,253);\n"
"};"));
        cb_pwd = new QCheckBox(centralwidget);
        cb_pwd->setObjectName(QString::fromUtf8("cb_pwd"));
        cb_pwd->setGeometry(QRect(113, 263, 71, 16));
        cb_pwd->setStyleSheet(QString::fromUtf8("QCheckBox#cb_pwd{\n"
"color:rgb(141,145,149);\n"
"}\n"
"QCheckBox#cb_pwd::indicator{\n"
"width:17px;\n"
"height:17px;\n"
"}\n"
"QCheckBox#cb_pwd::indicator:enabled:unchecked {\n"
"        image: url(\":/login/src/styles/uncheck.png\");\n"
"}\n"
"QCheckBox#cb_pwd::indicator:enabled:checked {\n"
"        image: url(\":/login/src/styles/check.png\");\n"
"}\n"
"QCheckBox#cb_pwd::indicator:unchecked:hover\n"
"{\n"
"    image: url(\":/login/src/styles/hover.png\");\n"
"}"));
        cb_autologin = new QCheckBox(centralwidget);
        cb_autologin->setObjectName(QString::fromUtf8("cb_autologin"));
        cb_autologin->setGeometry(QRect(245, 263, 71, 16));
        cb_autologin->setStyleSheet(QString::fromUtf8("QCheckBox#cb_autologin{\n"
"color:rgb(141,145,149);\n"
"}\n"
"QCheckBox#cb_autologin::indicator{\n"
"width:17px;\n"
"height:17px;\n"
"}\n"
"QCheckBox#cb_autologin::indicator:enabled:unchecked {\n"
"        image: url(\":/login/src/styles/uncheck.png\");\n"
"}\n"
"QCheckBox#cb_autologin::indicator:enabled:checked {\n"
"        image: url(\":/login/src/styles/check.png\");\n"
"}\n"
"QCheckBox#cb_autologin::indicator:unchecked:hover\n"
"{\n"
"    image: url(\":/login/src/styles/hover.png\");\n"
"}"));
        lbl_back = new QLabel(centralwidget);
        lbl_back->setObjectName(QString::fromUtf8("lbl_back"));
        lbl_back->setGeometry(QRect(0, 0, 426, 179));
        lbl_back->setStyleSheet(QString::fromUtf8("QLabel#lbl_back{\n"
"image: url(\":/login/src/styles/statedemo.png\");\n"
"}"));
        lbl_reg_num = new QLabel(centralwidget);
        lbl_reg_num->setObjectName(QString::fromUtf8("lbl_reg_num"));
        lbl_reg_num->setGeometry(QRect(336, 207, 54, 12));
        lbl_reg_num->setStyleSheet(QString::fromUtf8("QLabel#lbl_reg_num{\n"
"color:rgb(39,134,228);\n"
"}"));
        lbl_find_password = new QLabel(centralwidget);
        lbl_find_password->setObjectName(QString::fromUtf8("lbl_find_password"));
        lbl_find_password->setGeometry(QRect(336, 237, 54, 12));
        lbl_find_password->setStyleSheet(QString::fromUtf8("QLabel#lbl_find_password{\n"
"color:rgb(39,134,228);\n"
"}"));
        lineEdit_Account = new QLineEdit(centralwidget);
        lineEdit_Account->setObjectName(QString::fromUtf8("lineEdit_Account"));
        lineEdit_Account->setGeometry(QRect(113, 198, 200, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(11);
        lineEdit_Account->setFont(font1);
        lineEdit_Account->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit_Account\n"
"{\n"
"    border:1px solid rgb(209,209,209);\n"
"    border-top-right-radius:4px;\n"
"    border-top-left-radius:4px;\n"
"    border-bottom-right-radius:0px;\n"
"    border-bottom-left-radius:0px;\n"
"}\n"
"QLineEdit#lineEdit_Account:hover\n"
"{\n"
"    border:1px solid rgb(21,131,221);\n"
"}\n"
""));
        lineEdit_Password = new QLineEdit(centralwidget);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(113, 226, 200, 28));
        lineEdit_Password->setFont(font1);
        lineEdit_Password->setStyleSheet(QString::fromUtf8("QLineEdit#lineEdit_Password\n"
"{\n"
"    border:1px solid rgb(209,209,209);\n"
"}\n"
"QLineEdit#lineEdit_Password:hover\n"
"{\n"
"    border:1px solid rgb(21,131,221);\n"
"}\n"
""));
        lbl_avator = new QLabel(centralwidget);
        lbl_avator->setObjectName(QString::fromUtf8("lbl_avator"));
        lbl_avator->setGeometry(QRect(20, 195, 86, 88));
        lbl_avator->setStyleSheet(QString::fromUtf8("QLabel#lbl_avator{\n"
"image: url(\":/login/src/styles/avatar.png\");\n"
"}"));
        btn_Min = new QPushButton(centralwidget);
        btn_Min->setObjectName(QString::fromUtf8("btn_Min"));
        btn_Min->setGeometry(QRect(370, 0, 25, 29));
        btn_Min->setStyleSheet(QString::fromUtf8("QPushButton#btn_Min{\n"
"image: url(\":/login/src/styles/mim_size.png\");\n"
"}\n"
"QPushButton#btn_Min:hover\n"
"{\n"
"    image: url(\":/login/src/styles/min_hover.png\");\n"
"}"));
        btn_close = new QPushButton(centralwidget);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(400, 5, 21, 27));
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton#btn_close{\n"
"image: url(\":/login/src/styles/close.png\");\n"
"}\n"
"QPushButton#btn_close:hover\n"
"{\n"
"    image: url(\":/login/src/styles/close_hover.png\");\n"
"}"));
        btn_drop = new QPushButton(centralwidget);
        btn_drop->setObjectName(QString::fromUtf8("btn_drop"));
        btn_drop->setGeometry(QRect(345, 3, 26, 26));
        btn_drop->setStyleSheet(QString::fromUtf8("QPushButton#btn_drop{\n"
"image: url(\":/login/src/styles/dropdown.png\");\n"
"}\n"
"QPushButton#btn_drop:hover\n"
"{\n"
"    image: url(\":/login/src/styles/dropdown_hover.png\");\n"
"}"));
        btn_addaccount = new QPushButton(centralwidget);
        btn_addaccount->setObjectName(QString::fromUtf8("btn_addaccount"));
        btn_addaccount->setGeometry(QRect(10, 300, 29, 29));
        btn_addaccount->setStyleSheet(QString::fromUtf8("QPushButton#btn_addaccount{\n"
"image: url(\":/login/src/styles/add_account.png\");\n"
"}\n"
"QPushButton#btn_addaccount:hover{\n"
"image: url(\":/login/src/styles/add_account_hover.png\");\n"
"}"));
        btn_qrcode = new QPushButton(centralwidget);
        btn_qrcode->setObjectName(QString::fromUtf8("btn_qrcode"));
        btn_qrcode->setGeometry(QRect(385, 300, 29, 29));
        btn_qrcode->setStyleSheet(QString::fromUtf8("QPushButton#btn_qrcode{\n"
"image: url(\":/login/src/styles/qr_code.png\");\n"
"}\n"
"QPushButton#btn_qrcode:hover{\n"
"image: url(\":/login/src/styles/qr_code_hover.png\");\n"
"}"));
        lbl_Tips = new QLabel(centralwidget);
        lbl_Tips->setObjectName(QString::fromUtf8("lbl_Tips"));
        lbl_Tips->setGeometry(QRect(0, 337, 426, 29));
        lbl_Tips->setStyleSheet(QString::fromUtf8("QLabel#lbl_Tips{\n"
"background-color:rgb(249,244,212);\n"
"}"));
        btn_pull = new QPushButton(centralwidget);
        btn_pull->setObjectName(QString::fromUtf8("btn_pull"));
        btn_pull->setGeometry(QRect(402, 342, 21, 18));
        btn_pull->setStyleSheet(QString::fromUtf8("QPushButton#btn_pull{\n"
"image: url(\":/login/src/styles/re_sour.png\");\n"
"}"));
        lbl_warning_ico = new QLabel(centralwidget);
        lbl_warning_ico->setObjectName(QString::fromUtf8("lbl_warning_ico"));
        lbl_warning_ico->setGeometry(QRect(1, 343, 19, 18));
        lbl_warning_ico->setStyleSheet(QString::fromUtf8("QLabel#lbl_warning_ico{\n"
"image: url(\":/login/src/styles/warning_ico.png\");\n"
"}"));
        widget_qrcode = new QWidget(centralwidget);
        widget_qrcode->setObjectName(QString::fromUtf8("widget_qrcode"));
        widget_qrcode->setGeometry(QRect(0, 30, 426, 307));
        btn_choose = new QPushButton(centralwidget);
        btn_choose->setObjectName(QString::fromUtf8("btn_choose"));
        btn_choose->setGeometry(QRect(288, 203, 19, 19));
        btn_choose->setStyleSheet(QString::fromUtf8("QPushButton#btn_choose{\n"
"  image: url(\":/login/src/styles/choose.png\");\n"
"}\n"
"QPushButton#btn_choose:hover{\n"
"  image: url(\":/login/src/styles/choose_hover.png\");\n"
"}\n"
"QPushButton#btn_choose:pressed{\n"
"  image: url(\":/login/src/styles/choose_on.png\");\n"
"}"));
        YLogin->setCentralWidget(centralwidget);
        btn_Login->raise();
        cb_pwd->raise();
        cb_autologin->raise();
        lbl_back->raise();
        lbl_reg_num->raise();
        lbl_find_password->raise();
        lineEdit_Account->raise();
        lineEdit_Password->raise();
        lbl_avator->raise();
        btn_Min->raise();
        btn_close->raise();
        btn_drop->raise();
        btn_addaccount->raise();
        btn_qrcode->raise();
        lbl_Tips->raise();
        btn_pull->raise();
        lbl_warning_ico->raise();
        btn_choose->raise();
        widget_qrcode->raise();

        retranslateUi(YLogin);

        QMetaObject::connectSlotsByName(YLogin);
    } // setupUi

    void retranslateUi(QMainWindow *YLogin)
    {
        YLogin->setWindowTitle(QCoreApplication::translate("YLogin", "YLogin", nullptr));
        btn_Login->setText(QCoreApplication::translate("YLogin", "\347\231\273 \345\275\225", nullptr));
        cb_pwd->setText(QCoreApplication::translate("YLogin", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        cb_autologin->setText(QCoreApplication::translate("YLogin", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        lbl_back->setText(QString());
        lbl_reg_num->setText(QCoreApplication::translate("YLogin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"www.baidu.com\"><span style=\" font-family:'SimSun';text-decoration:none; color:rgb(39,134,228);\">\346\263\250\345\206\214\350\264\246\345\217\267</span></a></p></body></html>", nullptr));
        lbl_find_password->setText(QCoreApplication::translate("YLogin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"www.baidu.com\"><span style=\" font-family:'SimSun';text-decoration:none; color:rgb(39,134,228);\">\346\211\276\345\233\236\345\257\206\347\240\201</span></a></p></body></html>", nullptr));
        lbl_avator->setText(QString());
        btn_Min->setText(QString());
        btn_close->setText(QString());
        btn_drop->setText(QString());
        btn_addaccount->setText(QString());
        btn_qrcode->setText(QString());
        lbl_Tips->setText(QCoreApplication::translate("YLogin", "     \346\202\250\345\267\262\347\231\273\345\275\225942840260,\344\270\215\350\203\275\351\207\215\345\244\215\347\231\273\345\275\225\343\200\202", nullptr));
        btn_pull->setText(QString());
        lbl_warning_ico->setText(QString());
        btn_choose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YLogin: public Ui_YLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YLOGIN_H
