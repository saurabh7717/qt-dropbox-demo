/****************************************************************************
** Meta object code from reading C++ file 'qdbox.h'
**
** Created: Mon Jul 22 17:23:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qdbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qdbox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,    6,    6,    6, 0x0a,
      61,    6,    6,    6, 0x0a,
      93,    6,    6,    6, 0x0a,
     128,    6,    6,    6, 0x0a,
     163,    6,    6,    6, 0x0a,
     200,    6,    6,    6, 0x0a,
     235,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qdbox[] = {
    "qdbox\0\0finished(QNetworkReply*)\0"
    "slotFinished(QNetworkReply*)\0"
    "urlslotFinished(QNetworkReply*)\0"
    "accessslotFinished(QNetworkReply*)\0"
    "uploadslotFinished(QNetworkReply*)\0"
    "createFolderFinished(QNetworkReply*)\0"
    "listFolderFinished(QNetworkReply*)\0"
    "accountInfoFinished(QNetworkReply*)\0"
};

void qdbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qdbox *_t = static_cast<qdbox *>(_o);
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->slotFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->urlslotFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->accessslotFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->uploadslotFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->createFolderFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->listFolderFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->accountInfoFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qdbox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qdbox::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qdbox,
      qt_meta_data_qdbox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qdbox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qdbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qdbox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qdbox))
        return static_cast<void*>(const_cast< qdbox*>(this));
    return QObject::qt_metacast(_clname);
}

int qdbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void qdbox::finished(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
