#ifndef MESSAGETYPES_H
#define MESSAGETYPES_H
#include <QString>
enum class MessageType{
    DELETE_IP_AND_PORT,
    DATA_REQUEST_FROM_CLIENT,
    SET_CLIENT_IP_AND_PORT,
    SEND_XML_PARAMETERS_TO_CLIENTS,
    DELETE_SOCKET_WRAPPER_THREAD,

};


namespace TextMessageType {
    const QString dataRequestFromClient = "Data, please";
}
#endif // MESSAGETYPES_H
