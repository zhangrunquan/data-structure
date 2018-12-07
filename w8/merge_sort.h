//
// Created by zrq on 2018/11/26.
//

#include <malloc.h>

#ifndef W8_MERGE_SORT_H
#define W8_MERGE_SORT_H

#endif //W8_MERGE_SORT_H
void merge(int *ar,int begin,int mid,int end){
    int len=end-begin+1;
    int *tempar=(int *)malloc(len* sizeof(int));
    int start=begin;
    int begin2=mid+1;
    int t_index=0;
    while(begin<=mid&&begin2<=end){
        if(ar[begin]<ar[begin2]){
            tempar[t_index]=ar[begin];
            ++begin;
        }else{
            tempar[t_index]=ar[begin2];
            ++begin2;
        }
        ++t_index;
    }
    while(begin<=mid){
        tempar[t_index++]=ar[begin++];
    }
    while(begin2<=end){
        tempar[t_index++]=ar[begin2++];
    }
    for (int i = 0; i < len; ++i) {
        ar[start+i]=tempar[i];
    }
    free(tempar);
}

void merge_sort(int *ar,int begin,int end){
    if(end==begin){
        return;
    }
    int mid=(begin+end)/2;
    merge_sort(ar,begin,mid);
    merge_sort(ar,mid+1,end);
    merge(ar,begin,mid,end);
}

