/****************************************************************************
** Meta object code from reading C++ file 'point.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../QMapControl 0.9.7.9/QMapControl/src/point.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'point.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qmapcontrol__Point_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qmapcontrol__Point_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qmapcontrol__Point_t qt_meta_stringdata_qmapcontrol__Point = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qmapcontrol::Point"
QT_MOC_LITERAL(1, 19, 13), // "setCoordinate"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "point"
QT_MOC_LITERAL(4, 40, 10), // "setVisible"
QT_MOC_LITERAL(5, 51, 7) // "visible"

    },
    "qmapcontrol::Point\0setCoordinate\0\0"
    "point\0setVisible\0visible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qmapcontrol__Point[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void qmapcontrol::Point::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Point *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCoordinate((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qmapcontrol::Point::staticMetaObject = { {
    QMetaObject::SuperData::link<Geometry::staticMetaObject>(),
    qt_meta_stringdata_qmapcontrol__Point.data,
    qt_meta_data_qmapcontrol__Point,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qmapcontrol::Point::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qmapcontrol::Point::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__Point.stringdata0))
        return static_cast<void*>(this);
    return Geometry::qt_metacast(_clname);
}

int qmapcontrol::Point::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Geometry::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
