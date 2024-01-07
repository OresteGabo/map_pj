//
// Created by oreste on 04/01/24.
//
#ifndef MAP_PJ_APP_H
#define MAP_PJ_APP_H




#include <vector>
#include "Arret.h"

// App.h
#pragma once

#include <vector>
#include "Arret.h"
#include "Car.h"
#include "Path.h"
#include "Hexagon.h"
#include <QRandomGenerator>
#include "CarConnectionManager.h"

class App {
public:
    App();

    void initialize(); // Initialize Arrets and Cars

    const std::vector<Arret*>& getArrets() const;
    const std::vector<Car*>& getCars() const;
    void drawArrets(QPainter& painter) const;
    void drawCars(QPainter& painter) const;
    void drawPaths(QPainter& painter) const;
    void logMessage(const QString &message, QPlainTextEdit *debugOutput )const;
    void updateHexagons();
    void drawHexagons(QPainter&)const;
    void initialiseHexagones();

    void updateCarPositions(qreal elapsedTime);
    void dessineApp(QPainter& painter,bool arretsVisible);


private:
    std::vector<Arret*> arrets;
    std::vector<Car*> cars;
    std::vector<Path*>paths;
    QVector<Hexagon> hexagons;
};



#endif //MAP_PJ_APP_H





