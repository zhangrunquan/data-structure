//
// Created by zrq on 2018/12/10.
//

#ifndef W9_POST_ORDER_MAKE_TREE_H
#define W9_POST_ORDER_MAKE_TREE_H

#endif //W9_POST_ORDER_MAKE_TREE_H

#include <string>
#include <algorithm>
using  namespace std;
/*
 * 1.为了能从根节点开始创建，倒着读字符串
 * 2.写一个类，把字符串作为构造方式
 */

class BinaryTree{
public:
    BinaryTree(string str);
};

BinaryTree::BinaryTree(string str) {
    if(str.length()==0);
    reverse(str.begin(),str.end());

}