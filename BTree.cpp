#include "BTree.h"
#include "BNode.h"

BTree::BTree(int order)
{
    m = order;
    root = NULL;
}

void BTree::print()
{
    if (root != NULL)
        root->print();
}

void BTree::insert(ReviewNode k)
{
    if (root != NULL)
    {
        if (root->n == m - 1)
        {
            BNode* l = new BNode(m, false);
            l->children[0] = root;
            l->splitChild(0, root);
            int i = 0;
            if (l->keys[0].id < k.id)
                i++;

            BNode::comparisons++;

            l->children[i]->insertNode(k);
            root = l;
        }
        else
        {
            root->insertNode(k);
        }
    }
    else
    {
        root = new BNode(m, true);
        root->n = 1;
        root->keys[0] = k;
    }
}

BNode* BTree::search(ReviewNode k)
{
    if (root != NULL)
        return root->search(k.id);
    return NULL;
}

