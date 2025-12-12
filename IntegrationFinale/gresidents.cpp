#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "residents.h"
#include "connection.h"
#include <QMessageBox>

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QSqlRecord>
#include <QtCharts>

/*#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>*/


void MainWindow::on_btn_ajouter_clicked()
{
    int id_resident = ui->lineEdit_idresident->text().toInt();
    int id_residence = ui->lineEdit_idresidence->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    int age = ui->lineEdit_age->text().toInt();
    QString sexe = ui->lineEdit_sexe->text();
    QString profession = ui->lineEdit_profession->text();
    QString situation = ui->lineEdit_situation->text();

    Resident R(id_resident, id_residence, nom, prenom, age, sexe, profession, situation);

    if (R.ajouter()) {
        QMessageBox::information(this, "Succès", "Résident ajouté !");
        ui->tableView->setModel(R.afficher());
        clearFields();
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout échoué !");
    }
}

void MainWindow::on_btn_supprimer_clicked()
{
    int id = ui->lineEdit_idresident->text().toInt();
    Resident R;

    if (R.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Résident supprimé !");
        ui->tableView->setModel(R.afficher());
        clearFields();
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression échouée !");
    }
}

void MainWindow::on_btn_modifier_clicked()
{
    int id_resident = ui->lineEdit_idresident->text().toInt();
    int id_residence = ui->lineEdit_idresidence->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    int age = ui->lineEdit_age->text().toInt();
    QString sexe = ui->lineEdit_sexe->text();
    QString profession = ui->lineEdit_profession->text();
    QString situation = ui->lineEdit_situation->text();

    Resident R(id_resident, id_residence, nom, prenom, age, sexe, profession, situation);

    if (R.modifier()) {
        QMessageBox::information(this, "Succès", "Résident modifié !");
        ui->tableView->setModel(R.afficher());
        clearFields();
    } else {
        QMessageBox::critical(this, "Erreur", "Modification échouée !");
    }
}

