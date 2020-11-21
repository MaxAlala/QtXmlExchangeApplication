#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtXml>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new TCPServer(this);
    connect(this, SIGNAL(sendReceivedDataToAllClient(QString)), server, SLOT(getReceivedDataToAllClient(QString)));
    connect(server, SIGNAL(sendClientIP_andPort(QString, int)), this, SLOT(getClientIP_andPort(QString, int)));
    connect(server, SIGNAL(sendMessageToMainWindow(QString)), this, SLOT(getMessageForMainWindow(QString)));
    qDebug() << QThread::currentThreadId() << "MainWINDOW";
    this->setWindowTitle("Server");

}

MainWindow::~MainWindow()
{
    delete ui;

}

//start
void MainWindow::on_startServerButton_clicked()
{
    qDebug() << QThread::currentThreadId() << "startServer";
    server->startServer();
    qDebug() << " SERVER ADDRESS: " <<server->serverAddress();
    ui->serverip->setText(server->serverAddress().toString());
    ui->isServerRunning->setText("yes");

}

//stop
void MainWindow::on_stopServerButton_clicked()
{
    server->stopServer();
    ui->isServerRunning->setText("no");

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
    //        qDebug() << pixmap.size();
    ui->image->setPixmap(pixmap.scaled(x,y,Qt::KeepAspectRatio));
    ui->image->show();

}

void changeImageResolution(QString imageText, int x = 150, int y = 150)
{
    QByteArray byteArray = QByteArray::fromBase64(imageText.toAscii());
    QPixmap pixmap = QPixmap::fromImage(QImage::fromData(byteArray, "bmp"));
    //    qDebug() << "before changing resolution:" <<pixmap.size();
    pixmap = pixmap.scaled(x,y,Qt::KeepAspectRatio);

    QFile file(QDir::currentPath() + "/resizedImg.bmp");
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "bmp");

}


void MainWindow::setImageWithPath(QString& pathToImage)
{
    int x = 150;
    int y = 150;
    QPixmap pixmap;
    pixmap.load(pathToImage);
    qDebug() << "setImageWithPath:" <<pixmap.size();
    qDebug() << pathToImage;
    ui->image->setPixmap(pixmap.scaled(x,y,Qt::KeepAspectRatio));
    ui->image->show();

}

void MainWindow::addImageToXML_Doc(QDomDocument& document, QString& imagePath)
{
    // reads an image
    QImage image(imagePath);
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "bmp");

    // adds an image data into the "image" element node of xml document
    QDomText data = document.createTextNode(byteArray.toBase64());
    document.firstChildElement().firstChildElement("image").firstChild().setNodeValue(byteArray.toBase64());

    // gets new image in text format
    data = document.firstChildElement().firstChildElement("image").firstChild().toText();

    // rewrites an image using a current text
    byteArray = QByteArray::fromBase64(data.toText().data().toAscii());

    // saves a new document
    QFile file( xmlFilePath );

    if( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        qDebug( "Failed to open file for writing." );
    }

    QTextStream stream( &file );
    stream << document.toString();
    file.close();

}

QString MainWindow::readFirstChildXmlElementTextValue(QDomElement& root, QString tagname)
{
    // image can be very big for debug
    //    qDebug() << tagname << " " << root.firstChildElement(tagname).text();
    return root.firstChildElement(tagname).text();

}

void MainWindow::openDocument(QDomDocument& document, QString& xmlFilePath)
{
    QFile file(xmlFilePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << " Can't open a file";

    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug() << " Can't open a document";
        }
        file.close();
    }

}

void MainWindow::selectFile(QString& path, QString regularExpression)
{
    path = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), regularExpression);
    qDebug() << "selected path: " << path;

}

