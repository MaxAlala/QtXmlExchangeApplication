#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent ) : QTcpServer(parent)
{
}

void TCPServer::stopServer()
{
    close();
    qDebug() << "server was stoped.";
    emit(stopThreads());

}

void TCPServer::startServer()
{
    qDebug() << "start a server on port " << server_port;
    if(!this->listen(QHostAddress::Any, server_port))
    {
        qDebug() << "Could not start server";

    }
    else
    {
        qDebug() << "Listening incoming connections...";

    }
//    qDebug() << "Server IP address is:" << this->serverAddress() << ". Server port is: " << this->serverPort();

}

void TCPServer::incomingConnection(int socketDescriptor)
{
    QTcpSocket * tcp_socket = new QTcpSocket();
    tcp_socket->setSocketDescriptor(socketDescriptor);
    qDebug() << tcp_socket->peerAddress().toString() << " "
             << tcp_socket->peerPort()
             <<" from incommingConnection";
    qDebug() << QThread::currentThreadId() << "incommingConnection";
    qDebug() << socketDescriptor << " is trying to connect...";
    TCP_client_thread * thread = new TCP_client_thread(tcp_socket, socketDescriptor, this);

    emit(sendMessageToMainWindow("clientip&port:" + tcp_socket->peerAddress().toString() + " " + QString::number(tcp_socket->peerPort())));
    thread->setSocketIpAddress(tcp_socket->peerAddress().toString());
    thread->setSocketPort(QString::number(tcp_socket->peerPort()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(this, SIGNAL(stopThreads()), thread, SLOT(disconnected()));
    connect(this, SIGNAL(sendReceivedDataToAllClient(QString)), thread, SLOT(getReceivedDataForAllClient(QString)));
    connect(thread, SIGNAL(sendMessageToMainWindow(QString)), this, SLOT(getMessageForMainWindow(QString)));
    thread->start();

}

int TCPServer::getServer_port() const
{
    return server_port;

}

void TCPServer::setServer_port(int value)
{
    server_port = value;

}

void TCPServer::getMessageForMainWindow(QString message)
{
    emit(sendMessageToMainWindow(message));

}

void TCPServer::getReceivedDataForAllClient(QString data)
{
    savedMessageForClient = data;
    emit(sendReceivedDataToAllClient(data));

}
