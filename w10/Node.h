//
// Created by 123 on 2018/12/22.
//

#ifndef W10_NODE_H
#define W10_NODE_H

#endif //W10_NODE_H

class Node{
public:
    bool operator>(const Node& Node2);
    int getx()const ;
    int gety()const ;
private:
    int x;
    int y ;
};

int Node::getx() const{
    return x;
}
int Node::gety() const{
    return y;
}

bool Node::operator>(const Node &Node2) {
    int x1=this->x;
    int x2=Node2.getx();
    int y1=this->y;
    int y2=Node2.gety();
    return x1 > x2 || (x1 == x2 && y1 > y2);
}