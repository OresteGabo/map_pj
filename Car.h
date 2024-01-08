//
// Created by oreste on 04/01/24.
//

#ifndef MAP_PJ_CAR_H
#define MAP_PJ_CAR_H


#pragma once
#include <qdebug.h>
#include <QPainter>
#include <QPointF>
#include <QPlainTextEdit>
#include "PathNode.h"
#include <QPixmap>
#include<QRandomGenerator>
#include<cmath>
class PathNode;

class Car {
public:
    Car(int id=0,PathNode* destinationPathHead = nullptr,
        double speed = 100.0,
        const QPixmap& car=QPixmap("car.png"),
        double frequence=QRandomGenerator::global()->bounded(10, 300)
                );

    void updatePosition(qreal elapsedTime,QVector<Car*> allCars);
    void draw(QPainter& painter) const;
    void logMessage(const QString &message, QPlainTextEdit *debugOutput )const;
    QString toString()const;
    QPointF getPosition()const;
    void updateConnectedCars(QVector<Car*> allCars);
    bool connectedTo(const Car*)const ;
    int getRadius()const;
    void resetPosition();

    double getFrequence() const;


    int getId() const;

private:
    QPointF position;
    qreal speed;
    const PathNode* destinationPathHead;
    PathNode* nextDestinationNode;
    QPixmap carImage;
    double frequence;
    QVector<Car*> connectedCars;
public:
    const QVector<Car *> &getConnectedCars() const;

private:
    int id;
public:
};

#endif //MAP_PJ_CAR_H
