// Widget.cpp
#include "Widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QSlider>


Widget::Widget(App& app, QWidget* parent) : QWidget(parent), d_app(app), animationDuration(5000), hexagonsVisible(true), arretsVisible(true) {
    QRect screenGeometry = QApplication::desktop()->availableGeometry();
      // Adjust the geometry as needed

    // Set the size of the widget to match the size of the screen
    setFixedSize(screenGeometry.width()-100, screenGeometry.height()-100);
    initialiseDebugOutput();
    // Initialize animation variables
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Widget::updateAnimation);

    initialiseButtons();
    initialiseSlider();
    initialiseHexagones();
}

Widget::~Widget() {}
void Widget::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    // Draw the background image
    QPixmap backgroundImage("bg.png");
    painter.drawPixmap(rect(), backgroundImage, backgroundImage.rect());

    if (hexagonsVisible) {
        for (Hexagon& hexagon : hexagons) {
            hexagon.setIsCarInside(false);  // Reset the flag for each hexagon

            for (int x = 0; x < d_app.getCars().size(); x++) {
                if (hexagon.isPointInside(d_app.getCars()[x]->getPosition())) {
                    hexagon.setIsCarInside(true);
                    break;  // No need to check other cars once one is inside
                }
            }
            hexagon.draw(painter);
        }

    }

    if (hexagonsVisible) {
        for (const Hexagon& hexagon : hexagons) {
            hexagon.draw(painter);
        }
    }

    // Call the custom drawing function for your app
    dessineApp(painter, d_app);

}

void Widget::dessineApp(QPainter& painter, const App& app) {
    // Draw all Arrets in the App
    if (arretsVisible) {
        app.drawArrets(painter);
    }

    app.drawCars(painter);
    app.drawPaths(painter);
}
int Widget::counterArrets=0;
void Widget::mousePressEvent(QMouseEvent* event) {
    // Get the position (x, y) when the mouse is clicked
    int x = event->x();
    int y = event->y();
    counterArrets++;
    QString s=QString("Mouse clicked at position: (" + QString::number(x) + ", " +QString::number(y) + ")");
    qDebug()<<s;
}

void Widget::updateAnimation() {
    // Update the animation progress based on the elapsed time
    qreal elapsedTime = animationTimer->interval() / qreal(animationDuration);

    // Update the positions of all Cars
    for (Car* car : d_app.getCars()) {
        car->updatePosition(elapsedTime);
    }

    // Check if the animation is complete
    if (animationTimer->isActive()) {
        // Redraw the widget
        update();
    } else {
        simulationButton->setText("Lancer Simulation");
    }
}

void Widget::toggleSimulation() {
    if (animationTimer->isActive()) {
        // If the animation is active, stop it
        animationTimer->stop();
        simulationButton->setText("Lancer Simulation");
        logMessage("\t>Simulation arretée");
    } else {
        // If the animation is not active, start it
        animationTimer->start(16);  // Update approximately every 16 milliseconds (60 frames per second)
        simulationButton->setText("Stop Simulation");
        logMessage("\t>Simulation lancée");
    }
}

void Widget::updateSimulationSpeed(int speed) {
    // Update the animation timer interval based on the simulation speed slider
    int newInterval = static_cast<int>(animationDuration / (speed / 50.0));
    animationTimer->setInterval(newInterval);

    // Set the sleep duration between iterations based on the simulation speed
    // This will make the simulation slower as the slider moves to the right
    int sleepDuration = static_cast<int>(animationDuration / speed);
    animationTimer->setInterval(sleepDuration);
}

void Widget::logMessage(const QString& message) {
    // Append the message to the QPlainTextEdit
    debugOutput->appendPlainText(message);
}

void Widget::initialiseDebugOutput() {
    debugOutput = new QPlainTextEdit(this);
    debugOutput->setGeometry(width()-420 , 20, 400, height()-100);
    debugOutput->setDisabled(true);


    debugOutput->setStyleSheet("background-color: rgba(0, 0, 0, 150); color: white;border:2px solid black;");
}

void Widget::initialiseHexagones() {
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

    toggleHexagonsButton = new QPushButton(!hexagonsVisible?"Afficher les mailles":"Masquer les mailles", this);
    toggleHexagonsButton->setGeometry(350, 10, 150, 30);
    connect(toggleHexagonsButton, &QPushButton::clicked, this, &Widget::toggleHexagonsVisibility);

}

void Widget::toggleHexagonsVisibility() {
    hexagonsVisible = !hexagonsVisible;
    if(hexagonsVisible){
        toggleHexagonsButton->setText("Masquer les mailles");
        debugOutput->appendPlainText("Les mailles sont affichés");
    }else{
        toggleHexagonsButton->setText("Afficher les mailles");
        debugOutput->appendPlainText("Les mailles sont masqués");
    }
    update();
}
void Widget::initialiseButtons() {
    // Create simulation button
    simulationButton = new QPushButton("Lancer Simulation", this);
    simulationButton->setGeometry(10, 10, 150, 30);
    connect(simulationButton, &QPushButton::clicked, this, &Widget::toggleSimulation);

    clearButton = new QPushButton("Clear", this);
    clearButton->setGeometry(width() - 420, height() - 70, 100, 30);
    connect(clearButton, &QPushButton::clicked, this, &Widget::clearDebugOutput);

    carsInfoButton = new QPushButton("Cars Info", this);
    carsInfoButton->setGeometry(width() - 310, height() - 70, 100, 30);
    connect(carsInfoButton, &QPushButton::clicked, this, &Widget::displayCarsInfo);

    toggleArretsButton = new QPushButton(arretsVisible ? "Masquer les arrêts" : "Afficher les arrêts", this);
    toggleArretsButton->setGeometry(500, 10, 150, 30);
    connect(toggleArretsButton, &QPushButton::clicked, this, &Widget::toggleArretsVisibility);

}

void Widget::clearDebugOutput() {
    debugOutput->clear();
}

void Widget::displayCarsInfo() {
    // Assuming you have a function to get the cars information from App
    const std::vector<Car*>& cars = d_app.getCars();  // Replace with your actual function to get the cars

    // Display car information in the QPlainTextEdit
    logMessage("\n");
    for (const Car* car : cars) {
        logMessage(car->toString());
    }
}

void Widget::initialiseSlider() {
// Create simulation speed slider
    simulationSpeedSlider = new QSlider(Qt::Horizontal, this);
    simulationSpeedSlider->setGeometry(180, 10, 150, 30);
    simulationSpeedSlider->setMinimum(1);
    simulationSpeedSlider->setMaximum(100);
    simulationSpeedSlider->setValue(50);  // Initial speed
    connect(simulationSpeedSlider, &QSlider::valueChanged, this, &Widget::updateSimulationSpeed);

}

void Widget::toggleArretsVisibility() {
    arretsVisible = !arretsVisible;
    toggleArretsButton->setText(arretsVisible ? "Masquer les arrêts" : "Afficher les arrêts");
    update();
}
