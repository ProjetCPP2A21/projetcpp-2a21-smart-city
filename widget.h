#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModelIndex>

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

private:
    Ui::Widget *ui;
    void viderChamps();
    void remplirTableau();
};

#endif // WIDGET_H
