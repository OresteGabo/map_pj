//
// Created by oreste on 04/01/24.
//

#ifndef MAP_PJ_PATHNODE_H
#define MAP_PJ_PATHNODE_H


#include "Arret.h"

class PathNode {
    friend class Car;
    //friend class App;
    friend class Path;
public:
    PathNode(Arret* arret,PathNode* next=nullptr);

    const Arret* getArret() const;

private:
    Arret* arret;
    PathNode* next;
};




#endif //MAP_PJ_PATHNODE_H
