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
        int id;
        string tipo;
        resultados(){movimentos = 0, comparacoes = 0, tempo = 0, id = 0;}
        void salvar(){
            ofstream saida;
            saida.open("saida.txt", fstream::app);
            saida << tipo << endl;
            saida << "Movimentos: " << movimentos << endl;
            saida << "Comparacoes: " << comparacoes << endl;
            saida << "Tempo em milissegundos: " << tempo << endl << endl;
            saida.close();
        }
};

#endif