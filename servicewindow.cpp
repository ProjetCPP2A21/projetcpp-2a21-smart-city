#include "widget.h"          // Inclusion de notre classe principale
#include "ui_widget.h"       // Interface graphique générée automatiquement par Qt Designer
#include "servicec.h"        // Classe qui contient les fonctions CRUD
#include <QMessageBox>       // Pour afficher les boîtes de dialogue (messages à l’utilisateur)

// ============================================================================
// Constructeur de la classe Widget
// ============================================================================
// Cette fonction est appelée automatiquement au démarrage du programme.
// Elle initialise l’interface et affiche les données existantes dans la table.
// ============================================================================
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); // Chargement de l’interface graphique (widget.ui)

    // Création d’un objet temporaire de type ServiceC
    ServiceC tmp;

    // Affichage de la liste des services existants dans la base de données
    ui->tableView->setModel(tmp.afficher());
}

// ============================================================================
// Destructeur : libère la mémoire occupée par l’interface (Qt la gère automatiquement)
// ============================================================================
Widget::~Widget()
{
    delete ui;
}

// ============================================================================
// Fonction : on_ajouterButton_clicked()
// ---------------------------------------------------------------------------
// Cette fonction est exécutée automatiquement lorsque l’utilisateur clique
// sur le bouton “Ajouter” dans l’interface graphique.
// Elle récupère les valeurs saisies dans les champs et appelle la méthode
// ajouter() de la classe ServiceC pour insérer un nouveau service.
// ============================================================================
void Widget::on_ajouterButton_clicked()
{
    // Récupération des données saisies dans les champs de texte
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();
    double cout = ui->lineEdit_cout->text().toDouble();

    // Création d’un objet ServiceC avec les valeurs récupérées
    ServiceC s(id, nom, type, cout);

    // Appel de la méthode ajouter() pour insérer le service dans la base
    bool test = s.ajouter();

    // Vérification du résultat et affichage d’un message approprié
    if (test) {
        QMessageBox::information(this, "Ajout", "✅ Service ajouté avec succès !");
        ui->tableView->setModel(s.afficher()); // Actualiser le tableau
    } else {
        QMessageBox::warning(this, "Erreur", "❌ Échec de l’ajout du service !");
    }
}

// ============================================================================
// Fonction : on_supprimerButton_clicked()
// ---------------------------------------------------------------------------
// Supprime un service de la base de données selon l’ID saisi.
// ============================================================================
void Widget::on_supprimerButton_clicked()
{
    // Récupération de l’identifiant saisi
    int id = ui->lineEdit_id->text().toInt();

    // Création d’un objet ServiceC vide (on utilise juste la méthode supprimer)
    ServiceC s;

    // Appel de la fonction de suppression
    bool test = s.supprimer(id);

    // Message selon le résultat
    if (test) {
        QMessageBox::information(this, "Suppression", "🗑️ Service supprimé avec succès !");
        ui->tableView->setModel(s.afficher()); // Mise à jour du tableau
    } else {
        QMessageBox::warning(this, "Erreur", "⚠️ Échec de la suppression !");
    }
}

// ============================================================================
// Fonction : on_modifierButton_clicked()
// ---------------------------------------------------------------------------
// Met à jour les informations d’un service existant dans la base de données.
// ============================================================================
void Widget::on_modifierButton_clicked()
{
    // Récupération des nouvelles valeurs
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();
    double cout = ui->lineEdit_cout->text().toDouble();

    // Création d’un objet ServiceC contenant les nouvelles données
    ServiceC s(id, nom, type, cout);

    // Appel de la méthode modifier()
    bool test = s.modifier();

    // Message selon le résultat
    if (test) {
        QMessageBox::information(this, "Modification", "✏️ Service modifié avec succès !");
        ui->tableView->setModel(s.afficher()); // Rafraîchissement du tableau
    } else {
        QMessageBox::warning(this, "Erreur", "❌ Échec de la modification !");
    }
}

// ============================================================================
// Fonction : on_afficherButton_clicked()
// ---------------------------------------------------------------------------
// Affiche la liste complète des services dans la table (rafraîchissement).
// ============================================================================
void Widget::on_afficherButton_clicked()
{
    ServiceC s;
    ui->tableView->setModel(s.afficher());
}
