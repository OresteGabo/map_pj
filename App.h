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
#include <QRandomGenerator>

class App {
public:
    App();

    void initialize(); // Initialize Arrets and Cars

    const std::vector<Arret*>& getArrets() const;
    const std::vector<Car*>& getCars() const;
    void drawArrets(QPainter& painter) const;
    void drawCars(QPainter& painter) const;


private:
    std::vector<Arret*> arrets;
    std::vector<Car*> cars;
};



#endif //MAP_PJ_APP_H





