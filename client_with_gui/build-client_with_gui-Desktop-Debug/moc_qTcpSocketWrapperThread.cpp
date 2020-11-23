/****************************************************************************
** Meta object code from reading C++ file 'qTcpSocketWrapperThread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client_with_gui/qTcpSocketWrapperThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTcpSocketWrapperThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTcpSocketWrapperThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      45,   25,   24,   24, 0x05,
      95,   83,   24,   24, 0x25,
     125,   25,   24,   24, 0x05,
     166,   83,   24,   24, 0x25,

 // slots: signature, parameters, type, tag, flags
     199,   25,   24,   24, 0x0a,
     240,   83,   24,   24, 0x2a,
     273,   25,   24,   24, 0x0a,
     311,   83,   24,   24, 0x2a,
     341,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QTcpSocketWrapperThread[] = {
    "QTcpSocketWrapperThread\0\0messageType,message\0"
    "sendMessageToTop(MessageType,QString)\0"
    "messageType\0sendMessageToTop(MessageType)\0"
    "sendMessageToBottom(MessageType,QString)\0"
    "sendMessageToBottom(MessageType)\0"
    "getMessageForBottom(MessageType,QString)\0"
    "getMessageForBottom(MessageType)\0"
    "getMessageForTop(MessageType,QString)\0"
    "getMessageForTop(MessageType)\0"
    "deleteThreadObject()\0"
};

void QTcpSocketWrapperThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QTcpSocketWrapperThread *_t = static_cast<QTcpSocketWrapperThread *>(_o);
        switch (_id) {
        case 0: _t->sendMessageToTop((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sendMessageToTop((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 2: _t->sendMessageToBottom((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendMessageToBottom((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 4: _t->getMessageForBottom((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->getMessageForBottom((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 6: _t->getMessageForTop((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->getMessageForTop((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 8: _t->deleteThreadObject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QTcpSocketWrapperThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QTcpSocketWrapperThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QTcpSocketWrapperThread,
      qt_meta_data_QTcpSocketWrapperThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTcpSocketWrapperThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTcpSocketWrapperThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTcpSocketWrapperThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTcpSocketWrapperThread))
        return static_cast<void*>(const_cast< QTcpSocketWrapperThread*>(this));
    return QThread::qt_metacast(_clname);
}

int QTcpSocketWrapperThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QTcpSocketWrapperThread::sendMessageToTop(MessageType _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void QTcpSocketWrapperThread::sendMessageToBottom(MessageType _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
