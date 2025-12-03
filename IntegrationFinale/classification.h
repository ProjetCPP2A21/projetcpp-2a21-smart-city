#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <QString>

class Classification
{
private :
    // La mémoire de l'IA : elle retient combien de fois un mot apparaît dans chaque catégorie
    std::map<std::string, int> mots_interieur;
    std::map<std::string, int> mots_exterieur;
    int total_mots_interieur = 0;
    int total_mots_exterieur = 0;

    std::vector<std::string> tokeniser(std::string texte);
public:
    Classification();

    void apprendre(std::string texte, int categorie);
    int predire(QString qTexte);
    void initialiser();
};

#endif // CLASSIFICATION_H
