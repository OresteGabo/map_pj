//
// Created by oreste on 07/01/24.
//

#include "CarConnectionManager.h"
#include "Car.h"

CarConnectionManager::CarConnectionManager() {}

void CarConnectionManager::addConnectedCars(Car* car1, Car* car2) {
    connectedCars.append(qMakePair(car1, car2));
}

void CarConnectionManager::removeConnectedCars(Car* car1, Car* car2) {
    connectedCars.removeAll(qMakePair(car1, car2));
}

bool CarConnectionManager::areCarsConnected(Car* car1, Car* car2) {
    return connectedCars.contains(qMakePair(car1, car2)) || connectedCars.contains(qMakePair(car2, car1));
}

void CarConnectionManager::updateConnections(const QVector<Car*>& cars) {
    // Save the previous connections
    QVector<QPair<Car *, Car *>> previousConnections = connectedCars;

    // Clear the existing connections
    connectedCars.clear();

    // Iterate through all cars and check for connections
    for (int i = 0; i < cars.size(); ++i) {
        for (int j = i + 1; j < cars.size(); ++j) {
            Car* car1 = cars[i];
            Car* car2 = cars[j];

            // If both conditions are met, add the connection
            if (car1->checkProximity( car2) ) {
                addConnectedCars(car1, car2);
            }
        }
    }

    // Detect new connections and removals
    for (const auto& connection : connectedCars) {
        if (!previousConnections.contains(connection)) {
            qDebug() << "New connection: Car" << connection.first->toString() << " and Car" << connection.second->toString();
        }
    }

    for (const auto& connection : previousConnections) {
        if (!connectedCars.contains(connection)) {
            qDebug() << "Connection removed: Car" << connection.first->toString() << " and Car" << connection.second->toString();
        }
    }
}


const QVector<QPair<Car *, Car *>> &CarConnectionManager::getConnectedCars() const {
    return connectedCars;
}

CarConnectionManager* CarConnectionManager::instance() {
    static CarConnectionManager instance;
    return &instance;
}

