#include "qTcpSocketWrapper.h"

void QTcpSocketWrapper::getMessageForBottom(MessageType messageType, QString message)
{
    if(messageType == MessageType::REQUEST_XML_PARAMETERS_FROM_SERVER)
        write(TextMessageType::dataRequestFromClientText.toLatin1());
    else if(messageType == MessageType::TRY_TO_CONNECT_TO_SERVER)
    {
//        QAbstractSocket::SocketState state = this->state();
//        qDebug()<<state;
        connectToHost(server_ip_address, server_port);
//         state = this->state();
//        qDebug()<<state;
        if(!waitForConnected(500))
        {
            this->close();
            this->abort();
            emit(sendMessageToTop(MessageType::CANT_CONNECT_TO_SERVER));
//            qDebug()<<state;
            deleteLater();
            emit(disconnected());
        emit(destroyThread());
        }else
        {
            emit(sendMessageToTop(MessageType::SUCCESSFULLY_CONNECTED_TO_SERVER));
        }

    }
    else if(messageType == MessageType::DELETE_SOCKET_WRAPPER_THREAD)
    {
        deleteLater();
        emit(disconnected());
    }

}

void QTcpSocketWrapper::readyRead()
{

    if (waitForConnected(500))
    {
        waitForReadyRead(500);
        QString receivedData(readAll());

        // it checks if a received data is not empty to avoid some noise
        if(!(receivedData == "")) emit(sendMessageToTop(MessageType::MESSAGE_FROM_SERVER, receivedData));

    }
}

int QTcpSocketWrapper::getServer_port() const
{
    return server_port;
}

void QTcpSocketWrapper::setServer_port(int value)
{
    server_port = value;
}

void QTcpSocketWrapper::disconnected()
{
    qDebug() << "disconnected socket.";
}

QString QTcpSocketWrapper::getServer_ip_address() const
{
    return server_ip_address;
}

void QTcpSocketWrapper::setServer_ip_address(const QString &value)
{
    server_ip_address = value;
}
