#include "tcp_client_thread.h"

TCP_client_thread::TCP_client_thread(QTcpSocket * tcp_socket, const int socketDescriptor, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
    tcp_socket->moveToThread(this);
    socket = tcp_socket;

}

void TCP_client_thread::run()
{
    qDebug() << QThread::currentThreadId() << "run";
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);
    qDebug() << socketDescriptor << " Client connected.";
    exec();

}

void TCP_client_thread::readyRead()
{
    qDebug() << QThread::currentThreadId() << "readyRead";
    QByteArray data = socket->readAll();
    QString data_str(data);
    if(data_str == "Data, please") emit(sendMessageToMainWindow("Data, please"));
    qDebug() << "Received data from a client" << socketDescriptor << ": " << data;

}

void TCP_client_thread::disconnected()
{
    qDebug() << socketDescriptor << " was disconnected.";
    socket->deleteLater();
    emit(sendMessageToMainWindow("delete ip&port:" + getSocketIpAddress() + " " + getSocketPort()));
    // exit should stop exec(), i.e a thread event loop
    exit(0);

}

void TCP_client_thread::getReceivedDataForAllClient(QString data)
{
    qDebug() << QThread::currentThreadId() << "sending a message to all client.";
    socket->write(data.toAscii());

}

QString TCP_client_thread::getSocketPort() const
{
    return socketPort;

}

void TCP_client_thread::setSocketPort(const QString &value)
{
    socketPort = value;

}

QString TCP_client_thread::getSocketIpAddress() const
{
    return socketIpAddress;

}

void TCP_client_thread::setSocketIpAddress(const QString &value)
{
    socketIpAddress = value;

}
