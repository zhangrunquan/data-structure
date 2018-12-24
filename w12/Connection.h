//
// Created by 123 on 2018/12/24.
//

#ifndef W12_CONNECTION_H
#define W12_CONNECTION_H
using namespace std;

class Connection {

public:
    Connection(int node1, int node2, int weight);
    int get_weight();
    int get_node1();
    int get_node2();
    friend ostream& operator<<(ostream& output,Connection & connection);
private:
    int node1,node2,weight;
};

int Connection::get_weight() {
    return weight;
}

Connection::Connection(int node1, int node2, int weight) {
    this->node1=node1;
    this->node2=node2;
    this->weight=weight;
}

int Connection::get_node1() {
    return node1;
}

int Connection::get_node2() {
    return node2;
}

ostream &operator<<(ostream &output, Connection &connection) {
    return output<<'('<<connection.node1<<','<<connection.node2<<','<<connection.weight<<')';
}


#endif //W12_CONNECTION_H
