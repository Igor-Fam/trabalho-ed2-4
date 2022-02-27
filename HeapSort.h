#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <string>
#include <iostream>

#include "fileManager.h"
#include "resultados.h"

using namespace std;

void trocaposH(Review *regs,int a, int b){
    Review *aux = new Review;
    *aux = regs[a];
    regs[a] = regs[b];
    regs[b] = *aux;
    delete aux;
}

void heapify(int arr[], int n, int i,resultados *resultH)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    resultH->addcomp();
    if (l < n && arr[l] > arr[largest])
        largest = l;
    resultH->addcomp();
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    if (largest != i) {
        swap(arr[i], arr[largest]);
        resultH->addmov();
        heapify(arr, n, largest,resultH);
    }
}

void heapSort(int arr[], int n, resultados *resultH)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i,resultH);
  
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        resultH->addmov();
        heapify(arr, i, 0,resultH);
    }
}

void StartHeapsort(int *arr, int n,int m){
  string tipo="Heap";
  auto c = chrono::high_resolution_clock::now();
  resultados *resultH = new resultados;
  resultH->setresult(m+1);
  heapSort(arr,n,resultH);
  auto f = chrono::high_resolution_clock::now();
  auto total = chrono::duration_cast<chrono::microseconds>(f-c);
  float tempo = total.count();
  resultH->addtempo(tempo);
  resultH->addtipo(tipo);
  resultH->salvar();
  delete resultH;
}

#endif