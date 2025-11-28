#include "residence.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "CrudResidence.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QTextTable>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include <cstdlib>




void MainWindow::afficherTableResidence()
{
    // récupère DATE_CONST comme number
    QSqlQuery query("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                    "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CREATION FROM RESIDENCE");

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);

    QStringList headers;
    headers << "ID" << "Nom" << "Adresse" << "Type" << "Nbr Unités"
            << "Nbr Habitants" << "État" << "Date Création";
    ui->affichage->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->affichage->insertRow(row);
        // colonnes 0..6 : conversion normale
        for (int col = 0; col < 7; ++col) {
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        // colonne 7 = DATE_CONST (NUMBER) -> formater en "YYYY-MM-DD"
        int dateNum = query.value(7).toInt();
        QString dateStr = QString::number(dateNum);

        if (dateStr.length() >= 8) {
            // ex: 20240201 -> "2024-02-01"
            dateStr = dateStr.mid(0,4) + "-" + dateStr.mid(4,2) + "-" + dateStr.mid(6,2);
        }
        // sinon on laisse la valeur brute

        ui->affichage->setItem(row, 7, new QTableWidgetItem(dateStr));
        row++;
    }
}

void MainWindow::on_Ajouter_Residence_clicked()
{
    int id = ui->Id_Residence->text().toInt();
    QString nom = ui->Nom_Residence->text();
    QString adresse = ui->Adresse_Residence->text();
    QString type = ui->Type_Residence->text();
    int nbrUnite = ui->Nbr_Unites->text().toInt();
    int nbrHabitants = ui->Nbr_Habitants->text().toInt();
    QString etat = ui->Etat->text();
    QString dateCreation = ui->Date_Creation->text();

    if (crud.ajouter(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès", "Résidence ajoutée avec succès !");
        afficherTableResidence();

    } else {
        QMessageBox::critical(this, "Erreur", "L’ajout a échoué !");
    }
}


void MainWindow::on_Modifier_Residence_clicked()
{
    int id = ui->Id_Residence->text().toInt();
    QString nom = ui->Nom_Residence->text();
    QString adresse = ui->Adresse_Residence->text();
    QString type = ui->Type_Residence->text();
    int nbrUnite = ui->Nbr_Unites->text().toInt();
    int nbrHabitants = ui->Nbr_Habitants->text().toInt();
    QString etat = ui->Etat->text();
    QString dateCreation = ui->Date_Creation->text();

    if (crud.modifier(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès","Résidence modifiée !");
        afficherTableResidence();


    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué !");
    }
}


void MainWindow::on_Supprimer_Residence_clicked()
{
    int id = ui->Id_Residence->text().toInt();

    if (crud.supprimer(id)) {
        QMessageBox::information(this, "Succès","Résidence supprimer !");
        afficherTableResidence();


    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué !");
    }
}
void MainWindow::on_recherche_clicked()
{
    int id = ui->search->text().toInt();

    QSqlQuery query = crud.rechercherParID(id);

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);

    QStringList headers;
    headers << "ID" << "Nom" << "Adresse" << "Type" << "Nbr Unités"
            << "Nbr Habitants" << "État" << "Date Création";
    ui->affichage->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->affichage->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Résultat", "Aucune résidence trouvée avec cet ID.");
    }
}







void MainWindow::on_trie_clicked()
{
    QSqlQueryModel *model = crud.trierParNbrHabitants();
    if (!model) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données triées.");
        return;
    }

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(model->columnCount());

    QStringList headers = {"ID", "Nom", "Adresse", "Type", "Nbr Unités",
                           "Nbr Habitants", "État", "Date Création"};
    ui->affichage->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < model->rowCount(); ++row) {
        ui->affichage->insertRow(row);
        for (int col = 0; col < model->columnCount(); ++col) {
            ui->affichage->setItem(row, col,
                                   new QTableWidgetItem(model->data(model->index(row, col)).toString()));
        }
    }

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Résultat", "Aucune résidence trouvée.");
    }

    delete model;
}






void MainWindow::on_statistique_clicked()
{
    QSqlQuery query = crud.statistiquesHabitants();

    if(!query.isActive()) {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de générer les statistiques");
        return;
    }


    QPieSeries *series = new QPieSeries();
    while(query.next()) {
        QString range = query.value(0).toString();
        int total = query.value(1).toInt();
        series->append(range, total);
    }

    for(QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg(slice->value()));
    }


    QChart *chartObj = new QChart();
    chartObj->addSeries(series);
    chartObj->setTitle("Répartition des résidences selon le nombre d'habitants");
    chartObj->legend()->setAlignment(Qt::AlignRight);


    QChartView *chartView = new QChartView(chartObj);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chart);
    chartView->setGeometry(ui->chart->rect());
    chartView->show();
}




