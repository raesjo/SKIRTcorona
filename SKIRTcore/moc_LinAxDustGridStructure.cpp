/****************************************************************************
** Meta object code from reading C++ file 'LinAxDustGridStructure.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../git/SKIRTcore/LinAxDustGridStructure.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LinAxDustGridStructure.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LinAxDustGridStructure_t {
    QByteArrayData data[27];
    char stringdata[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinAxDustGridStructure_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinAxDustGridStructure_t qt_meta_stringdata_LinAxDustGridStructure = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 5),
QT_MOC_LITERAL(2, 29, 55),
QT_MOC_LITERAL(3, 85, 8),
QT_MOC_LITERAL(4, 94, 12),
QT_MOC_LITERAL(5, 107, 40),
QT_MOC_LITERAL(6, 148, 8),
QT_MOC_LITERAL(7, 157, 6),
QT_MOC_LITERAL(8, 164, 8),
QT_MOC_LITERAL(9, 173, 1),
QT_MOC_LITERAL(10, 175, 12),
QT_MOC_LITERAL(11, 188, 32),
QT_MOC_LITERAL(12, 221, 1),
QT_MOC_LITERAL(13, 223, 8),
QT_MOC_LITERAL(14, 232, 6),
QT_MOC_LITERAL(15, 239, 7),
QT_MOC_LITERAL(16, 247, 3),
QT_MOC_LITERAL(17, 251, 11),
QT_MOC_LITERAL(18, 263, 39),
QT_MOC_LITERAL(19, 303, 11),
QT_MOC_LITERAL(20, 315, 31),
QT_MOC_LITERAL(21, 347, 15),
QT_MOC_LITERAL(22, 363, 0),
QT_MOC_LITERAL(23, 364, 5),
QT_MOC_LITERAL(24, 370, 15),
QT_MOC_LITERAL(25, 386, 14),
QT_MOC_LITERAL(26, 401, 14)
    },
    "LinAxDustGridStructure\0Title\0"
    "a cylindrical grid structure with a linear distribution\0"
    "Property\0radialExtent\0"
    "the outer radius in the radial direction\0"
    "Quantity\0length\0MinValue\0""0\0radialPoints\0"
    "the number of radial grid points\0""5\0"
    "MaxValue\0""100000\0Default\0""250\0axialExtent\0"
    "the outer radius in the axial direction\0"
    "axialPoints\0the number of axial grid points\0"
    "setRadialExtent\0\0value\0setRadialPoints\0"
    "setAxialExtent\0setAxialPoints"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinAxDustGridStructure[] = {

 // content:
       7,       // revision
       0,       // classname
      19,   14, // classinfo
       8,   52, // methods
       0,    0, // properties
       0,    0, // enums/sets
       1,  109, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,
       1,    5,
       6,    7,
       8,    9,
       3,   10,
       1,   11,
       8,   12,
      13,   14,
      15,   16,
       3,   17,
       1,   18,
       6,    7,
       8,    9,
       3,   19,
       1,   20,
       8,   12,
      13,   14,
      15,   16,

 // methods: name, argc, parameters, tag, flags
      21,    1,   92,   22, 0x02 /* Public */,
       4,    0,   95,   22, 0x02 /* Public */,
      24,    1,   96,   22, 0x02 /* Public */,
      10,    0,   99,   22, 0x02 /* Public */,
      25,    1,  100,   22, 0x02 /* Public */,
      17,    0,  103,   22, 0x02 /* Public */,
      26,    1,  104,   22, 0x02 /* Public */,
      19,    0,  107,   22, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Int,

 // constructors: parameters
    0x80000000 | 22,

 // constructors: name, argc, parameters, tag, flags
       0,    0,  108,   22, 0x0e /* Public */,

       0        // eod
};

void LinAxDustGridStructure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { LinAxDustGridStructure *_r = new LinAxDustGridStructure();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        LinAxDustGridStructure *_t = static_cast<LinAxDustGridStructure *>(_o);
        switch (_id) {
        case 0: _t->setRadialExtent((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: { double _r = _t->radialExtent();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 2: _t->setRadialPoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->radialPoints();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->setAxialExtent((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: { double _r = _t->axialExtent();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: _t->setAxialPoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: { int _r = _t->axialPoints();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LinAxDustGridStructure::staticMetaObject = {
    { &AxDustGridStructure::staticMetaObject, qt_meta_stringdata_LinAxDustGridStructure.data,
      qt_meta_data_LinAxDustGridStructure,  qt_static_metacall, 0, 0}
};


const QMetaObject *LinAxDustGridStructure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinAxDustGridStructure::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LinAxDustGridStructure.stringdata))
        return static_cast<void*>(const_cast< LinAxDustGridStructure*>(this));
    return AxDustGridStructure::qt_metacast(_clname);
}

int LinAxDustGridStructure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AxDustGridStructure::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
