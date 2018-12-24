//
// Created by zrq on 2018/12/24.
//

#ifndef W12_UFSET_H
#define W12_UFSET_H

#endif //W12_UFSET_H


class UFset{
public:
    UFset(int *ar,int len);
    ~UFset();
    bool in_same_set(int node1,int node2);//判断两结点是否在同一集合（是否连通）
    void connect(int node1,int node2);//将两个节点所在集合连通（使所有点具有相同根节点，将数量较少的根节点连到较多的根节点上）
private:
    int *ar_p;
    int len;
};

UFset::UFset(int *ar, int len) {
    this->len=len;
    ar_p=new int[len];
    //将所有父节点初始化为-1
    for (int i = 0; i < len; ++i) {
        ar_p[i]=-1;
    }
}

UFset::~UFset() {
    delete ar_p;
}



