//
// Created by oreste on 04/01/24.
//

#ifndef MAP_PJ_ARRET_H
#define MAP_PJ_ARRET_H



#pragma once

#include <QString>
#include <QPainter>
#include <QPlainTextEdit>

class Arret : public QPointF {
public:
    Arret(const QString& id, int x, int y);

    const QString& getName() const;
    void setName(const QString& name);

    void draw(QPainter& painter) const;
    void logMessage(const QString &message, QPlainTextEdit *debugOutput )const;

private:
    QString id;
};




#endif //MAP_PJ_ARRET_H
