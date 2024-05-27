#include "mainwindow.h"
#include "holodwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    QFile file(":/style.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        a.setStyleSheet(stream.readAll());
    }
    MainWindow w;
    w.show();
    return a.exec();
}
