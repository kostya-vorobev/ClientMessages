/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SendB;
    QPlainTextEdit *LoginTB;
    QLabel *label;
    QLabel *label_2;
    QPushButton *SendB_2;
    QLineEdit *PasswordTB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SendB = new QPushButton(centralwidget);
        SendB->setObjectName(QString::fromUtf8("SendB"));
        SendB->setGeometry(QRect(210, 200, 80, 31));
        LoginTB = new QPlainTextEdit(centralwidget);
        LoginTB->setObjectName(QString::fromUtf8("LoginTB"));
        LoginTB->setGeometry(QRect(210, 60, 331, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 70, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 140, 49, 16));
        SendB_2 = new QPushButton(centralwidget);
        SendB_2->setObjectName(QString::fromUtf8("SendB_2"));
        SendB_2->setGeometry(QRect(460, 200, 80, 31));
        PasswordTB = new QLineEdit(centralwidget);
        PasswordTB->setObjectName(QString::fromUtf8("PasswordTB"));
        PasswordTB->setGeometry(QRect(210, 130, 331, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SendB->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        LoginTB->setPlainText(QCoreApplication::translate("MainWindow", "user1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        SendB_2->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        PasswordTB->setText(QCoreApplication::translate("MainWindow", "user", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
