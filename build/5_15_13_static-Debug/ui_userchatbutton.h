/********************************************************************************
** Form generated from reading UI file 'userchatbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCHATBUTTON_H
#define UI_USERCHATBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserChatButton
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *UsernameL;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TimeL;
    QVBoxLayout *verticalLayout_2;
    QLabel *LastMessageL;

    void setupUi(QWidget *UserChatButton)
    {
        if (UserChatButton->objectName().isEmpty())
            UserChatButton->setObjectName(QString::fromUtf8("UserChatButton"));
        UserChatButton->resize(340, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserChatButton->sizePolicy().hasHeightForWidth());
        UserChatButton->setSizePolicy(sizePolicy);
        UserChatButton->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(UserChatButton);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 321, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        UsernameL = new QLabel(verticalLayoutWidget);
        UsernameL->setObjectName(QString::fromUtf8("UsernameL"));

        horizontalLayout_3->addWidget(UsernameL);


        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        TimeL = new QLabel(verticalLayoutWidget);
        TimeL->setObjectName(QString::fromUtf8("TimeL"));
        TimeL->setTextFormat(Qt::TextFormat::AutoText);
        TimeL->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        horizontalLayout_2->addWidget(TimeL);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        LastMessageL = new QLabel(verticalLayoutWidget);
        LastMessageL->setObjectName(QString::fromUtf8("LastMessageL"));

        verticalLayout_2->addWidget(LastMessageL);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(UserChatButton);

        QMetaObject::connectSlotsByName(UserChatButton);
    } // setupUi

    void retranslateUi(QWidget *UserChatButton)
    {
        UserChatButton->setWindowTitle(QCoreApplication::translate("UserChatButton", "Form", nullptr));
        UsernameL->setText(QCoreApplication::translate("UserChatButton", "TextLabel", nullptr));
        TimeL->setText(QCoreApplication::translate("UserChatButton", "TextLabel", nullptr));
        LastMessageL->setText(QCoreApplication::translate("UserChatButton", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserChatButton: public Ui_UserChatButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCHATBUTTON_H
