#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtextcodec.h>

void MainWindow::gethttp(QNetworkReply* reply)
{
    QString data = reply->readAll();
    qDebug() << data;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString str2qstr(const string str)
{
    return QString::fromLocal8Bit(str.data());
}


void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit_Name->text();
    QString line = ui->lineEdit_Line->text();
    QString phone = ui->lineEdit_Phone->text();
    QString amount = ui->lineEdit_Amount->text();
    QString location = ui->comboBox_location->currentText();

    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &MainWindow::gethttp);
    const QUrl url = QUrl(myUrl);
    QNetworkRequest request(url);
    //man->get(request);

    QJsonObject object;
    QJsonArray array;

    QJsonObject jsonOBJ
    {
        {"name",name},
        {"line",line},
        {"phone",phone},
        {"amount",amount},
        {"location",location},
        {"contact_time","任何時間皆可"},
    };

    QJsonDocument document(jsonOBJ);

    request.setRawHeader("Content-type", "application/json");
    request.setRawHeader("X-Requested-With", "XMLHttpRequest");
    request.setRawHeader("Accept-Encoding", "gzip, deflate, br");
    request.setRawHeader("Connection", "keep-alive");
    request.setRawHeader("Accept", "*/*");
    request.setRawHeader("APP_KEY", "123");

    man->post(request, document.toJson());
}
