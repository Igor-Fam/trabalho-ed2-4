#include "VPNode.h"

VPNode::VPNode(){
    parent = NULL;
    color = 1;
    left = NULL;
    right = NULL;
    node = NULL;
}

VPNode::~VPNode(){
    parent = NULL;
    left = NULL;
    right = NULL;
}

VPNode* VPNode::getUncle(){
    if(parent->parent == NULL){
        return NULL;
    }else{
        if(parent->parent->left == parent){
            return parent->parent->right;
        }else{
            return parent->parent->left;
        }
    }
}

void VPNode::addcomp(){
    comparisons++;
}