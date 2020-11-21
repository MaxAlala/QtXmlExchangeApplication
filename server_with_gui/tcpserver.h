#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include "tcp_client_thread.h"

class MainWindow;
class TCPServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = nullptr);
    void startServer();
    void stopServer();
    int getServer_port() const;
    void setServer_port(int value);

signals:
    void stopThreads();
    void sendClientIP_andPort(QString, int);
    void sendReceivedDataToAllClient(QString);
    void sendMessageToMainWindow(QString);
private slots:
    void getMessageForMainWindow(QString);
    void getReceivedDataForAllClient(QString);
protected:
    void incomingConnection(int socketDescriptor);

private:
    QString server_address;
    int server_port = 3333;
    QString savedMessageForClient;
};

#endif // TCPSERVER_H
