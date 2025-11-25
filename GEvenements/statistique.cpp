#include "statistique.h"
#include <QPainter>
#include <QFont>
#include <QtCharts>
#include <QVBoxLayout>

Statistique::Statistique(QWidget *parent)
    : QWidget(parent)
{
}

void Statistique::setData(int nbMusique, int nbCinema, int nbAutre)
{
    // 1. Création de la série
    QPieSeries *series = new QPieSeries();

    // --- OPTIMISATION TAILLE ---
    // On augmente la taille du cercle (0.7 = 70% de l'espace)
    series->setPieSize(0.55);
    series->setHoleSize(0.25); // Donut

    int total = nbMusique + nbCinema + nbAutre;

    // Configuration de la police (Gras et taille 9 pour être bien visible)
    QFont font("Arial", 9, QFont::Bold);

    // Fonction lambda pour configurer chaque part rapidement
    auto configurerSlice = [&](QPieSlice *slice, QString colorCode, QString texte) {
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setBrush(QColor(colorCode));
        slice->setLabelFont(font);

        // --- ASTUCE IMPORTANTE ---
        // On raccourcit la ligne qui pointe vers le texte (0.15 est très court)
        // Cela permet de rapprocher le texte du centre et d'éviter qu'il sorte du cadre.
        slice->setLabelArmLengthFactor(0.15);

        slice->setLabel(texte);
        // Couleur du texte (optionnel, pour faire joli)
        slice->setLabelColor(Qt::black);
    };

    // --- Part 1 : Musique ---
    QPieSlice *s1 = series->append("Musique", nbMusique);
    if (total > 0 && nbMusique > 0) {
        QString label = QString("Musique\n%1%").arg(QString::number((double)nbMusique/total*100, 'f', 1));
        configurerSlice(s1, "#002554", label);
    } else {
        s1->setLabelVisible(false); // On cache si 0
    }

    // --- Part 2 : Cinéma ---
    QPieSlice *s2 = series->append("Cinéma", nbCinema);
    if (total > 0 && nbCinema > 0) {
        QString label = QString("Cinéma\n%1%").arg(QString::number((double)nbCinema/total*100, 'f', 1));
        configurerSlice(s2, "#87CEEB", label);
    } else {
        s2->setLabelVisible(false);
    }

    // --- Part 3 : Autre ---
    QPieSlice *s3 = series->append("Autre", nbAutre);
    if (total > 0 && nbAutre > 0) {
        QString label = QString("Autre\n%1%").arg(QString::number((double)nbAutre/total*100, 'f', 1));
        configurerSlice(s3, "#FF0000", label);
    } else {
        s3->setLabelVisible(false);
    }

    // 2. Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des types d'évènement");
    chart->setTitleFont(QFont("Arial", 10, QFont::Bold));
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->hide();

    // --- OPTIMISATION ESPACE ---
    // Marges à 0 absolu pour coller aux bords du frame
    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundRoundness(0); // Supprime les coins arrondis qui mangent de la place

    // 3. Vue
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 4. Nettoyage et affichage
    if (layout()) {
        QLayoutItem *item;
        while ((item = layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout();
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    // Marges du layout à 0 aussi
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(chartView);
    this->setLayout(layout);
}

void Statistique::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}
