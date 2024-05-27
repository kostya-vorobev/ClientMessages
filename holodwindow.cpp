#include "holodwindow.h"
#include "ui_holodwindow.h"
#include <QThread>
HolodWindow::HolodWindow(QString username, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::HolodWindow)
    , m_username(username)
    , socketManager(new SocketManager(this))  // Инициализируем SocketManager в конструкторе
{
    ui->setupUi(this);

    // Устанавливаем связи между сигналами и слотами
    connect(socketManager, SIGNAL(dataReceived(QByteArray)), this, SLOT(onReadyRead(QByteArray)));
    connect(socketManager, SIGNAL(connected()), this, SLOT(onConnected()));

    // Пытаемся подключиться к серверу при инициализации
    socketManager->connectToServer();

    // Устанавливаем таймер, который будет вызывать requestUserChats каждые 10 секунд
    m_timer->setInterval(10000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(checkAndUpdateChats()));
    m_timer->start();
}

void HolodWindow::checkAndUpdateChats(){
    // Если поле поиска не пустое, не обновляем список чатов, иначе обновляем
    if(ui->SearchChatTB->toPlainText().isEmpty()){
        requestUserChats();
    }
}



HolodWindow::~HolodWindow()
{
    delete socketManager;
    delete ui;
}

void HolodWindow::onConnected()
{
    // Когда подключились к серверу, делаем запрос на чаты
    requestUserChats();
}

// Send command with message to the server
void HolodWindow::sendCommand(const QString &command, const QString &message) {
    socketManager->writeData(command, message);
}

void HolodWindow::onReadyRead(const QByteArray &receivedData) {
    qDebug() << m_username;
    // Prepare the widget and layout for the chats
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);
    scrollWidget->setStyleSheet("background-color: #fff;");
    scrollLayout->setAlignment(Qt::AlignTop);

    // Parse the response data
    QStringList responseParts = QString(receivedData).split("\n");

    QMap<QDateTime, QPair<QString, QString>> maps;

    for (const QString &chatInfo : responseParts) {
        // Skip empty names
        if (chatInfo.trimmed().isEmpty())
            continue;

        // Split the info into username and message
        QStringList chatParts = chatInfo.split("|");
        QString chatName = chatParts[0].trimmed();
        QString lastMessage = chatParts.size() > 2 ? chatParts[1] : "Нет сообщений";
        QString messageTime = chatParts.size() > 2 ? chatParts[2] : "";
        if (chatName == "") chatName = m_username;

        // Add to map
        maps[QDateTime::fromString(messageTime, "yyyy/MM/dd HH:mm:ss")] = QPair<QString, QString>(chatName, lastMessage);
    }

    // Create the button for the chat
    std::map<QDateTime, QPair<QString, QString>> stdMap = maps.toStdMap();

    // Create the button for the chat in reverse order
    for(auto i = stdMap.rbegin(); i != stdMap.rend(); i++) {
        UserChatButton *chatButton = createChatButton(i->second.first, i->second.second, i->first);
        scrollLayout->addWidget(chatButton);
    }

    // Update the chat layout with the new widgets
    updateChatLayout(scrollWidget);
}

UserChatButton* HolodWindow::createChatButton(const QString &chatName, const QString &lastMessage, const QDateTime &messageTime) {
    UserChatButton *chatButton = new UserChatButton(chatName, m_username);
    chatButton->setStyleSheet(
        "QWidget {"
        "background-color: #f4f4f4;"
        "border: 1px solid #ccc;"
        "border-radius: 5px;"
        "color: #333;"
        "}"
        "QWidget:hover {"
        "background-color: #dcdcdc;"
        "}"

        );
    chatButton->setLastMessage(lastMessage);
    chatButton->setLastMessageTime(messageTime);
    connect(chatButton, &UserChatButton::clicked, chatButton, &UserChatButton::onClicked);
    chatButton->setFixedHeight(100); // задаем фиксированную высоту для кнопки

    return chatButton;
}

void HolodWindow::updateSearch(const QString &newText) {
    // Если поле поиска не пустое, отправляем запрос на поиск на сервер.
    if(!newText.isEmpty()){
        sendCommand("search", newText);
    } else {
        // Если поле поиска снова стало пустым, мы обновляем список чатов
        requestUserChats();
    }
}

void HolodWindow::updateChatLayout(QWidget *widget) {
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(widget);

    // Clear current content of ChatLayout
    QLayoutItem* item;
    while ( (item = ui->ChatLayout->takeAt(0)) ) {
        delete item->widget();
        delete item;
    }

    ui->ChatLayout->addWidget(scrollArea);
}

void HolodWindow::requestUserChats() {
    sendCommand("getChats", m_username);
}


void HolodWindow::on_SearchChatTB_textChanged()
{
    updateSearch(ui->SearchChatTB->toPlainText());
}


void HolodWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

