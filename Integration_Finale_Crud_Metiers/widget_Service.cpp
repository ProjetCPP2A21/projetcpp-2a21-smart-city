#include "widget_Service.h"
#include "service.h"
#include "email_Service.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QColor>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>


// ========== AFFICHER TOUS LES SERVICES ==========
void MainWindow::afficherServices()
{
    QSqlQuery query("SELECT ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                    "BUDGET_P, NIVEAU_PR, ETAT, DATE_CR FROM SERVICE");

    ui->tableServices->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tableServices->insertRow(row);

        ui->tableServices->setItem(row, 0,
                                   new QTableWidgetItem(query.value(1).toString()));
        ui->tableServices->setItem(row, 1,
                                   new QTableWidgetItem(query.value(2).toString()));
        ui->tableServices->setItem(row, 2,
                                   new QTableWidgetItem(query.value(3).toString()));
        ui->tableServices->setItem(row, 3,
                                   new QTableWidgetItem(query.value(4).toString()));
        ui->tableServices->setItem(row, 4,
                                   new QTableWidgetItem(query.value(5).toString()));
        ui->tableServices->setItem(row, 5,
                                   new QTableWidgetItem(query.value(6).toString()));
        ui->tableServices->setItem(row, 6,
                                   new QTableWidgetItem(query.value(0).toString()));

        row++;
    }

    ui->tableServices->resizeColumnsToContents();
}

// ========== AJOUTER UN SERVICE ==========
void MainWindow::ajouterService()
{
    QString nom = ui->lineEdit_Nom->text();
    QString type = ui->combo_type->currentText();
    QString responsable = ui->lineEdit_responsable->text();
    double budget = ui->spin_budget->value();
    QString priorite = ui->combo_priority->currentText();
    QString etat = ui->combo_state->currentText();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le nom du service est obligatoire!");
        return;
    }

    if (responsable.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le responsable est obligatoire!");
        return;
    }

    QRegularExpression regex("^[A-Za-zÀ-ÿ\\s]+$");
    if (!regex.match(responsable).hasMatch()) {
        QMessageBox::warning(this, "Attention",
                             "Le nom du responsable ne doit contenir que des lettres et des espaces !");
        return;
    }

    QSqlQuery queryMax;
    queryMax.exec("SELECT NVL(MAX(ID_SERVICE), 0) + 1 FROM SERVICE");

    int newId = 1;
    if (queryMax.next()) {
        newId = queryMax.value(0).toInt();
    }

    qDebug() << "Prochain ID calculé automatiquement:" << newId;

    QSqlQuery query;
    query.prepare("INSERT INTO SERVICE (ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                  "BUDGET_P, NIVEAU_PR, ETAT) "
                  "VALUES (:id, :nom, :type, :responsable, :budget, :priorite, :etat)");

    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);

    if (query.exec()) {
        QMessageBox::information(this, "Succès",
                                 "Service ajouté avec succès!");

        Email mail;
        mail.envoyerChangementService("khirallahmaram65@gmail.com",
                                      nom,
                                      "Nouveau",
                                      type);

        afficherServices();
        afficherStatistiques();
        viderChamps();
    } else {
        QString erreur = query.lastError().text();
        QMessageBox::critical(this, "Erreur",
                              "Échec de l'ajout:\n" + erreur);
        qDebug() << "✗ Erreur SQL:" << erreur;
        qDebug() << "Requête:" << query.lastQuery();
        qDebug() << "ID utilisé:" << newId;
    }
}

