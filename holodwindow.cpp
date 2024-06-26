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

// Объект socketManager отправляет команду и соответствующее сообщение серверу.
void HolodWindow::sendCommand(const QString &command, const QString &message) {
    socketManager->writeData(command, message);
}

// Эта функция выполняется при получении данных от сервера
void HolodWindow::onReadyRead(const QByteArray &receivedData) {
    // Выводим имя пользователя в консоль
    qDebug() << m_username;
    // Создаем новый виджет и макет для чатов
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);
    // Устанавливаем белый цвет фона виджета
    scrollWidget->setStyleSheet("background-color: #fff;");
    // Устанавливаем выравнивание элементов макета по верхнему краю
    scrollLayout->setAlignment(Qt::AlignTop);

    // Разбиваем полученные данные на составные части
    QStringList responseParts = QString(receivedData).split("\n");

    // Сохраняем все чаты в QMap
    QMap<QDateTime, QPair<QString, QString>> maps;

    // Итерируемся по каждому чату в полученных данных
    for (const QString &chatInfo : responseParts) {
        // Пропускаем пустые имена
        if (chatInfo.trimmed().isEmpty())
            continue;

        // Разбиваем информацию чата на имя пользователя и сообщение
        QStringList chatParts = chatInfo.split("|");
        QString chatName = chatParts[0].trimmed();
        QString lastMessage = chatParts.size() > 2 ? chatParts[1] : "Нет сообщений";
        QString messageTime = chatParts.size() > 2 ? chatParts[2] : "";
        if (chatName == "") chatName = m_username;

        // Добавляем информацию об этом чате в QMap
        maps[QDateTime::fromString(messageTime, "yyyy/MM/dd HH:mm:ss")] = QPair<QString, QString>(chatName, lastMessage);
    }

    // Преобразуем QMap в map из стандартной библиотеки C++
    std::map<QDateTime, QPair<QString, QString>> stdMap = maps.toStdMap();

    // Итерируемся через map и создаем кнопку для каждого чата
    for(auto i = stdMap.rbegin(); i != stdMap.rend(); i++) {
        UserChatButton *chatButton = createChatButton(i->second.first, i->second.second, i->first);
        // Добавляем чат-кнопку в макет
        scrollLayout->addWidget(chatButton);
    }

    // Обновляем макет чата с новыми виджетами-кнопками
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

