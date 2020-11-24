#include "qTcpSocketWrapperThread.h"

QTcpSocketWrapperThread::QTcpSocketWrapperThread(QTcpSocketWrapper * tcp_socket, const int socketDescriptor, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
    // moveToThread must be before calling connect!
    tcp_socket->moveToThread(this);
    socket = tcp_socket;

}

void QTcpSocketWrapperThread::run()
{
    // socket reads and sends data to the main thread
    connect(socket, SIGNAL(readyRead()), socket, SLOT(readyRead()));

    //sends messages to a socket
    connect(this, SIGNAL(sendMessageToBottom(MessageType, QString)), socket, SLOT(getMessageForBottom(MessageType, QString)));

    //socket sends messages to the top layers
    connect(socket, SIGNAL(sendMessageToTop(MessageType, QString)), this, SLOT(getMessageForTop(MessageType, QString)));

    connect(socket, SIGNAL(disconnected()), this, SLOT(quit()));

    // when run is finished
    connect(this, SIGNAL(finished()), this, SLOT(deleteThreadObject()));

    exec();

}

void QTcpSocketWrapperThread::deleteThreadObject()
{
    emit(sendMessageToTop(MessageType::DELETE_IP_AND_PORT, getSocketIpAddress() + " " + getSocketPort()));
    deleteLater();
}

void QTcpSocketWrapperThread::getMessageForTop(MessageType messageType, QString message)
{
    emit(sendMessageToTop(messageType, message));
}

void QTcpSocketWrapperThread::getMessageForBottom(MessageType messageType, QString message)
{
    if(messageType == MessageType::SEND_XML_PARAMETERS_TO_CLIENTS)
        emit(sendMessageToBottom(messageType, message));

    // a case where the stop server button was pressed.
    //That will ask a socket to delete itself.
    //If socket will be deleted then thread will be deleted also
    else if(messageType == MessageType::DELETE_SOCKET_WRAPPER_THREAD)
        emit(sendMessageToBottom(MessageType::DELETE_SOCKET_WRAPPER_THREAD));

}

QString QTcpSocketWrapperThread::getSocketPort() const
{
    return socketPort;

}

void QTcpSocketWrapperThread::setSocketPort(const QString &value)
{
    socketPort = value;

}

QString QTcpSocketWrapperThread::getSocketIpAddress() const
{
    return socketIpAddress;

}

void QTcpSocketWrapperThread::setSocketIpAddress(const QString &value)
{
    socketIpAddress = value;

}
