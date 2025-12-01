#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
using namespace std;
struct ImpactResult {
    float co2;
    float pollution;
    float impact;
};

class Evenement
{
    int ID;
    int ID_Employe;
    QString Nom;
    QString Type;
    QDate Date;
    QString Heure;
    QString Lieu;
    int Nbr_Participants;
public:
    Evenement();
    Evenement(int ID,int ID_Employe, QString Nom, QString Type, QDate Date, QString Heure, QString Lieu, int Nbr_Participants);
    ~Evenement();

    //Getters
    int getID(){return ID;}
    int getID_Employe(){return ID_Employe;}
    QString getNom(){return Nom;}
    QString getType(){return Type;}
    QDate getDate(){return Date;}
    QString getHeure(){return Heure;}
    QString getLieu(){return Lieu;}
    int getNbr_Participants(){return Nbr_Participants;}

    // setters
    void setID(int id){ID = id;}
    void setID_Employe(int IDE){ID_Employe = IDE;}
    void setNom(QString n){Nom = n;}
    void setType(QString T){Type = T;}
    void setDate(QDate D){Date = D;}
    void setHeure(QString H){Heure = H;}
    void setLieu(QString L){Lieu = L;}
    void setNbr_Participants(int Nbr){Nbr_Participants = Nbr;}

    // CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int id);

    //metier
    QSqlQueryModel *rechercher(int id);


    //metiers Avancés
    ImpactResult predireImpact(int id);
    QString RecupererLieu(int);
};

#endif // EVENEMENT_H
