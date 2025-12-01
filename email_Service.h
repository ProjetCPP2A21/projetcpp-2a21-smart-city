#ifndef EMAIL_H
#define EMAIL_H

#include <QObject>
#include <QTcpSocket>
#include <QSslSocket>
#include <QString>

class Email : public QObject
{
    Q_OBJECT
public:
    explicit Email(QObject *parent = nullptr);
    ~Email();

    // Méthode SMTP générique
    bool envoyerSMTP(const QString &to, const QString &sujet, const QString &corps);

    // Méthodes spécialisées
    void envoyerChangementService(const QString &to, const QString &serviceName,
                                  const QString &ancienType, const QString &nouveauType);
    void envoyerChangementStatut(const QString &to, const QString &serviceName,
                                 const QString &ancienStatut, const QString &nouveauStatut);
    void envoyerBudgetDepasse(const QString &to, double budget, double limite,
                              const QString &serviceName);
    void envoyerServiceSupprime(const QString &to, const QString &serviceName,
                                const QString &raison);
    void envoyerServiceAjoute(const QString &to, const QString &serviceName,
                              double budget, const QString &type, const QString &priorite);
    void envoyerServiceModifie(const QString &to,
                               const QString &ancienNom,
                               const QString &nouveauNom,
                               double ancienBudget,
                               double nouveauBudget,
                               const QString &ancienType,
                               const QString &nouveauType);

private:
    QString monEmail = "khirallahmaram65@gmail.com";   // ton compte Gmail
    QString mdpApp   = "grpiyfhv conu klmi";    // mot de passe d'application Gmail
};

#endif // EMAIL_H
