#ifndef TOASTNOTIFICATION_H
#define TOASTNOTIFICATION_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QPropertyAnimation>
#include <QScreen>
#include <QGuiApplication>
#include <QApplication>

class ToastNotification : public QWidget
{
    Q_OBJECT
public:
    explicit ToastNotification(QWidget *parent = nullptr);

private slots:
    void fadeOut(); // Pour l'animation de fermeture

private:
    QLabel *label;
    QTimer *timer;
    float opacity;
};

#endif // TOASTNOTIFICATION_H
