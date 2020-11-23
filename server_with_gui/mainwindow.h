#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qTcpServer.h"
#include <QtXml>
#include "serverMessageType.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:


    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do? This method sends messages to underlying objects.
    */
    void sendMessageToBottom(MessageType messageType, QString message = "");
private slots:
    void on_stopServerButton_clicked();
    void on_startServerButton_clicked();
    void on_changeServerPortButton_clicked();
    /*!
    * \brief invokes readXmlParametersAndFitImage method which does all job with a XML file.
    */
    void on_openXmlButton_clicked();
    /*!
    * \brief this method was created for communication through SLOT and SIGNAL between all objects in all threads.
    * The whole hierarchy
    * Top == MainWindow -> QTcpServerWrapper -> QTcpSocketWrapperThread -> QTcpSpcketWrapper == Bottom
    *
    *  What does it do?  This method receives messages from underlying objects
    * to use them or sends to higher objects depending on the MessageType.
    */
    void getMessageForTop(MessageType messageType, QString message = "");

private:
    /*!
    * \brief reads first child of an xml element. This first child is a text element, i.e. a text value.
    */
    QString readFirstChildXmlElementTextValue(QDomElement& root, QString tagname);

    /*!
    * \brief opens a QDomDocument using specified path
    */
    void openDocument(QDomDocument& document, QString& xmlFilePath);


    /*!
    * \brief in this method a user selects XML file and then the method parses it. Also it changes a XML file's image resolution to fit a label which is 150 by 150 pixels.
    * Resulted XML file with a new image text will be saved with suffix "Resized". Resizing is important because otherwise image can be too big for sending through a socket.
    * In any case, 150 by 150 pixel label can't get an image with bigger size. Also this method reads all parameters and saves them.
    * After creating a new XML file and a new resized image, the method try to send xml parameters "from", "color", "text", "image" to connected clients.
    */
    void readXmlParametersAndFitImage();

    /*!
    * \brief sets a resized image to an image label, resized image should fit 150 by 150 pixels.
    */
    void setImage(QByteArray& byteArray);

    /*!
    * \brief sets new "image" parameter's value using a specified image
    */
    void addImageToXML_Doc(QDomDocument& document, QString& imagePath);

    /*!
    * \brief sets a resized image to an image label, resized image should fit 150 by 150 pixels.
    */
    void setImage(QString& imageText);

    /*!
    * \brief sets a resized image to an image label, resized image should fit 150 by 150 pixels.
    */
    void setImageWithPath(QString& pathToImage);

    /*!
    * \brief here you can select a XML file
    */
    void selectFile(QString& path, QString regularExpression = "*.XML");
    Ui::MainWindow *ui;

    /*!
    * \brief this pointer will point to the server which waits connections from clients. For each clients a server creates a new thread.
    */
    QTcpServerWrapper*  server;
    QString xmlFilePath;

    /*!
    * \brief parsed XML parameters will create a message for clients. Necessary parameters in a message: "from", "color", "text", "image" .
    */
    QString messageForClients;

};
#endif // MAINWINDOW_H
