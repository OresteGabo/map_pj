//
// Created by oreste on 04/01/24.
//

#include "Arret.h"
// Arret.cpp
#include "Arret.h"
#include <QPainter>

Arret::Arret(const QString& id, int x, int y) : QPointF(x, y), id(id) {
}

const QString& Arret::getName() const {
    return id;
}

void Arret::draw(QPainter& painter) const {
    // Draw the Arret as a red rectangle with its ID
    painter.setBrush(QBrush(Qt::red));
    painter.drawRect(x(), y(), 30, 15);

    // Draw the Arret's ID inside the rectangle
    painter.drawText(x(), y(), 30, 15, Qt::AlignCenter, id);
}
