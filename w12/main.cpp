#include <iostream>
#include "Neighbou_table.h"
#include "UFset.h"
int main() {
    //input these
    /*
    6
    2 1 6 3 4
    4 0 6 3 7 4 7 2 10
    4 1 10 3 8 4 5 5 6
    4 0 4 1 7 2 8 4 12
    4 1 7 2 5 3 12 5 7
    2 2 6 4 7
     */
    /*nodenum
     * noden  node weight node weight ...
     * */
    int nodenum{};
    cin>>nodenum;
    Neighbor_table neighbor_table(nodenum);//construct from cin
    UFset ufset(nodenum);
    Connection temp_connenction(0,0,0);

    int counter=0;//num of adopted edges
    for (int i = 0; i < neighbor_table.get_edgenum(); ++i) {
        if(counter==nodenum){
            break;
        } else{//hasn't find ennough proper edges
            neighbor_table.get_connection(i,temp_connenction);//get smallest weight edge that has't been tested
            if (ufset.in_same_set(temp_connenction.get_node1(),temp_connenction.get_node2())){//node1 and node2 is in same set
                continue;
            } else{//node1 and node2 in this connection is not in same set
                ufset.connect(temp_connenction.get_node1(),temp_connenction.get_node2());
                cout<<temp_connenction<<endl;
            }
        }
    }
    cout<<"above are connections (node,node,weight) in least generated tree"<<endl;

    return 0;
}