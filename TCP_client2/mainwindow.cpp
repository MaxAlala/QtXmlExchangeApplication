#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow * MainWindow::pMainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMainWindow = this;
    this->setWindowTitle("Client");
}

MainWindow::~MainWindow()
{
    delete ui;
}


// kind of singleton reference.
//MainWindow *MainWindow::getMainWinPtr()
//{
//    return pMainWindow;
//}

//void MainWindow::disconnected()
//{
//    socket->deleteLater();
//}

//void MainWindow::readyRead()
//{
//    if (socket->waitForConnected(500))
//    {
//        socket->waitForReadyRead(500);
//        Data = socket->readAll();
//        qDebug() << Data;
//    }
//}

void MainWindow::on_startConnectionButton_clicked()
{
    qDebug() << QThread::currentThreadId() << "111";
    // it creates thread with a client socket
    if(g_clientSocket){ qDebug() << g_clientSocket << " not empty";
        g_clientSocket->stopSocket();
        // if delete a dangling ptr when a program will collapse
        g_clientSocket = nullptr;

    }
    else qDebug() << g_clientSocket << " empty";
    //for(int i = 0; i < 100; i++)
    //   new double[100000000];

    qDebug() << g_clientSocket << "objectname";
    g_clientSocket = new SocketWrapper(this, server_ip_address, server_port);
    connect(g_clientSocket, SIGNAL(finished()), g_clientSocket, SLOT(deleteLater()));
    connect(g_clientSocket, SIGNAL(sendReceivedData(QByteArray)), this, SLOT(getReceivedData(QByteArray)));
    connect(g_clientSocket, SIGNAL(sendError(QString)), this, SLOT(getError(QString)));
    connect(g_clientSocket, SIGNAL(successfullyConnectedToServer()), this, SLOT(getSuccessfullyConnectedToServerMessage()));
    connect(g_clientSocket, SIGNAL(cantConnectToServer()), this, SLOT(getCantConnectToServerMessage()));
    connect(this, SIGNAL(sendRequestToServer()), g_clientSocket, SLOT(getRequestToServer()));
    connect(g_clientSocket, SIGNAL(sendTextToMainWindow(QString)), this, SLOT(getTextForMainWindow(QString)));

    g_clientSocket->start();
    //    qDebug() << "thread is dead!";
    qDebug() << g_clientSocket << " after creation";
}

void MainWindow::on_stopConnectionButton_clicked()
{
    if(g_clientSocket)
    {
        qDebug() << QThread::currentThreadId() << "222";
        g_clientSocket->stopSocket();
        g_clientSocket->deleteLater();
        // if delete a dangling ptr when a program will collapse
        g_clientSocket = nullptr;
    }
}

void MainWindow::setImage(QString imageText)
{
    int x = 150;
    int y = 150;
    QByteArray byteArray = QByteArray::fromBase64(imageText.toAscii());
    QPixmap pixmap = QPixmap::fromImage(QImage::fromData(byteArray, "bmp"));
    //        qDebug() << pixmap.size();
    ui->image->setPixmap(pixmap.scaled(x, y, Qt::KeepAspectRatio));
    ui->image->show();
}

void MainWindow::setImage(QByteArray byteArray)
{
    int x = 150;
    int y = 150;
    QPixmap pixmap = QPixmap::fromImage(QImage::fromData(byteArray, "bmp"));
    //        qDebug() << pixmap.size();
    ui->image->setPixmap(pixmap.scaled(x,y,Qt::KeepAspectRatio));
    ui->image->show();
}

void MainWindow::getReceivedData(QByteArray data)
{
    QString receivedMessage(data);

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

    qDebug() << fromIndex << " " <<   colorIndex << " " << textIndex <<  " " << imageIndex;
    qDebug() << fromTag.length() <<  " " << colorTag.length()
             <<  " " << textTag.length() << " " << imageTag.length();

    from_text = receivedMessage.mid(fromTag.length(), colorIndex-fromTag.length());
    color_text = receivedMessage.mid(colorIndex+colorTag.length(), textIndex - (colorIndex+colorTag.length()));
    text_text = receivedMessage.mid(textIndex+textTag.length(), imageIndex - (textIndex+textTag.length()));
    image_text = receivedMessage.mid(imageIndex + imageTag.length(), receivedMessage.length()-(imageIndex + imageTag.length()));
    qDebug() <<"from is: " <<  from_text << " color_text is: " << color_text << " text is: " << text_text << " image is: " << image_text;
    ui->from->setText(from_text);
    ui->color->setText(color_text);
    ui->text->setStyleSheet("color:#" + color_text + ";");
    ui->text->setPlainText(text_text);
    setImage(image_text);

    qDebug() << "Mainwindow received a data from a thread: " << QString(data);
    QDateTime local(QDateTime::currentDateTime());
    qDebug() << "Local time is:" << local;

    //it changes time to current time
    QLocale locale(QLocale::English);
    QDateTime UTC(local);
    UTC.setTimeSpec(Qt::UTC);
    qDebug() << "UTC time is:" << UTC;
    ui-> serverMessageTime->setText(QLocale{QLocale::English}.toString(local));

}

void MainWindow::getError(QString error)
{
    QMessageBox::warning(this, "Connection problem", error);
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
    emit(sendRequestToServer());
}

void MainWindow::getSuccessfullyConnectedToServerMessage()
{
    ui->isConnectedToServer->setText("yes");
}

void MainWindow::getCantConnectToServerMessage()
{
    ui->isConnectedToServer->setText("no");
}

void MainWindow::getTextForMainWindow(QString receivedTextFromThread)
{
    QString ipaddressTag = "ipaddress:";
    QString localportTag = "localport:";
    if(receivedTextFromThread.startsWith(ipaddressTag))
    {
        clientIpAddress = receivedTextFromThread.mid(ipaddressTag.length(), receivedTextFromThread.length()-1);
        ui->clientIp->setText(clientIpAddress);


    }else if(receivedTextFromThread.startsWith(localportTag))
    {
        clientPort = receivedTextFromThread.mid(ipaddressTag.length(), receivedTextFromThread.length()-1);
        ui->clientPort->setText(clientPort);
    }

    qDebug() << " received text from thread: " << receivedTextFromThread;
}

