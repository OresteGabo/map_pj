// App.cpp
#include "App.h"

// App.cpp
#include "App.h"
#include "Path.h"

App::App() {
    initialize();
}

void App::initialize() {
        std::vector<Arret*> v = {
            new Arret(QString::number(1), 32, 150),
            new Arret(QString::number(2), 118, 109),
            new Arret(QString::number(3), 55, 183),
            new Arret(QString::number(4), 129, 149),
            new Arret(QString::number(5), 69, 213),
            new Arret(QString::number(6), 145, 182),
            new Arret(QString::number(7), 87, 252),
            new Arret(QString::number(8), 159, 212),
            new Arret(QString::number(9), 4, 295),
            new Arret(QString::number(10), 19, 327),
            new Arret(QString::number(11), 105, 288),
            new Arret(QString::number(12), 177, 252),
            new Arret(QString::number(13), 38, 358),
            new Arret(QString::number(14), 121, 317),
            new Arret(QString::number(15), 196, 276),
            new Arret(QString::number(16), 55, 395),
            new Arret(QString::number(17), 141, 357),
            new Arret(QString::number(18), 215, 319),
            new Arret(QString::number(19), 111, 375),
            new Arret(QString::number(20), 166, 349),
            new Arret(QString::number(21), 90, 464),
            new Arret(QString::number(22), 148, 438),
            new Arret(QString::number(23), 197, 414),
            new Arret(QString::number(24), 244, 393),
            new Arret(QString::number(25), 119, 532),
            new Arret(QString::number(26), 173, 504),
            new Arret(QString::number(27), 229, 478),
            new Arret(QString::number(28), 270, 466),
            new Arret(QString::number(29), 24, 581),
            new Arret(QString::number(30), 51, 646),
            new Arret(QString::number(31), 157, 609),
            new Arret(QString::number(32), 231, 576),
            new Arret(QString::number(33), 302, 548),
            new Arret(QString::number(34), 319, 590),
            new Arret(QString::number(35), 255, 618),
            new Arret(QString::number(36), 242, 630),
            new Arret(QString::number(37), 181, 655),
            new Arret(QString::number(38), 72, 708),
            new Arret(QString::number(39), 31, 725),
            new Arret(QString::number(40), 122, 808),
            new Arret(QString::number(41), 279, 710),
            new Arret(QString::number(42), 285, 737),
            new Arret(QString::number(43), 260, 810),
            new Arret(QString::number(44), 158, 867),
            new Arret(QString::number(45), 204, 925),
            new Arret(QString::number(46), 316, 842),
            new Arret(QString::number(47), 383, 690),
            new Arret(QString::number(48), 398, 645),
            new Arret(QString::number(49), 447, 837),
            new Arret(QString::number(50), 472, 825),
            new Arret(QString::number(51), 283, 925),
            new Arret(QString::number(52), 542, 916),
            new Arret(QString::number(53), 273, 292),
            new Arret(QString::number(54), 294, 332),
            new Arret(QString::number(55), 335, 316),
            new Arret(QString::number(56), 319, 349),
            new Arret(QString::number(57), 315, 341),
            new Arret(QString::number(58), 342, 330),
            new Arret(QString::number(59), 372, 497),
            new Arret(QString::number(60), 366, 462),
            new Arret(QString::number(61), 401, 442),
            new Arret(QString::number(62), 421, 478),
            new Arret(QString::number(63), 445, 525),
            new Arret(QString::number(64), 525, 491),
            new Arret(QString::number(65), 495, 432),
            new Arret(QString::number(66), 580, 390),
            new Arret(QString::number(67), 608, 447),
            new Arret(QString::number(68), 659, 421),
            new Arret(QString::number(69), 538, 308),
            new Arret(QString::number(70), 609, 273),
            new Arret(QString::number(71), 438, 264),
            new Arret(QString::number(72), 415, 223),
            new Arret(QString::number(73), 478, 197),
            new Arret(QString::number(74), 463, 158),
            new Arret(QString::number(75), 524, 122),
            new Arret(QString::number(76), 548, 160),
            new Arret(QString::number(77), 572, 201),
            new Arret(QString::number(78), 609, 185),
            new Arret(QString::number(79), 641, 241),
            new Arret(QString::number(80), 645, 256),
            new Arret(QString::number(81), 668, 289),
            new Arret(QString::number(82), 685, 337),
            new Arret(QString::number(83), 714, 398),
            new Arret(QString::number(84), 876, 318),
            new Arret(QString::number(85), 855, 266),
            new Arret(QString::number(86), 834, 225),
            new Arret(QString::number(87), 818, 169),
            new Arret(QString::number(88), 801, 124),
            new Arret(QString::number(89), 793, 101),
            new Arret(QString::number(90), 843, 72),
            new Arret(QString::number(91), 912, 36),
            new Arret(QString::number(92), 823, 27),
            new Arret(QString::number(93), 759, 9),
            new Arret(QString::number(94), 585, 93),
            new Arret(QString::number(95), 543, 22),
            new Arret(QString::number(96), 424, 78),
            new Arret(QString::number(1), 177, 97),
            new Arret(QString::number(2), 196, 89),
            new Arret(QString::number(3), 225, 162),
            new Arret(QString::number(4), 298, 131),
            new Arret(QString::number(5), 306, 146),
            new Arret(QString::number(6), 259, 59),
            new Arret(QString::number(7), 305, 48),
            new Arret(QString::number(8), 362, 209),
            new Arret(QString::number(9), 399, 192),
            new Arret(QString::number(10), 379, 245),
            new Arret(QString::number(11), 399, 290),
            new Arret(QString::number(12), 429, 354),
            new Arret(QString::number(13), 450, 349),
            new Arret(QString::number(14), 472, 333),
            new Arret(QString::number(15), 508, 594),
            new Arret(QString::number(16), 557, 568),
            new Arret(QString::number(17), 648, 528),
            new Arret(QString::number(18), 567, 709),
            new Arret(QString::number(19), 528, 889),
            new Arret(QString::number(20), 678, 801),
            new Arret(QString::number(21), 744, 749),
            new Arret(QString::number(22), 694, 790),
            new Arret(QString::number(23), 765, 747),
            new Arret(QString::number(24), 810, 733),
            new Arret(QString::number(25), 711, 493),
            new Arret(QString::number(26), 825, 441),
            new Arret(QString::number(27), 923, 703),
            new Arret(QString::number(28), 783, 784),
            new Arret(QString::number(29), 872, 753),
            new Arret(QString::number(30), 909, 843),
            new Arret(QString::number(31), 954, 889),
            new Arret(QString::number(32), 921, 186),
            new Arret(QString::number(33), 942, 233),
            new Arret(QString::number(34), 994, 209),
            new Arret(QString::number(35), 983, 159),
            new Arret(QString::number(36), 1116, 31),
            new Arret(QString::number(37), 1208, 122),
            new Arret(QString::number(38), 1310, 85),
            new Arret(QString::number(39), 1197, 236),
            new Arret(QString::number(40), 1250, 312),
            new Arret(QString::number(41), 1164, 373),
            new Arret(QString::number(42), 1213, 343),
            new Arret(QString::number(43), 1252, 490),
            new Arret(QString::number(44), 1299, 459),
            new Arret(QString::number(45), 1337, 424),
            new Arret(QString::number(46), 1274, 732),
            new Arret(QString::number(47), 1324, 773),
            new Arret(QString::number(48), 973, 885),
            new Arret(QString::number(49), 1317, 776),
            new Arret(QString::number(50), 1148, 808),
            new Arret(QString::number(1), 910, 393),
            new Arret(QString::number(2), 961, 370),
            new Arret(QString::number(3), 922, 411),
            new Arret(QString::number(4), 975, 402),
            new Arret(QString::number(5), 941, 477),
            new Arret(QString::number(6), 989, 462),
            new Arret(QString::number(7), 949, 488),
            new Arret(QString::number(8), 997, 474),
            new Arret(QString::number(9), 844, 474),
            new Arret(QString::number(10), 896, 459),
            new Arret(QString::number(11), 1100, 414),
            new Arret(QString::number(12), 1142, 554),
            new Arret(QString::number(13), 1006, 257),
            new Arret(QString::number(14), 1141, 156),
            new Arret(QString::number(15), 1100, 171),
            new Arret(QString::number(16), 1116, 205),
            new Arret(QString::number(17), 1218, 890),
            new Arret(QString::number(18), 811, 844),
            new Arret(QString::number(19), 853, 829),
            new Arret(QString::number(20), 820, 873),
            new Arret(QString::number(21), 722, 819),
            new Arret(QString::number(22), 432, 793),
            new Arret(QString::number(1), 969, 564),
            new Arret(QString::number(2), 937, 573),
            new Arret(QString::number(3), 1006, 677),
            new Arret(QString::number(4), 1064, 665),
            new Arret(QString::number(5), 1157, 673),
    };


    std::vector<PathNode*>nodes(0);
    for(int x=0;x<v.size();x++){
        v[x]->setName(QString::number(x+1));
        arrets.push_back(v[x]);
        nodes.push_back(new PathNode(arrets[x]));
    }



    Path* p1=new Path(nodes[37]);
    p1->addNode(nodes[36])->addNode(nodes[35])->addNode(nodes[34])->addNode(nodes[33])->addNode(nodes[62])->addNode(nodes[60])->addNode(nodes[57])->addNode(nodes[54])->addNode(nodes[106])->addNode(nodes[105])->addNode(nodes[103])->addNode(nodes[104]);

    Path* p2=new Path(nodes[1]);
    p2->addNode(nodes[0])->addNode(nodes[2])->addNode(nodes[3])->addNode(nodes[5])->addNode(nodes[7])->addNode(nodes[11]);

    Path* p3=new Path(nodes[145]);
    p3->addNode(nodes[172])->addNode(nodes[157])->addNode(nodes[138])->addNode(nodes[136])->addNode(nodes[137])->addNode(nodes[135])->addNode(nodes[134])->addNode(nodes[159])->addNode(nodes[132]);

    paths.push_back(p1);
    paths.push_back(p2);
    paths.push_back(p3);


    auto car1 = new Car(1,p1->getHead(), 350.0);  // Car associated with Arret 1
    auto car2 = new Car(2,p2->getHead(), 350.0);  // Car associated with Arret 2
    auto car3 = new Car(3,p3->getHead(), 320.0);  // Car associated with Arret 3

    // Add Cars to the vector
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);

    CarConnectionManager::instance();

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
void App::drawPaths(QPainter& painter) const {
    // Draw all paths in the App
    for (const Path* path : paths) {
        path->draw(painter);
    }
}