// ========== MODIFIER UN SERVICE ==========
void MainWindow::modifierService()
{
    QString idText = ui->lineEdit_id->text();

    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Veuillez d'abord sélectionner un service dans le tableau !");
        return;
    }

    int id = idText.toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Attention",
                             "ID de service invalide. Sélectionnez un service dans le tableau.");
        return;
    }

    QString nom = ui->lineEdit_Nom->text();
    QString type = ui->combo_type->currentText();
    QString responsable = ui->lineEdit_responsable->text();
    double budget = ui->spin_budget->value();
    QString priorite = ui->combo_priority->currentText();
    QString etat = ui->combo_state->currentText();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le nom du service est obligatoire!");
        return;
    }

    if (responsable.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le responsable est obligatoire!");
        return;
    }

    qDebug() << "========== MODIFICATION ==========";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom;
    qDebug() << "Type:" << type;
    qDebug() << "Responsable:" << responsable;
    qDebug() << "Budget:" << budget;
    qDebug() << "Priorité:" << priorite;
    qDebug() << "État:" << etat;

    QSqlQuery query;
    query.prepare("UPDATE SERVICE SET "
                  "NOM = :nom, "
                  "TYPE_SERVICE = :type, "
                  "RESPONSABLE = :responsable, "
                  "BUDGET_P = :budget, "
                  "NIVEAU_PR = :priorite, "
                  "ETAT = :etat "
                  "WHERE ID_SERVICE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "Succès",
                                     "Service modifié avec succès!");

            Email mail;
            mail.envoyerChangementService("khirallahmaram65@gmail.com",
                                          nom,
                                          "Modification",
                                          type);

            afficherServices();
            afficherStatistiques();
            viderChamps();
        } else {
            QMessageBox::warning(this, "Attention",
                                 "Aucun service trouvé avec cet ID.\n"
                                 "Il a peut-être été supprimé.");
        }
    } else {
        QString erreur = query.lastError().text();
        QMessageBox::critical(this, "Erreur",
                              "Échec de la modification:\n" + erreur);
        qDebug() << "✗ Erreur SQL:" << erreur;
        qDebug() << "Requête:" << query.lastQuery();
    }
}

// ========== SUPPRIMER UN SERVICE ==========
void MainWindow::supprimerService()
{
    QString idText = ui->lineEdit_id->text();

    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Veuillez sélectionner un service à supprimer!");
        return;
    }

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Confirmation",
                                    "Êtes-vous sûr de vouloir supprimer ce service?",
                                    QMessageBox::Yes | QMessageBox::No);

    if (reponse != QMessageBox::Yes) {
        return;
    }

    int id = idText.toInt();
    QString nom = ui->lineEdit_id->text();

    QSqlQuery query;
    query.prepare("DELETE FROM SERVICE WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Succès",
                                 "Service supprimé avec succès!");

        Email mail;
        mail.envoyerServiceSupprime("khirallahmaram65@gmail.com",
                                    nom,
                                    "Suppression effectuée depuis l'interface");

        afficherServices();
        afficherStatistiques();
        viderChamps();
    } else {
        QString erreur = query.lastError().text();
        QMessageBox::critical(this, "Erreur",
                              "Échec de la suppression:\n" + erreur);
        qDebug() << "✗ Erreur SQL:" << erreur;
    }
}

// ========== RECHERCHER UN SERVICE ==========
void MainWindow::rechercherService()
{
    QString critere = ui->Rechercher_Service->text();
    if (critere.isEmpty()) {
        afficherServices();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                  "BUDGET_P, NIVEAU_PR, ETAT "
                  "FROM SERVICE "
                  "WHERE NOM LIKE :critere OR RESPONSABLE LIKE :critere");

    query.bindValue(":critere", "%" + critere + "%");


    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Erreur de recherche:\n" + query.lastError().text());
        return;
    }

    ui->tableServices->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableServices->insertRow(row);

        ui->tableServices->setItem(row, 0,
                                   new QTableWidgetItem(query.value(1).toString()));
        ui->tableServices->setItem(row, 1,
                                   new QTableWidgetItem(query.value(2).toString()));
        ui->tableServices->setItem(row, 2,
                                   new QTableWidgetItem(query.value(3).toString()));
        ui->tableServices->setItem(row, 3,
                                   new QTableWidgetItem(query.value(4).toString()));
        ui->tableServices->setItem(row, 4,
                                   new QTableWidgetItem(query.value(5).toString()));
        ui->tableServices->setItem(row, 5,
                                   new QTableWidgetItem(query.value(6).toString()));
        ui->tableServices->setItem(row, 6,
                                   new QTableWidgetItem(query.value(0).toString()));

        row++;
    }

    ui->tableServices->resizeColumnsToContents();
}

