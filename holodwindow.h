#ifndef HOLODWINDOW_H
#define HOLODWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QScrollArea>
#include <QStringList>
#include <QTimer>
#include "userchatbutton.h"
#include <QMap>

namespace Ui {
class HolodWindow;
}

class HolodWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HolodWindow(QString username, QWidget *parent = nullptr);
    ~HolodWindow();
    void sendCommand(const QString& command, const QString& message);

private slots:
    void onReadyRead(const QByteArray &receivedData);
    void on_SearchChatTB_textChanged();
        void onConnected();
        void checkAndUpdateChats();

        void on_pushButton_clicked();

    private:
    Ui::HolodWindow *ui;
    SocketManager *socketManager;
    QString m_username;
    QTimer *m_timer = new QTimer(this);
    void setupConnection();
    void requestUserChats();
    void updateChatLayout(QWidget *widget);
    UserChatButton* createChatButton(const QString &chatName, const QString &lastMessage, const QDateTime &messageTime);
    void updateSearch(const QString &newText);



};

#endif // HOLODWINDOW_H
