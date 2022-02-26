#ifndef BNODE_H
#define BNODE_H

#include <string>
#include <fstream>

#include "ReviewNode.h"

class BNode
{
public:
    BNode();

    BNode(int order_, bool leaf);

    void insertNode(ReviewNode k);

    int findKey(string k);

    BNode* search(string k);

    void splitChild(int i, BNode* node);

    void print();

    void getRegistry(string id);

    static int comparisons;

    friend class BTree;

private:
    ReviewNode* keys;
    BNode** children;
    int m;
    int n;
    bool isLeaf;
};

#endif