#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
using namespace std;

class Evenement
{
    int ID;
    string Nom;
    string Type;
    int Date;
    int Heure;
    string Lieu;
    int Nbr_Participants;
public:
    Evenement();
    Evenement(int ID, string Nom, string Type, int Date, int Heure, string Lieu, int Nbr_Participants);
    ~Evenement();

    //Getters
    int getID(){return ID;}
    string getNom(){return Nom;}
    string getType(){return Type;}
    int getDate(){return Date;}
    int getHeure(){return Heure;}
    string getLieu(){return Lieu;}
    int getNbr_Participants(){return Nbr_Participants;}

    // setters
    void setID(int id){ID = id;}
    void setNom(string n){Nom = n;}
    void setType(string T){Type = T;}
    void setDate(int D){Date = D;}
    void setHeure(int H){Heure = H;}
    void setLieu(string L){Lieu = L;}
    void setNbr_Participants(int Nbr){Nbr_Participants = Nbr;}

    // CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);

};

#endif // EVENEMENT_H
