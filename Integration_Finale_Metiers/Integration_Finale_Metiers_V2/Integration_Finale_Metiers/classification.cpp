#include "classification.h"

Classification::Classification() {initialiser();}

void Classification::initialiser() {

    // Mots-clés INTÉRIEUR (Label 0)
    apprendre("cinema film salle obscure projection pop-corn", 0);
    apprendre("restaurant diner repas gastronomie manger chef", 0);
    apprendre("bibliotheque livre lecture silence etagere etude", 0);
    apprendre("musee art galerie peinture exposition vernissage", 0);
    apprendre("conference reunion salle debat bureau travail vote", 0);
    apprendre("theatre scene rideau spectacle comedie acteurs", 0);
    apprendre("piscine couverte nager eau", 0);
    apprendre("appartement salon soiree amis maison", 0);
    apprendre("opera classique fauteuil ballet", 0);
    apprendre("hotel chambre reception seminaire", 0);
    apprendre("cafe bistrot boisson table bar", 0);
    apprendre("bowling jeu piste interieur", 0);
    apprendre("salle de concert acoustique", 0);
    apprendre("universite cours amphitheatre culture", 0);
    apprendre("discotheque club danse nuit", 0);

    // Mots-clés EXTÉRIEUR (Label 1)
    apprendre("parc promenade nature arbre banc herbe fleurs", 1);
    apprendre("stade football match gradins rugby supporters", 1);
    apprendre("manifestation rue foule cortege slogan pancarte", 1);
    apprendre("plage sable soleil mer baignade vagues", 1);
    apprendre("randonnee montagne sentier foret bois", 1);
    apprendre("marche place publique etal fruits legumes frais", 1);
    apprendre("festival musique plein air boue rock scene ouverte dj", 1);
    apprendre("camping tente nature feu", 1);
    apprendre("foire brocante vide-grenier rue", 1);
    apprendre("marathon course route bitume", 1);
    apprendre("pique-nique pelouse dejeuner dehors", 1);
    apprendre("feu d'artifice ciel nuit exterieur", 1);
    apprendre("carnaval defile char ville", 1);
    apprendre("barbecue jardin grillade ete", 1);
    apprendre("rue pietonne balade magasin", 1);
    apprendre("place publique rassemblement", 1);
    apprendre("tourisme voyage excursion decouverte visite guide", 1);
    apprendre("oasis désert sud sahara chameau", 1); // Pour Gabès/Sud
    apprendre("mer corniche littoral bord", 1);      // Pour Gabès/Littoral
    apprendre("site archeologique ruines histoire pierres", 1);
    apprendre("gymnase sport interieur basket dojo judo tapis", 0);
}

std::vector<std::string> Classification::tokeniser(std::string texte) {
    std::vector<std::string> tokens;
    // Remplacer la ponctuation par des espaces
    std::replace_if(texte.begin(), texte.end(), [](char c){ return ispunct(c); }, ' ');

    std::stringstream ss(texte);
    std::string mot;
    while (ss >> mot) {
        std::string propre = "";
        for (char c : mot) {
            if (isalpha(c)) propre += tolower(c); // Garder seulement les lettres
        }
        // On ignore les petits mots de liaison (le, la, de...)
        if (propre.length() > 2) tokens.push_back(propre);
    }
    return tokens;
}


// Phase d'apprentissage
void Classification::apprendre(std::string texte, int categorie) {
    std::vector<std::string> mots = tokeniser(texte);
    for (const std::string& mot : mots) {
        if (categorie == 0) { // Intérieur
            mots_interieur[mot]++;
            total_mots_interieur++;
        } else { // Extérieur
            mots_exterieur[mot]++;
            total_mots_exterieur++;
        }
    }
}


// Phase de prédiction (Le calcul de probabilité)
int Classification::predire(QString qTexte) {
    std::string texte = qTexte.toStdString();
    std::vector<std::string> mots = tokeniser(texte);

    // Scores initiaux (logarithmiques pour éviter les erreurs de calcul)
    double score_in = 0.0;
    double score_out = 0.0;

    for (const std::string& mot : mots) {
        // On regarde la fréquence du mot dans nos deux dictionnaires
        // On ajoute +1 (Lissage de Laplace) pour éviter le score zéro si le mot est inconnu

        double freq_in = (double)(mots_interieur[mot] + 1) / (total_mots_interieur + mots_interieur.size());
        double freq_out = (double)(mots_exterieur[mot] + 1) / (total_mots_exterieur + mots_exterieur.size());

        score_in += log(freq_in);
        score_out += log(freq_out);
    }

    // Si le score Extérieur est supérieur, on renvoie 1
    if (score_out > score_in) return 1;
    return 0;
}




