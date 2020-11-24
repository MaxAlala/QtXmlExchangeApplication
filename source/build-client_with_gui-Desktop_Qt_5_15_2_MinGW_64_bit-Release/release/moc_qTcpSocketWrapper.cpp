/****************************************************************************
** Meta object code from reading C++ file 'qTcpSocketWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../client_with_gui/qTcpSocketWrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTcpSocketWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTcpSocketWrapper_t {
    QByteArrayData data[10];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTcpSocketWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTcpSocketWrapper_t qt_meta_stringdata_QTcpSocketWrapper = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QTcpSocketWrapper"
QT_MOC_LITERAL(1, 18, 13), // "destroyThread"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "sendMessageToTop"
QT_MOC_LITERAL(4, 50, 11), // "MessageType"
QT_MOC_LITERAL(5, 62, 11), // "messageType"
QT_MOC_LITERAL(6, 74, 7), // "message"
QT_MOC_LITERAL(7, 82, 12), // "disconnected"
QT_MOC_LITERAL(8, 95, 19), // "getMessageForBottom"
QT_MOC_LITERAL(9, 115, 9) // "readyRead"

    },
    "QTcpSocketWrapper\0destroyThread\0\0"
    "sendMessageToTop\0MessageType\0messageType\0"
    "message\0disconnected\0getMessageForBottom\0"
    "readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTcpSocketWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x0a /* Public */,
       8,    2,   59,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x2a /* Public | MethodCloned */,
       9,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    5,    6,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    5,    6,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void QTcpSocketWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTcpSocketWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->destroyThread(); break;
        case 1: _t->sendMessageToTop((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->sendMessageToTop((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 3: _t->disconnected(); break;
        case 4: _t->getMessageForBottom((*reinterpret_cast< MessageType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->getMessageForBottom((*reinterpret_cast< MessageType(*)>(_a[1]))); break;
        case 6: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTcpSocketWrapper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTcpSocketWrapper::destroyThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QTcpSocketWrapper::*)(MessageType , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTcpSocketWrapper::sendMessageToTop)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTcpSocketWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_meta_stringdata_QTcpSocketWrapper.data,
    qt_meta_data_QTcpSocketWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTcpSocketWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTcpSocketWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTcpSocketWrapper.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int QTcpSocketWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QTcpSocketWrapper::destroyThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QTcpSocketWrapper::sendMessageToTop(MessageType _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
