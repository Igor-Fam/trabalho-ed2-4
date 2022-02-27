#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <string>
#include <fstream>

using namespace std;

class resultados{
    public:
        int movimentos;
        int comparacoes;
        float tempo;
        int tam;
        string tipo;

        resultados(){
            movimentos = 0, comparacoes = 0, tempo = 0;
        }
        
        void salvar(){
            ofstream saida;
            saida.open("saida.txt", fstream::app);
            saida << tipo << endl;
            saida << "N = " << tam << endl;
            saida << "Movimentos: " << movimentos << endl;
            saida << "Comparacoes: " << comparacoes << endl;
            saida << "Tempo em milissegundos: " << tempo << endl << endl;
            saida.close();
        }

        void setresult(int m){
            tam = m;
            movimentos=0;
            comparacoes=0;
            tempo=0;
        }

        void addmov(){
            movimentos=movimentos+1;
        }

        void addcomp(){
            comparacoes=comparacoes+1;
        }

        void addtempo(float t){
            tempo=t;
        }

        void addtipo(string tipe){
            tipo=tipe;
        }
};

#endif