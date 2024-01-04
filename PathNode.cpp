//
// Created by oreste on 04/01/24.
//

#include "PathNode.h"



PathNode::PathNode(Arret* arret,PathNode* n) : arret(arret), next(n) {
}

const Arret* PathNode::getArret() const {
    return arret;
}
