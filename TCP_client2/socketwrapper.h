#ifndef qwer
#define qwer
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QThread>
//#include "mainwindow.h"

class SocketWrapper: public QThread
{
    Q_OBJECT
public:
    explicit SocketWrapper(QObject *parent = nullptr, QString serverIpAddress = "127.0.0.1", int serverPort = 3333);
    void connectToServer();
//    void changeServerIpAddress(QString serverIpAddress);
//    void changeServerPort(int serverPort);
//    void disconnectFromHost();
    void run();
    ~SocketWrapper();
    void stopSocket();
    QString getServer_ip_address() const;
    void setServer_ip_address(const QString &value);

    int getServer_port() const;
    void setServer_port(int value);

signals:
    void error(QTcpSocket::SocketError socketError);

    /*!
    * \brief it sends a received data to GUI
    */
    void sendReceivedData(QByteArray receivedData);

    /*!
    * \brief it sends a error report to mainwindow to display
    */
    void sendError(QString);
    void successfullyConnectedToServer();
    void cantConnectToServer();
    void sendTextToMainWindow(QString);
public slots:
    void getRequestToServer();
    void readyRead();
    void disconnected();

private:
    QTcpSocket* socket = nullptr;
    QByteArray Data;
    QString server_ip_address = "127.0.0.1";
    int server_port = 3333;

    // pointer to Main window to get access to its UI
//    MainWindow* mw;

};

#endif // SOCKETWRAPPER_H
