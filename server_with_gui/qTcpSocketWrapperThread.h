#ifndef TCP_CLIENT_THREAD_H
#define TCP_CLIENT_THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "serverMessageType.h"
#include <qTcpSocketWrapper.h>
class QTcpSocketWrapperThread : public QThread
{
    Q_OBJECT
public:


    /*!
    * \brief receives created with descriptor socket, this socket moves to its thread
    */
    explicit QTcpSocketWrapperThread(QTcpSocketWrapper* tcp_socket, const int socketDescriptor, QObject* parent = nullptr);
    void run();
    QString getSocketIpAddress() const;
    QString getSocketPort() const;
    void setSocketIpAddress(const QString &value);
    void setSocketPort(const QString &value);

signals:
    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do? This method sends messages to higher objects.
    */
    void sendMessageToTop(MessageType messageType, QString message = "");

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do? This method sends messages to underlying objects.
    */
    void sendMessageToBottom(MessageType messageType, QString message = "");
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
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do?  This method receives messages from underlying objects
    * to use them or to send to higher objects depending on the MessageType.
    */
    void getMessageForTop(MessageType messageType, QString message = "");

    /*!
    * \brief calls deleteLater() to delete itself and also sends a command to delete correpsonding ip address and port
    */
    void deleteThreadObject();
private:

    /*!
    * \brief it needs a pointer to a socket to be able to connect signal and slots in the run method.
    */
    QTcpSocketWrapper* socket;
    int socketDescriptor;
    QString socketIpAddress;
    QString socketPort;

};

#endif // TCP_CLIENT_THREAD_H
