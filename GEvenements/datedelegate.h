#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QDate>

class DateDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    QString displayText(const QVariant &value, const QLocale &locale) const override {
        // Si la valeur est une date/heure, on retourne juste la date formatée
        if (value.type() == QVariant::Date || value.type() == QVariant::DateTime) {
            return value.toDate().toString("dd/MM/yyyy");
        }
        return QStyledItemDelegate::displayText(value, locale);
    }
};
#endif // DATEDELEGATE_H
