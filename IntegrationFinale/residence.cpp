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
#include "toastnotification.h"
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>




void MainWindow::on_Ajouter_Residence_2_clicked()
{
    int id = ui->Id_Residence_2->text().toInt();
    QString nom = ui->Nom_Residence_2->text();
    QString adresse = ui->Adresse_Residence_2->text();
    QString type = ui->Type_Residence_2->text();
    int nbrUnite = ui->Nbr_Unites_2->text().toInt();
    int nbrHabitants = ui->Nbr_Habitants_2->text().toInt();
    QString etat = ui->Etat_2->text();
    QString dateCreation = ui->Date_Creation_2->text();

    if (crud.ajouter(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès", "Résidence ajoutée avec succès !");
        afficherTableResidence();

    } else {
        QMessageBox::critical(this, "Erreur", "L’ajout a échoué !");
    }
}
void MainWindow::on_Modifier_Residence_2_clicked()
{
    int id = ui->Id_Residence_2->text().toInt();
    QString nom = ui->Nom_Residence_2->text();
    QString adresse = ui->Adresse_Residence_2->text();
    QString type = ui->Type_Residence_2->text();
    int nbrUnite = ui->Nbr_Unites_2->text().toInt();
    int nbrHabitants = ui->Nbr_Habitants_2->text().toInt();
    QString etat = ui->Etat_2->text();
    QString dateCreation = ui->Date_Creation_2->text();

    if (crud.modifier(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès","Résidence modifiée !");
        afficherTableResidence();


    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué !");
    }
}

void MainWindow::afficherTableResidence()
{
    // récupère DATE_CONST comme number
    QSqlQuery query("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                    "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST FROM RESIDENCE");

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

// DANS residence.cpp

void MainWindow::on_Supprimer_Residence_clicked()
{
    // 1. Vérification : Le champ est-il vide ?
    if (ui->Id_Residence_2->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez écrire un ID à supprimer !");
        return; // On arrête tout ici
    }

    // 2. On récupère l'ID (Assurez-vous d'utiliser Id_Residence_2 et pas Nom_Residence_2)
    int id = ui->Id_Residence_2->text().toInt();

    // 3. Appel au CRUD
    if (crud.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Résidence supprimée avec succès !");
        afficherTableResidence();
        ui->Id_Residence_2->clear(); // On vide le champ après
    } else {
        QMessageBox::critical(this, "Erreur", "Aucune résidence trouvée avec cet ID (ou erreur SQL).");
    }
}
void MainWindow::on_recherche_clicked()
{
    QString texteRecherche = ui->search->text();

    // 1. Si le champ est vide, on réinitialise l'affichage (on affiche tout)
    if (texteRecherche.isEmpty()) {
        afficherTableResidence();
        return;
        }

    // 2. Vérifier si c'est bien un nombre
    bool estUnNombre;
    int id = texteRecherche.toInt(&estUnNombre);

    if (!estUnNombre) {
    QMessageBox::warning(this, "Erreur de saisie", "La recherche fonctionne uniquement par ID (chiffres).");
    return;
        }

        // 3. Lancer la recherche SQL
        QSqlQuery query = crud.rechercherParID(id);

        ui->affichage->clear();
        ui->affichage->setRowCount(0);
        // On doit remettre le nombre de colonnes correct (8 colonnes dans votre affichage)
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
            // Optionnel : Réafficher tout si rien n'est trouvé
            // afficherTableResidence();
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
            int Etat_2 = query.value("ETAT").toInt();
            int nbrHab = query.value("NBR_HABITANTS").toInt();
            int nbrUnite = query.value("nbr_unite").toInt();
            int dateConst = query.value("date_const").toInt();
            QString nom = query.value("nom").toString();

            int yearConst = dateConst / 10000;

            double priority =
                (5.0 - Etat_2) * 0.4 +
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

void MainWindow::afficherNotification(const QString &message)
{
    // 1. Création du widget
    QWidget *popup = new QWidget(this);
    popup->setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);
    popup->setAttribute(Qt::WA_DeleteOnClose);

    // 2. STYLISATION MODERNE (Smart City)
    // On utilise un dégradé bleu-cyan et des coins bien arrondis
    popup->setStyleSheet(
        "QWidget {"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #141E30, stop:1 #243B55);" /* Dégradé sombre élégant */
        "   border-radius: 12px;"           /* Arrondi doux */
        "   border: 1px solid rgba(255, 255, 255, 30);" /* Bordure subtile semi-transparente */
        "}"
        "QLabel#IconLabel {"
        "   color: #00d2ff;"                /* Couleur Cyan Neon pour l'icône */
        "   background: transparent;"
        "   font-size: 24px;"
        "   border: none;"
        "}"
        "QLabel#TextLabel {"
        "   color: white;"
        "   background: transparent;"
        "   border: none;"
        "   font-family: 'Segoe UI', sans-serif;" /* Police moderne */
        "   font-size: 14px;"
        "}"
        );

    // 3. MISE EN PAGE HORIZONTALE (Icône + Texte)
    QHBoxLayout *layout = new QHBoxLayout(popup);
    layout->setContentsMargins(15, 10, 15, 10); // Marges internes aérées
    layout->setSpacing(15);

    // -- L'icône (On utilise un emoji ou un caractère unicode pour simuler une icône moderne)
    QLabel *icon = new QLabel("💡", popup);
    icon->setObjectName("IconLabel"); // Pour le CSS
    icon->setAlignment(Qt::AlignCenter);
    layout->addWidget(icon);

    // -- Le texte
    QLabel *lbl = new QLabel(message, popup);
    lbl->setObjectName("TextLabel"); // Pour le CSS
    lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lbl->setWordWrap(true);
    layout->addWidget(lbl);

    // 4. EFFET D'OMBRE (Pour l'effet "Flottant")
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(popup);
    shadow->setBlurRadius(20);
    shadow->setXOffset(0);
    shadow->setYOffset(5);
    shadow->setColor(QColor(0, 0, 0, 100)); // Ombre noire semi-transparente
    popup->setGraphicsEffect(shadow);

    // 5. TAILLE ET POSITION
    popup->resize(400, 90); // Plus large et moins haut pour un look "Toast"

    // Position : Bas Droite avec une marge
    int x = this->width() - popup->width() - 30;
    int y = this->height() - popup->height() - 30;
    popup->move(x, y);

    // 6. ANIMATION D'ENTRÉE (Optionnel : petit fondu)
    popup->setWindowOpacity(0.0);
    popup->show();
    popup->raise();

    // Petit timer pour l'effet d'apparition (fade in) fait main
    QTimer *fadeTimer = new QTimer(popup);
    connect(fadeTimer, &QTimer::timeout, [popup, fadeTimer](){
        double op = popup->windowOpacity();
        if(op < 1.0) {
            popup->setWindowOpacity(op + 0.1);
        } else {
            fadeTimer->stop();
            fadeTimer->deleteLater();
        }
    });
    fadeTimer->start(30); // Vitesse de l'animation

    // Fermeture automatique après 6 secondes
    QTimer::singleShot(6000, popup, &QWidget::close);
}

void MainWindow::handlePopupTimer()
{
        // 1. Vérification sécurisée : On vérifie directement le widget, pas le numéro.
        // Si la page affichée est "page_3" (Résidence), alors on affiche le message.
        if (ui->stackedWidget->currentWidget() == ui->page_3) {

            QString message = getMessageForCurrentTime();

            if (!message.isEmpty()) {
                afficherNotification(message);
            }
        }
    }
