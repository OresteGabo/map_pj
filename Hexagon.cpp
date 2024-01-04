//
// Created by oreste on 04/01/24.
//

#include "Hexagon.h"
// Hexagon.cpp
#include "Hexagon.h"
#include <cmath>

Hexagon::Hexagon(const QPointF& center, qreal size) : center(center), size(size) {}

void Hexagon::draw(QPainter& painter) const {
    QPolygonF hexagon;
    for (int i = 0; i < 6; ++i) {
        qreal angle = 2 * M_PI * i / 6.0;
        qreal x = center.x() + size * cos(angle);
        qreal y = center.y() + size * sin(angle);
        hexagon << QPointF(x, y);
    }

    painter.drawPolygon(hexagon);
}
