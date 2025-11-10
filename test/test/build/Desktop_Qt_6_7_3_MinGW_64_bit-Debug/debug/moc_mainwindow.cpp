/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_connecter_clicked",
    "",
    "on_Modifier_Employe_clicked",
    "on_Ajouter_Employe_clicked",
    "on_Supprimer_Employe_clicked",
    "clearChamps",
    "remplirTable",
    "QSqlQuery&",
    "query",
    "afficherEmployes",
    "on_tableWidgetEmployes_cellClicked",
    "row",
    "column",
    "on_Rechercher_Employe_2_clicked",
    "afficherTableResidence",
    "on_Ajouter_Residence_clicked",
    "on_Modifier_Residence_clicked",
    "on_Supprimer_Residence_clicked",
    "on_Ajouter_Service_clicked",
    "afficherServices",
    "on_Modifier_Service_clicked",
    "on_Supprimer_Service_clicked",
    "on_rechercher_Service_clicked",
    "on_tableServices_cellActivated",
    "trierServices",
    "index",
    "viderChamps",
    "on_Ajouter_Resident_clicked",
    "on_Supprimer_Resident_clicked",
    "on_Modifier_resident_clicked",
    "on_Rechercher_Resident_textChanged",
    "arg1",
    "on_comboBox_tri_Resident_currentIndexChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x08,    1 /* Private */,
       3,    0,  171,    2, 0x08,    2 /* Private */,
       4,    0,  172,    2, 0x08,    3 /* Private */,
       5,    0,  173,    2, 0x08,    4 /* Private */,
       6,    0,  174,    2, 0x08,    5 /* Private */,
       7,    1,  175,    2, 0x08,    6 /* Private */,
      10,    0,  178,    2, 0x08,    8 /* Private */,
      11,    2,  179,    2, 0x08,    9 /* Private */,
      14,    0,  184,    2, 0x08,   12 /* Private */,
      15,    0,  185,    2, 0x08,   13 /* Private */,
      16,    0,  186,    2, 0x08,   14 /* Private */,
      17,    0,  187,    2, 0x08,   15 /* Private */,
      18,    0,  188,    2, 0x08,   16 /* Private */,
      19,    0,  189,    2, 0x08,   17 /* Private */,
      20,    0,  190,    2, 0x08,   18 /* Private */,
      21,    0,  191,    2, 0x08,   19 /* Private */,
      22,    0,  192,    2, 0x08,   20 /* Private */,
      23,    0,  193,    2, 0x08,   21 /* Private */,
      24,    2,  194,    2, 0x08,   22 /* Private */,
      25,    1,  199,    2, 0x08,   25 /* Private */,
      27,    0,  202,    2, 0x08,   27 /* Private */,
      28,    0,  203,    2, 0x08,   28 /* Private */,
      29,    0,  204,    2, 0x08,   29 /* Private */,
      30,    0,  205,    2, 0x08,   30 /* Private */,
      31,    1,  206,    2, 0x08,   31 /* Private */,
      33,    1,  209,    2, 0x08,   33 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_connecter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_Employe_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Ajouter_Employe_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_Employe_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearChamps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'remplirTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlQuery &, std::false_type>,
        // method 'afficherEmployes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidgetEmployes_cellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Rechercher_Employe_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherTableResidence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Ajouter_Residence_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_Residence_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_Residence_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Ajouter_Service_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherServices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_Service_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_Service_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rechercher_Service_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableServices_cellActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'trierServices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'viderChamps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Ajouter_Resident_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_Resident_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_resident_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Rechercher_Resident_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_tri_Resident_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_connecter_clicked(); break;
        case 1: _t->on_Modifier_Employe_clicked(); break;
        case 2: _t->on_Ajouter_Employe_clicked(); break;
        case 3: _t->on_Supprimer_Employe_clicked(); break;
        case 4: _t->clearChamps(); break;
        case 5: _t->remplirTable((*reinterpret_cast< std::add_pointer_t<QSqlQuery&>>(_a[1]))); break;
        case 6: _t->afficherEmployes(); break;
        case 7: _t->on_tableWidgetEmployes_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->on_Rechercher_Employe_2_clicked(); break;
        case 9: _t->afficherTableResidence(); break;
        case 10: _t->on_Ajouter_Residence_clicked(); break;
        case 11: _t->on_Modifier_Residence_clicked(); break;
        case 12: _t->on_Supprimer_Residence_clicked(); break;
        case 13: _t->on_Ajouter_Service_clicked(); break;
        case 14: _t->afficherServices(); break;
        case 15: _t->on_Modifier_Service_clicked(); break;
        case 16: _t->on_Supprimer_Service_clicked(); break;
        case 17: _t->on_rechercher_Service_clicked(); break;
        case 18: _t->on_tableServices_cellActivated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 19: _t->trierServices((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->viderChamps(); break;
        case 21: _t->on_Ajouter_Resident_clicked(); break;
        case 22: _t->on_Supprimer_Resident_clicked(); break;
        case 23: _t->on_Modifier_resident_clicked(); break;
        case 24: _t->on_Rechercher_Resident_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_comboBox_tri_Resident_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
