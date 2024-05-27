#include "mainwindow.h"
#include "holodwindow.h"
#include "ui_mainwindow.h"
#include "ui_holodwindow.h"
#include <QTcpSocket>
#include <QTimer>
#include <QByteArray>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_tcpSocket(new QTcpSocket(this))
{
    ui->setupUi(this);
    ui->PasswordTB->setEchoMode(QLineEdit::Password);
    connect(m_tcpSocket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::onDisconnected);
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
    connect(m_tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &MainWindow::onError);
}



MainWindow::~MainWindow()
{
    delete m_tcpSocket; // Удаляем m_tcpSocket
    delete ui;
}

void MainWindow::on_SendB_clicked()
{
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost("localhost", 4242);

    QString login = ui->LoginTB->toPlainText();
    QString password = ui->PasswordTB->text();
    QByteArray data;

    data.append("login\n");
    data.append(login + "\n");
    data.append(password + "\n");

    m_tcpSocket->write(data);
}

void MainWindow::onConnected() {
    qDebug() << "Connected!";
}

void MainWindow::onDisconnected() {
    qDebug() << "Disconnected!";
}

void MainWindow::onReadyRead() {
    QString response = m_tcpSocket->readAll();
    if (response.startsWith("Успешная регистрация") || response.startsWith("Успешная аутентификация")) {
        m_tcpSocket->disconnectFromHost();
        HolodWindow *holodWindow = new HolodWindow(ui->LoginTB->toPlainText());
        holodWindow->show();
        this->hide();

    } else if (response.startsWith("Ошибка регистрации")) {
        QMessageBox::warning(this, "Ошибка", "Не удалось зарегистрироваться");
    } else if (response.startsWith("Ошибка аутентификации")) {
        QMessageBox::warning(this, "Ошибка", "Не удалось аутентифицироваться");
    } else {
        QMessageBox::warning(this, "Ошибка", "Непредвиденная ошибка");
    }
    m_tcpSocket->disconnectFromHost();
}

void MainWindow::onError(QAbstractSocket::SocketError socketError) {
    qDebug() << "Error: " << socketError;
}


void MainWindow::on_SendB_2_clicked()
{
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost("localhost", 4242);

    QString login = ui->LoginTB->toPlainText();
    QString password = ui->PasswordTB->text();
    QByteArray data;

    data.append("register\n"); // Маркер запроса на регистрацию
    data.append(login + "\n");
    data.append(password + "\n");

    m_tcpSocket->write(data);
}

