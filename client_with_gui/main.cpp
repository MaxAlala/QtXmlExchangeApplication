#include "mainwindow.h"

#include <QApplication>

// SOME MEMORY FOR APP CREATOR
//debug methods
//    qDebug() << QThread::currentThreadId() << "run"; // return a thread id
//    qDebug()<<thread(); // returns a thread affinity
//pointer to a dynamically-allocated object,
//why Wrapper for socket?
// queued connection?
//QObject: Cannot create children for a parent that is in a different thread.
//Parent is QNativeSocketEngine(0x30297a0),
//parent's thread is TCP_client_thread(0x30e4700==new thread), current thread is QThread(0x2e65e30==main thread)
//    socket->write(data.toAscii());
// after calling write using GUI thread
//1485
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
