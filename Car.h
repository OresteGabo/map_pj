//
// Created by oreste on 04/01/24.
//

#ifndef MAP_PJ_CAR_H
#define MAP_PJ_CAR_H


// Car.h
#pragma once


#include<cmath>

// Car.h
#pragma once

#include <QPainter>
#include <QPointF>
#include "PathNode.h"

class Car {
public:
    Car(PathNode* destinationPathHead = nullptr, double speed = 100.0);

    void updatePosition(qreal elapsedTime);
    void draw(QPainter& painter) const;
    void setPosition(const QPointF&);

private:
    QPointF position;
    qreal speed;
    PathNode* destinationPathHead;
    PathNode* nextDestinationNode;
};

#endif //MAP_PJ_CAR_H