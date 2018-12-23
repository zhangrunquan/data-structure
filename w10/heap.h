//
// Created by 123 on 2018/12/22.
//


#include "Node.h"
#include <iostream>

#ifndef W10_HEAP_H
#define W10_HEAP_H

#endif //W10_HEAP_H
const int maxnodenum = 100;
int impx = -10000;
int impy = -10000;


enum position {//the position of target after heapify
    above,
    left,
    right
};

//int power(int, int);

//int largest_2_power_below(int num);

template<typename Node>
class Heap {//root index is 0
public:
    void sort();

    Heap(const Node *ar_p, int len);

    ~Heap();

    position heapify_one(int index, int endindex);

    void heapify_recur(int index, int endindex);

    int parent_index(int childindex);

    int child_index(position pos, int parentindex);

    bool is_placeholder(int index);//检查node是否为占位符

    void exchange_node_in_triangle(int aboveindex, int childindex);

    int find_max_node_index(int node1_i, int node2_i, int node3_i);
    int max_node_index(int node1_i,int node2_i);

    void topk(const Node&newnode);
    void output();
    void heapify(int index,int endindex);//index的左右子树是堆，heapify后包括index的树是堆
    int compute_heap_len(int inputarlen);
private:
    Node *heapar_p;
    int len;
    Node impnode;
};

template<typename Node>
void Heap<Node>::heapify(int index, int endindex) {
    if(index>=endindex|| heapar_p[index]==impnode)//index is not valid node
        return;
    int lchild_i = child_index(left, index);
    int rchild_i = child_index(right, index);
    //check if there is a child  neither below endindex ,nor a placeholder
    bool lexist = lchild_i < endindex && (!is_placeholder(lchild_i));
    bool rexist = rchild_i < endindex && (!is_placeholder(rchild_i));
    //heapify logic
    if (lexist && rexist) {//choose the largest, exchange with the one above
        int maxnode_i = find_max_node_index(lchild_i, rchild_i, index);
        if (index == maxnode_i) {
            //pass
        } else {//a child is largest ,change it with index
            int target = lchild_i == maxnode_i ? lchild_i : rchild_i;
            exchange_node_in_triangle(index, target);
            int child_i=child_index(target==lchild_i?left:right,index);
            heapify(child_i,endindex);
        }
    } else if (lexist ||rexist) {//only one child exist ,compare child with above
        int child_i=lexist?lchild_i:rchild_i;
        if(index==max_node_index(index,child_i)){
            //pass
        }else{//child larger than index
            exchange_node_in_triangle(index,child_i);
            child_i=child_index(lexist?left:right,index);
            heapify(child_i,endindex);
        }
    }  else {//neither child exist ,do nothing
    }
}

template<typename Node>
void Heap<Node>::exchange_node_in_triangle(int aboveindex, int childindex) {
    Node temp=heapar_p[aboveindex];
    heapar_p[aboveindex]=heapar_p[childindex];
    heapar_p[childindex]=temp;
}
template<typename Node>
void Heap<Node>::topk(const Node &newnode) {
    if (heapar_p[0]>newnode){
        heapar_p[0]=newnode;
        heapify(0,len);
    }else{//heapar_p[0]<=newnode
        //pass
    }
    output();
}
template<typename Node>
void Heap<Node>::output() {
    for (int i = 0; i < len; ++i) {
        heapar_p[i].print();
        std::cout<<" ";
    }
    std::cout<<std::endl;
}
template<typename Node>
bool Heap<Node>::is_placeholder(int index) {
    return heapar_p[index]==impnode;
}

template<typename Node>
Heap<Node>::Heap(const Node *ar_p, int len) {
    if(len==0)
        return ;
    int k=this->len=len;
    //copy data
    Node impnode(impx, impy);
    this->impnode=impnode;
    heapar_p = new Node[k];
    for (int i = 0; i < len; ++i) {
        heapar_p[i] = ar_p[i];//需要注意是不是浅拷贝就可以
    }
    //将长度不足的地方替换为占位符
    /*Node impNode = Node(impx, impy);
    for (int l = len; l < k; ++l) {
        heapar_p[l] = impNode;
    }*/
    //heapify
    for (int j = (compute_heap_len(len)+1)/2-2; j >= 0; --j) {
        heapify(j,len);
    }
}