void MainWindow::on_exporter_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    if (!fileName.endsWith(".pdf"))
        fileName += ".pdf";


    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html;


    html += "<h2>Liste des Résidences</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='3'>";
    html += "<tr>"
            "<th>ID</th>"
            "<th>Nom</th>"
            "<th>Adresse</th>"
            "<th>Type</th>"
            "<th>Nbr Unités</th>"
            "<th>Nbr Habitants</th>"
            "<th>État</th>"
            "<th>Date Création</th>"
            "</tr>";


    QSqlDatabase db = Connection::instance().getDatabase();
    if (!db.isOpen()) {
        if (!Connection::instance().createConnection()) {
            QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données.");
            return;
        }
    }

    QSqlQuery query(db);
    QString sql = R"(
        SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE,
               NBR_UNITE, NBR_HABITANTS, ETAT,
             DATE_CONST
        FROM RESIDENCE
        ORDER BY NBR_HABITANTS ASC
    )";

    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les résidences : " + query.lastError().text());
        return;
    }


    while (query.next()) {
        html += "<tr>";
        for (int col = 0; col < 8; ++col) {
            html += "<td>" + query.value(col).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";


    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "La liste des résidences a été exportée avec succès !");
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_P)
    {
        QSqlQuery query("SELECT NOM, NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST  FROM RESIDENCE");

        QString message = "Priorité des résidences :\n\n";

        while (query.next())
        {
            int etat = query.value("etat").toInt();
            int nbrHab = query.value("nbr_habitants").toInt();
            int nbrUnite = query.value("nbr_unite").toInt();
            int dateConst = query.value("date_const").toInt();
            QString nom = query.value("nom").toString();

            int yearConst = dateConst / 10000;

            double priority =
                (5.0 - etat) * 0.4 +
                ((double)nbrHab / nbrUnite) * 0.3 +
                (2025.0 - yearConst) * 0.3;

            message += nom + " → " + QString::number(priority, 'f', 2) + "\n";
        }


        QDialog dialog(this);
        dialog.setWindowTitle("Priorités");
        dialog.resize(600, 500);

        QVBoxLayout *layout = new QVBoxLayout(&dialog);

        QTextEdit *text = new QTextEdit();
        text->setText(message);
        text->setReadOnly(true);
        text->setFont(QFont("Rockwell", 11));

        layout->addWidget(text);

        dialog.exec();
    }
}


QString MainWindow::getMessageForCurrentTime()
{
    int hour = QTime::currentTime().hour();

    auto randomChoice = [](const QStringList &list) {
        return list.at(QRandomGenerator::global()->bounded(list.size()));
    };


    if (hour >= 7 && hour <= 11) {
        QStringList matin = {
            "Bon matin ! Pensez à vérifier les résidences dont l’état est inférieur à 3.",
            "Contactez le consièrge SVP.",
            "Conseil du jour : consultez les résidences les plus anciennes pour la maintenance.",
            "Veillez consulter le responsable service pour planifier la maintenance.."
        };
        return randomChoice(matin);
    }


    if (hour >= 12 && hour <= 16) {
        QStringList apm = {
            "Point mi-journée : avez-vous mis à jour les résidences modifiées ?",
            "Recommandation : vérifiez les résidences à densité élevée.",
            "Suggestion : consulter la priorité si il ya des modification dans la BD."
        };
        return randomChoice(apm);
    }


    if (hour >= 17 && hour <= 20) {
        QStringList soir = {
            "Fin de journée : souhaitez-vous générer un fichier pdf des résidences ?",
            "Astuce : vérifiez les résidences critiques pour demain.",
            "Pensez à enregistrer vos dernières modifications."
        };
        return randomChoice(soir);
    }


    if (hour >= 21 && hour <= 23) {
        QStringList nuit = {
            "Nuit calme… pensez à sauvegarder vos données.",
            "Conseil : vérifiez demain les résidences dont l’état est bas.",
            "Astuce : un nettoyage de la base peut améliorer les performances."
        };
        return randomChoice(nuit);
    }


    if (hour >= 0 && hour <= 6) {
        QStringList tard = {
            "Il est tard… n'oubliez pas de sauvegarder avant de fermer l’application.",
            "Recommandation : générez un rapport avant de finir et le verifiez avec les responsable ",
            "Pensez à revoir demain les résidences critiques."
        };
        return randomChoice(tard);
    }

    return "";
}
void MainWindow::handlePopupTimer()
{
    // --- À MODIFIER : Définissez l'index de la page de votre travail ---
    // Si votre page est le premier onglet/page, utilisez 0.
    // Si c'est le deuxième, utilisez 1, etc.
    const int page_3 = 0; // Ex: page d'accueil = 0, votre page = 1

    // Vérifiez que le widget existe et que l'interface est prête.
    if (!ui->stackedWidget) {
        qDebug() << "Erreur: ui->stackedWidget non trouvé.";
        return;
    }

    // VERIFICATION: N'afficher la pop-up que si nous sommes sur la bonne page.
    if (ui->stackedWidget->currentIndex() == page_3) {
        QString message = getMessageForCurrentTime();
        if (!message.isEmpty()) {
            QMessageBox::information(this, "Recommandation NEOCITY", message);
        }
    } else {
        qDebug() << "Pop-up Timer: Ignoré (pas sur la bonne page - Index actuel:" << ui->stackedWidget->currentIndex() << ")";
    }
}
