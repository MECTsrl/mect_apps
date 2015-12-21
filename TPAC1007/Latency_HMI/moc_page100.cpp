/****************************************************************************
** Meta object code from reading C++ file 'page100.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "page100.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page100.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_page100[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_page100[] = {
    "page100\0\0event\0changeEvent(QEvent*)\0"
};

void page100::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        page100 *_t = static_cast<page100 *>(_o);
        switch (_id) {
        case 0: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData page100::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject page100::staticMetaObject = {
    { &page::staticMetaObject, qt_meta_stringdata_page100,
      qt_meta_data_page100, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &page100::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *page100::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *page100::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_page100))
        return static_cast<void*>(const_cast< page100*>(this));
    return page::qt_metacast(_clname);
}

int page100::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = page::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
