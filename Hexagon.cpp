// Hexagon.cpp
#include "Hexagon.h"
#include <cmath>

Hexagon::Hexagon(const QPointF& center, qreal size, bool isCarInside)
        : isCarInside(isCarInside) {
    // Initialize the polygon in the constructor
    for (int i = 0; i < 6; ++i) {
        qreal angle = 2 * M_PI * i / 6.0;
        qreal x = center.x() + size * cos(angle);
        qreal y = center.y() + size * sin(angle);
        *this << QPointF(x, y);
    }
}

void Hexagon::draw(QPainter& painter) const {
    if (isCarInside) {
        painter.setBrush(QBrush(Qt::green));
    } else {
        painter.setBrush(QBrush(Qt::transparent));
    }

    painter.drawPolygon(*this);
}

bool Hexagon::isPointInside(const QPointF& point) const {
    return this->containsPoint(point, Qt::OddEvenFill);
}

void Hexagon::setIsCarInside(bool i) {
    isCarInside=i;
}
