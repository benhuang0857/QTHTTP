#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec *codec = QTextCodec::codecForName("gbk");
    MainWindow w;
    w.show();
    return a.exec();
}
