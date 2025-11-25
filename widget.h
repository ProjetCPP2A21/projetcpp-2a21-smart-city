#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModelIndex>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    // Opérations CRUD
    void ajouterService();
    void modifierService();
    void supprimerService();
    void afficherServices();
    void rechercherService();

    // Sélection
    void selectionnerService(int row, int column);

    // Tri
    void trierServices(int index);

    // Statistiques
    void afficherStatistiques();

    // Export PDF
    void on_btnExportPDF_clicked();

    // IA - Optimisation Budget
        // IA suggère si budget est élevé ou faible
    void rechercheSmart();          // recherche intelligente: low priority dépassant budget

private:
    Ui::Widget *ui;

    // Méthodes utilitaires
    void viderChamps();
    void remplirTableau();
    void calculerBudgetPrevu();     // met à jour la colonne Budget prévu
    void calculerPrioriteAuto();    // met à jour la colonne Priorité automatique
    void verifierAnomalies();       // surligne les services dépassant le budget prévu
};

#endif // WIDGET_H
