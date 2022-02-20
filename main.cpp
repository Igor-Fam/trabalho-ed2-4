#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#include "main.h"
#include "HuffmanTree.h"

using namespace std;

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

string buildtext(int N){
    ifstream file;
    string text="";
    file.open("tiktok_app_reviews.bin");
    file.seekg(0, ios::end);
    int max = (file.tellg() / sizeof(Review));
    Review *reg = new Review;
    std::random_device dev;
    std::mt19937 rng(time(nullptr));
    std::uniform_int_distribution<std::mt19937::result_type> random_number(0,max);

    for (int i = 0; i < N; i++) {
        int random = random_number(rng);
        file.seekg(random * sizeof(Review), ios::beg);
        file.read(reinterpret_cast<char*>(reg), sizeof(Review));
        text = text + reg->review_text;
    }
    delete reg;
    file.close();
    return text;
}

HuffmanTree* comprimir(int N){
    string text = buildtext(N);
    HuffmanTree *tree = buildtree(text);
    tree->map();
    text = tree->encode(text);
    ofstream file("reviewsComp.bin", ios::out | ios::binary);
    file << text;
    file.close();
    return tree;
}

float* descomprimir(HuffmanTree *a){
    ifstream file("reviewsComp.bin", ifstream::binary);
    string text;
    float *est= new float[2];
    file >> text;
    file.close();
    est[1] = text.size()/8.0;
    text = a->decode(text);
    est[0] = text.size();
    ofstream sfile("reviewsOrig.bin", ios::binary);
    sfile << text;
    sfile.close();
    return est;
}

float auxanalise(int N){
    float taxa_de_comp, med=0;
    ofstream fileout("saida.txt", ios_base::out | ios_base::app);
    fileout << "N: " << N << endl;
    HuffmanTree* a;
    for(int M=0;M<3;M++){
        a = comprimir(N);
        float *est = descomprimir(a);
        taxa_de_comp = (est[0]-est[1])/est[0];
        fileout << M << ": Taxa de compressao = " << taxa_de_comp*100 << "%" << endl;
        med = med + taxa_de_comp;
    }
    fileout.close();
    return med/3;
}

void analise(){
    ofstream file("saida.txt");
    file.close();
    float med=0;
    /* auxanalise(10000);
    auxanalise(100000);
    auxanalise(1000000); */

    med = med + auxanalise(10);
    med = med + auxanalise(100);
    med = med + auxanalise(1000);
    ofstream fileout("saida.txt", ios_base::out | ios_base::app);
    fileout << "Media final: " << med*100 << "%" << endl;
    fileout.close();
}

int main(int argc, char *argv[])
{
    ifstream check;
    check.open("tiktok_app_reviews.bin");
    if (check.is_open()) {
        cout << "Arquivo binario encontrado." << endl;
        check.close();
    }
    else {
        cout << "Erro: arquivo binario não encontrado.";
        processamento();
    }

    int aux0=0;
    int aux1=0;
    int aux2=0;
    HuffmanTree *a;
    cout << "Bem vindo a sua interface de compressao" << endl;
    cout << endl;

    while(aux0!=4)
    {

        cout << "Digite o numero da atividade a ser realizada:" << endl;
        cout << endl;
        cout << "1-Comprimir N reviews e salva-los em um arquivo  reviewsComp.bin" << endl;
        cout << "2-Descomprimir um arquivo reviewsComp.bin e salva-lo num arquivo reviewsOrig.bin" << endl;
        cout << "3-Executar uma sequencia de compressoes de N reviews aleatorios e computar suas metricas" << endl;
        cout << "4-Sair" << endl;

             cin >> aux0;


        switch(aux0)
        {
        case 1:
            cout << "Quantas Reviews você desja comprimir?" << endl;
            cin >> aux1;
            a=comprimir(aux1);
            break;
        case 2:
            descomprimir(a);
            break;
        case 3:
            analise();
            break;
        default:
            cout << "Opcao invalida" << endl;
        }
        cout<< endl;
    }

    return 0;
}