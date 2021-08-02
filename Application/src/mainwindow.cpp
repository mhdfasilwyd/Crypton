#include "./include/mainwindow.h"
#include "ui_mainwindow.h"
#include "QMovie"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->loading->setValue(50);
    gecko::api coinGecko;

    if (coinGecko.ping())
    {
        ui->holder->setCurrentIndex(CRYPTON_DISPLAY);
        ui->price->setText(QString::fromStdString(coinGecko.simple.getPrice("bitcoin", "usd").text));

        QByteArray crypto = QString::fromStdString(coinGecko.simple.getPrice("bitcoin", "usd").text).toUtf8();
        QJsonDocument list = QJsonDocument::fromJson(crypto);
        QJsonObject obj = list.object();

        QJsonObject bitcoin = obj.value("bitcoin").toObject();
        QJsonValue value = bitcoin.value("usd");
        ui->price->setText(QString::number(value.toInt()));
    }
    else
    {
        ui->holder->setCurrentIndex(CRYPTON_DISPLAY);
        ui->price->setText("CoinGecko Offline!");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
