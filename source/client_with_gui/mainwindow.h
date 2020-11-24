#ifndef qwe
#define qwe

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QThread>
#include "qTcpSocketWrapperThread.h"
#include "clientMessageTypes.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*!
    * \brief changes a server ip address
    */
    void on_changeServerIpButton_clicked();

    /*!
    * \brief changes a server port
    */
    void on_changeServerPortButton_clicked();

    /*!
    * \brief sends a command to a socket to send a request to a server to get XML parameters
    */
    void on_sendRequestToServerButton_clicked();

    /*!
    * \brief start a connection by sending a command to a socket. Also it create a socket thread
    */
    void on_startConnectionButton_clicked();

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? This method receives messages from underlying objects
    * to use them or send to higher depending on the MessageType.
    */
    void getMessageForTop(MessageType messageType, QString message = "");

signals:

    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * At the top there is MainWindow object, then below there is QTcpSocketWrapperThread object,
    * and at the end there is  QTcpSocketWrapper object.
    *  What does it do? This method sends messages to underlying objects.
    */
    void sendMessageToBottom(MessageType messageType, QString message = "");

private:

    /*!
    * \brief this method parses messages from server containing XML parameters.
    * Parameters: from, color, text, image.
    */
    void parseReceivedMessageFromServer(QString&);

    /*!
    * \brief changes the time in the time label
    */
    void setCurrentTime();

    /*!
    * \brief sets a resized image to an image label, resized image should fit 150 by 150 pixels.
    */
    void setImage(QByteArray& byteArray);

    /*!
    * \brief sets a resized image to an image label, resized image should fit 150 by 150 pixels.
    */
    void setImage(QString& imageText);

    /*!
    * \brief through this object all widgets can be reached
    */
    Ui::MainWindow* ui;

    /*!
    * \brief ip address which can be change using specific widgets(qPushButton & QLineEdit)
    */
    QString server_ip_address = "127.0.0.1";

    /*!
    * \brief port which can be change using specific widgets(qPushButton & QLineEdit)
    */
    int server_port = 3333;

    /*!
    * \brief client ip address received from qTcpSocketWrapperThread object through SIGNAL
    * sendMessageToTop(MessageTypes messageType, QString message = "") and SLOT getMessageForTop(MessageTypes messageType, QString message = "")
    * MessageTypes is CLIENT_IP_ADDRESS.
    */
    QString clientIpAddress = "";

    /*!
    * \brief client port received from qTcpSocketWrapperThread object through SIGNAL
    * sendMessageToTop(MessageTypes messageType, QString message = "") and SLOT getMessageForTop(MessageTypes messageType, QString message = "")
    * MessageTypes is CLIENT_IP_ADDRESS.
    */
    QString clientPort = "";

};

#endif // MAINWINDOW_H
