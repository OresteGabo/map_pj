// Widget.cpp
#include "Widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QSlider>


Widget::Widget(App& app, QWidget* parent) : QWidget(parent), d_app(app), animationDuration(5000),hexagonsVisible(true) {
    QRect screenGeometry = QApplication::desktop()->availableGeometry();
      // Adjust the geometry as needed

    // Set the size of the widget to match the size of the screen
    setFixedSize(screenGeometry.width()-100, screenGeometry.height()-100);
    initialiseDebugOutput();
    // Initialize animation variables
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Widget::updateAnimation);

    // Create simulation button
    simulationButton = new QPushButton("Lancer Simulation", this);
    simulationButton->setGeometry(10, 10, 150, 30);
    connect(simulationButton, &QPushButton::clicked, this, &Widget::toggleSimulation);

    initialiseButtons();

    // Create simulation speed slider
    simulationSpeedSlider = new QSlider(Qt::Horizontal, this);
    simulationSpeedSlider->setGeometry(180, 10, 150, 30);
    simulationSpeedSlider->setMinimum(1);
    simulationSpeedSlider->setMaximum(100);
    simulationSpeedSlider->setValue(50);  // Initial speed
    connect(simulationSpeedSlider, &QSlider::valueChanged, this, &Widget::updateSimulationSpeed);

    // Set up initial animation
    updateCarPosition();



    initialiseHexagones();

}

Widget::~Widget() {
}

void Widget::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    // Draw the background image
    QPixmap backgroundImage("bg.png");
    painter.drawPixmap(rect(), backgroundImage, backgroundImage.rect());

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
    app.drawArrets(painter);
    app.drawCars(painter);
    app.drawPaths(painter);
}
int Widget::counterArrets=0;
void Widget::mousePressEvent(QMouseEvent* event) {
    // Get the position (x, y) when the mouse is clicked
    int x = event->x();
    int y = event->y();
    counterArrets++;
    QString s=QString("new Arret(QString::number(%1), %2, %3);").arg(counterArrets).arg(event->x()).arg(event->y());
    qDebug()<<s;
    //qDebug() << "Mouse clicked at position: (" << x << ", " << y << ")";
    logMessage("Mouse clicked at position: (" + QString::number(x) + ", " +QString::number(y) + ")");
}

void Widget::updateCarPosition() {
    // Assuming you have a function to get the cars from App
    //const std::vector<Car*>& cars = d_app.getCars();  // Replace with your actual function to get the cars

    // Update the cars' positions based on the associated Arret
    //const Arret* associatedArret = d_app.getArrets()[0];  // Use the first Arret for demonstration

    //for (Car* car : cars) {
      //  car->setPosition(QPointF(associatedArret->x(), associatedArret->y()));
    //}
    //QString carInfo = QString("Car position updated. New position: (%1, %2)").arg(car.x()).arg(car.y());
    //logMessage(carInfo);

    // Redraw the widget
    //update();*/
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
        logMessage("Simulation lancée");
    } else {
        // If the animation is not active, start it
        animationTimer->start(16);  // Update approximately every 16 milliseconds (60 frames per second)
        simulationButton->setText("Stop Simulation");
        logMessage("Simulation Arretée");
    }
}

void Widget::updateSimulationSpeed(int speed) {
    // Update the animation timer interval based on the simulation speed slider
    int newInterval = static_cast<int>(animationDuration / (speed / 50.0));
    animationTimer->setInterval(newInterval);
}


void Widget::logMessage(const QString& message) {
    // Append the message to the QPlainTextEdit
    debugOutput->appendPlainText(message);
}

void Widget::initialiseDebugOutput() {
    debugOutput = new QPlainTextEdit(this);
    debugOutput->setGeometry(width()-420 , 20, 400, height()-100);
    debugOutput->setDisabled(true);
    debugOutput->appendPlainText("Hello text");
    debugOutput->appendPlainText("Hello text");



    // Assuming you have a QPlainTextEdit named debugOutput
    QTextCharFormat format;
    format.setForeground(QColor(Qt::black)); // Set the text color to red
    debugOutput->setCurrentCharFormat(format);

// Append text with the specified color
    debugOutput->appendPlainText("This text will appear in red.");

// You can reset the format to apply the default text color
    //format.clearForeground();
    //debugOutput->setCurrentCharFormat(format);

// Append more text with the default color
    debugOutput->appendPlainText("This text will appear in the default color.");
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
    clearButton = new QPushButton("Clear", this);
    clearButton->setGeometry(width() - 420, height() - 70, 100, 30);
    connect(clearButton, &QPushButton::clicked, this, &Widget::clearDebugOutput);

    carsInfoButton = new QPushButton("Cars Info", this);
    carsInfoButton->setGeometry(width() - 310, height() - 70, 100, 30);
    connect(carsInfoButton, &QPushButton::clicked, this, &Widget::displayCarsInfo);
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
