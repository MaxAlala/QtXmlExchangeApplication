/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *first;
    QGridLayout *parameters;
    QLabel *server_parameters_const;
    QFormLayout *xmlParameters;
    QLabel *format_const;
    QLabel *format;
    QLabel *from_const;
    QLabel *from;
    QLabel *to_const;
    QLabel *to;
    QLabel *id_const;
    QLabel *id;
    QLabel *color_const;
    QLabel *color;
    QLabel *image_const;
    QLabel *xml_parameters_const;
    QLabel *image;
    QGridLayout *serverParameters;
    QLabel *clientPort_const;
    QLabel *serverMessageTime_const;
    QLineEdit *serverPort;
    QPushButton *changeServerPortButton;
    QLabel *serverMessageTime;
    QLabel *isServerRunning_const;
    QLabel *serverIp_const;
    QLabel *clientIp_const;
    QLabel *clientPort;
    QLineEdit *serverIp;
    QHBoxLayout *offOnButtons;
    QPushButton *startConnectionButton;
    QLabel *isConnectedToServer;
    QLabel *clientIp;
    QPushButton *changeServerIpButton;
    QLabel *serverPort_const;
    QVBoxLayout *textAndButton;
    QPlainTextEdit *text;
    QHBoxLayout *BottomButton;
    QPushButton *sendRequestToServerButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 592);
        MainWindow->setStyleSheet(QString::fromUtf8("background:#FFFFFF;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        first = new QVBoxLayout();
        first->setObjectName(QString::fromUtf8("first"));
        parameters = new QGridLayout();
        parameters->setObjectName(QString::fromUtf8("parameters"));
        server_parameters_const = new QLabel(centralwidget);
        server_parameters_const->setObjectName(QString::fromUtf8("server_parameters_const"));
        server_parameters_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        parameters->addWidget(server_parameters_const, 0, 2, 1, 1);

        xmlParameters = new QFormLayout();
        xmlParameters->setObjectName(QString::fromUtf8("xmlParameters"));
        format_const = new QLabel(centralwidget);
        format_const->setObjectName(QString::fromUtf8("format_const"));
        format_const->setMinimumSize(QSize(80, 0));
        format_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        xmlParameters->setWidget(0, QFormLayout::LabelRole, format_const);

        format = new QLabel(centralwidget);
        format->setObjectName(QString::fromUtf8("format"));
        format->setMinimumSize(QSize(80, 0));
        format->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        xmlParameters->setWidget(0, QFormLayout::FieldRole, format);

        from_const = new QLabel(centralwidget);
        from_const->setObjectName(QString::fromUtf8("from_const"));
        from_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        xmlParameters->setWidget(1, QFormLayout::LabelRole, from_const);

        from = new QLabel(centralwidget);
        from->setObjectName(QString::fromUtf8("from"));
        from->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        xmlParameters->setWidget(1, QFormLayout::FieldRole, from);

        to_const = new QLabel(centralwidget);
        to_const->setObjectName(QString::fromUtf8("to_const"));
        to_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        xmlParameters->setWidget(2, QFormLayout::LabelRole, to_const);

        to = new QLabel(centralwidget);
        to->setObjectName(QString::fromUtf8("to"));
        to->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        xmlParameters->setWidget(2, QFormLayout::FieldRole, to);

        id_const = new QLabel(centralwidget);
        id_const->setObjectName(QString::fromUtf8("id_const"));
        id_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        xmlParameters->setWidget(3, QFormLayout::LabelRole, id_const);

        id = new QLabel(centralwidget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        xmlParameters->setWidget(3, QFormLayout::FieldRole, id);

        color_const = new QLabel(centralwidget);
        color_const->setObjectName(QString::fromUtf8("color_const"));
        color_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        xmlParameters->setWidget(4, QFormLayout::LabelRole, color_const);

        color = new QLabel(centralwidget);
        color->setObjectName(QString::fromUtf8("color"));
        color->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        xmlParameters->setWidget(4, QFormLayout::FieldRole, color);


        parameters->addLayout(xmlParameters, 1, 0, 1, 1);

        image_const = new QLabel(centralwidget);
        image_const->setObjectName(QString::fromUtf8("image_const"));
        image_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        parameters->addWidget(image_const, 0, 1, 1, 1);

        xml_parameters_const = new QLabel(centralwidget);
        xml_parameters_const->setObjectName(QString::fromUtf8("xml_parameters_const"));
        xml_parameters_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        parameters->addWidget(xml_parameters_const, 0, 0, 1, 1);

        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setMinimumSize(QSize(150, 150));
        image->setMaximumSize(QSize(150, 150));
        image->setStyleSheet(QString::fromUtf8("background:#f6f6f6;"));

        parameters->addWidget(image, 1, 1, 1, 1);

        serverParameters = new QGridLayout();
        serverParameters->setObjectName(QString::fromUtf8("serverParameters"));
        clientPort_const = new QLabel(centralwidget);
        clientPort_const->setObjectName(QString::fromUtf8("clientPort_const"));
        clientPort_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        serverParameters->addWidget(clientPort_const, 4, 0, 1, 1);

        serverMessageTime_const = new QLabel(centralwidget);
        serverMessageTime_const->setObjectName(QString::fromUtf8("serverMessageTime_const"));

        serverParameters->addWidget(serverMessageTime_const, 5, 0, 1, 1);

        serverPort = new QLineEdit(centralwidget);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serverPort->sizePolicy().hasHeightForWidth());
        serverPort->setSizePolicy(sizePolicy);
        serverPort->setStyleSheet(QString::fromUtf8("background:#f6f6f6 ;color:#000000;; border: none;border-bottom: 1px solid currentColor;"));

        serverParameters->addWidget(serverPort, 2, 1, 1, 1);

        changeServerPortButton = new QPushButton(centralwidget);
        changeServerPortButton->setObjectName(QString::fromUtf8("changeServerPortButton"));
        changeServerPortButton->setStyleSheet(QString::fromUtf8("color:#000000; border: none;color:#000000; border: none;border-bottom: 1px solid currentColor;"));

        serverParameters->addWidget(changeServerPortButton, 2, 2, 1, 1);

        serverMessageTime = new QLabel(centralwidget);
        serverMessageTime->setObjectName(QString::fromUtf8("serverMessageTime"));
        serverMessageTime->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        serverParameters->addWidget(serverMessageTime, 5, 1, 1, 1);

        isServerRunning_const = new QLabel(centralwidget);
        isServerRunning_const->setObjectName(QString::fromUtf8("isServerRunning_const"));
        isServerRunning_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        serverParameters->addWidget(isServerRunning_const, 0, 0, 1, 1);

        serverIp_const = new QLabel(centralwidget);
        serverIp_const->setObjectName(QString::fromUtf8("serverIp_const"));
        serverIp_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        serverParameters->addWidget(serverIp_const, 1, 0, 1, 1);

        clientIp_const = new QLabel(centralwidget);
        clientIp_const->setObjectName(QString::fromUtf8("clientIp_const"));
        clientIp_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        serverParameters->addWidget(clientIp_const, 3, 0, 1, 1);

        clientPort = new QLabel(centralwidget);
        clientPort->setObjectName(QString::fromUtf8("clientPort"));
        clientPort->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        serverParameters->addWidget(clientPort, 4, 1, 1, 1);

        serverIp = new QLineEdit(centralwidget);
        serverIp->setObjectName(QString::fromUtf8("serverIp"));
        serverIp->setStyleSheet(QString::fromUtf8("background:#f6f6f6 ;color:#000000;; border: none;border-bottom: 1px solid currentColor;"));

        serverParameters->addWidget(serverIp, 1, 1, 1, 1);

        offOnButtons = new QHBoxLayout();
        offOnButtons->setObjectName(QString::fromUtf8("offOnButtons"));
        startConnectionButton = new QPushButton(centralwidget);
        startConnectionButton->setObjectName(QString::fromUtf8("startConnectionButton"));
        startConnectionButton->setStyleSheet(QString::fromUtf8("color:#000000; border: none;border-bottom: 1px solid currentColor;"));

        offOnButtons->addWidget(startConnectionButton);


        serverParameters->addLayout(offOnButtons, 0, 2, 1, 1);

        isConnectedToServer = new QLabel(centralwidget);
        isConnectedToServer->setObjectName(QString::fromUtf8("isConnectedToServer"));
        isConnectedToServer->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        serverParameters->addWidget(isConnectedToServer, 0, 1, 1, 1);

        clientIp = new QLabel(centralwidget);
        clientIp->setObjectName(QString::fromUtf8("clientIp"));
        clientIp->setStyleSheet(QString::fromUtf8("background:#f6f6f6;color:#000000;"));

        serverParameters->addWidget(clientIp, 3, 1, 1, 1);

        changeServerIpButton = new QPushButton(centralwidget);
        changeServerIpButton->setObjectName(QString::fromUtf8("changeServerIpButton"));
        changeServerIpButton->setStyleSheet(QString::fromUtf8("color:#000000; border: none;color:#000000; border: none;border-bottom: 1px solid currentColor;"));

        serverParameters->addWidget(changeServerIpButton, 1, 2, 1, 1);

        serverPort_const = new QLabel(centralwidget);
        serverPort_const->setObjectName(QString::fromUtf8("serverPort_const"));
        serverPort_const->setStyleSheet(QString::fromUtf8("color:#000000"));

        serverParameters->addWidget(serverPort_const, 2, 0, 1, 1);


        parameters->addLayout(serverParameters, 1, 2, 1, 1);


        first->addLayout(parameters);

        textAndButton = new QVBoxLayout();
        textAndButton->setObjectName(QString::fromUtf8("textAndButton"));
        text = new QPlainTextEdit(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setMinimumSize(QSize(900, 300));
        text->setStyleSheet(QString::fromUtf8("color:#000000; background:#f6f6f6;"));

        textAndButton->addWidget(text);

        BottomButton = new QHBoxLayout();
        BottomButton->setObjectName(QString::fromUtf8("BottomButton"));
        sendRequestToServerButton = new QPushButton(centralwidget);
        sendRequestToServerButton->setObjectName(QString::fromUtf8("sendRequestToServerButton"));
        sendRequestToServerButton->setStyleSheet(QString::fromUtf8("color:#000000; border: none; color:#000000; border: none;border-bottom: 1px solid currentColor;"));

        BottomButton->addWidget(sendRequestToServerButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BottomButton->addItem(horizontalSpacer);


        textAndButton->addLayout(BottomButton);


        first->addLayout(textAndButton);


        gridLayout->addLayout(first, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 922, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        server_parameters_const->setText(QCoreApplication::translate("MainWindow", "                                                   server parameters", nullptr));
        format_const->setText(QCoreApplication::translate("MainWindow", "format", nullptr));
        format->setText(QString());
        from_const->setText(QCoreApplication::translate("MainWindow", "from", nullptr));
        from->setText(QString());
        to_const->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        to->setText(QString());
        id_const->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        id->setText(QString());
        color_const->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        color->setText(QString());
        image_const->setText(QCoreApplication::translate("MainWindow", "       received image", nullptr));
        xml_parameters_const->setText(QCoreApplication::translate("MainWindow", "Received xml parameters", nullptr));
        image->setText(QString());
        clientPort_const->setText(QCoreApplication::translate("MainWindow", "client port", nullptr));
        serverMessageTime_const->setText(QCoreApplication::translate("MainWindow", "server message time", nullptr));
        serverPort->setText(QCoreApplication::translate("MainWindow", "3333", nullptr));
        changeServerPortButton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        serverMessageTime->setText(QString());
        isServerRunning_const->setText(QCoreApplication::translate("MainWindow", "is connected", nullptr));
        serverIp_const->setText(QCoreApplication::translate("MainWindow", "server ip", nullptr));
        clientIp_const->setText(QCoreApplication::translate("MainWindow", "client ip", nullptr));
        clientPort->setText(QString());
        serverIp->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        startConnectionButton->setText(QCoreApplication::translate("MainWindow", "start/stop", nullptr));
        isConnectedToServer->setText(QCoreApplication::translate("MainWindow", "no", nullptr));
        clientIp->setText(QString());
        changeServerIpButton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        serverPort_const->setText(QCoreApplication::translate("MainWindow", "server port", nullptr));
        sendRequestToServerButton->setText(QCoreApplication::translate("MainWindow", "request data", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
