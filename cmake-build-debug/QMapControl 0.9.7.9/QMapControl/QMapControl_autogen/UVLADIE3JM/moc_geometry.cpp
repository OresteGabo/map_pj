/****************************************************************************
** Meta object code from reading C++ file 'geometry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../QMapControl 0.9.7.9/QMapControl/src/geometry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geometry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qmapcontrol__Geometry_t {
    QByteArrayData data[12];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qmapcontrol__Geometry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qmapcontrol__Geometry_t qt_meta_stringdata_qmapcontrol__Geometry = {
    {
QT_MOC_LITERAL(0, 0, 21), // "qmapcontrol::Geometry"
QT_MOC_LITERAL(1, 22, 13), // "updateRequest"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "Geometry*"
QT_MOC_LITERAL(4, 47, 4), // "geom"
QT_MOC_LITERAL(5, 52, 4), // "rect"
QT_MOC_LITERAL(6, 57, 15), // "geometryClicked"
QT_MOC_LITERAL(7, 73, 8), // "geometry"
QT_MOC_LITERAL(8, 82, 5), // "point"
QT_MOC_LITERAL(9, 88, 15), // "positionChanged"
QT_MOC_LITERAL(10, 104, 10), // "setVisible"
QT_MOC_LITERAL(11, 115, 7) // "visible"

    },
    "qmapcontrol::Geometry\0updateRequest\0"
    "\0Geometry*\0geom\0rect\0geometryClicked\0"
    "geometry\0point\0positionChanged\0"
    "setVisible\0visible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qmapcontrol__Geometry[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    1,   42,    2, 0x06 /* Public */,
       6,    2,   45,    2, 0x06 /* Public */,
       9,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QRectF,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint,    7,    8,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void qmapcontrol::Geometry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Geometry *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateRequest((*reinterpret_cast< Geometry*(*)>(_a[1]))); break;
        case 1: _t->updateRequest((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 2: _t->geometryClicked((*reinterpret_cast< Geometry*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 3: _t->positionChanged((*reinterpret_cast< Geometry*(*)>(_a[1]))); break;
        case 4: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Geometry* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Geometry* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Geometry* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Geometry::*)(Geometry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Geometry::updateRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Geometry::*)(QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Geometry::updateRequest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Geometry::*)(Geometry * , QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Geometry::geometryClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Geometry::*)(Geometry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Geometry::positionChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qmapcontrol::Geometry::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qmapcontrol__Geometry.data,
    qt_meta_data_qmapcontrol__Geometry,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qmapcontrol::Geometry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qmapcontrol::Geometry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__Geometry.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qmapcontrol::Geometry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qmapcontrol::Geometry::updateRequest(Geometry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qmapcontrol::Geometry::updateRequest(QRectF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qmapcontrol::Geometry::geometryClicked(Geometry * _t1, QPoint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qmapcontrol::Geometry::positionChanged(Geometry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
