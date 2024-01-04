// App.cpp
#include "App.h"

// App.cpp
#include "App.h"

App::App() {
    initialize();
}

void App::initialize() {
    // Create and initialize Arrets
    Arret* arret1 = new Arret("1", 100, 100);
    Arret* arret2 = new Arret("2", 300, 200);
    Arret* arret3 = new Arret("3", 500, 300);
    Arret* arret4 = new Arret("1", 100, 100);
    Arret* arret5 = new Arret("2", 300, 200);
    Arret* arret6 = new Arret("3", 500, 300);
    Arret* arret7 = new Arret("1", 100, 100);
    Arret* arret8 = new Arret("2", 300, 200);
    Arret* arret9 = new Arret("3", 500, 300);
    Arret* arret10 = new Arret("1", 100, 100);
    Arret* arret11 = new Arret("2", 300, 200);
    Arret* arret12 = new Arret("3", 500, 300);
    Arret* arret13 = new Arret("1", 100, 100);
    Arret* arret14 = new Arret("2", 300, 200);
    Arret* arret15 = new Arret("3", 500, 300);
    Arret* arret16 = new Arret("1", 100, 100);
    Arret* arret17 = new Arret("2", 300, 200);
    Arret* arret18 = new Arret("3", 500, 300);
    Arret* arret19 = new Arret("1", 100, 100);
    Arret* arret20 = new Arret("2", 300, 200);
    Arret* arret321 = new Arret("3", 500, 300);

    // Add Arrets to the vector
    arrets.push_back(arret1);
    arrets.push_back(arret2);
    arrets.push_back(arret3);

    // Create and initialize Cars
    PathNode *node00,*node01,*node02,*node03;
    PathNode *node10,*node11,*node12,*node13;
    PathNode *node20,*node21,*node22,*node23;

    node00=new PathNode(arret1);
    node01=new PathNode(arret1);
    node02=new PathNode(arret2);
    node03=new PathNode(arret3);
    node10=new PathNode(arret4);
    node11=new PathNode(arret5);
    node12=new PathNode(arret6);
    node13=new PathNode(arret7);
    node20=new PathNode(arret8);
    node21=new PathNode(arret9);
    node22=new PathNode(arret10);
    node23=new PathNode(arret12);


    node00->next=node01;
    node01->next=node02;
    node02->next=node03;

    node10->next=node11;
    node11->next=node12;
    node12->next=node13;

    node20->next=node21;
    node21->next=node22;
    node22->next=node23;



    auto car1 = new Car(node00, 100.0);  // Car associated with Arret 1
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
