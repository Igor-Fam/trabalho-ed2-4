#ifndef BTREE_H
#define BTREE_H

#include "BNode.h"
#include "ReviewNode.h"

class BTree
{
private:
    int m;
    BNode* root;

public:
    BTree(int order);

    void print();

    void insert(ReviewNode k);

    BNode* search(ReviewNode k);

};

#endif