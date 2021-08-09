#include "./include/mainwindow.h"
#include "ui_mainwindow.h"
#include "QMovie"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

using namespace::std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->loading->setValue(50);

    if (coinGecko.ping() == true)
    {
        ui->holder->setCurrentIndex(CRYPTON_DISPLAY);
        QString temp = getCryptoPrice("bitcoin","usd");
        ui->price->setText(temp);
    }
    else
    {
        ui->holder->setCurrentIndex(CRYPTON_DISPLAY);
        ui->price->setText("CoinGecko Offline!");
    }
}

QString MainWindow::getCryptoPrice(std::string coin, std::string currency)
{
    QString retPrice = "";
    if((coin.empty() == false) && (currency.empty() == false))
    {
        QByteArray bCrypto = QString::fromStdString(coinGecko.simple.getPrice(coin, currency).text).toUtf8();
        QJsonDocument dList = QJsonDocument::fromJson(bCrypto);
        QJsonObject oList = dList.object();
        QJsonObject oCoin = oList.value(QString::fromStdString(coin)).toObject();
        QJsonValue jValue = oCoin.value(QString::fromStdString(currency));
        retPrice = QString::number(jValue.toInt());
    }
    return retPrice;
}

MainWindow::~MainWindow()
{
    delete ui;
}
