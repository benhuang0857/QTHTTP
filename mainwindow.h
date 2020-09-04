#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma execution_character_set("utf-8")
#endif


#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QTextBrowser>
#include <QByteArray>
#include <string>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextCodec>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString myUrl = "http://127.0.0.1:8000/api/application/submit";
    Ui::MainWindow *ui;
private slots:
    void gethttp(QNetworkReply*);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
