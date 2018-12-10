//
// Created by zrq on 2018/12/10.
//
#include <malloc.h>
#include "List.h"
#ifndef W8_MERGE_SORT_LIST_H
#define W8_MERGE_SORT_LIST_H

#endif //W8_MERGE_SORT_LIST_H
/*
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
}*/
void merge(List &l,int begin,int mid,int end){
    int len=end-begin+1;
    int *tempar=(int *)malloc(len* sizeof(int));
    int start=begin;
    int begin2=mid+1;
    int t_index=0;
    while(begin<=mid&&begin2<=end){
        if(l.read_by_index(begin)<l.read_by_index(begin2)){
            tempar[t_index]=l.read_by_index(begin);
            ++begin;
        }else{
            tempar[t_index]=l.read_by_index(begin2);
            ++begin2;
        }
        ++t_index;
    }
    while(begin<=mid){
        tempar[t_index++]=l.read_by_index(begin);
        ++begin;
    }
    while(begin2<=end){
        tempar[t_index++]=l.read_by_index(begin2);
        ++begin2;
    }
    for (int i = 0; i < len; ++i) {
        l.assign(tempar[i],start+i);
    }
    free(tempar);
}

void merge_sort(List &l,int begin,int end){
    if(end==begin){
        return;
    }
    int mid=(begin+end)/2;
    merge_sort(l,begin,mid);
    merge_sort(l,mid+1,end);
    merge(l,begin,mid,end);
}

