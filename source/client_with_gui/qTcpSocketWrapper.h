#ifndef QTCPSOCKETWRAPPER_H
#define QTCPSOCKETWRAPPER_H

#include <QObject>
#include <QTcpSocket>
#include "clientMessageTypes.h"
#include <QThread>
class QTcpSocketWrapper : public QTcpSocket
{
    Q_OBJECT
public:
    QString getServer_ip_address() const;
    void setServer_ip_address(const QString &value);
    int getServer_port() const;
    void setServer_port(int value);

signals:

    void destroyThread();
    /*!
    * \brief this signal was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? Sends a message to higher objects
    */
    void sendMessageToTop(MessageType messageType, QString message = "");

public slots:
    void disconnected();
    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? This method receives messages from higher objects
    * to use them or send to undelying depending on the MessageType.
    */
    void getMessageForBottom(MessageType messageType, QString message = "");
    /*!
    * \brief receives xml parameters from a server
    */
    void readyRead();

private:
    /*!
    * \brief server ip to create a connection with a host
    */
    QString server_ip_address = "127.0.0.1";
    /*!
    * \brief server port to create a connection with a host
    */
    int server_port = 3333;
};

#endif // QTCPSOCKETWRAPPER_H
