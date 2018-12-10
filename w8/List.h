//
// Created by zrq on 2018/11/19.
//

#ifndef INC_1_LIST_H
#define INC_1_LIST_H

#endif //INC_1_LIST_H

#include <iostream>
using namespace std;
struct Lnode {
    int data;
    Lnode  *next;
};

enum Error_code{
    success,
    failure
};

/*
 * 1.头节点用作标兵*/

class List{
public:
    List();
    void addnode(int data);
    void output();
    //用链表模拟数组的行为，数组只能修改位置的值，不能操作位置
    Error_code assign(int data,int index);
    Lnode *find_by_index(int index);
    int read_by_index(int index);
private:
    int count;
    Lnode * head;
};

List::List() {
    count=0;
    head=new Lnode;
    head->data=0;
    head->next= nullptr;
}

void List::addnode(int data) {
    Lnode *now= head;
    //获取最后一个元素
    for (int i = 0; i < count; ++i) {
        now=now->next;
    }
    auto *newnode=new Lnode;
    newnode->data=data;
    newnode->next= nullptr;
    now->next=newnode;
    ++count;
}

Error_code List::assign(int data, int index) {
    Lnode *target_p=find_by_index(index);
    if(target_p!= nullptr){
        target_p->data=data;
        return success;
    }else{
        return failure;
    }
}

Lnode* List::find_by_index(int index) {
    if(index>=0 &&index<=count-1){
        Lnode *node_p=head;
        for (int i = 0; i < index+1; ++i) {
            node_p=node_p->next;
        }
        return  node_p;
    }else{
        return nullptr;
    }
}

int List::read_by_index(int index) {
    Lnode *target_p=find_by_index(index);
    if(target_p!= nullptr){
        return target_p->data;
    }else{
        return failure;
    }
}

void List::output() {
    Lnode *node_p=head;
    for (int i = 0; i < count; ++i) {
        node_p=node_p->next;
        cout<<"node "<<i<<" : "<<node_p->data<<endl;
    }
}