void App::logMessage(const QString &message, QPlainTextEdit *debugOutput) const {
    debugOutput->appendPlainText(message);
}

void App::updateHexagons() {
    for (Hexagon& hexagon : hexagons) {
        hexagon.setIsCarInside(false);  // Reset the flag for each hexagon

        for (int x = 0; x < cars.size(); x++) {
            if (hexagon.isPointInside(cars[x]->getPosition())) {
                hexagon.setIsCarInside(true);
                break;  // No need to check other cars once one is inside
            }
        }
        //hexagon.draw(painter);
    }

}

void App::drawHexagons(QPainter &painter) const {
    for(const Hexagon& hexagon:hexagons){
        hexagon.draw(painter);
    }
}
void App::initialiseHexagones() {
    qreal hexSize = 30.0;  // Adjust size as needed
    int numRows = 20;
    int numCols = 40;

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            qreal x = col * 1.5 * hexSize;
            qreal y = row * sqrt(3) * hexSize;

            if (col % 2 == 1) {
                y += sqrt(3) / 2 * hexSize;
            }

            QPointF hexCenter(x, y);
            Hexagon hexagon(hexCenter, hexSize);
            hexagons.push_back(hexagon);
        }
    }
}
void App::updateCarPositions(qreal elapsedTime) {
    for (Car* car : getCars()) {
        car->updatePosition(elapsedTime);
    }
}

void App::dessineApp(QPainter& painter,bool arretsVisible) {
    if (arretsVisible) {
        drawArrets(painter);
    }

    drawCars(painter);
    drawPaths(painter);
}

