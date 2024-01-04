// Car.cpp
#include "Car.h"
#include <QBrush>
#include <QtMath>

Car::Car(PathNode* destinationPathHead, double speed) : speed(speed), destinationPathHead(destinationPathHead) {
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
    // Draw the car at its current position
    painter.setBrush(QBrush(Qt::blue));
    painter.drawEllipse(position.x(), position.y(), 20, 20);
}


void Car::setPosition(const QPointF &p) {
    position = p;
}