template<typename Node>
void Heap<Node>::sort() {
    for (int replaced = len - 1; replaced >= 1; --replaced) {
        //exchange largest and last unordered
        Node temp = heapar_p[replaced];
        heapar_p[replaced] = heapar_p[0];
        heapar_p[0] = temp;
        //heapify until it's a heap again
        heapify(0, replaced);
    }
}

template<typename Node>
void Heap<Node>::heapify_recur(int index, int endindex) {
    //position pos=heapify_one(index,endindex);
    while (index < endindex) {
        position pos = heapify_one(index, endindex);
        if (pos == above) {
            break;
        } else if (pos == left) {
            index = child_index(left, index);//new target to heapify
        } else {//pos==right
            index = child_index(right, index);
        }
    }
}

template<typename Node>
int Heap<Node>::parent_index(int childindex) {
    if (childindex % 2 == 0) {
        return (childindex - 2) / 2;
    } else {//childindex%2==1
        return (childindex - 1) / 2;
    }
}

template<typename Node>
int Heap<Node>::child_index(position pos, int parentindex) {
    if (pos == left) {
        return 2 * parentindex + 1;
    } else {//pos==right
        return 2 * parentindex + 2;
    }
}

/*return where the index node is placed after heapify
 * */
template<typename Node>
position Heap<Node>::heapify_one(int index, int endindex) {
    if(index>=endindex|| heapar_p[index]==impnode)//index is not valid node
        return above;
    int lchild_i = child_index(left, index);
    int rchild_i = child_index(right, index);
    //check if there is a child  neither below endindex ,nor a placeholder
    bool lexist = lchild_i < endindex && (!is_placeholder(lchild_i));
    bool rexist = rchild_i < endindex && (!is_placeholder(rchild_i));
    //heapify logic
    /*
    Node lchild=lexist?heapar_p[lchild_i]:impnode;
    Node rchild=rexist?heapar_p[rchild_i]:impnode;
    Node index_node=heapar_p[index];*/
    if (lexist && rexist) {//choose the largest, exchange with the one above
        int maxnode_i = find_max_node_index(lchild_i, rchild_i, index);
        if (index == maxnode_i) {
            return above;
        } else {//a child is largest ,change it with index
            int target = lchild_i == maxnode_i ? lchild_i : rchild_i;
            exchange_node_in_triangle(index, target);
            return target==lchild_i?left:right;
        }
    } else if (lexist ||rexist) {//only one child exist ,compare child with above
        int child_i=lexist?lchild_i:rchild_i;
        if(index==max_node_index(index,child_i)){
            return above;
        }else{//child larger than index
            exchange_node_in_triangle(index,child_i);
            return lexist?left:right;
        }
    }  else {//neither child exist ,do nothing
        return above;
    }
}

template<typename Node>
Heap<Node>::~Heap() {
    delete heapar_p;
}


int power(int num, int times) {
    int temp = 1;
    for (int i = 0; i < times; ++i) {
        temp *= num;
    }
    return temp;
}
/*
int largest_2_power_below(int num) {//计算比num小的最大的2的幂
    int temp = 1;
    int k = 0;
    while (temp < num) {
        temp *= 2;
        ++k;
    }
    return k - 1;
}
*/
template<typename Node>
int Heap<Node>::find_max_node_index(int node1_i, int node2_i, int node3_i) {
    return max_node_index(node1_i,max_node_index(node2_i,node3_i));
}
template<typename Node>
int Heap<Node>::max_node_index(int node1_i, int node2_i) {
    return heapar_p[node1_i]>heapar_p[node2_i]? node1_i:node2_i;
}

template<typename Node>
int Heap<Node>::compute_heap_len(int inputarlen) {
    int temp=0;
    while(power(2,temp)-1<inputarlen){
        ++temp;
    }
    return power(2,temp)-1;
}
