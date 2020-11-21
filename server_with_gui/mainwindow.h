#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"
#include <QtXml>
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
    void sendReceivedDataToAllClient(QString);
private slots:
    void on_stopServerButton_clicked();
    void on_startServerButton_clicked();
    void on_changeServerPortButton_clicked();
    void on_openXmlButton_clicked();
    void getMessageForMainWindow(QString);
private:
    QString readFirstChildXmlElementTextValue(QDomElement& root, QString tagname);
    void openDocument(QDomDocument& document, QString& xmlFilePath);
    void readXmlParametersAndFitImage();
    void setImage(QByteArray& byteArray);
    void addImageToXML_Doc(QDomDocument& document, QString& imagePath);
    void setImage(QString& imageText);
    void setImageWithPath(QString& pathToImage);
    void selectFile(QString& path, QString regularExpression = "*.XML");
    Ui::MainWindow *ui;
    TCPServer*  server;
    QString xmlFilePath;
    QString messageForClients;

};
#endif // MAINWINDOW_H
