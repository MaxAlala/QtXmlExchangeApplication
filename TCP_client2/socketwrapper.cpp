#include "socketwrapper.h"
#include <QMessageBox>
#include <QNetworkInterface>

SocketWrapper::SocketWrapper(QObject *parent, QString serverIpAddress, int serverPort) :
    QThread(parent),
    server_ip_address(serverIpAddress),
    server_port(serverPort)
{
    //   mw = MainWindow::getMainWinPtr();

}

void SocketWrapper::run()
{
    qDebug() << "Starting thread.";
    socket = new QTcpSocket();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connectToServer();
    qDebug() << QThread::currentThreadId() << "run";
    qDebug() << "localport: " <<QString::number(socket->localPort());
    emit(sendTextToMainWindow("localport:" + QString::number(socket->localPort())));
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
            emit(sendTextToMainWindow("ipaddress:" + address.toString()));

    }

    exec();
}

SocketWrapper::~SocketWrapper()
{
    //     socket->deleteLater();

}

void SocketWrapper::disconnected()
{
    if(socket) socket->deleteLater();
    socket = nullptr;
    qDebug() << QThread::currentThreadId() <<" disconnected";
    emit(cantConnectToServer());

}

int SocketWrapper::getServer_port() const
{
    return server_port;
}

void SocketWrapper::setServer_port(int value)
{
    server_port = value;
}

void SocketWrapper::getRequestToServer()
{
    qDebug()<< "send a request to the server: Data, please";
    if(socket) socket->write("Data, please");

}

QString SocketWrapper::getServer_ip_address() const
{
    return server_ip_address;
}

void SocketWrapper::setServer_ip_address(const QString &value)
{
    server_ip_address = value;
}

void SocketWrapper::stopSocket()
{

    qDebug() << QThread::currentThreadId() <<" stopSocket";
    if(socket) socket->deleteLater();
    socket = nullptr;
    emit(cantConnectToServer());
    //    QThread::quit();
    //    this->quit();
}

void SocketWrapper::readyRead()
{
    qDebug() << QThread::currentThreadId() <<" readyRead";
    if (socket->waitForConnected(500))
    {
        socket->waitForReadyRead(500);
        Data = socket->readAll();
        // it checks if a received data is not empty
        if(!(QString(Data) == "")) emit(sendReceivedData(Data));
        qDebug() << "received data "<< Data;
    }
}

void SocketWrapper::connectToServer()
{
    qDebug() << "trying to connect to server";
    // it checks if a socket still exists to decide whether it is necessary to create a new socket
    socket->connectToHost(server_ip_address, server_port);
    socket->waitForConnected(100); // return true if connected

    bool connected = (socket->state() == QTcpSocket::ConnectedState);
    if(!connected)
    {
        qDebug() << "cant connect to server";
        emit(cantConnectToServer());
        emit(sendError("Can't connect to the server"));
        // to stop a socket
        emit(disconnected());
    }else
    {
        qDebug() << "connected";
        emit(successfullyConnectedToServer());
        //        socket-> write("sent data");
    }

}

//void SocketWrapper::changeServerIpAddress(QString serverIpAddress)
//{
//    server_ip_address = serverIpAddress;

//}

//void SocketWrapper::changeServerPort(int serverPort)
//{
//    server_port = serverPort;

//}

//void SocketWrapper::disconnectFromHost()
//{
//    socket->disconnectFromHost();
//    socket = nullptr;

//}
