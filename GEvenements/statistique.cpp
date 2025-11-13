#include "statistique.h"
#include <QPainter>
#include <QFont>

Statistique::Statistique(QWidget *parent)
    : QWidget(parent),
    m_musique(0),
    m_cinema(0),
    m_autre(0)
{
    // taille minimale pour que le camembert soit visible
    setMinimumSize(250, 250);
}

void Statistique::setData(int musique, int cinema, int autre)
{
    m_musique = musique;
    m_cinema  = cinema;
    m_autre   = autre;
    update();      // redessiner le widget
}

void Statistique::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    int total = m_musique + m_cinema + m_autre;
    if (total <= 0)
        return;

    int margin = 10;
    int size = qMin(width(), height()) - 2 * margin;
    QRect rect(margin, margin, size, size);

    double fMus = (double)m_musique / total;
    double fCin = (double)m_cinema / total;
    double fAut = (double)m_autre  / total;

    int startAngle = 0;
    int spanMus = qRound(fMus * 360 * 16);
    int spanCin = qRound(fCin * 360 * 16);
    int spanAut = 360 * 16 - spanMus - spanCin;

    // Musique
    p.setBrush(QColor(0, 51, 102));      // bleu foncé
    p.setPen(Qt::NoPen);
    p.drawPie(rect, startAngle, spanMus);
    startAngle += spanMus;

    // Cinéma
    p.setBrush(QColor(102, 204, 255));   // bleu clair
    p.drawPie(rect, startAngle, spanCin);
    startAngle += spanCin;

    // Autre
    p.setBrush(QColor(255, 0, 0));       // rouge
    p.drawPie(rect, startAngle, spanAut);

    // Légendes simples au centre (facultatif)
    p.setPen(Qt::black);
    QFont f = font();
    f.setPointSize(9);
    p.setFont(f);

    auto drawLabel = [&](double fraction, const QString &text, int dy) {
        if (fraction <= 0.0) return;
        int percent = qRound(fraction * 100);
        QString label = text + " " + QString::number(percent) + "%";
        p.drawText(rect.adjusted(0, dy, 0, 0), Qt::AlignCenter, label);
    };

    drawLabel(fMus, "Musique", -15);
    drawLabel(fCin, "Cinéma", 5);
    drawLabel(fAut, "Autre", 25);
}
