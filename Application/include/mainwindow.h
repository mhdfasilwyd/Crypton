#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../CoinGecko/include/gecko.h"

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
    Ui::MainWindow *ui;
    enum{
        CRYPTON_HOME,
        CRYPTON_DISPLAY,
        CRYPTON_ABOUT
    };
    gecko::api coinGecko;
    QString getCryptoPrice(std::string crypto, std::string currency);
};
#endif // MAINWINDOW_H
