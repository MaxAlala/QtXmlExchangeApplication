#include "qTcpSocketWrapper.h"

void QTcpSocketWrapper::getMessageForBottom(MessageType messageType, QString message)
{
    // queued connection? Should be
    if(messageType == MessageType::SEND_XML_PARAMETERS_TO_CLIENTS)
        this->write(message.toLatin1());
    else if(messageType == MessageType::DELETE_SOCKET_WRAPPER_THREAD)
        deleteLater();
}

void QTcpSocketWrapper::readyRead()
{

    QByteArray data = readAll();
    QString data_str(data);
    if(data_str == TextMessageType::dataRequestFromClient) emit(sendMessageToTop(MessageType::DATA_REQUEST_FROM_CLIENT));
}
