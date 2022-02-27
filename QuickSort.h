#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <string>
#include <iostream>

#include "fileManager.h"
#include "resultados.h"

using namespace std;

int media_3(int *upvts, int i, int f){
    int m = (i+f)/2;
    if(upvts[i] > upvts[f]){
        swap(upvts[i], upvts[f]);
    }
    if(upvts[m] > upvts[f]){
        swap(upvts[m], upvts[f]);
    }
    if(upvts[i] > upvts[m]){
        swap(upvts[i], upvts[m]);
    }
    swap(upvts[m], upvts[f]);
    return upvts[f];
}

int partquick(int upvts[], int c, int n,resultados *resultQ)
{
    int pivot = media_3(upvts,c,n);
    int count = 0;
    for (int i = c + 1; i <= n; i++) {
        if (upvts[i] <= pivot){
            count++;
            resultQ->addcomp();
        }
    }
    int pivotIndex = c + count;
    swap(upvts[pivotIndex], upvts[c]);
    resultQ->addmov();
    int i = c, j = n;
    resultQ->addcomp();
    while (i < pivotIndex && j > pivotIndex) {
        resultQ->addcomp();
        while(upvts[i] <= pivot) {
            i++;
        }
        resultQ->addcomp();
        while(upvts[j] > pivot) {
            resultQ->addcomp();
            j--;
        }
        resultQ->addcomp();
        if(i < pivotIndex && j > pivotIndex) {
            swap(upvts[i++], upvts[j--]);
            resultQ->addmov();
        }
    }
 
    return pivotIndex;
}
 
void QuickSort(int upvts[], int c, int n,resultados *resultQ)
{
    if (n-c>0){
    int p = partquick(upvts, c, n,resultQ);
    QuickSort(upvts, c, p - 1,resultQ);
    QuickSort(upvts, p + 1, n,resultQ);
    }
}

void StartQuicksort(int *upvts,int r, int m){
  resultados *resultQ = new resultados;
  resultQ->setresult(m+1);
  auto c = chrono::high_resolution_clock::now();
  QuickSort(upvts,0,r-1,resultQ);
  auto f = chrono::high_resolution_clock::now();
  auto total = chrono::duration_cast<chrono::milliseconds>(f-c);
  float tempo = total.count();
  resultQ->addtempo(tempo);
  resultQ->salvar();
  delete resultQ;
}



#endif