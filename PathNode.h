#ifndef MAP_PJ_PATHNODE_H
#define MAP_PJ_PATHNODE_H
#include "Arret.h"

class PathNode {
    friend class Car;
    friend class Path;
public:
    PathNode(Arret* arret,PathNode* next=nullptr);
    const Arret* getArret() const;
    void logMessage(const QString &message, QPlainTextEdit *debugOutput )const;
private:
    Arret* arret;
    PathNode* next;
};
#endif //MAP_PJ_PATHNODE_H