// ========== SÉLECTIONNER UN SERVICE ==========
void MainWindow::selectionnerService(int row, int column)
{
    Q_UNUSED(column);

    if (row < 0 || row >= ui->tableServices->rowCount()) {
        qDebug() << "✗ Ligne invalide:" << row;
        return;
    }

    QTableWidgetItem* idItem = ui->tableServices->item(row, 6);
    if (!idItem) {
        qDebug() << "✗ ID introuvable à la ligne" << row;
        return;
    }

    QString id = idItem->text();
    QString nom = ui->tableServices->item(row, 0)->text();
    QString type = ui->tableServices->item(row, 1)->text();
    QString responsable = ui->tableServices->item(row, 2)->text();
    QString budget = ui->tableServices->item(row, 3)->text();
    QString priorite = ui->tableServices->item(row, 4)->text();
    QString etat = ui->tableServices->item(row, 5)->text();

    qDebug() << "========== SERVICE SÉLECTIONNÉ ==========";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom;

    ui->lineEdit_id->setText(id);
    ui->lineEdit_Nom->setText(nom);
    ui->combo_type->setCurrentText(type);
    ui->lineEdit_responsable->setText(responsable);
    ui->spin_budget->setValue(budget.toDouble());
    ui->combo_priority->setCurrentText(priorite);
    ui->combo_state->setCurrentText(etat);
}

// ========== TRIER LES SERVICES ==========
void MainWindow::trierServices(int index)
{
    QString colonne;

    switch(index) {
    case 0: colonne = "BUDGET_P"; break;
    case 1: colonne = "NIVEAU_PR"; break;
    case 2: colonne = "ETAT"; break;
    default: colonne = "ID_SERVICE"; break;
    }

    QSqlQuery query("SELECT ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                    "BUDGET_P, NIVEAU_PR, ETAT "
                    "FROM SERVICE ORDER BY " + colonne);

    ui->tableServices->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableServices->insertRow(row);

        ui->tableServices->setItem(row, 0,
                                   new QTableWidgetItem(query.value(1).toString()));
        ui->tableServices->setItem(row, 1,
                                   new QTableWidgetItem(query.value(2).toString()));
        ui->tableServices->setItem(row, 2,
                                   new QTableWidgetItem(query.value(3).toString()));
        ui->tableServices->setItem(row, 3,
                                   new QTableWidgetItem(query.value(4).toString()));
        ui->tableServices->setItem(row, 4,
                                   new QTableWidgetItem(query.value(5).toString()));
        ui->tableServices->setItem(row, 5,
                                   new QTableWidgetItem(query.value(6).toString()));
        ui->tableServices->setItem(row, 6,
                                   new QTableWidgetItem(query.value(0).toString()));

        row++;
    }

    ui->tableServices->resizeColumnsToContents();
}

// ========== VIDER LES CHAMPS ==========
void MainWindow::viderChamps()
{
    ui->lineEdit_responsable->clear();
    ui->lineEdit_id->clear();
    ui->lineEdit_Nom->clear();
    ui->combo_type->setCurrentIndex(0);
    ui->spin_budget->setValue(0);
    ui->combo_priority->setCurrentIndex(0);
    ui->combo_state->setCurrentIndex(0);
    ui->dateEdit_date->setDate(QDate::currentDate());
}

