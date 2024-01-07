//
// Created by oreste on 07/01/24.
//

#ifndef MAP_PJ_CARCONNECTIONMANAGER_H
#define MAP_PJ_CARCONNECTIONMANAGER_H


#include <QObject>
#include <QVector>

class Car;

class CarConnectionManager : public QObject {
Q_OBJECT
public:
    static CarConnectionManager* instance();
    void addConnectedCars(Car* car1, Car* car2);
    void removeConnectedCars(Car* car1, Car* car2);
    bool areCarsConnected(Car* car1, Car* car2);
    void updateConnections(const QVector<Car*>& cars);
    const QVector<QPair<Car *, Car *>> &getConnectedCars() const;

private:
public:



private:
    CarConnectionManager();
    QVector<QPair<Car*, Car*>> connectedCars;
};


#endif //MAP_PJ_CARCONNECTIONMANAGER_H
