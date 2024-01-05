// Hexagon.h
#ifndef MAP_PJ_HEXAGON_H
#define MAP_PJ_HEXAGON_H

#include <QPointF>
#include <QPolygonF>
#include <QPainter>

class Hexagon : public QPolygonF {
public:
    Hexagon(const QPointF& center, qreal size, bool isCarInside = false);

    void draw(QPainter& painter) const;
    bool isPointInside(const QPointF& point) const;
    void setIsCarInside(bool isCarInside);

private:
    bool isCarInside;
};

#endif // MAP_PJ_HEXAGON_H
