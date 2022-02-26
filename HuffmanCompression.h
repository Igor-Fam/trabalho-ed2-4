#include <string>
#include <vector>
#include <random>

#include "HuffmanTree.h"
#include "fileManager.h"

char binario_decimal(string binario);

//funcao para construir a arvore e definir os codigos utilizados para comprimir a mensagem
HuffmanTree* buildtree(string text);

//constroi o texto baseado em um numero N de reviews_texts aleatorios
string buildtext(int N);

string convert(string text);

char binario_decimal(string binario);


string decimal_binario(int decimal);

//comprime um texto (N registros) baseado no codigo gerado
HuffmanTree* comprimir(int N);

//descomprime o texto do arquivo "reviewsComp.bin" baseado na arvore gerada
float* descomprimir(HuffmanTree *a);

//realiza as compressoes e descompressoes M=3 vezes e salva a taxa de comparacao
float auxanalise(int N);

//realiza as analises para os valores pre-determinados
void analise();

void compressionInterface();