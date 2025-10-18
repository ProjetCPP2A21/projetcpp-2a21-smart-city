#include "evenement.h"

Evenement::Evenement(int ID, string Nom, string Type, int Date, int Heure, string Lieu, int Nbr_Participants)
{
    this->ID = ID;
    this->Nom = Nom;
    this->Type = Type;
    this->Date = Date;
    this->Heure = Heure;
    this->Lieu = Lieu;
    this->Nbr_Participants = Nbr_Participants;
}
