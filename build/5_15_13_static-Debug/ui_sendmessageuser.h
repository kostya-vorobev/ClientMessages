/********************************************************************************
** Form generated from reading UI file 'sendmessageuser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMESSAGEUSER_H
#define UI_SENDMESSAGEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendMessageUser
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *TextL;
    QLabel *TimeL;

    void setupUi(QWidget *SendMessageUser)
    {
        if (SendMessageUser->objectName().isEmpty())
            SendMessageUser->setObjectName(QString::fromUtf8("SendMessageUser"));
        SendMessageUser->resize(400, 60);
        SendMessageUser->setMinimumSize(QSize(400, 60));
        verticalLayoutWidget = new QWidget(SendMessageUser);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 381, 41));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TextL = new QLabel(verticalLayoutWidget);
        TextL->setObjectName(QString::fromUtf8("TextL"));

        verticalLayout->addWidget(TextL);

        TimeL = new QLabel(verticalLayoutWidget);
        TimeL->setObjectName(QString::fromUtf8("TimeL"));
        TimeL->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(TimeL);


        retranslateUi(SendMessageUser);

        QMetaObject::connectSlotsByName(SendMessageUser);
    } // setupUi

    void retranslateUi(QWidget *SendMessageUser)
    {
        SendMessageUser->setWindowTitle(QCoreApplication::translate("SendMessageUser", "Form", nullptr));
        TextL->setText(QCoreApplication::translate("SendMessageUser", "TextLabel", nullptr));
        TimeL->setText(QCoreApplication::translate("SendMessageUser", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendMessageUser: public Ui_SendMessageUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMESSAGEUSER_H
