#include <iostream>
#include "heap.h"
int main() {
    Node ar[]={Node(1,2),Node(2,4),Node(4,5),Node(4,4)};
    int len= sizeof(ar)/ sizeof(ar[0]);
    Heap<Node> hp(ar,len);
    hp.sort();

    /*topk
     * */
    Heap<Node> hp2(ar,len);
    for (int i = 0; i < len; ++i) {
        hp2.topk(ar[i]);
    }
    return 0;
}