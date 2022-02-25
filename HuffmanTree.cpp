#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(){
    root = nullptr;
}

HuffmanTree::HuffmanTree(HuffmanTree* a, HuffmanTree* b)
{
    root = new HuffmanNode(a->root, b->root);
}

HuffmanTree::HuffmanTree(char c, int f){
    root = new HuffmanNode(c, f);
}

HuffmanTree::~HuffmanTree(){}

int HuffmanTree::getRootFreq(){
    if(root == nullptr){
        cout << "Arvora vazia!" << endl;
        exit(1);
    }
    else {
        return root->getFreq();
    }
}

void HuffmanTree::map(){
    auxMap(root, "");
}

void HuffmanTree::printMap(){
    for(auto k : charMap){
        cout << k.first << " => " << k.second << endl;
    }
}

string HuffmanTree::encode(string text){
    string encodedText;
    for(char c : text){
        encodedText = encodedText + charMap[c];
    }
    return encodedText;
}

string HuffmanTree::decode(string enc_text){
    string decodedtext="";
    HuffmanNode* current = root;
    for(char c : enc_text){
        if(c == '0'){
            current=current->left;
            if(current->left == nullptr && current->right == nullptr){
                decodedtext = decodedtext + current->character;
                current=root;
            }
        }else{
            current=current->right;
            if(current->left == nullptr && current->right == nullptr){
                decodedtext = decodedtext + current->character;
                current=root;
            }
        }
    }
    return decodedtext;
}

void HuffmanTree::auxMap(HuffmanNode* current, string code){
    if(current->left == nullptr && current->right == nullptr){
        charMap[current->character] = code;
    } else {
        auxMap(current->left, code + "0");
        auxMap(current->right, code + "1");
    }

}