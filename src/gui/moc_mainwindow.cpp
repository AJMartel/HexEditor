/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     204,  197,   11,   11, 0x08,
     229,  197,   11,   11, 0x08,
     258,  197,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0Info()\0on_ActionOpen_triggered()\0"
    "on_pushButton_clicked()\0"
    "on_actionZamknij_triggered()\0"
    "on_OpenParser_clicked()\0on_OpenBinary_clicked()\0"
    "on_ColsSpin_changed(int)\0"
    "on_ChangeTab_changed(int)\0tabNum\0"
    "on_CloseTab_request(int)\0"
    "on_CloseTabEdit_request(int)\0"
    "on_ChangeTabEdit_changed(int)\0"
    "SaveBinary()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->Info(); break;
        case 1: _t->on_ActionOpen_triggered(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_actionZamknij_triggered(); break;
        case 4: _t->on_OpenParser_clicked(); break;
        case 5: _t->on_OpenBinary_clicked(); break;
        case 6: _t->on_ColsSpin_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_ChangeTab_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_CloseTab_request((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_CloseTabEdit_request((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_ChangeTabEdit_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->SaveBinary(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
