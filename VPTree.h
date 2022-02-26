#ifndef VPTREE_H
#define VPTREE_H

#include <iostream>
#include "VPNode.h"
#include "ReviewNode.h"

class VPTree{


    public:
        VPNode *root;
        
        VPTree();

        ~VPTree();

        void destructor(VPNode* a);

        void insert(ReviewNode* id_new);

        VPNode* auxinsert(ReviewNode* id_new, VPNode* a);

        VPNode* verify_tree(VPNode* a);

        VPNode* verify_rot(VPNode* a);

       VPNode* search(string ids);

       VPNode* auxsearch(VPNode* a,string ids);

        VPNode* left_rotation(VPNode* a);
        
        VPNode* right_rotation(VPNode* a);

        VPNode* left_rotation_double(VPNode* a);
        
        VPNode* right_rotation_double(VPNode* a);

        void recolorSimpleRot(VPNode* a);

        void recolorDoubleRot(VPNode* a);
};

#endif