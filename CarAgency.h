#ifndef MAIN_CPP_CARAGENCY_H
#define MAIN_CPP_CARAGENCY_H

#include "CarType.h"
#include "avl_tree.h"

class CarAgency{
    int agency_id;
    int tree_size;
    CarAgency* father;
    AVLTree<CarType> types_tree;
public:

};
#endif //MAIN_CPP_CARAGENCY_H
