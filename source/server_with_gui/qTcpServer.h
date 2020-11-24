#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include "qTcpSocketWrapperThread.h"

class MainWindow;
class QTcpServerWrapper : public QTcpServer
{
    Q_OBJECT
public:
    explicit QTcpServerWrapper(QObject *parent = nullptr);

    /*!
    * \brief server starts listening to new connections
    */
    void startServer();

    /*!
    * \brief emits a signal to delete all sockets and their threads
    */
    void stopServer();

    int getServer_port() const;
    void setServer_port(int value);

signals:

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do? This method sends messages to underlying objects.
    */
    void sendMessageToBottom(MessageType messageType, QString message = "");

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do? This method sends messages to higher objects.
    */
    void sendMessageToTop(MessageType messageType, QString message = "");
private slots:

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do?  This method receives messages from underlying objects
    * to use them or to send to higher objects depending on the MessageType.
    */
    void getMessageForTop(MessageType messageType, QString message = "");

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do?  This method receives messages from higher objects
    * to use them or to send to undelying objects depending on the MessageType.
    */
    void getMessageForBottom(MessageType messageType, QString message = "");
protected:

    /*!
    * \brief catches new socket connections
    */
    void incomingConnection(qintptr socketDescriptor);

private:
    QString server_address;
    int server_port = 3333;
};

#endif // TCPSERVER_H
