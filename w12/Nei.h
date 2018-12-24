//
// Created by 123 on 2018/12/24.
//

#ifndef W12_NEI_H
#define W12_NEI_H


class Nei {

public:
    Nei(int node, int weight);
private:
    int node,weight;
};

Nei::Nei(int node, int weight) {
    this->node=node;
    this->weight=weight;
}


#endif //W12_NEI_H
