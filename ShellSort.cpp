#include <iostream>
#include <chrono>
#include "resultados.h"
#include "fileManager.h"

using namespace std;
using namespace std::chrono;
  
void shellSort(Review* arr, int N)
{
    auto c = high_resolution_clock::now();
    resultados r;
    for (int gap = N/2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i += 1) {
            Review temp = arr[i];
            int j;
            for (j = i; j >= gap && atoi(arr[j - gap].upvotes) > atoi(temp.upvotes); j -= gap){
                r.movimentos++;
                arr[j] = arr[j - gap];
                r.comparacoes ++;
            }
            arr[j] = temp;
            r.comparacoes ++;
        }
    }
    auto f = high_resolution_clock::now();
    auto total = duration_cast<milliseconds>(f-c);
    float tempo = total.count();
    r.tempo = tempo;
    r.tipo = "ShellSort";
    r.salvar();
    return;
}