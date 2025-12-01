/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
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
    "onLoginClicked",
    "",
    "on_pushButtonReset_clicked",
    "on_Ajouter_Employe_Clicked",
    "on_Modifier_Employe_Clicked",
    "on_Supprimer_Employe_Clicked",
    "onRechercherClicked",
    "ontableWidgetEmployesClicked",
    "row",
    "column",
    "on_pushButtonGoToMdp_clicked",
    "on_pushButtonRetourLogin_clicked",
    "on_pushButtonRetourLogin_2_clicked",
    "on_pushButtonRetourLogin_3_cliked",
    "onTrierClicked",
    "onExporterClicked",
    "onStatistiquesClicked",
    "on_pushButtonValiderReset_clicked",
    "on_pushButtonSuivant_clicked",
    "clearChamps",
    "on_pushButtonRetourLogin_3_clicked",
    "remplirTable",
    "QSqlQuery&",
    "query",
    "afficherEmployes",
    "on_quitter_clicked",
    "afficherTableResidence",
    "on_Ajouter_Residence_clicked",
    "on_Modifier_Residence_clicked",
    "on_Supprimer_Residence_clicked",
    "on_recherche_clicked",
    "on_statistique_clicked",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "on_trie_clicked",
    "on_exporter_clicked",
    "handlePopupTimer",
    "goToPage",
    "QWidget*",
    "page",
    "on_btn_ajouter_clicked",
    "on_btn_modifier_clicked",
    "on_btn_supprimer_clicked",
    "on_recherche_residents_textChanged",
    "arg1",
    "on_btn_statistiques_clicked",
    "afficherStatistiques",
    "on_btnExportPDF_clicked",
    "on_comboBox_tri_currentIndexChanged",
    "index",
    "on_tableView_clicked",
    "QModelIndex",
    "clearFields",
    "calculerStabilite",
    "age",
    "profession",
    "situation",
    "calculerMobilite",
    "ajouterService",
    "modifierService",
    "supprimerService",
    "afficherServices",
    "rechercherService",
    "selectionnerService",
    "trierServices",
    "afficherStatistiques_Services",
    "on_btnExportPDF_Services_clicked",
    "rechercheSmart",
    "onGpsProcessFinished",
    "exitCode",
    "QProcess::ExitStatus",
    "exitStatus",
    "on_Ajouterbutton_clicked",
    "on_Supprimer_clicked",
    "on_Modifier_clicked",
    "on_Prediction_clicked",
    "on_tableView_Evenement_clicked",
    "on_comboBox_currentIndexChanged",
    "on_Recherche_Line_textChanged",
    "text",
    "on_Excel_clicked",
    "on_Statistiques_Evenement_clicked",
    "on_Localiser_clicked",
    "on_btnItineraire_clicked"
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
      66,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  410,    2, 0x08,    1 /* Private */,
       3,    0,  411,    2, 0x08,    2 /* Private */,
       4,    0,  412,    2, 0x08,    3 /* Private */,
       5,    0,  413,    2, 0x08,    4 /* Private */,
       6,    0,  414,    2, 0x08,    5 /* Private */,
       7,    0,  415,    2, 0x08,    6 /* Private */,
       8,    2,  416,    2, 0x08,    7 /* Private */,
      11,    0,  421,    2, 0x08,   10 /* Private */,
      12,    0,  422,    2, 0x08,   11 /* Private */,
      13,    0,  423,    2, 0x08,   12 /* Private */,
      14,    0,  424,    2, 0x08,   13 /* Private */,
      15,    0,  425,    2, 0x08,   14 /* Private */,
      16,    0,  426,    2, 0x08,   15 /* Private */,
      17,    0,  427,    2, 0x08,   16 /* Private */,
      18,    0,  428,    2, 0x08,   17 /* Private */,
      19,    0,  429,    2, 0x08,   18 /* Private */,
      20,    0,  430,    2, 0x08,   19 /* Private */,
      21,    0,  431,    2, 0x08,   20 /* Private */,
      22,    1,  432,    2, 0x08,   21 /* Private */,
      25,    0,  435,    2, 0x08,   23 /* Private */,
      26,    0,  436,    2, 0x08,   24 /* Private */,
      27,    0,  437,    2, 0x08,   25 /* Private */,
      28,    0,  438,    2, 0x08,   26 /* Private */,
      29,    0,  439,    2, 0x08,   27 /* Private */,
      30,    0,  440,    2, 0x08,   28 /* Private */,
      31,    0,  441,    2, 0x08,   29 /* Private */,
      32,    0,  442,    2, 0x08,   30 /* Private */,
      33,    1,  443,    2, 0x08,   31 /* Private */,
      36,    0,  446,    2, 0x08,   33 /* Private */,
      37,    0,  447,    2, 0x08,   34 /* Private */,
      38,    0,  448,    2, 0x08,   35 /* Private */,
      39,    1,  449,    2, 0x08,   36 /* Private */,
      42,    0,  452,    2, 0x08,   38 /* Private */,
      43,    0,  453,    2, 0x08,   39 /* Private */,
      44,    0,  454,    2, 0x08,   40 /* Private */,
      45,    1,  455,    2, 0x08,   41 /* Private */,
      47,    0,  458,    2, 0x08,   43 /* Private */,
      48,    0,  459,    2, 0x08,   44 /* Private */,
      49,    0,  460,    2, 0x08,   45 /* Private */,
      50,    1,  461,    2, 0x08,   46 /* Private */,
      52,    1,  464,    2, 0x08,   48 /* Private */,
      54,    0,  467,    2, 0x08,   50 /* Private */,
      55,    3,  468,    2, 0x08,   51 /* Private */,
      59,    3,  475,    2, 0x08,   55 /* Private */,
      60,    0,  482,    2, 0x08,   59 /* Private */,
      61,    0,  483,    2, 0x08,   60 /* Private */,
      62,    0,  484,    2, 0x08,   61 /* Private */,
      63,    0,  485,    2, 0x08,   62 /* Private */,
      64,    0,  486,    2, 0x08,   63 /* Private */,
      65,    2,  487,    2, 0x08,   64 /* Private */,
      66,    1,  492,    2, 0x08,   67 /* Private */,
      67,    0,  495,    2, 0x08,   69 /* Private */,
      68,    0,  496,    2, 0x08,   70 /* Private */,
      69,    0,  497,    2, 0x08,   71 /* Private */,
      70,    2,  498,    2, 0x08,   72 /* Private */,
      74,    0,  503,    2, 0x08,   75 /* Private */,
      75,    0,  504,    2, 0x08,   76 /* Private */,
      76,    0,  505,    2, 0x08,   77 /* Private */,
      77,    0,  506,    2, 0x08,   78 /* Private */,
      78,    1,  507,    2, 0x08,   79 /* Private */,
      79,    1,  510,    2, 0x08,   81 /* Private */,
      80,    1,  513,    2, 0x08,   83 /* Private */,
      82,    0,  516,    2, 0x08,   85 /* Private */,
      83,    0,  517,    2, 0x08,   86 /* Private */,
      84,    0,  518,    2, 0x08,   87 /* Private */,
      85,    0,  519,    2, 0x08,   88 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, 0x80000000 | 53,   51,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   56,   57,   58,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   56,   57,   58,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 72,   71,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53,   51,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, QMetaType::QString,   81,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'onLoginClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonReset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Ajouter_Employe_Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_Employe_Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_Employe_Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRechercherClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ontableWidgetEmployesClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButtonGoToMdp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRetourLogin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRetourLogin_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRetourLogin_3_cliked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTrierClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExporterClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStatistiquesClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonValiderReset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSuivant_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearChamps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRetourLogin_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'remplirTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlQuery &, std::false_type>,
        // method 'afficherEmployes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_quitter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherTableResidence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Ajouter_Residence_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_Residence_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_Residence_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_recherche_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statistique_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>,
        // method 'on_trie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exporter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePopupTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goToPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'on_btn_ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_recherche_residents_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_btn_statistiques_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiques'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnExportPDF_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_tri_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'clearFields'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'calculerStabilite'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'calculerMobilite'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ajouterService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modifierService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'supprimerService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherServices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechercherService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectionnerService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'trierServices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'afficherStatistiques_Services'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnExportPDF_Services_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechercheSmart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGpsProcessFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>,
        // method 'on_Ajouterbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Prediction_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_Evenement_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Recherche_Line_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_Excel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Statistiques_Evenement_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Localiser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnItineraire_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onLoginClicked(); break;
        case 1: _t->on_pushButtonReset_clicked(); break;
        case 2: _t->on_Ajouter_Employe_Clicked(); break;
        case 3: _t->on_Modifier_Employe_Clicked(); break;
        case 4: _t->on_Supprimer_Employe_Clicked(); break;
        case 5: _t->onRechercherClicked(); break;
        case 6: _t->ontableWidgetEmployesClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->on_pushButtonGoToMdp_clicked(); break;
        case 8: _t->on_pushButtonRetourLogin_clicked(); break;
        case 9: _t->on_pushButtonRetourLogin_2_clicked(); break;
        case 10: _t->on_pushButtonRetourLogin_3_cliked(); break;
        case 11: _t->onTrierClicked(); break;
        case 12: _t->onExporterClicked(); break;
        case 13: _t->onStatistiquesClicked(); break;
        case 14: _t->on_pushButtonValiderReset_clicked(); break;
        case 15: _t->on_pushButtonSuivant_clicked(); break;
        case 16: _t->clearChamps(); break;
        case 17: _t->on_pushButtonRetourLogin_3_clicked(); break;
        case 18: _t->remplirTable((*reinterpret_cast< std::add_pointer_t<QSqlQuery&>>(_a[1]))); break;
        case 19: _t->afficherEmployes(); break;
        case 20: _t->on_quitter_clicked(); break;
        case 21: _t->afficherTableResidence(); break;
        case 22: _t->on_Ajouter_Residence_clicked(); break;
        case 23: _t->on_Modifier_Residence_clicked(); break;
        case 24: _t->on_Supprimer_Residence_clicked(); break;
        case 25: _t->on_recherche_clicked(); break;
        case 26: _t->on_statistique_clicked(); break;
        case 27: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 28: _t->on_trie_clicked(); break;
        case 29: _t->on_exporter_clicked(); break;
        case 30: _t->handlePopupTimer(); break;
        case 31: _t->goToPage((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 32: _t->on_btn_ajouter_clicked(); break;
        case 33: _t->on_btn_modifier_clicked(); break;
        case 34: _t->on_btn_supprimer_clicked(); break;
        case 35: _t->on_recherche_residents_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->on_btn_statistiques_clicked(); break;
        case 37: _t->afficherStatistiques(); break;
        case 38: _t->on_btnExportPDF_clicked(); break;
        case 39: _t->on_comboBox_tri_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 40: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 41: _t->clearFields(); break;
        case 42: { QString _r = _t->calculerStabilite((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 43: { QString _r = _t->calculerMobilite((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 44: _t->ajouterService(); break;
        case 45: _t->modifierService(); break;
        case 46: _t->supprimerService(); break;
        case 47: _t->afficherServices(); break;
        case 48: _t->rechercherService(); break;
        case 49: _t->selectionnerService((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 50: _t->trierServices((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 51: _t->afficherStatistiques_Services(); break;
        case 52: _t->on_btnExportPDF_Services_clicked(); break;
        case 53: _t->rechercheSmart(); break;
        case 54: _t->onGpsProcessFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 55: _t->on_Ajouterbutton_clicked(); break;
        case 56: _t->on_Supprimer_clicked(); break;
        case 57: _t->on_Modifier_clicked(); break;
        case 58: _t->on_Prediction_clicked(); break;
        case 59: _t->on_tableView_Evenement_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 60: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 61: _t->on_Recherche_Line_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 62: _t->on_Excel_clicked(); break;
        case 63: _t->on_Statistiques_Evenement_clicked(); break;
        case 64: _t->on_Localiser_clicked(); break;
        case 65: _t->on_btnItineraire_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
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
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    }
    return _id;
}
QT_WARNING_POP
