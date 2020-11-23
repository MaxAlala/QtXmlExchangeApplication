#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startConnectionButton_clicked()
{


    if(ui->isConnectedToServer->text() == "yes")
    {
        // if there is some qTcpSocketWrapper object, it will receive a command to delete itself and its thread object - qTcpSocketWrapperThread
        emit(sendMessageToBottom(MessageType::DELETE_SOCKET_WRAPPER_THREAD));

        //removes an old ip&port text by sending the corresponding command to a MainWindow object
//        getMessageForTop(MessageType::DELETE_OLD_IP_AND_PORT);
        ui->isConnectedToServer->setText("no");
    }else if(ui->isConnectedToServer->text() == "no")
    {
        // creates a thread object which will create QTcpSocketWrapper object in new thread
        QTcpSocketWrapperThread* g_clientSocket = new QTcpSocketWrapperThread(this, server_ip_address, server_port);

        //registers a custom type to be able to use it with the signal and slot system
        qRegisterMetaType<MessageType>("MessageType");

        // if run() is finished when delete thread object
        //    connect(g_clientSocket, SIGNAL(finished()), g_clientSocket, SLOT(deleteLater()));

        connect(g_clientSocket, SIGNAL(sendMessageToTop(MessageType, QString)), this, SLOT(getMessageForTop(MessageType, QString)));

        connect(this, SIGNAL(sendMessageToBottom(MessageType, QString)), g_clientSocket, SLOT(getMessageForBottom(MessageType, QString)));

        g_clientSocket->start();
        ui->isConnectedToServer->setText("yes");
    }
}

void MainWindow::on_stopConnectionButton_clicked()
{
    getMessageForTop(MessageType::DELETE_OLD_IP_AND_PORT);
    emit(sendMessageToBottom(MessageType::DELETE_SOCKET_WRAPPER_THREAD));
}

void MainWindow::setImage(QString& imageText)
{
    int x = 150;
    int y = 150;
    QByteArray byteArray = QByteArray::fromBase64(imageText.toAscii());
    QPixmap pixmap = QPixmap::fromImage(QImage::fromData(byteArray, "bmp"));
    ui->image->setPixmap(pixmap.scaled(x, y, Qt::KeepAspectRatio));
    ui->image->show();
}

void MainWindow::setImage(QByteArray& byteArray)
{
    int x = 150;
    int y = 150;
    QPixmap pixmap = QPixmap::fromImage(QImage::fromData(byteArray, "bmp"));
    ui->image->setPixmap(pixmap.scaled(x,y,Qt::KeepAspectRatio));
    ui->image->show();
}

void MainWindow::setCurrentTime()
{
    QDateTime local(QDateTime::currentDateTime());

    //it changes the time to a current time
    QLocale locale(QLocale::English);
    QDateTime UTC(local);
    UTC.setTimeSpec(Qt::UTC);
    ui-> serverMessageTime->setText(QLocale{QLocale::English}.toString(local));
}

void MainWindow::parseReceivedMessageFromServer(QString& receivedMessage)
{

    //  a received message looks like this ":from:Earth:color:003CFF:text:sometext:image:w12312e1wqeQWEQW"
    // here prefedined all message tags to easily work with received message
    QString fromTag = ":from:";
    QString colorTag = ":color:";
    QString textTag = ":text:";
    QString imageTag = ":image:";

    int fromIndex = receivedMessage.indexOf(fromTag);
    int colorIndex = receivedMessage.indexOf(colorTag);
    int textIndex = receivedMessage.indexOf(textTag);
    int imageIndex = receivedMessage.indexOf(imageTag);

    QString from_text;
    QString color_text;
    QString text_text;
    QString image_text;

    int spaceIndex;
    if(fromIndex == -1|| colorIndex == -1|| textIndex == -1|| imageIndex == -1
            || !(fromIndex < colorIndex) || !(colorIndex < textIndex) || !( textIndex < imageIndex))
    {

        QMessageBox::warning(this, "Connection problem", "Received a damaged message");
        return;
    }

    //    qDebug() << fromIndex << " " <<   colorIndex << " " << textIndex <<  " " << imageIndex;
    //    qDebug() << fromTag.length() <<  " " << colorTag.length()
    //             <<  " " << textTag.length() << " " << imageTag.length();

    from_text = receivedMessage.mid(fromTag.length(), colorIndex-fromTag.length());
    color_text = receivedMessage.mid(colorIndex+colorTag.length(), textIndex - (colorIndex+colorTag.length()));
    text_text = receivedMessage.mid(textIndex+textTag.length(), imageIndex - (textIndex+textTag.length()));
    image_text = receivedMessage.mid(imageIndex + imageTag.length(), receivedMessage.length()-(imageIndex + imageTag.length()));
    //    qDebug() <<"from is: " <<  from_text << ", color is: " << color_text << ", text is: " << text_text;
    ui->from->setText(from_text);
    ui->color->setText(color_text);
    ui->text->setStyleSheet("color:#" + color_text + ";");
    ui->text->setPlainText(text_text);
    setImage(image_text);

    setCurrentTime();

}

void MainWindow::on_changeServerIpButton_clicked()
{
    server_ip_address = ui->serverIp->text();

}

void MainWindow::on_changeServerPortButton_clicked()
{
    server_port = ui->serverPort->text().toInt();
}

void MainWindow::on_sendRequestToServerButton_clicked()
{
    emit(sendMessageToBottom(MessageType::REQUEST_XML_PARAMETERS_FROM_SERVER));
}

void MainWindow::getMessageForTop(MessageType messageType, QString message)
{
    //    qDebug() << message << "receivedmessage";
    if(messageType == MessageType::SUCCESSFULLY_CONNECTED_TO_SERVER)
    {
        qDebug() << "SUCCESSFULLY_CONNECTED_TO_SERVER";
        ui->isConnectedToServer->setText("yes");

    }else if(messageType == MessageType::CANT_CONNECT_TO_SERVER || messageType == MessageType::DELETE_OLD_IP_AND_PORT )
    {
        qDebug() << "CANT_CONNECT_TO_SERVER || DELETE_OLD_IP_AND_PORT";
        ui->isConnectedToServer->setText("no");
        ui->clientPort->setText("");
        ui->clientIp->setText("");
    }else if(messageType == MessageType::CLIENT_IP_ADDRESS)
    {
        qDebug() << "IP_ADDRESS";
        clientIpAddress = message;
        ui->clientIp->setText(clientIpAddress);

    }else if(messageType == MessageType::CLIENT_PORT)
    {
        qDebug() << "PORT";
        clientPort = message;
        ui->clientPort->setText(clientPort);

    }else if(messageType == MessageType::MESSAGE_FROM_SERVER)
    {
        //        qDebug() << "MESSAGE_FROM_SERVER";
        parseReceivedMessageFromServer(message);

    }

}
