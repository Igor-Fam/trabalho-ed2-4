#include <iostream>
#include <fstream>
#include <chrono>


#include "main.h"
#include "HuffmanTree.h"

using namespace std;

int main(int argc, char *argv[])
{
    //visualizar arvore: https://cmps-people.ok.ubc.ca/ylucet/DS/Huffman.html 
    //text: abbcccddddeeeee
    
    HuffmanTree* a = new HuffmanTree('a', 1);
    HuffmanTree* b = new HuffmanTree('b', 2);
    HuffmanTree* c = new HuffmanTree('c', 3);
    HuffmanTree* d = new HuffmanTree('d', 4);
    HuffmanTree* e = new HuffmanTree('e', 5);

    HuffmanTree* f = new HuffmanTree(a, b); // freq 3
    HuffmanTree* g = new HuffmanTree(f, c); // freq 6
    HuffmanTree* h = new HuffmanTree(d, e); // freq 9
    HuffmanTree* i = new HuffmanTree(g, h);
    i->map();
    i->printMap();
    return 0;
}

