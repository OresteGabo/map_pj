// App.cpp
#include "App.h"

// App.cpp
#include "App.h"

App::App() {
    initialize();
}

void App::initialize() {
    // Create and initialize Arrets

    Arret* arret1 = new Arret("1", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret2 = new Arret("2", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret3 = new Arret("3", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret4 = new Arret("4", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret5 = new Arret("5", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret6 = new Arret("6", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret7 = new Arret("7", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret8 = new Arret("8", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret9 = new Arret("9", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret10 = new Arret("10", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret11 = new Arret("11", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret12 = new Arret("12", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret13 = new Arret("13", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret14 = new Arret("14", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret15 = new Arret("15", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret16 = new Arret("16", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret17 = new Arret("17", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret18 = new Arret("18", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret19 = new Arret("19", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret20 = new Arret("20", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));
    Arret* arret21 = new Arret("21", QRandomGenerator::global()->bounded(1200), QRandomGenerator::global()->bounded(1000));


    // Add Arrets to the vector
    arrets.push_back(arret1);
    arrets.push_back(arret2);
    arrets.push_back(arret3);
    arrets.push_back(arret4);
    arrets.push_back(arret5);
    arrets.push_back(arret6);
    arrets.push_back(arret7);
    arrets.push_back(arret8);
    arrets.push_back(arret9);
    arrets.push_back(arret10);
    arrets.push_back(arret11);
    arrets.push_back(arret12);
    arrets.push_back(arret13);
    arrets.push_back(arret14);
    arrets.push_back(arret15);
    arrets.push_back(arret16);
    arrets.push_back(arret17);
    arrets.push_back(arret18);
    arrets.push_back(arret19);
    arrets.push_back(arret20);
    arrets.push_back(arret21);

    // Create and initialize Cars
    /*PathNode *node00,*node01,*node02,*node03;
    PathNode *node10,*node11,*node12,*node13;
    PathNode *node20,*node21,*node22,*node23;*/

    PathNode* node00 = new PathNode(arret1);
    PathNode* node01 = new PathNode(arret1);
    PathNode* node02 = new PathNode(arret2);
    PathNode* node03 = new PathNode(arret3);
    PathNode* node10 = new PathNode(arret4);
    PathNode* node11 = new PathNode(arret5);
    PathNode* node12 = new PathNode(arret6);
    PathNode* node13 = new PathNode(arret7);
    PathNode* node20 = new PathNode(arret8);
    PathNode* node21 = new PathNode(arret9);
    PathNode* node22 = new PathNode(arret10);
    PathNode* node23 = new PathNode(arret12);


    node00->next=node01;
    node01->next=node02;
    node02->next=node03;

    node10->next=node11;
    node11->next=node12;
    node12->next=node13;

    node20->next=node21;
    node21->next=node22;
    node22->next=node23;

    auto car1 = new Car(node00, 50.0);  // Car associated with Arret 1
    auto car2 = new Car(node10, 150.0);  // Car associated with Arret 2
    auto car3 = new Car(node20, 120.0);  // Car associated with Arret 3

    // Add Cars to the vector
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);

    /* Add Cars to corresponding Arrets
    arret1->addCar(car1);
    arret2->addCar(car2);
    arret3->addCar(car3);*/
}

const std::vector<Arret*>& App::getArrets() const {
    return arrets;
}

const std::vector<Car*>& App::getCars() const {
    return cars;
}

void App::drawArrets(QPainter& painter) const {
    // Draw all Arrets in the App
    for (const Arret* arret : arrets) {
        arret->draw(painter);
    }
}

void App::drawCars(QPainter& painter) const {
    // Draw all Cars in the App
    for (const Car* car : cars) {
        car->draw(painter);
    }
}
