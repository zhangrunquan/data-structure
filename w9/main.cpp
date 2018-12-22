#include <iostream>
#include "post_order_make_tree.h"
#include <algorithm>
int main() {
    char str[]="###ca##ji####spom";
    vector<char> vec;
    for(auto chara:str){
        vec.push_back(chara);
    }
    //vec[0] becomes '\0' if reverse now ,pop it
    vec.pop_back();
    //获取反转的字符串的vector
    reverse(vec.begin(),vec.end());
    //construct tree
    BinaryTree bitree(vec);
    bitree.find_node_print_trace('c');
    bitree.delete_node('m');
    return 0;
}