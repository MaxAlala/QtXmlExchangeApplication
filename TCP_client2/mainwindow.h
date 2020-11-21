#ifndef qwe
#define qwe

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QThread>
#include "socketwrapper.h"
//#include "antoshka.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow * getMainWinPtr();
    Ui::MainWindow* ui;
public slots:
    //    void readyRead();
    //    void disconnected();
    void getReceivedData(QByteArray);
    void getError(QString error);
private slots:
    void on_changeServerIpButton_clicked();
    void on_changeServerPortButton_clicked();
    void on_sendRequestToServerButton_clicked();
    void getSuccessfullyConnectedToServerMessage();
    void getCantConnectToServerMessage();
    void getTextForMainWindow(QString);
    void on_stopConnectionButton_clicked();
    void on_startConnectionButton_clicked();

signals:
    void sendRequestToServer();
private:
    void setImage(QByteArray byteArray);
    void setImage(QString imageText);

    static MainWindow* pMainWindow;
    QString server_ip_address = "127.0.0.1";
    int server_port = 3333;
    SocketWrapper* g_clientSocket = nullptr;
    QString clientIpAddress = "";
    QString clientPort = "";
    //    MainWindow * mw;
    //    SocketWrapper* clientSocket;
};

#endif // MAINWINDOW_H
