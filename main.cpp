#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

#include "ShellSort.h"
#include "fileManager.h"
#include "HuffmanCompression.h"
#include "BalancedStructures.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int BNode::comparisons;
int VPNode::comparisons;
string path;

int main(int argc, char *argv[])
{
    path = argv[1];
    ifstream check;
    check.open("tiktok_app_reviews.bin");
    if (check.is_open()) {
        cout << "Arquivo binario encontrado." << endl;
        check.close();
    }
    else {
        cout << "Erro: arquivo binario nao encontrado.";
        processamento();
    }
    int option = -1;
    while(option != 4){
        cout << "Qual parte do trabalho deseja executar?" << endl;
        cout << "1. Ordenacao" << endl;
        cout << "2. Estruturas Balanceadas" << endl;
        cout << "3. Compressao de Huffman" << endl;
        cout << "4. Sair" << endl;
        cin >> option;
        switch(option){
            case 1:
                break;
            case 2: 
                BalancedStructuresInterface();
                break;
            case 3: 
                compressionInterface();
                break;
            case 4:
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }


    return 0;
} 

void analiseQuickSort(){
    int n[5] = {10000, 50000, 100000, 500000, 1000000};
    //int n[5] = {10, 50, 100, 500, 1000};
    int i,j,k;
    int *arr;
    for(i=0; i<5; i++){
        Review *regs = new Review[n[i]];
        for(j=0; j<3; j++){
            regs = importReviews(n[i]);
            arr = new int[n[i]];
            for(k=0;k<n[i];k++){
                arr[k] = stoi(regs[k].upvotes);
            }
            StartQuicksort(arr,n[i],j);
        }
        delete [] regs;
    }
}

void analiseHeapSort(){
    int n[5] = {10000, 50000, 100000, 500000, 1000000};
    int i,j,k;
    int *arr;
    for(i=0; i<5; i++){
        Review *regs = new Review[n[i]];
        for(j=0; j<3; j++){
            regs = importReviews(n[i]);
            arr = new int[n[i]];
            for(k=0;k<n[i];k++){
                arr[k] = stoi(regs[k].upvotes);
            }
            StartHeapsort(arr,n[i],j);
            delete [] arr;
        }
        delete [] regs;
    }
}

void analiseShellSort(){
    int n[5] = {10000, 50000, 100000, 500000, 1000000};
    int i,j;
    for(i=0;i<5;i++){
        Review *regs = new Review[n[i]];
        for(j=0;j<3;j++){
            regs = importReviews(n[i]);
            shellSort(regs, n[i]);
        }
        delete [] regs;
    }
}

int main(int argc, char *argv[])
{
    path = argv[1];

    cout << "----------" << endl;
    cout<< "Escolha qual analise de ordenacao: " << endl;
    cout << "(1) Analise QuickSort" << endl;
    cout << "(2) Analise HeapSort" << endl;
    cout << "(3) Analise ShellSort" << endl;
    int option;
    cin >> option;
    switch(option){
        case 1:
            analiseQuickSort();
            break;
        case 2:
            analiseHeapSort();
            break;
        case 3:
            analiseShellSort();
            break;
    }
    return 0;
}