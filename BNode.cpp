#include "BNode.h"

BNode::BNode(){}

BNode::BNode(int order_, bool leaf) {
    m = order_;
    isLeaf = leaf;
    children = new BNode * [m];
    keys = new ReviewNode[m - 1];
    n = 0;
}

void BNode::insertNode(ReviewNode k) {
    int i = n - 1;
    if (isLeaf)
    {
        while (i >= 0)
        {
            comparisons++;
            if ((keys)[i].id > k.id) {
                keys[i + 1] = keys[i];
                i--;
            }
            else {
                break;
            }
        }
        (keys)[i + 1] = k;
        n++;
    }
    else
    {
        while (i >= 0)
        {
            comparisons++;
            if ((keys)[i].id > k.id) {
                i--;
            }
            else
                break;
        }
        if (children[i + 1]->n == m - 1)
        {
            splitChild(i + 1, children[i + 1]);

            if ((keys)[i + 1].id < k.id)
            {
                i++;
            }
            comparisons++;
        }
        children[i + 1]->insertNode(k);
    }
}

int BNode::findKey(string k) {
    int i = 0;
    while (i < n) {
        comparisons++;
        if ((keys)[i].id < k)
            i++;
        else
            break;
    }
    return i;
}

BNode* BNode::search(string k) {
    int i = findKey(k);

    comparisons++;
    if ((keys)[i].id == k)
        return this;
    else
        if (isLeaf)
            return NULL;
        else
            return children[i]->search(k);
}

void BNode::splitChild(int i, BNode* node) {
    BNode* newNode = new BNode(node->m, node->isLeaf);
    for (int j = 0; j < m / 2 - 1; j++)
    {
        newNode->keys[j] = node->keys[j + m / 2];
    }
    if (!node->isLeaf)
    {

        for (int j = 0; j + m / 2 < m; j++) {

            newNode->children[j] = node->children[j + m / 2];
        }
            
    }
    newNode->n = m / 2 - 1;
    node->n = m / 2 - 1;
    for (int j = n; j >= i + 1; j--)
    {
        children[j + 1] = children[j];
    }
    children[i + 1] = newNode;
    for (int j = n - 1; j >= i; j--)
    {
        keys[j + 1] = keys[j];
    }

    keys[i] = node->keys[m / 2 - 1];
    n = n + 1;
}

void BNode::print() {
    int i;
    for (i = 0; i < n; i++)
    {
        if (!isLeaf)
            children[i]->print();
        cout << endl << (keys)[i].id;
    }
    if (!isLeaf)
        children[i]->print();
}

void BNode::getRegistry(string id) {
    for (int i = 0; i < n; i++) {
        if (keys[i].id == id) {
            keys[i].getReview();
            break;
        }
    }
}