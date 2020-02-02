/****************************************************************************
** Meta object code from reading C++ file 'QHttpNet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../YQ/QHttpNet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHttpNet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QHttpNet_t {
    QByteArrayData data[16];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QHttpNet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QHttpNet_t qt_meta_stringdata_QHttpNet = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QHttpNet"
QT_MOC_LITERAL(1, 9, 11), // "LoginSignal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "LOGIN_ERROR"
QT_MOC_LITERAL(4, 34, 12), // "login_state_"
QT_MOC_LITERAL(5, 47, 11), // "Slots_Reply"
QT_MOC_LITERAL(6, 59, 15), // "Slots_WriteFile"
QT_MOC_LITERAL(7, 75, 18), // "Slots_ShowProgress"
QT_MOC_LITERAL(8, 94, 6), // "data_1"
QT_MOC_LITERAL(9, 101, 6), // "data_2"
QT_MOC_LITERAL(10, 108, 20), // "Slots_DownloadFinish"
QT_MOC_LITERAL(11, 129, 25), // "Slots_PostRequestFinished"
QT_MOC_LITERAL(12, 155, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 170, 6), // "reply_"
QT_MOC_LITERAL(14, 177, 24), // "Slots_GetRequestFinished"
QT_MOC_LITERAL(15, 202, 19) // "Slots_TimerCheckRes"

    },
    "QHttpNet\0LoginSignal\0\0LOGIN_ERROR\0"
    "login_state_\0Slots_Reply\0Slots_WriteFile\0"
    "Slots_ShowProgress\0data_1\0data_2\0"
    "Slots_DownloadFinish\0Slots_PostRequestFinished\0"
    "QNetworkReply*\0reply_\0Slots_GetRequestFinished\0"
    "Slots_TimerCheckRes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHttpNet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    2,   59,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,
      14,    1,   68,    2, 0x08 /* Private */,
      15,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void QHttpNet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QHttpNet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoginSignal((*reinterpret_cast< LOGIN_ERROR(*)>(_a[1]))); break;
        case 1: _t->Slots_Reply(); break;
        case 2: _t->Slots_WriteFile(); break;
        case 3: _t->Slots_ShowProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->Slots_DownloadFinish(); break;
        case 5: _t->Slots_PostRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->Slots_GetRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->Slots_TimerCheckRes(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QHttpNet::*)(LOGIN_ERROR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QHttpNet::LoginSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QHttpNet::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QHttpNet.data,
    qt_meta_data_QHttpNet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QHttpNet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpNet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QHttpNet.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttpNet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QHttpNet::LoginSignal(LOGIN_ERROR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
