//
// Created by 123 on 2018/12/22.
//


#ifndef W10_HEAP_H
#define W10_HEAP_H

#endif //W10_HEAP_H
const int maxnodenum=100;
const int impx=-10000;
const int impy=-10000;

enum position{//the position of target after heapify
    above,
    left,
    right
};

int power(int,int);
int largest_2_power_below(int num);

template <typename Node>
class Heap{//root index is 0
public:
    void sort();
    Heap(const Node *ar_p,int len);
    ~Heap();
    position heapify_one(int index,int endindex);
    void heapify_recur(int index,int endindex);
    int parent_index(int childindex);
    int child_index(position pos,int parentindex);
private:
    Node *heapar_p;
    int len;
};

template <typename Node>
Heap<Node>::Heap(const Node *ar_p, int len) {
    //compute length of heap ,len is length of ar_p ,
    int k=largest_2_power_below(len);
    k=power(2,k+1)-1;
    //copy data
    heapar_p=new Node(k);
    for (int i = 0; i < len; ++i) {
        heapar_p[i]=ar_p[i];//需要注意是不是浅拷贝就可以
    }
    //将长度不足的地方替换为占位符
    Node impNode=Node(impx,impy);
    for (int l = len; l <k ; ++l) {
        heapar_p[l]=impNode;
    }
    //heapify
    //all nodes need to be heapfied except the lowest level ,find the nodes below lowest level
    // note that some nodes in lowest level may not exist
    for (int j = k-1; j>=0 ; --j) {
        heapify_one(j);
    }
}

template <typename Node>
void Heap<Node>::sort() {
    for (int replaced = len-1; replaced >=2 ; --replaced) {
        //exchange largest and last unordered
        Node temp=heapar_p[replaced];
        heapar_p[replaced]=heapar_p[0];
        heapar_p[0]=temp;
        //heapify until it's a heap again

    }
}

template <typename Node>
void Heap<Node>::heapify_recur(int index, int endindex) {
    //position pos=heapify_one(index,endindex);
    while(index<endindex){
        position pos=heapify_one(index,endindex);

    }
}

template <typename Node>
int Heap<Node>::parent_index(int childindex) {

}


template <typename Node>
Heap<Node>::~Heap() {
    delete heapar_p;
}


int power(int num,int times){
    int temp=1;
    for (int i = 0; i <times ; ++i) {
        temp*=num;
    }
    return temp;
}

int largest_2_power_below(int num){//计算比num小的最大的2的幂
    int temp=1;
    int k=0;
    while(temp<num){
        temp*=2;
        ++k;
    }
    return k-1;
}