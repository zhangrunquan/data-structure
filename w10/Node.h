//
// Created by 123 on 2018/12/22.
//
#include <iostream>
#ifndef W10_NODE_H
#define W10_NODE_H

#endif //W10_NODE_H

class Node{
public:
    Node();
    Node(int x,int y);
    bool operator>(const Node& Node2);
    bool operator==(const Node&node2);
    int getx()const ;
    int gety()const ;
    void print();
private:
    int x;
    int y ;
};


Node::Node() {
    x=y=0;
}

Node::Node(int x, int y) {
    this->x=x;
    this->y=y;
}

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

bool Node::operator==(const Node &node2) {
    return this->x==node2.getx() &&this->y==node2.gety();
}

void Node::print() {
    std::cout<<'('<<x<<','<<y<<')';
}
