//
// Created by zrq on 2018/12/10.
//

#ifndef W9_POST_ORDER_MAKE_TREE_H
#define W9_POST_ORDER_MAKE_TREE_H

#endif //W9_POST_ORDER_MAKE_TREE_H

#include <string>
#include<iostream>
#include <vector>
#include <queue>

using namespace std;
/*
 * 1.为了能从根节点开始创建，倒着读字符串
 * 2.写一个类，把vector<char>作为构造方式
 */
enum direction {
    l,
    r
};

struct Node {
    char value;
    Node *left;
    Node *right;
};

/*
 * 缺少析构处理*/
class BinaryTree {
public:
    explicit BinaryTree(const vector<char> &str);

    void
    connectNode(Node *parent_p, direction dire, char childvalue, const vector<char> &str, int &index, int endindex);

    void str2tree(vector<char> str);

    void find_node_print_trace(char c) const;

    void output_queue(queue<char> &q) const;

    bool find_node(char c, Node *parent_p, queue<char> &qu) const;

    Node *get_node(char c) const;

    void delete_node(char c);

    Node *get_parent_node(char c);

    Node *get_parent_node_recur(char c, Node *current_p, Node *lastnode_p);

private:
    Node *head;

    Node *get_node_recur(char c, Node *parent_p) const;

    Node *get_least_right(Node *parent_p) const;//find the least node on the right

    Node *get_most_left(Node *parent_p) const;//find the largest node on the left
};

BinaryTree::BinaryTree(const vector<char> &str) {
    if (str[0] == '#') {
        cout << "e 2" << endl;
    }
    //初始化
    head = new Node;
    head->left = head->right = nullptr;
    head->value = str[0];
    //construct tree
    str2tree(str);
}

/*接受后序遍历字符串的反转，构建二叉树
 * 参数：str：后序遍历字符串的反转
 * */
void BinaryTree::str2tree(vector<char> str) {
    int index = 1;  //root node has been already initialized
    int endindex = (int) str.size();
    connectNode(head, r, str[index], str, index, endindex);
    connectNode(head, l, str[index], str, index, endindex);
}

void BinaryTree::connectNode(Node *parent_p, direction dire, char childvalue, const vector<char> &str, int &index,
                             int endindex) {
    ++index;
    //connect
    if (childvalue == '#') {
        if (dire == l) {
            parent_p->left = nullptr;
        } else {//dire==r
            parent_p->right = nullptr;
        }
        //don't need next step
    } else {//childvalue is number
        Node *childnode = new Node;
        childnode->right = childnode->left = nullptr;
        childnode->value = childvalue;
        if (dire == l) {
            parent_p->left = childnode;
        } else {//dire==r
            parent_p->right = childnode;
        }
        //continue next step
        if (index < endindex) {
            connectNode(childnode, r, str[index], str, index, endindex);
            connectNode(childnode, l, str[index], str, index, endindex);
        }
    }
}

void BinaryTree::find_node_print_trace(char c) const {
    queue<char> qu;
    bool found = find_node(c, head, qu);
    if (found) {
        output_queue(qu);
    } else {//not found
        cout << "not present" << endl;
    }
}

/*a recursive function
 * */
bool BinaryTree::find_node(char c, Node *parent_p, queue<char> &qu) const {
    //check if parent_p is target
    if (parent_p->value == c) {
        qu.push(parent_p->value);
        return true;
    } else {//parent_p is not target
        qu.push(parent_p->value);//push parent_p->value into queue
        //find direction of childnode we want
        //check if parent_p has childnode in that direction
        if (c > parent_p->value) {
            if (parent_p->right == nullptr) {//can't find target in this tree, search end
                return false;
            } else {//childnode exists,go to check
                return find_node(c, parent_p->right, qu);
            }
        } else {//c<parent_p->value
            if (parent_p->left == nullptr) {//can't find target in this tree, search end
                return false;
            } else {//childnode exists,go to check
                return find_node(c, parent_p->left, qu);
            }
        }
    }
}

