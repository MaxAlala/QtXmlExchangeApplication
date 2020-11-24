#include "qTcpSocketWrapperThread.h"
#include <QMessageBox>
#include <QNetworkInterface>



QTcpSocketWrapperThread::QTcpSocketWrapperThread(QObject *parent, QString serverIpAddress, int serverPort) :
    QThread(parent),
    server_ip_address(serverIpAddress),
    server_port(serverPort)
{

}

void QTcpSocketWrapperThread::run()
{
    // create and forget
    socket = new QTcpSocketWrapper();

    // sets server ip and port to be able to connect to host
    socket->setServer_ip_address(server_ip_address);
    socket->setServer_port(server_port);

    connect(socket,SIGNAL(readyRead()),socket,SLOT(readyRead()));

    connect(this, SIGNAL(sendMessageToBottom(MessageType, QString)), socket, SLOT(getMessageForBottom(MessageType, QString)));

    connect(socket, SIGNAL(sendMessageToTop(MessageType, QString)), this, SLOT(getMessageForTop(MessageType, QString)));

    connect(socket, SIGNAL(disconnected()), socket, SLOT(disconnected()));

    //    connect(socket, SIGNAL(disconnected()), this, SLOT(quit()));
    // if a socket is disconnected, an event loop of its thread will be signed up for deletion
    connect(socket, SIGNAL(destroyThread()), this, SLOT(deleteThreadObject()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deleteThreadObject()));

    // when run() is finished, a thread object will be signed up for deletion in the main event loop
    //    connect(this, SIGNAL(finished()), this, SLOT(deleteThreadObject()));

    // connects a socket to a server
    emit(sendMessageToBottom(MessageType::TRY_TO_CONNECT_TO_SERVER));
    // if a socket connected to a server send port and ip address
    if(!(socket->localPort() == 0))
    {
        emit(sendMessageToTop(MessageType::CLIENT_PORT, QString::number(socket->localPort())));

        // searches a current ip address of ipv4 protocol
        const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
        for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
            if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
                emit(sendMessageToTop(MessageType::CLIENT_IP_ADDRESS, address.toString()));

        }
    }
    // starts an event loop
    exec();

}

int QTcpSocketWrapperThread::getServer_port() const
{
    return server_port;

}

void QTcpSocketWrapperThread::setServer_port(int value)
{
    server_port = value;

}

void QTcpSocketWrapperThread::getMessageForBottom(MessageType messageType, QString message)
{
    emit(sendMessageToBottom(messageType,message));
    qDebug() << "thread object got a message";
}

QString QTcpSocketWrapperThread::getServer_ip_address() const
{
    return server_ip_address;

}

void QTcpSocketWrapperThread::setServer_ip_address(const QString &value)
{
    server_ip_address = value;

}

void QTcpSocketWrapperThread::getMessageForTop(MessageType messageType, QString message)
{
    emit(sendMessageToTop(messageType, message));

}

void QTcpSocketWrapperThread::deleteThreadObject()
{
    qDebug() << "disconnected thread object.";
    quit();
    emit(sendMessageToTop(MessageType::DELETE_OLD_IP_AND_PORT));
    deleteLater();
}
