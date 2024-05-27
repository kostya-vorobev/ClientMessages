/********************************************************************************
** Form generated from reading UI file 'qdialogusers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOGUSERS_H
#define UI_QDIALOGUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDialogUsers
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *SendMessageTB;
    QPushButton *pushButton;
    QScrollArea *OutputArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QDialogUsers)
    {
        if (QDialogUsers->objectName().isEmpty())
            QDialogUsers->setObjectName(QString::fromUtf8("QDialogUsers"));
        QDialogUsers->resize(800, 600);
        centralwidget = new QWidget(QDialogUsers);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SendMessageTB = new QPlainTextEdit(centralwidget);
        SendMessageTB->setObjectName(QString::fromUtf8("SendMessageTB"));
        SendMessageTB->setGeometry(QRect(10, 480, 621, 70));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(649, 480, 121, 24));
        OutputArea = new QScrollArea(centralwidget);
        OutputArea->setObjectName(QString::fromUtf8("OutputArea"));
        OutputArea->setGeometry(QRect(10, 40, 771, 431));
        OutputArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 769, 429));
        OutputArea->setWidget(scrollAreaWidgetContents);
        QDialogUsers->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QDialogUsers);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        QDialogUsers->setMenuBar(menubar);
        statusbar = new QStatusBar(QDialogUsers);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QDialogUsers->setStatusBar(statusbar);

        retranslateUi(QDialogUsers);

        QMetaObject::connectSlotsByName(QDialogUsers);
    } // setupUi

    void retranslateUi(QMainWindow *QDialogUsers)
    {
        QDialogUsers->setWindowTitle(QCoreApplication::translate("QDialogUsers", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("QDialogUsers", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QDialogUsers: public Ui_QDialogUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOGUSERS_H
