// Widget.cpp
#include "Widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QSlider>

Widget::Widget(App& app, QWidget* parent) : QWidget(parent), d_app(app), animationDuration(5000) {
    QRect screenGeometry = QApplication::desktop()->availableGeometry();

    // Set the size of the widget to match the size of the screen
    setFixedSize(screenGeometry.width(), screenGeometry.height());

    // Initialize animation variables
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Widget::updateAnimation);

    // Create simulation button
    simulationButton = new QPushButton("Lancer Simulation", this);
    simulationButton->setGeometry(10, 10, 150, 30);
    connect(simulationButton, &QPushButton::clicked, this, &Widget::toggleSimulation);

    // Create simulation speed slider
    simulationSpeedSlider = new QSlider(Qt::Horizontal, this);
    simulationSpeedSlider->setGeometry(180, 10, 150, 30);
    simulationSpeedSlider->setMinimum(1);
    simulationSpeedSlider->setMaximum(100);
    simulationSpeedSlider->setValue(50);  // Initial speed
    connect(simulationSpeedSlider, &QSlider::valueChanged, this, &Widget::updateSimulationSpeed);

    // Set up initial animation
    updateCarPosition();
}

Widget::~Widget() {
}

void Widget::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    // Draw the background image
    QPixmap backgroundImage("bg.png");
    painter.drawPixmap(rect(), backgroundImage, backgroundImage.rect());

    // Call the custom drawing function for your app
    dessineApp(painter, d_app);
}

void Widget::dessineApp(QPainter& painter, const App& app) {
    // Draw all Arrets in the App
    app.drawArrets(painter);

    // Draw all Cars in the App
    for (Car* car : d_app.getCars()) {
        car->draw(painter);
    }
}

void Widget::mousePressEvent(QMouseEvent* event) {
    // Get the position (x, y) when the mouse is clicked
    int x = event->x();
    int y = event->y();

    qDebug() << "Mouse clicked at position: (" << x << ", " << y << ")";
}

void Widget::updateCarPosition() {
    // Assuming you have a function to get the cars from App
    const std::vector<Car*>& cars = d_app.getCars();  // Replace with your actual function to get the cars

    // Update the cars' positions based on the associated Arret
    const Arret* associatedArret = d_app.getArrets()[0];  // Use the first Arret for demonstration

    for (Car* car : cars) {
        car->setPosition(QPointF(associatedArret->x(), associatedArret->y()));
    }

    // Redraw the widget
    update();
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
    } else {
        // If the animation is not active, start it
        animationTimer->start(16);  // Update approximately every 16 milliseconds (60 frames per second)
        simulationButton->setText("Stop Simulation");
    }
}

void Widget::updateSimulationSpeed(int speed) {
    // Update the animation timer interval based on the simulation speed slider
    int newInterval = static_cast<int>(animationDuration / (speed / 50.0));
    animationTimer->setInterval(newInterval);
}
