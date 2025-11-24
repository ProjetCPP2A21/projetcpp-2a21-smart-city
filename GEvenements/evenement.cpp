#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <iostream>
#include <onnxruntime_cxx_api.h>
#include <QCoreApplication>
#include <algorithm>
#include <vector>
#include "classification.h"



//costructeur par défaut
Evenement::Evenement()
{
    ID = 0;
    Nom = "";
    Type = "";
    Heure = "";
    Lieu = "";
    Nbr_Participants = 0;
}
// constructeur paramétré
Evenement::Evenement(int ID,int ID_Employe, QString Nom, QString Type, QDate Date, QString Heure, QString Lieu, int Nbr_Participants)
{
    this->ID = ID;
    this->ID_Employe = ID_Employe;
    this->Nom = Nom;
    this->Type = Type;
    this->Date = Date;
    this->Heure = Heure;
    this->Lieu = Lieu;
    this->Nbr_Participants = Nbr_Participants;
}

Evenement::~Evenement() {}

// ajouter un évènement
 bool Evenement::ajouter()
{
     QSqlQuery query;
    QString res = QString::number(ID);
     query.prepare("INSERT INTO evenement (ID_Evenement, ID_Employe, Nom, Type_Evenement, Date_Evenement, Heure, Lieu, Nbr_Participants) "
                   "VALUES (:ID_Evenement, :ID_Employe, :Nom, :Type_Evenement, :Date_Evenement, :Heure, :Lieu, :Nbr_Participants)");
    // liaison entre les attributs de la classe et de la table en base de donnée
    query.bindValue(":ID_Evenement", ID);
    query.bindValue(":ID_Employe", ID_Employe);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Type_Evenement", Type);
    query.bindValue(":Date_Evenement", Date);
    query.bindValue(":Heure", Heure);
    query.bindValue(":Lieu", Lieu);
    query.bindValue(":Nbr_Participants", Nbr_Participants);

    return query.exec();
}
// supprimer un évènement
bool Evenement::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from Evenement where ID_Evenement = :id");
    query.bindValue(":id", res);
    return query.exec();
}
// afficher un évènement
QSqlQueryModel *Evenement::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EVENEMENT, ID_EMPLOYE, NOM, TYPE_EVENEMENT, "
                    "DATE_EVENEMENT,"
                    "HEURE, LIEU, NBR_PARTICIPANTS "
                    "FROM EVENEMENT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_Evenement"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Type_Evenement"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Date_Evenement"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("Nbr_Participants"));
    return model;
}
// modifier un évènement
bool Evenement::modifier(int id)
{
    QSqlQuery query(QSqlDatabase::database("oracleConnection")); // utilise la connexion existante

    query.prepare("UPDATE Evenement "
                  "SET Nom = :nom, "
                  "Type_Evenement = :type, "
                  "Date_Evenement = :date, "
                  "Heure = :heure, "
                  "Lieu = :lieu, "
                  "Nbr_Participants = :nbr "
                  "WHERE ID_Evenement = :id");

    query.bindValue(":nom", Nom);
    query.bindValue(":type", Type);
    query.bindValue(":date", Date);
    query.bindValue(":heure", Heure);
    query.bindValue(":lieu", Lieu);
    query.bindValue(":nbr", Nbr_Participants);
    query.bindValue(":id", id);

    if(!query.exec())
    {
        qDebug() << "Erreur modification Evenement :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel *Evenement::rechercher(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Vérifie si l'ID existe
    QSqlQuery query;
    query.prepare("SELECT * FROM Evenement WHERE ID_Evenement = :id");
    query.bindValue(":id", id);
    query.exec();

    if (!query.next()) { // aucun résultat
        return nullptr; // on retournera nullptr si ID invalide
    }

    // Si ID existe, on le charge dans le modèle
    model->setQuery(query);

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_Evenement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_Evenement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Evenement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nbr_Participants"));

    return model;
}

ImpactResult Evenement::predireImpact(int id)
{
    // =========================================================
    // 🔹 ÉTAPE 1 : RÉCUPÉRATION DES DONNÉES (SQL)
    // =========================================================
    QSqlQuery query;
    query.prepare("SELECT Type_Evenement, lieu, nbr_Participants FROM evenement WHERE id_evenement = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        qWarning() << "⚠️ Impossible de trouver l'événement avec l'ID :" << id;
        return {-1, -1, -1};
    }

    QString type = query.value(0).toString().toLower();
    QString lieu = query.value(1).toString().toLower();
    int nbrParticipants = query.value(2).toInt();
    // 🔹 Étape 2 : déterminer le type (0 = intérieur, 1 = extérieur)
    // 🔹 Étape 2 : Déterminer le type avec notre IA (Bayes)
    // ----------------------------------------------------

    // On déclare l'IA en "static" pour qu'elle ne s'initialise qu'une seule fois (performance)
    static Classification intelligenceArtificielle;

    // On combine le type et le lieu pour donner un maximum de contexte
    QString texteAAnalyser = type + " " + lieu;

    // L'IA calcule le score et décide
    int type_code = intelligenceArtificielle.predire(texteAAnalyser);

    if (type_code == 1) {
        qDebug() << "🧠 IA : Analyse de '" << texteAAnalyser << "' -> Détecté comme EXTÉRIEUR";
    } else {
        qDebug() << "🧠 IA : Analyse de '" << texteAAnalyser << "' -> Détecté comme INTÉRIEUR";
    }

    // ----------------------------------------------------

    // =========================================================
    // 🔹 ÉTAPE 4 : CALCUL D'IMPACT (ONNX)
    // =========================================================
    const OrtApi* g_ort = OrtGetApiBase()->GetApi(ORT_API_VERSION);
    OrtEnv* env = nullptr;
    g_ort->CreateEnv(ORT_LOGGING_LEVEL_WARNING, "GEvenement", &env);

    OrtSessionOptions* session_options = nullptr;
    g_ort->CreateSessionOptions(&session_options);

    QString modelPath = QCoreApplication::applicationDirPath() + "/impact_model.onnx";

    // Gestion propre du chemin (Windows vs Mac/Linux)
#ifdef Q_OS_WIN
    std::wstring wModelPath = modelPath.toStdWString();
    const ORTCHAR_T* modelPathStr = wModelPath.c_str();
#else
    std::string sModelPath = modelPath.toStdString();
    const ORTCHAR_T* modelPathStr = sModelPath.c_str();
#endif

    OrtSession* session = nullptr;
    OrtStatus* status = g_ort->CreateSession(env, modelPathStr, session_options, &session);

    if (status != nullptr) {
        const char* msg = g_ort->GetErrorMessage(status);
        std::cerr << "Erreur chargement ONNX : " << msg << std::endl;
        g_ort->ReleaseStatus(status);
        g_ort->ReleaseSessionOptions(session_options);
        g_ort->ReleaseEnv(env);
        return {-1, -1, -1};
    }

    // Préparation des données [Type (0/1), Participants]
    float input_data[2] = { float(type_code), float(nbrParticipants) };
    int64_t dims[2] = {1, 2};

    OrtMemoryInfo* memory_info = nullptr;
    g_ort->CreateCpuMemoryInfo(OrtArenaAllocator, OrtMemTypeDefault, &memory_info);

    OrtValue* input_tensor = nullptr;
    g_ort->CreateTensorWithDataAsOrtValue(memory_info, input_data, sizeof(input_data),
                                          dims, 2, ONNX_TENSOR_ELEMENT_DATA_TYPE_FLOAT, &input_tensor);

    const char* input_names[] = {"float_input"};
    const char* output_names[] = {"variable"};

    OrtValue* output_tensor = nullptr;
    g_ort->Run(session, nullptr, input_names, (const OrtValue* const*)&input_tensor, 1,
               output_names, 1, &output_tensor);

    // Lecture du résultat
    float* output_data = nullptr;
    g_ort->GetTensorMutableData(output_tensor, (void**)&output_data);

    ImpactResult result;
    result.co2 = output_data[0];
    result.pollution = output_data[1];
    result.impact = std::clamp(output_data[2], 0.0f, 1.0f); // Borne entre 0 et 1

    // Nettoyage ONNX
    g_ort->ReleaseValue(output_tensor);
    g_ort->ReleaseValue(input_tensor);
    g_ort->ReleaseMemoryInfo(memory_info);
    g_ort->ReleaseSession(session);
    g_ort->ReleaseSessionOptions(session_options);
    g_ort->ReleaseEnv(env);

    return result;
}
QString Evenement::RecupererLieu(int id)
{
    QSqlQuery query;
    query.prepare("SELECT lieu FROM evenement WHERE Id_Evenement = :id");
    query.bindValue(":id", id);

    if(query.exec()) {
        if(query.next()) {
            return query.value(0).toString();   // retourne le lieu
        }
    }

    return ""; // Retourne vide si rien trouvé
}

