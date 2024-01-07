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
void Path::draw(QPainter& painter) const {
    // Draw the car at its current position
    painter.setBrush(QBrush(Qt::green));
    PathNode* s=head;
    if(s==nullptr)return;
    while(s->next){
        //painter.drawLine(s->getArret()->x(),s->getArret()->y(),s->next->getArret()->x(),s->next->getArret()->y());
        //painter.drawLine(s->getArret()->x(),s->getArret()->y()+10,s->next->getArret()->x(),s->next->getArret()->y()+10);
        s=s->next;
    }
}

void Path::logMessage(const QString &message, QPlainTextEdit *debugOutput) const {
    debugOutput->appendPlainText(message);
}
