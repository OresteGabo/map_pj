//
// Created by oreste on 04/01/24.
//

#include "Path.h"
Path::Path(PathNode* head):head(head){}
Path* Path::addNode(PathNode* node){
    PathNode* s=head;

    if(head==nullptr){
        head=node;
        return this;
    }
    while(s->next!=nullptr){
        s=s->next;
    }
    s->next=node;
    return this;

}
Path* Path::addNode( Arret* a){
    auto s=head;
    auto node=new PathNode(a);

    if(head==nullptr){
        head=node;
        return this;
    }
    while(s->next!=nullptr){
        s=s->next;
    }
    s->next=node;
    return this;
}
PathNode* Path::getFinalPath()const{
    auto s=head;
    if(head==nullptr){
        return nullptr;
    }
    while(s->next!= nullptr){
        s=s->next;
    }
    return s;
}
int Path::getSize()const{
    int counter=0;
    PathNode* s=head;
    while(s!=nullptr){
        counter++;
        s=s->next;
    }
    return counter;
}
PathNode* Path::getHead()const{
    return head;
}