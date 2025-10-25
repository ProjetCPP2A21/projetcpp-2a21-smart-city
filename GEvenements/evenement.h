#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
using namespace std;

class Evenement
{
    int ID;
    QString Nom;
    QString Type;
    int Date;
    int Heure;
    QString Lieu;
    int Nbr_Participants;
public:
    Evenement();
    Evenement(int ID, QString Nom, QString Type, int Date, int Heure, QString Lieu, int Nbr_Participants);
    ~Evenement();

    //Getters
    int getID(){return ID;}
    QString getNom(){return Nom;}
    QString getType(){return Type;}
    int getDate(){return Date;}
    int getHeure(){return Heure;}
    QString getLieu(){return Lieu;}
    int getNbr_Participants(){return Nbr_Participants;}

    // setters
    void setID(int id){ID = id;}
    void setNom(QString n){Nom = n;}
    void setType(QString T){Type = T;}
    void setDate(int D){Date = D;}
    void setHeure(int H){Heure = H;}
    void setLieu(QString L){Lieu = L;}
    void setNbr_Participants(int Nbr){Nbr_Participants = Nbr;}

    // CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);

};

#endif // EVENEMENT_H
