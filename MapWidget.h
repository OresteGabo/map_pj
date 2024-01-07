//
// Created by oreste on 06/01/24.
//

#ifndef MAP_PJ_MAPWIDGET_H
#define MAP_PJ_MAPWIDGET_H


#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QWidget>
#include <QUrl>
#include<cmath>
#include <QtMath>
using namespace std;
#include<iostream>
class MapWidget : public QWidget {
Q_OBJECT

public:
    MapWidget(QWidget* parent = nullptr) : QWidget(parent) {
        setAttribute(Qt::WA_PaintOnScreen, true);
        setAttribute(Qt::WA_NoSystemBackground, true);
        setFixedSize(1800, 1600);
        qDebug() << "MapWidget constructor called";
        // Set the initial zoom level, center, and tile server URL
        /*centerLat =68045;
        centerLon = 45218;
        zoomLevel = 17;*/
        tileServerUrl = "https://a.tile.openstreetmap.org/15/5240/12663.png";


        //tileServerUrl = "https://a.tile.openstreetmap.org/12/2042/1393.png";// for mulhouse

        // Initialize network manager
        networkManager = new QNetworkAccessManager(this);

        // Trigger the initial tile load
        loadTiles();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        qDebug() << "MapWidget paintEvent called";
        QPainter painter(this);
        cout<<"Size =##"<<downloadedTiles.size();
        // Draw the downloaded tiles
        for (const Tile& tile : downloadedTiles) {
            qDebug()<<"loop called##############################################################""";
            if (!tile.image.isNull()) {
                qDebug()<<"x: "<<tile.position.x()<<" y:"<<tile.position.y();
                painter.drawImage(tile.position, tile.image);
            } else {
                qDebug() << "Null image encountered!";
            }
        }
    }

private slots:
    void handleTileDownloaded(QNetworkReply* reply) {
    qDebug()<<"handleTileDownloaded called";
        if (reply->error() == QNetworkReply::NoError) {
            qDebug()<<"handleTileDownloaded called no error";
            // Create a QImage from the downloaded data
            QImage image;
            image.loadFromData(reply->readAll());

            // Calculate the position for the tile based on its coordinates
            qreal tileSize = 256.0;
            qreal x = (tileSize * (reply->property("x").toInt() - topLeftTile.x())) * pow(2, zoomLevel);
            qreal y = (tileSize * (reply->property("y").toInt() - topLeftTile.y())) * pow(2, zoomLevel);

            Tile tile;
            tile.image = image;
            tile.position = QPoint(x, y);

            downloadedTiles.append(tile);

            // Update the widget
            update();
        }else{
            qDebug()<<"handleTileDownloaded ERRORRR";
        }

        reply->deleteLater();
    }

private:
    struct Tile {
        QImage image;
        QPoint position;
    };

    void loadTiles() {
        qreal tileSize = 256.0;
        qreal latRad = qDegreesToRadians(centerLat);
        int n = 1 << zoomLevel;

        topLeftTile.setX(int((centerLon + 180.0) / 360.0 * n));
        topLeftTile.setY(int((1.0 - qAsin(qTan(latRad)) / M_PI) / 2.0 * n));

        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                int tileX = (topLeftTile.x() + x + n) % n;
                int tileY = (topLeftTile.y() + y + n) % n;

                QUrl tileUrl(tileServerUrl);
                tileUrl = tileUrl.toString().replace("{z}", QString::number(zoomLevel))
                        .replace("{x}", QString::number(tileX))
                        .replace("{y}", QString::number(tileY));

                QNetworkReply* reply = networkManager->get(QNetworkRequest(tileUrl));
                reply->setProperty("x", tileX);
                reply->setProperty("y", tileY);

                connect(reply, &QNetworkReply::finished, this, [this, reply]() {
                    handleTileDownloaded(reply);
                });
            }
        }
    }

    qreal centerLat;
    qreal centerLon;
    int zoomLevel;
    QString tileServerUrl;
    QPoint topLeftTile;
    QList<Tile> downloadedTiles;
    QNetworkAccessManager* networkManager;
};



#endif //MAP_PJ_MAPWIDGET_H
