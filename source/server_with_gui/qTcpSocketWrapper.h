#ifndef QTCPSOCKETWRAPPER_H
#define QTCPSOCKETWRAPPER_H

#include <QObject>
#include <QTcpSocket>
#include "serverMessageType.h"
#include <QThread>
class QTcpSocketWrapper : public QTcpSocket
{
    Q_OBJECT
public:

signals:

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do? This method sends messages to higher objects.
    */
    void sendMessageToTop(MessageType messageType, QString message = "");

public slots:
    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do?  This method receives messages from higher objects
    * to use them or to send to undelying objects depending on the MessageType.
    */
    void getMessageForBottom(MessageType messageType, QString message = "");

    /*!
    * \brief receives xml parameters from a server
    */
    void readyRead();
};

#endif // QTCPSOCKETWRAPPER_H
