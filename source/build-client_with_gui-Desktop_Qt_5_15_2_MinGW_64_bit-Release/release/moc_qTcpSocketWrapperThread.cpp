/****************************************************************************
** Meta object code from reading C++ file 'qTcpSocketWrapperThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../client_with_gui/qTcpSocketWrapperThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qTcpSocketWrapperThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTcpSocketWrapperThread_t {
    QByteArrayData data[10];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTcpSocketWrapperThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTcpSocketWrapperThread_t qt_meta_stringdata_QTcpSocketWrapperThread = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QTcpSocketWrapperThread"
QT_MOC_LITERAL(1, 24, 16), // "sendMessageToTop"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 11), // "MessageType"
QT_MOC_LITERAL(4, 54, 11), // "messageType"
QT_MOC_LITERAL(5, 66, 7), // "message"
QT_MOC_LITERAL(6, 74, 19), // "sendMessageToBottom"
QT_MOC_LITERAL(7, 94, 19), // "getMessageForBottom"
QT_MOC_LITERAL(8, 114, 16), // "getMessageForTop"
QT_MOC_LITERAL(9, 131, 18) // "deleteThreadObject"

    },
    "QTcpSocketWrapperThread\0sendMessageToTop\0"
    "\0MessageType\0messageType\0message\0"
    "sendMessageToBottom\0getMessageForBottom\0"
    "getMessageForTop\0deleteThreadObject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTcpSocketWrapperThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       1,    1,   64,    2, 0x26 /* Public | MethodCloned */,
       6,    2,   67,    2, 0x06 /* Public */,
       6,    1,   72,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   75,    2, 0x0a /* Public */,
       7,    1,   80,    2, 0x2a /* Public | MethodCloned */,
       8,    2,   83,    2, 0x0a /* Public */,
       8,    1,   88,    2, 0x2a /* Public | MethodCloned */,
       9,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void QTcpSocketWrapperThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTcpSocketWrapperThread *>(_o);
        Q_UNUSED(_t)
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTcpSocketWrapperThread::*)(MessageType , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTcpSocketWrapperThread::sendMessageToTop)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QTcpSocketWrapperThread::*)(MessageType , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTcpSocketWrapperThread::sendMessageToBottom)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTcpSocketWrapperThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_QTcpSocketWrapperThread.data,
    qt_meta_data_QTcpSocketWrapperThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTcpSocketWrapperThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTcpSocketWrapperThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTcpSocketWrapperThread.stringdata0))
        return static_cast<void*>(this);
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QTcpSocketWrapperThread::sendMessageToTop(MessageType _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void QTcpSocketWrapperThread::sendMessageToBottom(MessageType _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
