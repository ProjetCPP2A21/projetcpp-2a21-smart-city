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
}

void MainWindow::on_btn_statistiques_clicked()
{
    afficherStatistiques();
}

void MainWindow::afficherStatistiques()
{
    QSqlQuery query;
    int nbHomme = 0, nbFemme = 0;

    query.exec("SELECT SEXE FROM RESIDENT");
    while (query.next()) {
        QString sexe = query.value(0).toString().toLower();
        if (sexe == "homme")
            nbHomme++;
        else if (sexe == "femme")
            nbFemme++;
    }

    int total = nbHomme + nbFemme;

    // 🔥 Calcul des pourcentages (éviter /0)
    double pourH = (total == 0) ? 0 : (nbHomme * 100.0 / total);
    double pourF = (total == 0) ? 0 : (nbFemme * 100.0 / total);

    // 🔥 Pie chart
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

    // On sépare un peu visuellement les parts (optionnel)
    sliceH->setExploded(false);
    sliceF->setExploded(false);

    // Activer l’affichage des labels sur le graphique
    series->setLabelsVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par sexe");
    chart->legend()->setAlignment(Qt::AlignBottom);

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

    // Placer le graphe dans l'espace rouge
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
