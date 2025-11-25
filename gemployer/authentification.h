#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>

// Nécessaire pour faire référence à 'Ui::Authentification'
namespace Ui {
class Authentification;
}

class Authentification : public QDialog
{
    Q_OBJECT

public:
    explicit Authentification(QWidget *parent = nullptr);
    ~Authentification();

private slots:
    // Ces slots sont connectés automatiquement par Qt
    // grâce à leur nom (on_NOMDUWIDGET_SIGNAL)

    // Slots pour la logique métier
    void on_pushButtonLogin_clicked();
    void on_pushButtonCreer_clicked();
    void on_pushButtonReset_clicked();

    // Slots pour la navigation
    void on_pushButtonGoToCreer_clicked();
    void on_pushButtonGoToMdp_clicked();
    void on_pushButtonRetourLogin_1_clicked();
    void on_pushButtonRetourLogin_2_clicked();

private:
    Ui::Authentification *ui;

    // Fonction privée pour hacher les mots de passe
    QString hashPassword(const QString &password);

    // Fonction pour vider les champs
    void clearFields();
};

#endif // AUTHENTIFICATION_H