void BinaryTree::output_queue(queue<char> &q) const {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

/*search node whose value is c , if found ,return pointer ,else return nullptr
 * */
Node *BinaryTree::get_node(char c) const {
    return get_node_recur(c, head);
}

Node *BinaryTree::get_node_recur(char c, Node *parent_p) const {
    //check if parent is target
    if (parent_p->value == c) {
        return parent_p;
    } else {//parent is not target
        //go to check childnode if exists
        if (c < parent_p->value) {
            if (parent_p->left == nullptr) {// no proper childnode
                return nullptr;
            } else {//there is desired childnode ,check it
                return get_node_recur(c, parent_p->left);
            }
        } else {//c>parent_p->value
            if (parent_p->right == nullptr) {
                return nullptr;
            } else {
                return get_node_recur(c, parent_p->right);
            }
        }
    }
}


/*只依题意设计处理删除root的功能
 * */
void BinaryTree::delete_node(char c) {
    Node *target_p = get_node(c);
    //Node *parent_p=get_parent_node(c);
    if (target_p == nullptr) {//target not found
        cout << "node not exists" << endl;
        return;
    }
    Node *l = target_p->left;
    Node *r = target_p->right;

    /*
     *
     * 删除处理非常繁杂易错，向助教请教一下怎么写得简单不易出错
     *
     */
    if (target_p == head) {
        if (l == nullptr && r == nullptr) {
            cout << "root is the only node" << endl;
        } else if (r != nullptr) {//r!=nullptr
            Node *least_right_p = get_least_right(target_p);//least node on the right
            if (least_right_p == head->right) {//第二层是特殊情况
                least_right_p->left = head->left;
                delete (head);
                head = least_right_p;
            } else {//not second
                //if the least-right node has a right subtree ,make it the left of its parent ,if not ,nullptr is made
                Node *l_r_rsubtree_p = least_right_p->right;
                Node *p_lr_p = get_parent_node(least_right_p->value);//find parent
                p_lr_p->left = l_r_rsubtree_p;
                head->value = least_right_p->value;
                delete (least_right_p);//delete the least_right node
            }
        } else {//r==nullptr && l!=nullptr
            /*
            Node *most_left_p = get_most_left(target_p);
            Node *p = get_parent_node(most_left_p->value);
            head->value = most_left_p->value;
            delete (most_left_p);
            p->right = nullptr;*/
        }
    } else {//target isn't root

    }
}

/*return pointer if found ,nullptr if not found ,
 * raise error if target is root ,and return nullptr
 * */
Node *BinaryTree::get_parent_node(char c) {
    if (head->value == c) {
        cout << "root has no parent" << endl;
    }
    return get_parent_node_recur(c, head, nullptr);
}

/*same as get_node() except remember and return parent's pointer
 * */
Node *BinaryTree::get_parent_node_recur(char c, Node *current_p, Node *lastnode_p) {
    //check if parent is target
    if (current_p->value == c) {
        return lastnode_p;
    } else {//parent is not target
        //go to check childnode if exists
        if (c < current_p->value) {
            if (current_p->left == nullptr) {// no proper childnode
                return nullptr;
            } else {//there is desired childnode ,check it
                return get_parent_node_recur(c, current_p->left, current_p);
            }
        } else {//c>current_p->value
            if (current_p->right == nullptr) {
                return nullptr;
            } else {
                return get_parent_node_recur(c, current_p->right, current_p);
            }
        }
    }
}

Node *BinaryTree::get_most_left(Node *parent_p) const {
    Node *p = head->left;
    while (p->right != nullptr) {
        p = p->right;
    }
    return p;
}

Node *BinaryTree::get_least_right(Node *parent_p) const {
    Node *p = head->right;
    while (p->left != nullptr) {
        p = p->left;
    }
    return p;
}