#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QWidget>

class Statistique : public QWidget
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *parent = nullptr);

    // Pour mettre à jour les valeurs depuis GEvenement
    void setData(int musique, int cinema, int autre);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_musique;
    int m_cinema;
    int m_autre;
};

#endif // STATISTIQUE_H