void MainWindow::on_recherche_residents_textChanged(const QString &arg1)
{
    Resident R;
    //Mise à jour du tableau
    ui->tableView->setModel(R.rechercher(arg1));
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{

    Resident R;
    QString critere;

    if (index == 0)
        critere = "NOM";
    else if (index == 1)
        critere = "AGE";
    else if (index == 2)
        critere = "SEXE";

    ui->tableView->setModel(R.trier(critere, "ASC"));
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();

    ui->lineEdit_id->setText(ui->tableView->model()->index(row, 0).data().toString());
    ui->lineEdit_nom->setText(ui->tableView->model()->index(row, 2).data().toString());
    ui->lineEdit_prenom->setText(ui->tableView->model()->index(row, 3).data().toString());
    ui->lineEdit_age->setText(ui->tableView->model()->index(row, 4).data().toString());
    ui->lineEdit_sexe->setText(ui->tableView->model()->index(row, 5).data().toString());
    ui->lineEdit_profession->setText(ui->tableView->model()->index(row, 6).data().toString());
    ui->lineEdit_situation->setText(ui->tableView->model()->index(row, 7).data().toString());

    //  Récupération des valeurs une seule fois
    int age = ui->lineEdit_age->text().toInt();
    QString profession = ui->lineEdit_profession->text();
    QString situation = ui->lineEdit_situation->text();

    //  Calcul stabilité
    QString stab = calculerStabilite(age, profession, situation);
    ui->label_stabilite->setText("Stabilité sociale : " + stab);

    //  Calcul mobilité
    QString mobilite = calculerMobilite(age, profession, situation);
    ui->labelMobilite->setText("Mobilité : " + mobilite);
}


void MainWindow::on_btn_statistiques_clicked()
{
    afficherStatistiques();
}

void MainWindow::afficherStatistiques()
{
    QSqlQuery query;
    int nbHomme = 0, nbFemme = 0;

    //Récupération des sexes depuis la base
    query.exec("SELECT SEXE FROM RESIDENT");
    while (query.next()) {
        QString sexe = query.value(0).toString().toLower();
        if (sexe == "homme")
            nbHomme++;
        else if (sexe == "femme")
            nbFemme++;
    }

    int total = nbHomme + nbFemme;

    //  Calcul des pourcentages
    double pourH = (total == 0) ? 0 : (nbHomme * 100.0 / total);
    double pourF = (total == 0) ? 0 : (nbFemme * 100.0 / total);

    //  Création du camembert
    QPieSeries *series = new QPieSeries();

    // Slices avec labels contenant les pourcentages
    QPieSlice *sliceH = series->append(
        QString("Hommes (%1%)").arg(QString::number(pourH, 'f', 1)),
        nbHomme
        );

    QPieSlice *sliceF = series->append(
        QString("Femmes (%1%)").arg(QString::number(pourF, 'f', 1)),
        nbFemme
        );

    // On sépare un peu visuellement les parts
    sliceH->setExploded(false);
    sliceF->setExploded(false);

    // Activer l’affichage des labels sur le graphique
    series->setLabelsVisible(true);

    //Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par sexe");
    chart->legend()->setAlignment(Qt::AlignBottom);

    //Vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Nettoyer ce qu’il y avait avant
    if (QLayout *oldLayout = ui->widget_stats->layout()) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Ajouter le nouveau graphique
    QVBoxLayout *layout = new QVBoxLayout(ui->widget_stats);
    layout->addWidget(chartView);
    ui->widget_stats->setLayout(layout);
}



void MainWindow::clearFields()
{
    ui->lineEdit_idresident->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_sexe->clear();
    ui->lineEdit_profession->clear();
    ui->lineEdit_situation->clear();
}

void MainWindow::on_btnExportPDF_clicked()
{
    //Choix de l’emplacement du PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    //Création du document PDF
    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    //Création du “stylo” pour dessiner sur le PDF
    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    // Couleurs
    QColor blueLight("#2D89EF");
    QColor blueDark("#1E5BB8");
    QColor lineDark("#2C3E50");
    QColor lineLight("#F2F2F2");
    QColor white("#FFFFFF");

    // Titre
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.setPen(blueDark);
    painter.drawText(QRect(0, 200, pdf.width(), 100), Qt::AlignCenter, "Liste des Résidents");
    painter.setPen(QPen(blueLight, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    // Tableau
    int x = 80, y = 500, h = 90;

    // Largeur des colonnes
    int w[] = {180, 180, 250, 250, 120, 150, 200, 300};


    //Titres des colonnes
    QStringList headers = {
        "ID Résident", "ID Résidence", "Nom", "Prénom", "Âge", "Sexe", "Profession", "Situation"
    };

    // Récupérer le modèle du tableau
    QAbstractItemModel *model = ui->tableView->model();
    int rows = model->rowCount();
    int cols = model->columnCount();

    // En-tête
    painter.setFont(QFont("Arial", 11, QFont::Bold));
    painter.setBrush(blueLight);
    painter.setPen(white);
    painter.drawRect(x, y,
                     w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7],
                     h
                     );

    int cx = x;

    //Puis affichage de chaque titre
    for (int i = 0; i < headers.size(); i++) {
        painter.drawText(QRect(cx, y, w[i], h), Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    // Données
    painter.setFont(QFont("Arial", 9));
    for (int i = 0; i < rows; ++i) {

        QColor bg = (i % 2 == 0 ? lineLight : lineDark);
        QColor tx = (i % 2 == 0 ? Qt::black : white);

        painter.fillRect(x, y,
                         w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7],
                         h, bg
                         );

        painter.setPen(tx);

        cx = x;

        //Affichage des colonnes
        for (int j = 0; j < cols; ++j) {

            QString val = model->data(model->index(i, j)).toString();

            painter.drawText(QRect(cx + 5, y, w[j] - 10, h),
                             Qt::AlignVCenter | Qt::AlignLeft,
                             val);

            cx += w[j];
        }

        y += h;

        // Nouvelle page si nécessaire
        if (y > pdf.height() - 400) {
            pdf.newPage();
            y = 200;
        }
    }

    // Pied de page
    painter.setFont(QFont("Arial", 10));
    painter.setPen(blueDark);
    painter.drawText(100, pdf.height() - 150,
                     "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "PDF Exporté avec succès !");
}
// Fonction utilitaire pour obtenir le niveau de stabilité d'un métier (0 à 3)
int MainWindow::obtenirNiveauMetier(QString profession) {
    profession = profession.toLower().trimmed();

    // Catégorie 1 : Haute stabilité / Cadres (Score 3)
    QStringList motsClesHaut = {
        "ingenieur", "medecin", "directeur", "responsable", "chef",
        "avocat", "cadre", "enseignant", "professeur", "fonctionnaire",
        "architecte", "pharmacien", "juge", "expert", "cdi"
    };

    // Catégorie 2 : Stabilité Moyenne / Employés / Ouvriers (Score 2)
    QStringList motsClesMoyen = {
        "technicien", "infirmier", "comptable", "secretaire", "assistant",
        "agent", "ouvrier", "chauffeur", "mecanicien", "electricien",
        "plombier", "maçon", "cuisinier", "boulanger", "vendeur",
        "commercial", "coiffeur", "agriculteur"
    };

    // Catégorie 3 : Indépendants / Etudiants / Précaires (Score 1)
    QStringList motsClesBas = {
        "etudiant", "stagiaire", "interim", "freelance", "independant",
        "artiste", "journaliste", "saisonnier", "apprenti"
    };

    // Catégorie 4 : Sans emploi / Retraité (Score 0)
    QStringList motsClesInactif = {
        "chomeur", "sans emploi", "retraite", "au foyer"
    };

    // Vérification
    for (const QString &mot : motsClesHaut) if (profession.contains(mot)) return 3;
    for (const QString &mot : motsClesMoyen) if (profession.contains(mot)) return 2;
    for (const QString &mot : motsClesBas) if (profession.contains(mot)) return 1;
    for (const QString &mot : motsClesInactif) if (profession.contains(mot)) return 0;

    // Par défaut, si on ne reconnait pas le métier, on le considère comme "Moyen" (2)
    return 2;
}
QString MainWindow::calculerStabilite(int age, QString profession, QString situation)
{
    int scoreMetier = obtenirNiveauMetier(profession); // 0, 1, 2 ou 3
    situation = situation.toLower();

    // LOGIQUE DE STABILITÉ
    // Règle 1 : Si le métier est très stable (3) ET marié
    if (scoreMetier >= 3 && situation.contains("marier")) {
        return "Élevée";
    }

    // Règle 2 : Si métier correct (2 ou 3) et âge adulte "mûr"
    if (scoreMetier >= 2 && age > 30 && age < 60) {
        return "Bonne";
    }

    // Règle 3 : Etudiant ou début de carrière
    if (scoreMetier == 1 || (age < 25 && scoreMetier == 2)) {
        return "Moyenne (En construction)";
    }

    // Règle 4 : Inactif ou très âgé
    if (scoreMetier == 0 || age > 70) {
        return "Faible (Dépendance probable)";
    }

    return "Moyenne"; // Valeur par défaut
}
QString MainWindow::calculerMobilite(int age, QString profession, QString situation)
{
    int scoreMetier = obtenirNiveauMetier(profession);

    // 1. Jeunes actifs et étudiants (Haute mobilité)
    if (age < 35 && (scoreMetier == 1 || scoreMetier == 2 || scoreMetier == 3)) {
        return "Mobilité Élevée – Participe aux activités";
    }

    // 2. Actifs installés (Moyenne mobilité car souvent occupés)
    if (age >= 35 && age < 60 && scoreMetier >= 2) {
        return "Mobilité Moyenne – Disponible soirs/week-ends";
    }

    // 3. Retraités dynamiques (souvent très mobiles pour les loisirs)
    if (age >= 60 && age < 75 && profession.toLower().contains("retraite")) {
        return "Mobilité Active – Disponible en journée";
    }

    // 4. Personnes âgées ou sans emploi (Mobilité réduite)
    if (age >= 75 || scoreMetier == 0) {
        return "Mobilité Faible – Peut nécessiter assistance";
    }

    return "Mobilité Standard";
}
