#ifndef GEMPLOYER_H
#define GEMPLOYER_H

#include <QMainWindow>
#include <QSqlQuery> // Important pour le type QSqlQuery

QT_BEGIN_NAMESPACE
namespace Ui { class GEmployer; }
QT_END_NAMESPACE

class GEmployer : public QMainWindow
{
    Q_OBJECT

public:
    GEmployer(QWidget *parent = nullptr);
    ~GEmployer();

private slots:
    // --- Slots du Login / Création / MDP ---
    void onLoginClicked();
    void on_pushButtonCreer_clicked();
    void on_pushButtonReset_clicked();

    // --- Slots du CRUD ---
    void onAjouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onRechercherClicked();
    void onTableEmployeClicked(int row, int column);

    // --- Slots de Navigation ---
    void on_pushButtonGoToCreer_clicked();
    void on_pushButtonGoToMdp_clicked();
    void on_pushButtonRetourLogin_clicked();
    void on_pushButtonRetourLogin_2_clicked();
    void on_pushButtonRetourLogin_3_cliked();

    // ===============================================
    // AJOUT : NOUVEAUX SLOTS (Tri, Export, Stats)
    // ===============================================
    void onTrierClicked();
    void onExporterClicked();
    void onStatistiquesClicked();
    void on_pushButtonValiderReset_clicked();
    void on_pushButtonSuivant_clicked();

    void on_pushButtonRetourLogin_3_clicked();

    void on_quitter_clicked();

private:
    Ui::GEmployer *ui;

    // --- Fonctions internes (Helpers) ---
    QString hashPassword(const QString &password);
    void afficherEmployes();
    void remplirTable(QSqlQuery &query);
    void goToPage(QWidget *page);
    void clearChamps();
    QString codeVerificationGenere; // Le code envoyé par mail
    QString idUtilisateurEnCours;

};
#endif // GEMPLOYER_H
