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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->btn_statistiques, &QPushButton::clicked, this, &MainWindow::on_btn_statistiques_clicked);

    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);


    // --- VALIDATION DES CHAMPS ---

    // Lettres seulement (Nom, Prénom)
    QRegularExpression rxLetters("^[A-Za-z]+$");
    ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rxLetters, this));
    ui->lineEdit_prenom->setValidator(new QRegularExpressionValidator(rxLetters, this));

    // Sexe : H ou F uniquement
    QRegularExpression rxSexe2("^(Homme|Femme|homme|femme)$");
    ui->lineEdit_sexe->setValidator(new QRegularExpressionValidator(rxSexe2, this));

    // Profession et Situation : lettres + espaces
    QRegularExpression rxText("^[A-Za-z ]+$");
    ui->lineEdit_profession->setValidator(new QRegularExpressionValidator(rxText, this));
    ui->lineEdit_situation->setValidator(new QRegularExpressionValidator(rxText, this));

    // Age : seulement chiffres (0 à 120)
    ui->lineEdit_age->setValidator(new QIntValidator(0, 120, this));

    // ID Resident : seulement chiffres
    ui->lineEdit_idresident->setValidator(new QIntValidator(0, 999999, this));


    // Navigation
    QObject::connect(ui->RH, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->residence_2, SIGNAL(clicked()), this, SLOT(page_3()));
    QObject::connect(ui->resident, SIGNAL(clicked()), this, SLOT(page()));
    QObject::connect(ui->RH_2, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->residence_3, SIGNAL(clicked()), this, SLOT(page_3()));
    QObject::connect(ui->resident_3, SIGNAL(clicked()), this, SLOT(page()));

    // Charger table
    Resident Rtmp;
    ui->tableView->setModel(Rtmp.afficher());

    // ComboBox de tri
    ui->comboBox_tri->addItem("Nom");
    ui->comboBox_tri->addItem("Age");
    ui->comboBox_tri->addItem("Sexe");
}

void MainWindow::page_3() { ui->stackedWidget->setCurrentWidget(ui->page_3); }
void MainWindow::page_4() { ui->stackedWidget->setCurrentWidget(ui->page_4); }
void MainWindow::page() { ui->stackedWidget->setCurrentWidget(ui->page); }

void MainWindow::on_btn_ajouter_clicked()
{
    int id_resident = ui->lineEdit_idresident->text().toInt();
    int id_residence = 250;
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
    int id_residence = 250;
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

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();

    ui->lineEdit_idresident->setText(ui->tableView->model()->index(row, 0).data().toString());
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

QString MainWindow::calculerStabilite(int age, QString profession, QString situation)
{
    profession = profession.toLower();
    situation = situation.toLower();

    // Stabilité élevée
    if ((profession.contains("cdi") ||
         profession.contains("employer") ||
         profession.contains("ingenieur") ||
         profession.contains("medecin") ||
         profession.contains("enseignant")))
    {
        if (situation.contains("marier") && (age >= 25 && age <= 55))
            return "Élevée";
    }

    // Stabilité moyenne
    if ((profession.contains("etudiant") ||
         profession.contains("ouvrier") ||
         profession.contains("independant")))
    {
        if (situation.contains("celibataire") && (age >= 20 && age <= 60))
            return "Moyenne";
    }

    // Sinon stabilité faible
    return "Faible";
}

QString MainWindow::calculerMobilite(int age, QString profession, QString situation)
{
    profession = profession.toLower();
    situation = situation.toLower();

    //  Mobilité élevée
    if (age < 40 &&
        (profession.contains("etudiant") ||
         profession.contains("employe") ||
         profession.contains("medecin") ||
         profession.contains("ingenieur") ||
         profession.contains("enseignant")) &&
        (situation.contains("celibataire") ||
         situation.contains("marier")))
    {
        return "Mobilité élevée – Peut participer aux activités extérieures";
    }

    //  Mobilité moyenne
    if (age >= 40 && age <= 60 &&
        (profession.contains("ouvrier") ||
         profession.contains("independant")) &&
        situation.contains("marier"))
    {
        return "Mobilité moyenne – Mobilité correcte";
    }

    //  Mobilité faible
    if (age > 60 ||
        profession.contains("sans emploi") ||
        profession.contains("retraite") ||
        situation.contains("veuf"))
    {
        return "Mobilité faible – Peut nécessiter assistance";
    }

    // Valeur par défaut
    return "Mobilité non définie";
}
