#ifndef VPNODE_H
#define VPNODE_H

#include <iostream>
#include "ReviewNode.h"

using namespace std;

class VPNode
{
public:
    VPNode *left;
    VPNode *right;
    VPNode *parent;
    ReviewNode* node;
    int color;
    static int comparisons;
    
    VPNode();

    ~VPNode();

    VPNode* getUncle();

    void addcomp();
};

#endif