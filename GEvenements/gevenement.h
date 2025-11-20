#ifndef GEVENEMENT_H
#define GEVENEMENT_H
#include "connection.h"
#include "evenement.h"
#include <QMainWindow>
#include <QWidget>
#include <QQuickWidget>
#include <QMap>
#include <QPointF>
#include <QQuickView>
#include <QGeoCodingManager>
#include <QGeoServiceProvider>


QT_BEGIN_NAMESPACE
namespace Ui {
class GEvenement;
}
QT_END_NAMESPACE

class GEvenement : public QMainWindow
{
    Q_OBJECT

public:
    GEvenement(QWidget *parent = nullptr);
    ~GEvenement();

private slots:


    void on_Ajouterbutton_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    //void on_Rechercher_clicked();
    // metiers
    void on_Prediction_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_comboBox_currentIndexChanged(int index);
    void on_Recherche_Line_textChanged(const QString &text);
    void on_Excel_clicked();

    void on_Statistiques_2_clicked();

    void on_Localiser_clicked();

private:
    Ui::GEvenement *ui;
    Evenement E;
     QMap<QString, QPointF> lieuCoords;
    QQuickView *mapView;
    QGeoCodingManager *geoCoder;
    QObject *rootMapObject;



};
#endif // GEVENEMENT_H
