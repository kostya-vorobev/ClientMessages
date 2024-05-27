/********************************************************************************
** Form generated from reading UI file 'holodwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOLODWINDOW_H
#define UI_HOLODWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HolodWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ChatLayout;
    QPlainTextEdit *SearchChatTB;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HolodWindow)
    {
        if (HolodWindow->objectName().isEmpty())
            HolodWindow->setObjectName(QString::fromUtf8("HolodWindow"));
        HolodWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HolodWindow->sizePolicy().hasHeightForWidth());
        HolodWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(HolodWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(240, 50, 551, 491));
        ChatLayout = new QVBoxLayout(verticalLayoutWidget);
        ChatLayout->setSpacing(10);
        ChatLayout->setObjectName(QString::fromUtf8("ChatLayout"));
        ChatLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        ChatLayout->setContentsMargins(0, 0, 0, 0);
        SearchChatTB = new QPlainTextEdit(centralwidget);
        SearchChatTB->setObjectName(QString::fromUtf8("SearchChatTB"));
        SearchChatTB->setGeometry(QRect(240, 10, 551, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 510, 191, 24));
        HolodWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HolodWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        HolodWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HolodWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HolodWindow->setStatusBar(statusbar);

        retranslateUi(HolodWindow);

        QMetaObject::connectSlotsByName(HolodWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HolodWindow)
    {
        HolodWindow->setWindowTitle(QCoreApplication::translate("HolodWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("HolodWindow", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HolodWindow: public Ui_HolodWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLODWINDOW_H