void MainWindow::readXmlParametersAndFitImage()
{
    selectFile(xmlFilePath);

    QFile file(xmlFilePath);
    QDomDocument document;
    openDocument(document, xmlFilePath);

    // gets a root element of a XML file
    QDomElement root = document.firstChildElement();

    // first of all is an image resizing. Rewrite document with resized image.
    QString image_text = readFirstChildXmlElementTextValue(root, "image");
    changeImageResolution(image_text);
    QString resizedImagePath = QDir::currentPath() + "/resizedImg.bmp";

    //changes a file name to create another XML file
    int index = xmlFilePath.indexOf(".xml");
    xmlFilePath = xmlFilePath.insert(index, "Resized");
    qDebug() << "new xmlPath: " << xmlFilePath;

    addImageToXML_Doc(document, resizedImagePath);

    // opens a document with a resized image
    openDocument(document,xmlFilePath);

    // reads a resized image
    image_text = readFirstChildXmlElementTextValue(root, "image");
    setImage(image_text);

    // reads "from"
    QString from_text = readFirstChildXmlElementTextValue(root, "from");
    ui->from->setText(from_text);

    // reads "to"
    ui->to->setText(readFirstChildXmlElementTextValue(root, "to"));

    // reads "id"
    ui->id->setText(readFirstChildXmlElementTextValue(root, "id"));

    // reads "color"
    QString color_text = readFirstChildXmlElementTextValue(root, "color");
    ui->color->setText(color_text);
    color_text = "color:#" + color_text + ";";

    // reads "text"
    ui->text->setStyleSheet(color_text);
    QString text_text = readFirstChildXmlElementTextValue(root, "text");
    ui->text->setPlainText(text_text);

    // reads "formatVersion"
    QString formatVersion_text = readFirstChildXmlElementTextValue(root, "FormatVersion");
    ui->format->setText(formatVersion_text);

    messageForClients  = ":from:"   + from_text;
    messageForClients += ":color:"  + readFirstChildXmlElementTextValue(root, "color");
    messageForClients += ":text:"   + text_text;
    messageForClients += ":image: " + image_text;

    emit(sendReceivedDataToAllClient(messageForClients));

    // if you want to add an image data to the XML file to "image" element uncomment line below
    //        xmlFilePath ="newpath/newfile.xml";
    //        QString imagePath = ":/resources/images/mars.bmp";
    //        addImageToXML_Doc(document, imagePath);

}

void MainWindow::on_openXmlButton_clicked()
{
    readXmlParametersAndFitImage();

}

void MainWindow::getMessageForMainWindow(QString message)
{

    // if a client was disconnected it removes ip and port from the combobox
    QString deleteIpAndPort = "delete ip&port:";

    // it asks to send xml parameters to a client
    QString dataRequestFromClient = "Data, please";

    // it gives connected client ip & port
    QString clientIpAndPort = "clientip&port:";

    qDebug() << "getmessagefromMainWindow " << message;

    if(message.startsWith(dataRequestFromClient))
    {
        if(messageForClients != "") emit(sendReceivedDataToAllClient(messageForClients));
        else ui->statusbar->showMessage("client requested data, but no xml file was opened before");
    }
    else if(message.startsWith(deleteIpAndPort))
    {
        qDebug() << "delete ip& port:" + message.mid(deleteIpAndPort.length(), message.length() - deleteIpAndPort.length());

        // index of combobox element with a found ip and port
        int index = ui->comboBox_clients->findText(message.mid(deleteIpAndPort.length(), message.length() - deleteIpAndPort.length()));
        if(index != -1)
            ui->comboBox_clients->removeItem(index);

    }else if(message.startsWith(clientIpAndPort))
    {
        int space_index = message.indexOf(" ");
        qDebug() << space_index;
        QString ip_address = message.mid(clientIpAndPort.length(),space_index - clientIpAndPort.length());
        QString port = message.mid(space_index, message.length() - space_index);
        qDebug( ) << "ip: "<< ip_address;
        qDebug( ) << "port: "<< port;
        ui->comboBox_clients->addItem(QString(ip_address + " " + port));

    }
}

void MainWindow::on_changeServerPortButton_clicked()
{
    server->setServer_port((ui->serverport->text().toInt()));
    if(server->isListening()) server->stopServer();

}
