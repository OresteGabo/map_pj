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
#include <qdebug.h>
#include <QPainter>
#include <QPointF>
#include <QPlainTextEdit>
#include "PathNode.h"
#include <QPixmap>
#include<QRandomGenerator>

class Car {
public:
    Car(PathNode* destinationPathHead = nullptr,
        double speed = 100.0,
        const QPixmap& car=QPixmap("car.png"),
        double frequence=QRandomGenerator::global()->bounded(10, 30001)
                );

    void updatePosition(qreal elapsedTime);
    void draw(QPainter& painter) const;
    void logMessage(const QString &message, QPlainTextEdit *debugOutput )const;
    QString toString()const;
    QPointF getPosition()const;
private:
    QPointF position;
    qreal speed;
    const PathNode* destinationPathHead;
    PathNode* nextDestinationNode;
    QPixmap carImage;
    double frequence;
};

#endif //MAP_PJ_CAR_H
