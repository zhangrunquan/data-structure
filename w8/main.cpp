#include <iostream>
//#include "merge_sort.h"
#include "twosum.h"
#include "merge_sort_list.h"
using namespace std;
const int n=8;
int main() {
    List l;
    for (int i = 0; i < n; ++i) {
        l.addnode(n-i);
    }
    merge_sort(l,0,n-1);
    l.output();
    //mergesort
    /*
    int ar[n]={0};
    for (int i = n; i >0 ; --i) {
        ar[n-i]=i;
    }
    for (int j = 0; j < n; ++j) {
        cout<<' '<<ar[j];
    }
    cout<<endl;
    merge_sort(ar,0,n-1);
    for (int j = 0; j < n; ++j) {
        cout<<' '<<ar[j];
    }
    cout<<endl;
    //std::cout << "Hello, World!" << std::endl;*/



    //twosum
    int ar[n]={1,1,1,3,3,2,2,6};
    Twosumer sumer(ar,n);
    sumer.getsum(4);
    return 0;
}