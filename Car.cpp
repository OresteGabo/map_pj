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

void Car::updatePosition(qreal elapsedTime) {
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
    checkForConnections();
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
    return QString("Car info(N%8):\n\tspeed %1,\n\tposition (%2,%3) \n\tnext_destination %4(%5,%6)\n\tfrequence %7")
    .arg(speed)
    .arg(position.x())
    .arg(position.y())
    .arg(nextDestinationNode->getArret()->getName())
    .arg(nextDestinationNode->getArret()->x())
    .arg(nextDestinationNode->getArret()->y())
    .arg(frequence)
    .arg(id)
    ;
}

QPointF Car::getPosition() const {
    return position;
}


void Car::checkForConnections() {
    for (Car* connectedCar : connectedCars) {
        if (connectedCar && !checkProximity(connectedCar)) {
            // If the connected car is not in proximity, remove the connection
            connectedCar->connectedCars.removeOne(this);
            connectedCars.removeOne(connectedCar);
            qDebug() << "Connection removed: Car" << toString() << " and Car" << connectedCar->toString();
        }
    }

    // Iterate through all cars and check for new connections
    const QVector<QPair<Car*, Car*>>& allConnections = CarConnectionManager::instance()->getConnectedCars();
    for (const QPair<Car*, Car*>& connectionPair : allConnections) {
        Car* otherCar = nullptr;

        // Determine the other car in the connection pair
        if (connectionPair.first == this) {
            otherCar = connectionPair.second;
        } else if (connectionPair.second == this) {
            otherCar = connectionPair.first;
        }

        if (otherCar && !connectedCars.contains(otherCar) && checkProximity(otherCar)) {
            // If the car is not already connected and is in proximity, add the connection
            connectedCars.append(otherCar);
            otherCar->connectedCars.append(this);
            qDebug() << "New connection: Car" << toString() << " and Car" << otherCar->toString();
        }
    }
}



bool Car::checkProximity(const Car *otherCar) const {
    // Calculate the distance between the centers of the imaginary circles
    double distance = QLineF(position, otherCar->getPosition()).length();

    // Sum of the radii of the imaginary circles
    double combinedRadius = frequence + otherCar->frequence;

    // If the distance is less than the sum of the radii, the circles intersect
    return distance < combinedRadius;
}


