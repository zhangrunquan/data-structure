//
// Created by zrq on 2018/11/26.
//

#include <malloc.h>
#include <iostream>
#include <vector>
#include "quick_sort.h"
#include <vector>

using namespace std;
#ifndef W8_TWOSUM_H
#define W8_TWOSUM_H

#endif //W8_TWOSUM_H
/*
struct Node{
    int value;
    int index;
};*/
#define IMPOSSIBLEVALUE 0.1

/*思路：先将数组转换为结构体数组，结构体中保存对应数组元素的数据和索引，然后按数据对结构体数组进行快排
 * 在查找时算出要找的数字，用二分查找找到一个值，然后向左右两侧探查值相同的项，
 */
/*将int数组转换为所需的结构体数组*/
class Twosumer {
public:
    Twosumer(const int *ar, const int length);

    ~Twosumer();

    void getsum(int sum) const;

    int bisearch(int key, int beg, int last) const;

    void output(int index1, int index2)const;

private:
    Node *start;
    int len, indexlen;
    vector<vector<int> > index;
};

//将整数数组转化为结构体数组
Twosumer::Twosumer(const int *ar, const int length) {//缺陷：length比ar实际长度长时会出错，且不知如何检查
    len = length;
    start = (Node *) malloc(len * sizeof(Node));
    //将数组转换为结构体数组
    for (int i = 0; i < len; ++i) {
        (start + i)->index = i + 1;
        (start + i)->value = ar[i];
    }
    //快排
    qksort(start, 0, len - 1);
    indexlen = 0;
    //建立index
    vector<int> siglerow(2,0);
    int last = IMPOSSIBLEVALUE;
    for (int j = 0; j < len; ++j) {//
        if (start[j].value != last) {
            last = start[j].value;
            index.push_back(siglerow);
            index[indexlen][0]=last; //index的记录每个数值在节点数组第一次出现的索引和数值
            index[indexlen++][1] = j;
        }
    }
}

Twosumer::~Twosumer() {
    free(start);
}


void Twosumer::getsum(int sum) const {
    vector<int> results1, results2;//存储两个加数的全部索引（数值相同的所有索引）
    vector<vector<int> >::const_iterator it;
    bool endflag= false;
    for (it = index.begin(); it != index.end(); ++it) {
        //更新
        int added = (*it)[0];
        int addend = sum - added;
        if (addend < added) {
            return;
        }else if(addend==added){
            endflag= true;
        }
        int addend_i;
        if ((addend_i = bisearch(addend, 0, indexlen-1)) == -1) {//当前数值在数组中找不到加和为sum的值
            continue;
        } else {
            int beg_i=index[addend_i][1];
            output((*it)[1],beg_i);//start数组中两加数的起始值
        }
        if(endflag){
            return;
        }
    }
}

//返回索引
int Twosumer::bisearch(int key, int beg, int last) const {
    if (beg == last) {
        return -1;
    }
    int mid = (beg + last) / 2;
    int middata = index[mid][0];
    if (middata == key) {//检查中间
        return mid;
    } else if (middata > key) {
        bisearch(key, beg, mid - 1);
    } else if (middata < key) {
        bisearch(key, mid + 1, last);
    }
}



void Twosumer::output(int index1,int index2) const{
    int added=start[index1].value;
    int addend=start[index2].value;
    if(index1==index2){
        ++index2;//避免自己与自己的组合
    }
    int index2_counter=index2;
    while(start[index1].value==added){
        while(start[index2_counter].value==addend){
            cout<<'('<<start[index1].index<<','<<start[index2_counter++].index<<')'<<endl;
        }
        ++index1;
    }
}


