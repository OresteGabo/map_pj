//
// Created by oreste on 04/01/24.
//

#ifndef MAP_PJ_PATH_H
#define MAP_PJ_PATH_H


#include "PathNode.h"

class Path {

public:
    Path(PathNode* h=nullptr);
    Path* addNode(PathNode*);
    Path* addNode(Arret*);
    PathNode* getFinalPath()const;
    int getSize()const;
    PathNode* getHead()const;
    void draw(QPainter& painter) const;
private:
    PathNode* head;
};


#endif //MAP_PJ_PATH_H
