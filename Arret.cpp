//
// Created by oreste on 04/01/24.
//

#include "Arret.h"
// Arret.cpp
#include "Arret.h"
#include <QPainter>
#include <QPainterPath>

Arret::Arret(const QString& id, int x, int y) : QPointF(x, y), id(id) {
}

const QString& Arret::getName() const {
    return id;
}

void Arret::draw(QPainter& painter) const {
    // Draw the Arret as a red rectangle with its ID
    QPainterPath path;
    int width = 20, height = 20;
    painter.setPen(Qt::white);
    QRectF roundedRect(x() - (width / 2), y() - (height / 2), width, height);
    path.addRoundedRect(roundedRect, width/6, height/6);  // Adjust the radii according to your preference

    // Set the brush and draw the rounded rectangle
    painter.setBrush(QBrush(Qt::red));
    painter.drawPath(path);

    // Draw the Arret's ID inside the rounded rectangle
    painter.drawText(roundedRect, Qt::AlignCenter, id);
    painter.setPen(Qt::black);
}
void Arret::logMessage(const QString &message, QPlainTextEdit *debugOutput )const {
    debugOutput->appendPlainText(message);
}

void Arret::setName(const QString &name) {
    id=name;
}
