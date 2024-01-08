// Car.cpp
#include "Car.h"
#include <QBrush>
#include <QtMath>

Car::Car(int id,PathNode* destinationPathHead, double speed,const QPixmap& car,double frequence) :
id(id),
speed(speed), destinationPathHead(destinationPathHead),
position(destinationPathHead->getArret()->toPoint()),
carImage(car),
frequence(frequence)
{
    carImage = carImage.scaledToWidth(30);
    // Set the initial position based on the starting destination node
    if (destinationPathHead) {
        position = QPointF(destinationPathHead->getArret()->x(), destinationPathHead->getArret()->y());
        nextDestinationNode = destinationPathHead->next;
        qDebug()<<"The car initialised with path adress (" << destinationPathHead->getArret()->x()<<","<<destinationPathHead->getArret()->y()<<")";
    } else {
        // If no starting node is provided, set an initial position at (0, 0)
        position = QPointF(0, 0);
        qDebug()<<"The car initialised with 0,0";
        nextDestinationNode = nullptr;
    }

}

void Car::updatePosition(qreal elapsedTime,QVector<Car*> allCars) {
    if (!nextDestinationNode) {
        return;  // No destination path set, do nothing
    }

    // Update the position based on the elapsed time and speed
    qreal deltaX = speed * elapsedTime * qCos(qAtan2(nextDestinationNode->getArret()->y() - position.y(), nextDestinationNode->getArret()->x() - position.x()));
    qreal deltaY = speed * elapsedTime * qSin(qAtan2(nextDestinationNode->getArret()->y() - position.y(), nextDestinationNode->getArret()->x() - position.x()));

    position += QPointF(deltaX, deltaY);

    // Check if the car has reached the current destination node
    qreal distance = (position - *(nextDestinationNode->getArret())).manhattanLength();
    if (distance <= 1.0) {
        // If the distance is small enough, consider it reached and set the next destination node
        nextDestinationNode = nextDestinationNode->next;
        if (!nextDestinationNode) {
            // If there's no next destination, stop the car
            speed = 0.0;
        }
    }

    updateConnectedCars(allCars);



}

void Car::draw(QPainter& painter) const {
    //painter.setPen(Qt::NoPen);  // Set no outline for the circles
    painter.setBrush(Qt::Dense7Pattern);

    int radius = frequence ;  // Adjust scaleFactor as needed
    painter.drawEllipse(position, radius, radius);
    // Draw the car image at the current position
    painter.drawPixmap(position.toPoint() - QPoint(carImage.width() / 2, carImage.height() / 2), carImage);
}


void Car::logMessage(const QString &message, QPlainTextEdit *debugOutput) const {
    debugOutput->appendPlainText(message);
}

QString Car::toString() const {
    QString result= QString("Car info(N%8):\n\tspeed %1,\n\tposition (%2,%3) \n\tnext_destination %4(%5,%6)\n\tfrequence %7")
    .arg(speed)
    .arg(position.x())
    .arg(position.y())
    .arg(nextDestinationNode? nextDestinationNode->getArret()->getName():"NULL")
    .arg(nextDestinationNode ? QString::number(nextDestinationNode->getArret()->x()):"NULL")
    .arg(nextDestinationNode? QString::number(nextDestinationNode->getArret()->y()):"NULL")
    .arg(frequence)
    .arg(id)
    ;
    result += "\nConnected Cars:";
    for (const Car* connectedCar : connectedCars) {
        result += " " + QString::number(connectedCar->getId());
    }
    return result;

}

QPointF Car::getPosition() const {
    return position;
}



double Car::getFrequence() const {
    return frequence;
}

int Car::getId() const {
    return id;
}

void Car::updateConnectedCars(QVector<Car*> allCars) {
    connectedCars.clear();
    for (const Car* otherCar : allCars) {
        if (otherCar != this && connectedTo( otherCar)) {
            connectedCars.push_back(const_cast<Car*>(otherCar));
        }
    }
}

const QVector<Car *> &Car::getConnectedCars() const {
    return connectedCars;
}

bool Car::connectedTo(const Car *car) const {
    QPointF position2 = car->getPosition();
    double radius1=frequence;
    double radius2 = car->getFrequence();

    // Calculate the distance between the centers of the circles
    double distance = std::hypot(position.x() - position2.x(), position.y() - position2.y());

    // Determine if the circles intersect based on their radii and distance
    //return distance < (getRadius() + radius2);
    return radius1 > distance || radius2> distance;
}

int Car::getRadius() const {
    return frequence;
}

void Car::resetPosition() {
    position=QPointF(destinationPathHead->getArret()->x(),destinationPathHead->getArret()->y());
    nextDestinationNode=destinationPathHead->next;
}


