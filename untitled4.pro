QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    holodwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qdialogusers.cpp \
    sendmessageuser.cpp \
    socketmanager.cpp \
    userchatbutton.cpp

HEADERS += \
    holodwindow.h \
    mainwindow.h \
    qdialogusers.h \
    sendmessageuser.h \
    socketmanager.h \
    userchatbutton.h

FORMS += \
    holodwindow.ui \
    mainwindow.ui \
    qdialogusers.ui \
    sendmessageuser.ui \
    userchatbutton.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
