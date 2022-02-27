#include "QuickSort.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include "fileManager.h"

void analiseQuickSort(){
    int n[3] = {10000, 50000, 100000};
    int i,j,k;
    int *arr;
    for(i=0; i<3; i++){
        Review *regs = new Review[n[i]];
        for(j=0; j<3; j++){
            regs = importReviews(n[i]);
            arr = new int[n[i]];
            for(k=0;k<n[i];k++){
                arr[k] = stoi(regs[k].upvotes);
            }
            StartQuicksort(arr,n[i]);
        }
        delete [] regs;
    }
}

void analiseHeapSort(){
    int n[3] = {10000, 50000, 100000};
    int i,j,k;
    int *arr;
    for(i=0; i<3; i++){
        Review *regs = new Review[n[i]];
        for(j=0; j<3; j++){
            regs = importReviews(n[i]);
            arr = new int[n[i]];
            for(k=0;k<n[i];k++){
                arr[k] = stoi(regs[k].upvotes);
            }
            StartHeapsort(arr,n[i]);
            delete [] arr;
        }
        delete [] regs;
    }
}

void analiseShellSort(){
    int n[3] = {10000, 50000, 100000};
    int i,j;
    for(i=0;i<3;i++){
        Review *regs = new Review[n[i]];
        for(j=0;j<3;j++){
            regs = importReviews(n[i]);
            shellSort(regs, n[i]);
        }
        delete [] regs;
    }
}