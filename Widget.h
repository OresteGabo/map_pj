// Widget.h
#pragma once

#include <QWidget>
#include "App.h"
#include "Car.h"
#include <QPushButton>
#include <QSlider>

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

private slots:
    void updateAnimation();
    void toggleSimulation();

private:
    void dessineApp(QPainter& painter, const App& app);


private:
    App& d_app;

    int animationDuration;
    QTimer* animationTimer;
    QPushButton* simulationButton;
    QSlider* simulationSpeedSlider;
};

