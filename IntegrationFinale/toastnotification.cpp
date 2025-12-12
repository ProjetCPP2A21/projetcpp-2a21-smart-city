#include "toastnotification.h"


ToastNotification::ToastNotification(const QString &message, QWidget *parent)
    : QWidget(parent)
{
    // --- 1. Configuration de la fenêtre ---
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground); // Permet la transparence
    setAttribute(Qt::WA_ShowWithoutActivating); // Ne vole pas le focus

    // --- 2. Style (CSS) - Adaptez les couleurs ici ---
    // Background: #2c3e50 (Bleu foncé NeoCity), Texte: Blanc, Bordure arrondie
    setStyleSheet(
        "QWidget {"
        "   background-color: #2c3e50;"
        "   color: white;"
        "   border: 1px solid #1abc9c;"
        "   border-radius: 10px;"
        "   padding: 10px;"
        "}"
        "QLabel {"
        "   background-color: transparent;"
        "   font-size: 14px;"
        "   font-weight: bold;"
        "}"
        );

    // --- 3. Mise en page ---
    QVBoxLayout *layout = new QVBoxLayout(this);
    label = new QLabel(message, this);
    label->setWordWrap(true); // Permet au texte de passer à la ligne
    label->setAlignment(Qt::AlignCenter);

    // Ajout d'une icône (Optionnel : vous pouvez mettre votre logo)
    // label->setPixmap(QPixmap(":/images/logo.png").scaled(30,30));

    layout->addWidget(label);
    setLayout(layout);

    // Ajuster la taille
    setFixedSize(300, 100);

    // --- 4. Positionnement (En bas à droite) ---
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeom = screen->availableGeometry();

    int x = screenGeom.width() - this->width() - 20; // 20px de marge à droite
    int y = screenGeom.height() - this->height() - 20; // 20px de marge en bas

    move(x, y);

    // --- 5. Timer pour fermer automatiquement après 5 secondes ---
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ToastNotification::close);
    timer->start(5000); // Disparaît après 5000ms (5 secondes)
}

void ToastNotification::fadeOut()
{
    // Fonction vide pour l'instant,
    // l'animation peut être ajoutée ici si vous voulez un effet de fondu.
    this->close();
}
