#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <string>
#include <iostream>

#include "fileManager.h"
#include "resultados.h"

using namespace std;

int media_3(int *arr, int i, int f){
    int meio = (i+f)/2;
    if(arr[i] > arr[f])
        swap(arr[i], arr[f]);
    if(arr[meio] > arr[f])
        swap(arr[meio], arr[f]);
    if(arr[i] > arr[meio])
        swap(arr[i], arr[meio]);
    swap(arr[meio], arr[f]);
    return arr[f];
}

int partition(int arr[], int start, int end,resultados *resultQ)
{
    int pivot = media_3(arr,start,end);
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot){
            count++;
            resultQ->addcomp();
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    resultQ->addmov();
    int i = start, j = end;
    resultQ->addcomp();
    while (i < pivotIndex && j > pivotIndex) {
        resultQ->addcomp();
        while (arr[i] <= pivot) {
            i++;
        }
        resultQ->addcomp();
        while (arr[j] > pivot) {
            resultQ->addcomp();
            j--;
        }
        resultQ->addcomp();
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            resultQ->addmov();
        }
    }
 
    return pivotIndex;
}
 
void QuickSort(int arr[], int start, int end,resultados *resultQ)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end,resultQ);
    QuickSort(arr, start, p - 1,resultQ);
    QuickSort(arr, p + 1, end,resultQ);
}

void StartQuicksort(int *arr,int r, int m){
  resultados *resultQ = new resultados;
  resultQ->setresult(m+1);
  auto c = chrono::high_resolution_clock::now();
  QuickSort(arr,0,r-1,resultQ);
  auto f = chrono::high_resolution_clock::now();
  auto total = chrono::duration_cast<chrono::milliseconds>(f-c);
  float tempo = total.count();
  resultQ->addtempo(tempo);
  resultQ->salvar();
  delete resultQ;
}



#endif