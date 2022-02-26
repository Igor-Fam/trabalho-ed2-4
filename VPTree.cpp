#include "VPTree.h"
#include "VPNode.h"

VPTree::VPTree(){
    root = NULL;
}

VPTree::~VPTree(){
    destructor(root);
}

void VPTree::destructor(VPNode* a){
    if(a != NULL){
        destructor(a->left);
        destructor(a->right);
        delete a;
    }
}

void VPTree::insert(ReviewNode* id_new){
    root = auxinsert(id_new,root);
}

VPNode* VPTree::auxinsert(ReviewNode* id_new, VPNode* a){
    VPNode* aux;
    if(a == NULL){
        aux = new VPNode();
        aux->addcomp();
        aux->node = id_new;
        aux->color = 0;
    }else{
        VPNode* auxp = new VPNode;
        while(a != NULL){
            auxp = a;
            a->addcomp();
            if(id_new->id < a->node->id){
                a = a->left;
            }else{
                a = a->right;
            }
        }
        a = new VPNode();
        a->parent = auxp;
        a->node = id_new;
        a->addcomp();
        if(a->node->id < auxp->node->id){
            auxp->left= a;
        }else{
            auxp->right = a;
        }
        while(a!=NULL){
            a = verify_tree(a);
            aux = a;
            a = a->parent;
        }
    }
    return aux;
}

VPNode* VPTree::verify_tree(VPNode* a){
    a->addcomp();
    if(a->parent == NULL){
        a->color = 0;
        return a;
    }else{
        a->addcomp();
        if(a->parent->color == 0){
            return a;
        }else{
            VPNode* uncle = a->getUncle();
            a->addcomp();
            if((a->color == 1) && (a->parent->color == 1)){
                a->addcomp();
                if(uncle != NULL){
                    if(uncle->color == 0){
                        a = verify_rot(a);
                    }else{
                        a->parent->color = 0;
                        uncle->color = 0;
                        a->parent->parent->color = 1;
                    }
                }else{
                    a = verify_rot(a);
                }
            }
            return a;
        }
    }
}

VPNode* VPTree::verify_rot(VPNode* a){
    VPNode* gparent = a->parent->parent;
    if(gparent->left == a->parent){
        a->addcomp();
        if(a->parent->right == a){
            recolorDoubleRot(a);
            gparent = right_rotation_double(gparent);
        }else{
            recolorSimpleRot(a);
            gparent = right_rotation(gparent);
        }
    }else{
        a->addcomp();
        if(a->parent->right == a){
            recolorSimpleRot(a);
            gparent = left_rotation(gparent);
        }else{
            recolorDoubleRot(a);
            gparent = left_rotation_double(gparent);
        }
    }
    a->addcomp();
    gparent->color = 0;
    gparent->left->color = 1;
    gparent->right->color = 1;
    return gparent;
}

VPNode* VPTree::search(string ids){
    return auxsearch(root,ids);
}

VPNode* VPTree::auxsearch(VPNode* a,string ids){
    VPNode* aux = new VPNode;
    aux = NULL;
    if(a != NULL){
        a->addcomp();
        if(a->node->id == ids){
            return a;
        }
        aux=auxsearch(a->left,ids);
        if(aux!=NULL){
            return aux;
        }
        aux=auxsearch(a->right,ids);
        if(aux!=NULL){
            return aux;
        }
        return aux;
    }
    return aux;
}

VPNode* VPTree::left_rotation(VPNode* a){
    VPNode* q = a->right;
    a->right = q->left;
    q->left = a;
    if(a->parent!=NULL){
        if(a->parent->left == a){
            a->parent->left = q;
        }else{
            a->parent->right = q;
        }
    }
    q->parent = a->parent;
    a->parent = q;
    if(a->right!=NULL){
        a->right->parent = a;
    }
    return q;
}

VPNode* VPTree::right_rotation(VPNode* a){
    VPNode* q = a->left;
    a->left = q->right;
    q->right = a;
    if(a->parent!=NULL){
        if(a->parent->left == a){
            a->parent->left = q;
        }else{
            a->parent->right = q;
        }
    }
    q->parent = a->parent;
    a->parent = q;
    if(a->left!=NULL){
        a->left->parent = a;
    }
    return q;
}

VPNode* VPTree::left_rotation_double(VPNode* a){
    VPNode* aux = a->right;
    a->right = right_rotation(aux);
    if(a->right!=NULL){
        a->right->parent = a;
    }
    return left_rotation(a);
}

VPNode* VPTree::right_rotation_double(VPNode* a){
    VPNode* aux = a->left;
    a->left = left_rotation(aux);
    if(a->left!=NULL){
        a->left->parent = a;
    }
    return right_rotation(a);
}

void VPTree::recolorSimpleRot(VPNode* a){
    a->parent->color=0;
    a->parent->parent->color=1;
}

void VPTree::recolorDoubleRot(VPNode* a){
    a->color=0;
    a->parent->parent->color=1;
}