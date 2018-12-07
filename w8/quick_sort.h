//
// Created by 20418 on 2018/11/24.
//


struct Node{
    int value;
    int index;
};
#ifndef W71_QUICK_SORT_H
#define W71_QUICK_SORT_H


#endif //W71_QUICK_SORT_H
int partition(Node *ar,int begin,int end){
    //选首元素作为中枢
    Node  mid=ar[begin];
    int count=0;//排序完的个数
    int total=end-begin;//移动total次后begin=end
    while(true){
        while(ar[end].value>=mid.value){
            --end;
            ++count;
            if(count==total) break;
        }
        if(count==total) break;
        if(ar[end].value<mid.value){
            ar[begin]=ar[end];
            ar[end]=mid;
        }
        while(ar[begin].value<=mid.value){
            ++begin;
            ++count;
            if(count==total) break;
        }
        if(count==total) break;
        if(ar[begin].value>mid.value){
            ar[end]=ar[begin];
            ar[begin]=mid;
        }
    }
    return begin;
}


void qksort(Node *ar,int begin,int end){
    if(begin>=end){
        return;
    }
    int mid=partition(ar,begin,end);
    if(end-begin==1){
        return;
    }
    qksort(ar,begin,mid-1<0?0:mid-1);
    qksort(ar,mid+1>end?end:mid+1,end);
}
