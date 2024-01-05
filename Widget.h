// Widget.h
#pragma once

#include <QWidget>
#include "App.h"
#include "Car.h"
#include "Hexagon.h"
#include <QPushButton>
#include <QSlider>
#include <QPlainTextEdit>

class Widget : public QWidget {
Q_OBJECT

public:
    Widget(App& app, QWidget* parent = nullptr);

    ~Widget();

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void updateCarPosition();
    void updateSimulationSpeed(int speed);
    void initialiseButtons();
    void clearDebugOutput();
    void displayCarsInfo();


private:
    void dessineApp(QPainter& painter, const App& app);

private slots:
    void updateAnimation();
    void toggleSimulation();
    void logMessage(const QString& message);
    void toggleHexagonsVisibility();



private:
    App& d_app;

    int animationDuration;
    QTimer* animationTimer;
    QPushButton* simulationButton,*toggleHexagonsButton,*clearButton,*carsInfoButton;
    QSlider* simulationSpeedSlider;
    QVector<Hexagon> hexagons;
    QPlainTextEdit* debugOutput;
    bool hexagonsVisible;
    static int counterArrets;


    void initialiseDebugOutput();
    void initialiseHexagones();
};

