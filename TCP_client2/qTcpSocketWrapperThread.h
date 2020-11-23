#ifndef qwer
#define qwer
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QThread>
#include "clientMessageTypes.h"
#include "qTcpSocketWrapper.h"

class QTcpSocketWrapperThread: public QThread
{
    Q_OBJECT
public:

    /*!
    * \brief this constructor inits server ip and server port to move them further to a socket to create a connection with a host
    */
    explicit QTcpSocketWrapperThread(QObject *parent = nullptr, QString serverIpAddress = "127.0.0.1", int serverPort = 3333);

    /*!
    * \brief starts a socket in a new thread
    */
    void run() override;
    QString getServer_ip_address() const;
    void setServer_ip_address(const QString &value);
    int getServer_port() const;
    void setServer_port(int value);

signals:
    /*!
    * \brief this signal was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? Sends a message to higher objects
    */
    void sendMessageToTop(MessageType messageType, QString message = "");

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? This method sends messages to underlying objects.
    */
    void sendMessageToBottom(MessageType messageType, QString message = "");

public slots:
    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? This method receives messages from higher objects
    * to use them or send to undelying depending on the MessageType.
    */
    void getMessageForBottom(MessageType messageType, QString message = "");

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? This method receives messages from underlying objects
    * to use them or send to higher depending on the MessageType.
    */
    void getMessageForTop(MessageType messageType, QString message = "");
    void deleteThreadObject();
private:
    /*!
    * \brief server ip to move it further to a socket to create a connection with a host
    */
    QString server_ip_address;

    /*!
    * \brief server port to move it further to a socket to create a connection with a host
    */
    int server_port;
    QTcpSocketWrapper* socket;
};

#endif // SOCKETWRAPPER_H
