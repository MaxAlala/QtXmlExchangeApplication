#ifndef TCP_CLIENT_THREAD_H
#define TCP_CLIENT_THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class TCP_client_thread : public QThread
{
    Q_OBJECT
public:
    explicit TCP_client_thread(QTcpSocket* tcp_socket, const int socketDescriptor, QObject* parent = nullptr);
    void run();
    QString getSocketIpAddress() const;
    QString getSocketPort() const;
    void setSocketIpAddress(const QString &value);
    void setSocketPort(const QString &value);
signals:
    void sendMessageToMainWindow(QString);
public slots:
    void readyRead();
    void disconnected();
    void getReceivedDataForAllClient(QString);
private:
    QTcpSocket* socket;
    int socketDescriptor;
    QString socketIpAddress;
    QString socketPort;

};

#endif // TCP_CLIENT_THREAD_H
