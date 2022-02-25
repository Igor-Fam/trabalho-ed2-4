#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(){}

HuffmanNode::HuffmanNode(char c, int f){
    character = c;
    freq = f;
    left = nullptr;
    right = nullptr;
}

HuffmanNode::HuffmanNode(HuffmanNode* a, HuffmanNode* b){
    freq = a->freq + b->freq;
    character = '\0';
    if(a->freq <= b->freq){
        left = a;
        right = b;
    } else {
        left = b;
        right = a;
    }
}

HuffmanNode::~HuffmanNode(){}

HuffmanNode* HuffmanNode::getLeft(){ return left; }

char HuffmanNode::getChar(){ return character; }

int HuffmanNode::getFreq(){ return freq; }

HuffmanNode* HuffmanNode::getRight(){ return right; }