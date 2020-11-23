#include "qTcpServer.h"
#include "qTcpSocketWrapper.h"

QTcpServerWrapper::QTcpServerWrapper(QObject *parent ) : QTcpServer(parent)
{
}

void QTcpServerWrapper::stopServer()
{
    close();
    emit(sendMessageToBottom(MessageType::DELETE_SOCKET_WRAPPER_THREAD));

}

void QTcpServerWrapper::startServer()
{
    if(!this->listen(QHostAddress::Any, server_port))
    {
        qDebug() << "Could not start server";

    }
    else
    {
        qDebug() << "Listening incoming connections...";

    }

}

void QTcpServerWrapper::incomingConnection(int socketDescriptor)
{
    QTcpSocketWrapper * tcp_socket = new QTcpSocketWrapper();
    tcp_socket->setSocketDescriptor(socketDescriptor);
    QTcpSocketWrapperThread * thread = new QTcpSocketWrapperThread(tcp_socket, socketDescriptor, this);
    emit(sendMessageToTop(MessageType::SET_CLIENT_IP_AND_PORT, tcp_socket->peerAddress().toString() + " " + QString::number(tcp_socket->peerPort())));
    thread->setSocketIpAddress(tcp_socket->peerAddress().toString());
    thread->setSocketPort(QString::number(tcp_socket->peerPort()));
    connect(this, SIGNAL(sendMessageToBottom(MessageType, QString)), thread, SLOT(getMessageForBottom(MessageType, QString)));
    connect(thread, SIGNAL(sendMessageToTop(MessageType, QString)), this, SLOT(getMessageForTop(MessageType, QString)));
    thread->start();

}

int QTcpServerWrapper::getServer_port() const
{
    return server_port;

}

void QTcpServerWrapper::setServer_port(int value)
{
    server_port = value;

}

void QTcpServerWrapper::getMessageForTop(MessageType messageType, QString message)
{
    emit(sendMessageToTop(messageType, message));

}

void QTcpServerWrapper::getMessageForBottom(MessageType messageType, QString data)
{
    if(messageType == MessageType::SEND_XML_PARAMETERS_TO_CLIENTS)
    {
        emit(sendMessageToBottom(messageType, data));
    }
}
