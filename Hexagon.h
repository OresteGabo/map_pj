//
// Created by oreste on 04/01/24.
//

#ifndef MAP_PJ_HEXAGON_H
#define MAP_PJ_HEXAGON_H

#include <QPointF>
#include <QPolygonF>
#include <QPainter>

class Hexagon {
public:
    Hexagon(const QPointF& center, qreal size);

    void draw(QPainter& painter) const;

private:
    QPointF center;
    qreal size;
};


#endif //MAP_PJ_HEXAGON_H
