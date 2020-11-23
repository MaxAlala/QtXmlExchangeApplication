/****************************************************************************
** Meta object code from reading C++ file 'qTcpSocketWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client_with_gui/qTcpSocketWrapper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTcpSocketWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTcpSocketWrapper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   19,   18,   18, 0x05,
      89,   77,   18,   18, 0x25,

 // slots: signature, parameters, type, tag, flags
     119,   18,   18,   18, 0x0a,
     134,   19,   18,   18, 0x0a,
     175,   77,   18,   18, 0x2a,
     208,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QTcpSocketWrapper[] = {
    "QTcpSocketWrapper\0\0messageType,message\0"
    "sendMessageToTop(MessageType,QString)\0"
    "messageType\0sendMessageToTop(MessageType)\0"
    "disconnected()\0getMessageForBottom(MessageType,QString)\0"
    "getMessageForBottom(MessageType)\0"
    "readyRead()\0"
};

void QTcpSocketWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QTcpSocketWrapper *_t = static_cast<QTcpSocketWrapper *>(_o);
        switch (_id) {
        case 0: _t->sendMessageToTop((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sendMessageToTop((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 2: _t->disconnected(); break;
        case 3: _t->getMessageForBottom((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->getMessageForBottom((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 5: _t->readyRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QTcpSocketWrapper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QTcpSocketWrapper::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_QTcpSocketWrapper,
      qt_meta_data_QTcpSocketWrapper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTcpSocketWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTcpSocketWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTcpSocketWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTcpSocketWrapper))
        return static_cast<void*>(const_cast< QTcpSocketWrapper*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int QTcpSocketWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QTcpSocketWrapper::sendMessageToTop(MessageType _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
