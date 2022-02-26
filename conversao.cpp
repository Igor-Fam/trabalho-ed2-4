#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>

#include "HuffmanTree.h"

using namespace std;

typedef std::basic_string<unsigned char> ustring;

char binario_decimal(string binario);
string decimal_binario(int decimal);
string convert(string text);

HuffmanTree* a;

HuffmanTree* buildtree(string text){
    unordered_map<char, int> freqMap;
    for(char c : text){
        freqMap[c]=0;
    }
    for(char c : text){
        freqMap[c]=freqMap[c]+1;
    }

    unordered_map<HuffmanTree*, int> treeMap;
    for(auto k : freqMap){
        treeMap[new HuffmanTree(k.first, k.second)]=k.second;
    }

    HuffmanTree* l1, *l2;
    unordered_map<HuffmanTree*,int> :: iterator itr, itraux;

    while(treeMap.size() > 1){
        for(itr = treeMap.begin(); itr != treeMap.end(); itr++){
            if(itr == treeMap.begin()){
                l1 = itr->first;
            }else{
                if(l1->getRootFreq() > itr->second){
                    l1 = itr->first;
                }
            }
        }
        treeMap.erase(l1);
        for(itr = treeMap.begin(); itr != treeMap.end(); itr++){
            if(itr == treeMap.begin()){
                l2 = itr->first;
            }else{
                if(l2->getRootFreq() > itr->second){
                    l2 = itr->first;
                }
            }
        }
        treeMap.erase(l2);
        if(l1->getRootFreq() <= l2->getRootFreq()){
            treeMap[new HuffmanTree(l1,l2)] = l1->getRootFreq() + l2->getRootFreq();
        }else{
            treeMap[new HuffmanTree(l2,l1)] = l1->getRootFreq() + l2->getRootFreq();
        }
    }
    return treeMap.begin()->first;
}



void teste(){
    string text;
    cout << "Insira o texto: ";
    //cin >> text;
    text = "dwadawdawdaw";
    HuffmanTree *tree = buildtree(text);
    a = tree;
    tree->map();
    text = tree->encode(text);
    string text_c = convert(text);
    ofstream file("teste.txt", ios::out | ios::binary);
    file << text_c;
    file.close();
}

string convert(string text){
    unsigned int nstring;
    int i;
    string text_c = "";
    nstring = text.length()/8;
    text_c = text_c + to_string(nstring);
    for(i=0;i<nstring;i++){
        text_c = text_c + binario_decimal(text.substr(i*8,8));
    }
    text_c = text_c + text.substr(i*8);
    return text_c;
}

char binario_decimal(string binario)
{
    unsigned long long decimal=0;
    char aux;
    reverse(binario.begin(),binario.end());
    int tam = binario.size();
    for(int i=0; i< tam; i++)
        if(binario[i] == '1')
        {
            decimal += pow(2,i);
        }

    aux = decimal;
    return aux;
}

void getfromfile(){
    ifstream file("teste.txt", ifstream::binary);
    string text_c="";
    string text="";
    int n;

    string aux;
    while(getline(file, aux)){
        text_c = text_c + aux + '\n';
    }
    text_c.erase(text_c.end()-1);
    char nstring = text_c[0];
    text_c = text_c.substr(1);
    int max = nstring - '0';

    int cont=0;
    for(unsigned char c : text_c){
        if(cont<max){
            n = c;
            text = text + decimal_binario(n);
            cont++;
        }
    }
    text = text + text_c.substr(max);
    text = a->decode(text);
}

string decimal_binario(int decimal){
    vector<int> binario;
    string btext;
    while (decimal>0){
        binario.push_back(decimal % 2);
        decimal = decimal/2;
    }
    while(binario.size()<8){
        binario.push_back(0);
    }
    for(int i = binario.size()-1; i >=0; i--){
        btext = btext + to_string(binario.at(i));
    }
    return btext;
}


int main()
{
    teste();
    getfromfile();

    return 0;
}