// Car.cpp
#include "Car.h"
#include <QBrush>
#include <QtMath>

Car::Car(PathNode* destinationPathHead, double speed,const QPixmap& car,double frequence) :
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
}

void Car::draw(QPainter& painter) const {
    // Draw the car image at the current position
    painter.drawPixmap(position.toPoint() - QPoint(carImage.width() / 2, carImage.height() / 2), carImage);
}


void Car::logMessage(const QString &message, QPlainTextEdit *debugOutput) const {
    debugOutput->appendPlainText(message);
}

QString Car::toString() const {
    return QString("Car info:\n\tspeed %1,\n\tposition (%2,%3) \n\tnext_destination %4(%5,%6)\n\tfrequence %7")
    .arg(speed)
    .arg(position.x())
    .arg(position.y())
    .arg(nextDestinationNode->getArret()->getName())
    .arg(nextDestinationNode->getArret()->x())
    .arg(nextDestinationNode->getArret()->y())
    .arg(frequence)
    ;
}

QPointF Car::getPosition() const {
    return position;
}