// ========== EXPORTER PDF ==========
void MainWindow::on_btnExportPDF_Services_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor blueLight("#2D89EF");
    QColor blueDark("#1E5BB8");
    QColor lineDark("#2C3E50");
    QColor lineLight("#F2F2F2");
    QColor white("#FFFFFF");

    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.setPen(blueDark);
    painter.drawText(QRect(0, 200, pdf.width(), 100), Qt::AlignCenter, "Liste des services");
    painter.setPen(QPen(blueLight, 3));
    painter.drawLine(200, 350, pdf.width() - 200, 350);

    int x = 80, y = 500, h = 90;
    int w[] = {300, 300, 350, 250, 250, 250, 200};
    QStringList headers = {"Nom", "Type", "Responsable", "Budget", "Priorité", "État", "ID"};

    painter.setFont(QFont("Arial", 11, QFont::Bold));
    painter.setBrush(blueLight);
    painter.setPen(white);
    painter.drawRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6], h);
    int cx = x;
    for (int i = 0; i < headers.size(); i++) {
        painter.drawText(QRect(cx, y, w[i], h), Qt::AlignCenter, headers[i]);
        cx += w[i];
    }
    y += h;

    painter.setFont(QFont("Arial", 9));
    int rows = ui->tableServices->rowCount();

    // CORRECTION : On force la limite à 7 colonnes car w[] a une taille de 7
    int cols = 7;

    for (int i = 0; i < rows; ++i) {
        QColor bg = (i % 2 == 0 ? lineLight : lineDark);
        QColor tx = (i % 2 == 0 ? Qt::black : white);

        // Dessiner le fond de la ligne
        painter.fillRect(x, y, w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6], h, bg);

        painter.setPen(tx);
        cx = x;

        for (int j = 0; j < cols; ++j) {
            // SÉCURITÉ 1 : Vérifier si l'item existe (n'est pas null)
            QTableWidgetItem *item = ui->tableServices->item(i, j);
            QString val = "";
            if (item != nullptr) {
                val = item->text();
            }

            // SÉCURITÉ 2 : On est sûr que w[j] existe car cols = 7
            painter.drawText(QRect(cx + 5, y, w[j] - 10, h), Qt::AlignVCenter | Qt::AlignLeft, val);
            cx += w[j];
        }

        y += h;
        if (y > pdf.height() - 400) {
            pdf.newPage();
            y = 200;
        }
    }

    painter.setFont(QFont("Arial", 10));
    painter.setPen(blueDark);
    painter.drawText(100, pdf.height() - 150, "Généré le : " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();
    QMessageBox::information(this, "PDF", "PDF Exporté avec succès !");
}


// ========== AFFICHER STATISTIQUES ==========
void MainWindow::afficherStatistiques_Services()
{
    int totalServices = Service::compterServices();
    int actif       = Service::compterParEtat("Actif");
    int enAttente   = Service::compterParEtat("En attente");
    int suspendu    = Service::compterParEtat("Suspendu");

    QBarSet *set = new QBarSet("Services");
    *set << actif << enAttente << suspendu;

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des services par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories = {"Actif", "En attente", "Suspendu"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, totalServices);
    axisY->setLabelFormat("%d");
    axisY->setTickCount(totalServices + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QLayoutItem* child;
    while ((child = ui->verticalLayout_Service->takeAt(0)) != nullptr) {
        if (child->widget()) delete child->widget();
        delete child;
    }

    ui->verticalLayout_Service->addWidget(chartView);
}

// Exemple simple dans Widget.cpp
void MainWindow::rechercheSmart() {
    int rows = ui->tableServices->rowCount();
    for(int i=0;i<rows;i++){
        QString prio = ui->tableServices->item(i,4)->text();
        double budget = ui->tableServices->item(i,3)->text().toDouble();
        double predicted = ui->tableServices->item(i,7)->text().toDouble();

        if(prio=="Low" && budget>predicted) {
            ui->tableServices->selectRow(i); // sélectionne la ligne automatiquement
        }
    }
}
