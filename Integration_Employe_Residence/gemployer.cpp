#include "employer.h"
#include "gemployer.h"
#include "connection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QRegularExpression>
#include <QCryptographicHash> // <-- AJOUTÉ POUR LA SÉCURITÉ
#include <QByteArray>         // <-- AJOUTÉ POUR LA SÉCURITÉ
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>
#include "smtp.h"              // Pour reconnaitre la classe 'Smtp'
#include <QRandomGenerator>
#include <QFileDialog>  // Pour la fenêtre "Enregistrer sous"
#include <QFile>        // Pour écrire dans un fichier
#include <QTextStream>  // Pour formater le texte du fichier
// ===============================================
//using namespace QtCharts;
#include <QSslSocket>// <-- AJOUTÉ POUR LA VALIDATION

// Définition de la requête SELECT pour garantir l'ordre des colonnes
// L'ordre doit correspondre à vos en-têtes : {"ID", "nom", "prenom", "telephone", "salaire", "Sexe", "Tâche"}
const QString SELECT_QUERY = "SELECT ID_EMPLOYE, NOM, PRENOM, NUMTEL_EMPLOYE, SALAIRE, SEXE_EMPLOYE, RESPONSABILITE FROM EMPLOYER"  ;
// ==================== TABLE ====================
void MainWindow::afficherEmployes() // Modifié
{
    QSqlQuery query(SELECT_QUERY);
    remplirTable(query);
}
// ==================== LOGIN ====================
void MainWindow::on_connecter_clicked()
{

    QString username = ui->Username->text();
    QString password = ui->Motdepasse->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM USERS WHERE USERNAME = :username AND PASSWORD = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la connexion à la base !");
        return;
    }

    if (query.next()) {
        QMessageBox::information(this, "Succès", "Connexion réussie !");
        ui->Ajouter_Employe->setEnabled(true);
        ui->Modifier_Employe->setEnabled(true);
        ui->Supprimer_Employe->setEnabled(true);
        ui->Rechercher_Employe->setEnabled(true);

        // --- CORRECTION NAVIGATION ---
        // Aller au dashboard (page principale), pas à la page de login
        goToPage(ui->page); // Anciennement: ui->stackedWidget->setCurrentWidget(ui->page_2);

        clearChamps();
        afficherEmployes();
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }
}


// ==================== CRUD ====================

