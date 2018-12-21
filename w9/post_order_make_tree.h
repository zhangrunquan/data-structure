//
// Created by zrq on 2018/12/10.
//

#ifndef W9_POST_ORDER_MAKE_TREE_H
#define W9_POST_ORDER_MAKE_TREE_H

#endif //W9_POST_ORDER_MAKE_TREE_H

#include <string>
#include<iostream>
#include <vector>

using  namespace std;
/*
 * 1.为了能从根节点开始创建，倒着读字符串
 * 2.写一个类，把vector<char>作为构造方式
 */
enum direction{
    left,
    right
};

struct Node{
    int value;
    Node *left;
    Node *right;
};

class BinaryTree{
public:
    BinaryTree(const vector<char>& str);
    void connectNode(Node *parent_p,direction dire,char childvalue,const vector<char>& str,int index);
    void str2tree(vector<char> str);
};

BinaryTree::BinaryTree(const vector<char>& str) {
    str2tree(str);
}

/*接受后序遍历字符串的反转，构建二叉树
 * 参数：str：后序遍历字符串的反转
 * */
void BinaryTree::str2tree(vector<char> str) {
    int index=0;

    connectNode(right)
    connectNode(left);

}

void BinaryTree::connectNode(Node *parent_p, direction dire, char childvalue,const vector<char> &str, int index) {
    //connect
    //find next step
    if(childvalue=='#'){
    }else{
        connectNode(right)
        connectNode((left))
    }
}


