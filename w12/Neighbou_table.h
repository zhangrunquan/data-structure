//
// Created by 123 on 2018/12/24.
//

#include "Connection.h"
#include "Nei.h"
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef W12_NEIGHBOU_TABLE_H
#define W12_NEIGHBOU_TABLE_H

#endif //W12_NEIGHBOU_TABLE_H
bool compare_connection(Connection connection1,Connection connection2);

using namespace std;
class Neighbor_table{
public:
    explicit Neighbor_table(int nodenum);//construct from cin ,store graph in neighbor table ,store connections in array
    //and sort them by weight
    void read_edge(int node1,int node2,int weight);//if node1<node2 ,save this in connection_ar ,else do nothing
    // only node1<node2 is valid to avoid save twice in undirected graph
    void get_connection(int index,Connection &receiver);//将receiver设置为索引对应的connection
    void sort_edges();//排序边
    int get_nodenum();
    int get_edgenum();
private:
    int nodenum;
    int edgenum{};
    vector<Connection> connection_ar_p;
    vector<vector<Nei *>> nei_table;

    /*
     * 成员变量的vector push局部变量可以吗*/
};

Neighbor_table::Neighbor_table(int nodenum) {
    this->nodenum=nodenum;
    //read data from cin
    for (int i = 0; i <nodenum ; ++i) {
        vector<Nei *> row;// create one row
        int num=0;//number of connection
        cin>>num;
        int nodeindex,weight;
        for (int j = 0; j <  num; ++j) {
            //put data into nei_table
            cin>>nodeindex>>weight;
            auto *conn_p=new Nei(nodeindex,weight);
            row.push_back(conn_p);
            //put data into connection_ar
            read_edge(i,nodeindex,weight);//valid only when node1<node2
        }
        nei_table.push_back(row);//add row to nei_table
    }
    sort_edges();
}

//仅支持了不会自己连接自己的图
void Neighbor_table::read_edge(int node1, int node2, int weight) {
    if(node1>=node2)
        return;
    Connection connection(node1,node2,weight);
    connection_ar_p.push_back(connection);
    ++edgenum;
}

void Neighbor_table::get_connection(int index, Connection &receiver) {
    if(index>=0 && index<edgenum){
        receiver=connection_ar_p[index];
    }
}

void Neighbor_table::sort_edges() {
    sort(connection_ar_p.begin(),connection_ar_p.end(),compare_connection);
}

int Neighbor_table::get_nodenum() {
    return nodenum;
}

int Neighbor_table::get_edgenum() {
    return edgenum;
}

bool compare_connection(Connection connection1,Connection connection2){
    return connection1.get_weight()<connection2.get_weight();
}