// --- MISE À JOUR ---
// Ajout des contrôles de saisie (validation)
void MainWindow::on_Ajouter_Employe_clicked()
{
    // --- 1. Récupérer tous les champs en QString ---
    QString idStr = ui->ID_Employe->text();
    QString salaireStr = ui->Salaire->text();
    QString telephoneStr = ui->Telephone_Employe->text();
    QString nom = ui->Nom_Employe->text();
    QString prenom = ui->Prenom_Employe->text();
    QString sexe = ui->Sexe_Employe->text();
    QString tache = ui->Responsabilite->text();

    // --- 2. Définir les règles de validation (Regex) ---
    QRegularExpression regexID("^[0-9]+$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexTexte("^[a-zA-Z '-]+$");
    QRegularExpression regexSalaire("^[0-9]+$");

    // --- 3. Effectuer les validations ---
    if (idStr.isEmpty() || salaireStr.isEmpty() || telephoneStr.isEmpty() || nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty() || tache.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs doivent être remplis.");
        return;
    }
    if (!regexID.match(idStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID ne doit contenir que des chiffres.");
        return;
    }
    if (!regexTexte.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le Nom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTexte.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le Prénom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTel.match(telephoneStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexSalaire.match(salaireStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le salaire doit être un nombre entier valide.");
        return;
    }
    QString sexeLower = sexe.toLower();
    if (sexeLower != "homme" && sexeLower != "femme") {
        QMessageBox::warning(this, "Erreur de saisie", "Le Sexe doit être 'homme' ou 'femme'.");
        return;
    }
    if (!regexTexte.match(tache).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "La Tâche (Responsabilité) ne doit contenir que des lettres.");
        return;
    }

    // --- 4. Si tout est valide, convertir et créer l'objet ---
    int id = idStr.toInt();
    int salaire = salaireStr.toInt();
    int telephone = telephoneStr.toInt();
    sexe = sexeLower.replace(0, 1, sexeLower.at(0).toUpper()); // Met "Homme" ou "Femme"

    employer e(id, salaire, telephone, nom, prenom, sexe, tache);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout ! (Vérifiez si l'ID existe déjà)");
    }
}


void MainWindow::on_Modifier_Employe_clicked()
{
    // ... (votre code pour modifier est correct)
    // ... (vous pouvez aussi ajouter les validations ici)
    int id = ui->ID_Employe->text().toInt();
    float salaire = ui->Salaire->text().toInt();
    int telephone = ui->Telephone_Employe->text().toInt();
    QString nom = ui->Nom_Employe->text();
    QString prenom = ui->Prenom_Employe->text();
    QString sexe = ui->Sexe_Employe->text();
    QString tache = ui->Responsabilite->text();

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYER SET NOM=?, PRENOM=?, SEXE_EMPLOYE=?, RESPONSABILITE=?, SALAIRE=?, NUMTEL_EMPLOYE=? WHERE ID_EMPLOYE=?");
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(sexe);
    query.addBindValue(tache);
    query.addBindValue(salaire);
    query.addBindValue(telephone);
    query.addBindValue(id);
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
        qDebug() << "Erreur modif:" << query.lastError().text();
    }
}

void MainWindow::on_Supprimer_Employe_clicked()
{
    // ... (votre code pour supprimer est correct)
    int id = ui->ID_Employe->text().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYER WHERE ID_EMPLOYE=?");
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
        qDebug() << "Erreur suppression:" << query.lastError().text();
    }
}

// ==================== TABLE CLICK ====================
void MainWindow::on_tableWidgetEmployes_cellClicked(int row, int column)
{
    // 'column' n'est pas utilisé ici, seule la ligne 'row' nous intéresse
    (void)column;

    // Récupérer les 'items' de la ligne cliquée
    // Nous vérifions si l'item existe (n'est pas nullptr) avant de lire son texte

    QTableWidgetItem *itemID = ui->tableWidgetEmployes_2->item(row, 0);
    QTableWidgetItem *itemNom = ui->tableWidgetEmployes_2->item(row, 1);
    QTableWidgetItem *itemPrenom = ui->tableWidgetEmployes_2->item(row, 2);
    QTableWidgetItem *itemTel = ui->tableWidgetEmployes_2->item(row, 3);
    QTableWidgetItem *itemSalaire = ui->tableWidgetEmployes_2->item(row, 4);
    QTableWidgetItem *itemSexe = ui->tableWidgetEmployes_2->item(row, 5);
    QTableWidgetItem *itemTache = ui->tableWidgetEmployes_2->item(row, 6);

    // Remplir les champs (LineEdits) avec le texte des items

    if (itemID)
        ui->ID_Employe->setText(itemID->text());

    if (itemNom)
        ui->Nom_Employe->setText(itemNom->text());

    if (itemPrenom)
        ui->Prenom_Employe->setText(itemPrenom->text());

    if (itemTel)
        ui->Telephone_Employe->setText(itemTel->text());

    if (itemSalaire)
        ui->Salaire->setText(itemSalaire->text());

    if (itemSexe)
        ui->Sexe_Employe->setText(itemSexe->text());

    if (itemTache)
        ui->Responsabilite->setText(itemTache->text());
}

void MainWindow::on_Rechercher_Employe_2_clicked()
{
    // ... (votre code pour rechercher est correct)
    QString critere = ui->Rechercher_Employe->text();
    QSqlQuery query;

    if (critere.isEmpty()) {
        query.prepare(SELECT_QUERY);
    } else {

        query.prepare(QString("%1 WHERE "
                              "TO_CHAR(ID_EMPLOYE) LIKE :critere OR "
                              "LOWER(NOM) LIKE LOWER(:critere) OR "
                              "LOWER(PRENOM) LIKE LOWER(:critere) OR "
                              "LOWER(SEXE_EMPLOYE) LIKE LOWER(:critere) OR "
                              "LOWER(RESPONSABILITE) LIKE LOWER(:critere)")
                          .arg(SELECT_QUERY));

        query.bindValue(":critere", "%" + critere + "%");
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche !");
        qDebug() << "Erreur recherche:" << query.lastError().text();
        return;
    }
    remplirTable(query);
}



void MainWindow::remplirTable(QSqlQuery &query) // Modifié
{
    ui->tableWidgetEmployes_2->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidgetEmployes_2->insertRow(row);
        for (int col = 0; col < 7; col++) {
            ui->tableWidgetEmployes_2->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}

// ==================== UTILS ====================
void MainWindow::clearChamps() // Modifié
{
    ui->ID_Employe->clear();
    ui->Nom_Employe->clear();
    ui->Prenom_Employe->clear();
    ui->Sexe_Employe->clear();
    ui->Responsabilite->clear();
    ui->Salaire->clear();
    ui->Telephone_Employe->clear();
    ui->Username->clear();
    ui->Motdepasse->clear();
}
QString MainWindow::hashPassword(const QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

// ==================== LOGIN (CORRIGÉ ET SÉCURISÉ) ====================
void MainWindow::onLoginClicked()
{
    QString username = ui->Username->text();
    QString password = ui->Motdepasse->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QString inputHash = hashPassword(password);
    QSqlQuery query;
    query.prepare("SELECT PASSWORD_HASH FROM UTILISATEURS WHERE USERNAME = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la connexion à la base !");
        qDebug() << "Login Error:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        if (inputHash == storedHash) {
            // SUCCÈS
            QMessageBox::information(this, "Succès", "Connexion réussie !");
            ui->Ajouter_Employe->setEnabled(true);
            ui->Modifier_Employe->setEnabled(true);
            ui->Supprimer_Employe->setEnabled(true);
            ui->Rechercher_Employe_2->setEnabled(true);

            goToPage(ui->page);
            clearChamps();
            afficherEmployes();
        } else {
            QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }
}

void MainWindow::on_Trier_2_clicked()
{
    // On trie le QTableWidget directement.
    // 1 est l'index de votre colonne "nom" (0=ID, 1=nom, ...)
    // Qt::AscendingOrder = Ordre alphabétique (A-Z)

    ui->tableWidgetEmployes_2->sortByColumn(1, Qt::AscendingOrder);

    QMessageBox::information(this, "Tri", "Le tableau a été trié par nom (A-Z).");
}

void MainWindow::on_Exporter_2_clicked()
{
    // 1. Choisir où enregistrer le fichier
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter les employés", "", "Fichiers CSV (*.csv)");

    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé
    }

    QFile file(filePath);

    // 2. Tenter d'ouvrir le fichier en écriture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier pour l'exportation !");
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8); // <-- LIGNE CORRIGÉE (pour Qt 6)
    // 3. Écrire les en-têtes (Noms des colonnes)
    QStringList headers;
    for (int c = 0; c < ui->tableWidgetEmployes_2->columnCount(); ++c) {
        headers << ui->tableWidgetEmployes_2->horizontalHeaderItem(c)->text();
    }
    // Nous utilisons ";" comme séparateur (standard Excel France)
    out << headers.join(";") << "\n";

    // 4. Écrire toutes les lignes de données
    for (int r = 0; r < ui->tableWidgetEmployes_2->rowCount(); ++r) {
        QStringList rowData;
        for (int c = 0; c < ui->tableWidgetEmployes_2->columnCount(); ++c) {
            QTableWidgetItem *item = ui->tableWidgetEmployes_2->item(r, c);
            QString text = (item ? item->text() : "");
            // Gérer les ";" dans le texte
            if (text.contains(';')) {
                rowData << "\"" + text + "\"";
            } else {
                rowData << text;
            }
        }
        out << rowData.join(";") << "\n";
    }

    // 5. Fermer le fichier et notifier l'utilisateur
    file.close();
    QMessageBox::information(this, "Succès", "Exportation vers le fichier CSV réussie !");
}
void MainWindow::on_Statistiques_2_clicked()
{

    int h = 0, f = 0;
    QSqlQuery q;
    // --- DEBUG MESSAGE 1 ---
    QMessageBox::information(this, "Debug", "Le bouton a été cliqué !");

    // We check for errors in the query
    if (!q.exec("SELECT COUNT(*) FROM EMPLOYER WHERE LOWER(sexe_employe)='homme'")) {
        QMessageBox::critical(this, "Erreur SQL", q.lastError().text());
    }
    if (q.next()) h = q.value(0).toInt();

    if (!q.exec("SELECT COUNT(*) FROM EMPLOYER WHERE LOWER(sexe_employe)='femme'")) {
        QMessageBox::critical(this, "Erreur SQL", q.lastError().text());
    }
    if (q.next()) f = q.value(0).toInt();

    // --- DEBUG MESSAGE 2 ---
    // Show us the numbers found
    QMessageBox::information(this, "Données", QString("Hommes: %1, Femmes: %2").arg(h).arg(f));

    if (h == 0 && f == 0) {
        QMessageBox::warning(this, "Attention", "Aucune donnée trouvée. Le graphique ne s'affichera pas.");
        return;
    }
    q.exec("SELECT COUNT(*) FROM EMPLOYER WHERE LOWER(sexe_employe)='homme'");
    if (q.next()) h = q.value(0).toInt();
    q.exec("SELECT COUNT(*) FROM EMPLOYER WHERE LOWER(sexe_employe)='femme'");
    if (q.next()) f = q.value(0).toInt();

    if (h == 0 && f == 0) return;

    // 2. PRÉPARER LE CAMEMBERT
    // Notez qu'on n'écrit plus "QtCharts::QPieSeries", juste "QPieSeries"
    QPieSeries *series = new QPieSeries();
    series->append("Hommes", h);
    series->append("Femmes", f);

    // Couleurs et Labels
    QPieSlice *sliceH = series->slices().at(0);
    sliceH->setBrush(QColor("#3498db")); // Bleu
    sliceH->setLabelVisible(true);
    sliceH->setLabel(QString("Hommes: %1").arg(h));

    QPieSlice *sliceF = series->slices().at(1);
    sliceF->setBrush(QColor("#e74c3c")); // Rouge
    sliceF->setLabelVisible(true);
    sliceF->setLabel(QString("Femmes: %1").arg(f));

    // 3. CRÉER LE GRAPHIQUE
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques Sexe");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignRight);

    // 4. METTRE LE GRAPHIQUE DANS LE WIDGET
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // --- CORRECTION DE L'ERREUR "ui->widgetStats" ---
    // Vérifiez bien que le widget existe, sinon le programme plantera ici.
    if (ui->widgetStats->layout() != nullptr) {
        QLayoutItem* item;
        while ((item = ui->widgetStats->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete ui->widgetStats->layout();
    }

    QVBoxLayout *layout = new QVBoxLayout(ui->widgetStats);
    layout->addWidget(chartView);
    ui->widgetStats->setLayout(layout);
}




