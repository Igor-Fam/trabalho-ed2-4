#include "BalancedStructures.h"
#include "BTree.h"
#include "BNode.h"
#include "VPTree.h"
#include "VPNode.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

void BTreeSearchId(string id, int m) {
    BTree t(m);

    //importar N = 1000000 registros
    cout << "Importando 1000000 registros do arquivo binario..." << endl;
    ReviewNode* regs = new ReviewNode[1000000];
    regs = ReviewNode::importNodes(1000000);
    cout << "1000000 registros importados com sucesso." << endl;
    //inserir N = 1000000 registros
    cout << "Inserindo 1000000 registros na arvore B..." << endl;
    for (int i = 0; i < 1000000; i++) {
        t.insert(regs[i]);
    }
    cout << "1000000 registros inseridos." << endl;
    cout << "Buscando registro..." << endl;
    ReviewNode* k = new ReviewNode(-1, id);
    BNode* r = new BNode;
    r = t.search(*k);
    if (r == NULL) {
        cout << "Id nao encontrado!" << endl;
    }
    else {
        r->getRegistry(id);
    }
    delete k;
    delete r;
    
}

void VPTreeSearchId(string id){
    cout << "Importando 1000000 registros do arquivo binario..." << endl;
    ReviewNode* regs = new ReviewNode[1000000];
    regs = ReviewNode::importNodes(1000000);
    cout << "1000000 registros importados com sucesso." << endl;
    cout << "Inserindo 1000000 registros na arvore VP..." << endl;
    VPTree arvre;
    for (int i = 0; i < 1000000; i++) {
        arvre.insert(&regs[i]);
    }
    cout << "1000000 registros inseridos." << endl;
    cout << "Buscando registro..." << endl;
    VPNode* r = new VPNode;
    r=arvre.search(id);
    if(r == NULL){
        cout << "Id nao encontrado!" << endl;
    }else{
        cout << "Id encontrado!" << endl;
        r->node->getReview();
    }
}

void BTreePerformanceTest(int m) {
    int insertionComparisons[3];
    int searchComparisons[3];
    int insertionTimes[3];
    int searchTimes[3];
    for (int M = 0; M < 3; M++) {
        BTree t(m);
        BNode::comparisons = 0;

        //importar N = 1000000 registros
        cout << "Importando 1000000 registros do arquivo binario..." << endl;
        ReviewNode* regs = new ReviewNode[1000000];
        regs = ReviewNode::importNodes(1000000);
        cout << "1000000 registros importados com sucesso." << endl;

        //inserir N = 1000000 registros
        auto insertionStart = high_resolution_clock::now();

        cout << "Inserindo 1000000 registros na arvore B..." << endl;
        for (int i = 0; i < 1000000; i++) {
            //cout << i << endl;
            t.insert(regs[i]);
        }
        cout << "1000000 registros inseridos." << endl;
        
        auto insertionStop = high_resolution_clock::now();
        auto insertionDuration = duration_cast<milliseconds>(insertionStop - insertionStart);
        insertionTimes[M] = insertionDuration.count();

        cout << "Comparacoes nas insercoes: " << BNode::comparisons << endl;
        insertionComparisons[M] = BNode::comparisons;
        BNode::comparisons = 0;

        //Importar B = 100 registros

        cout << "Importando 100 registros do arquivo binario..." << endl;
        regs = new ReviewNode[100];
        regs = ReviewNode::importNodes(100);
        cout << "100 registros importados com sucesso." << endl;

        //Buscar B = 100 registros
        auto searchStart = high_resolution_clock::now();

        cout << "Buscando 100 registros" << endl;
        for (int i = 0; i < 100; i++) {
            t.search(regs[i]);
        }

        auto searchStop = high_resolution_clock::now();
        auto searchDuration = duration_cast<microseconds>(searchStop - searchStart);
        searchTimes[M] = searchDuration.count();

        cout << "Comparacoes nas buscas: " << BNode::comparisons << endl;
        searchComparisons[M] = BNode::comparisons;
        BNode::comparisons = 0;

    }
    float avgInsertionComparisons = (insertionComparisons[0] + insertionComparisons[1] + insertionComparisons[2]) / 3;
    float avgSearchComparisons = (searchComparisons[0] + searchComparisons[1] + searchComparisons[2]) / 3;
    float avgInsertionTimes = (insertionTimes[0] + insertionTimes[1] + insertionTimes[2]) / 3;
    float avgSearchTimes = (searchTimes[0] + searchTimes[1] + searchTimes[2]) / 3;
    
    ofstream file("saida.txt", std::ios::app);
    file << endl << "//// Arvore B de ordem " << m << ": " << endl;
    file << "* 1a execução : " << endl;
    file << "  -Inserção: " << insertionComparisons[0] << " comparações; " << insertionTimes[0] << "ms." << endl;
    file << "  -Busca: " << searchComparisons[0] << " comparações; " << searchTimes[0] << "μs." << endl << endl;

    file << "* 2a execução : " << endl;
    file << "  -Inserção: " << insertionComparisons[1] << " comparações; " << insertionTimes[1] << "ms." << endl;
    file << "  -Busca: " << searchComparisons[1] << " comparações; " << searchTimes[1] << "μs." << endl << endl;
    
    file << "* 3a execução : " << endl;
    file << "  -Inserção: " << insertionComparisons[2] << " comparações; " << insertionTimes[2] << "ms." << endl;
    file << "  -Busca: " << searchComparisons[2] << " comparações; " << searchTimes[2] << "μs." << endl << endl;
    
    file << "* Média : " << endl;
    file << "  -Inserção: " << avgInsertionComparisons << " comparações; " << avgInsertionTimes << "ms." << endl;
    file << "  -Busca: " << avgSearchComparisons << " comparações; " << avgSearchTimes << "μs." << endl << endl;

    file.close();
}

void VPTreePerformanceTest(){
    int insertionComparisons[3];
    int searchComparisons[3];
    int insertionTimes[3];
    int searchTimes[3];
    for (int M = 0; M < 3; M++) {
        VPTree arvre;
        VPNode::comparisons = 0;

        cout << "Importando 1000000 registros do arquivo binario..." << endl;
        ReviewNode* regs = new ReviewNode[1000000];
        regs = ReviewNode::importNodes(1000000);
        cout << "1000000 registros importados com sucesso." << endl;

        //inserir N = 1000000 registros
        auto insertionStart = high_resolution_clock::now();

        cout << "Inserindo 1000000 registros na arvore VP..." << endl;
        for (int i = 0; i < 1000000; i++) {
            arvre.insert(&regs[i]);
        }
        cout << "1000000 registros inseridos." << endl;
        
        auto insertionStop = high_resolution_clock::now();
        auto insertionDuration = duration_cast<milliseconds>(insertionStop - insertionStart);
        insertionTimes[M] = insertionDuration.count();

        cout << "Comparacoes nas insercoes: " << VPNode::comparisons << endl;
        insertionComparisons[M] = VPNode::comparisons;
        VPNode::comparisons = 0;
        cout << "Importando 100 registros do arquivo binario..." << endl;
        regs = new ReviewNode[100];
        regs = ReviewNode::importNodes(100);
        cout << "100 registros importados com sucesso." << endl;
        auto searchStart = high_resolution_clock::now();

        cout << "Buscando 100 registros" << endl;
        for (int i = 0; i < 100; i++) {
            arvre.search(regs[i].getId());
        }

        auto searchStop = high_resolution_clock::now();
        auto searchDuration = duration_cast<microseconds>(searchStop - searchStart);
        searchTimes[M] = searchDuration.count();

        cout << "Comparacoes nas buscas: " << VPNode::comparisons << endl;
        searchComparisons[M] = VPNode::comparisons;
        VPNode::comparisons = 0;

    }
    float avgInsertionComparisons = (insertionComparisons[0] + insertionComparisons[1] + insertionComparisons[2]) / 3;
    float avgSearchComparisons = (searchComparisons[0] + searchComparisons[1] + searchComparisons[2]) / 3;
    float avgInsertionTimes = (insertionTimes[0] + insertionTimes[1] + insertionTimes[2]) / 3;
    float avgSearchTimes = (searchTimes[0] + searchTimes[1] + searchTimes[2]) / 3;
    
    ofstream file("saida.txt", std::ios::app);
    file << endl << "//// Arvore Vermelho-Preto : " << endl;
    file << "* 1a execução : " << endl;
    file << "  -Inserção: " << insertionComparisons[0] << " comparações; " << insertionTimes[0] << "ms." << endl;
    file << "  -Busca: " << searchComparisons[0] << " comparações; " << searchTimes[0] << "μs." << endl << endl;

    file << "* 2a execução : " << endl;
    file << "  -Inserção: " << insertionComparisons[1] << " comparações; " << insertionTimes[1] << "ms." << endl;
    file << "  -Busca: " << searchComparisons[1] << " comparações; " << searchTimes[1] << "μs." << endl << endl;
    
    file << "* 3a execução : " << endl;
    file << "  -Inserção: " << insertionComparisons[2] << " comparações; " << insertionTimes[2] << "ms." << endl;
    file << "  -Busca: " << searchComparisons[2] << " comparações; " << searchTimes[2] << "μs." << endl << endl;
    
    file << "* Média : " << endl;
    file << "  -Inserção: " << avgInsertionComparisons << " comparações; " << avgInsertionTimes << "ms." << endl;
    file << "  -Busca: " << avgSearchComparisons << " comparações; " << avgSearchTimes << "μs." << endl << endl;

    file.close();
}

void BalancedStructuresInterface(){
    int aux0=0;
    int aux1;
    int aux2;
    string id;

    while (aux0 != 3)
    {
        cout << endl << "Qual etapa voce deseja que seja executada:" << endl;
        cout << "1-Arvore Vermelho e Preto" << endl;
        cout << "2-Arvore B" << endl;
        cout << "3-Sair" << endl;
        cin >> aux0;

        if(aux0 == 1)
        {
            cout << "Voce escolheu arvore Vermelho e Preto." << endl << "Digite 1 para modulo de analise" << endl << "Digite 2 para modulo teste" << endl;
            cin >> aux1;
            if(aux1 == 1)
            {
                cout << "Voce escolheu modulo de analise."<< endl;
                VPTreePerformanceTest();
            }
            else if(aux1 == 2)
            {
                cout << "Voce escolheu modulo de teste." << endl;
                cout << "Insira um id para busca:" << endl;
                cin >> id;
                VPTreeSearchId(id);
            }
            else
            {
                cout << "Nao foi inserido um valor valido" << endl;
            }
        }
        else if(aux0 ==2 )
        {
            cout << "Voce escolheu arvore B." << endl << "Digite 1 para modulo de analise" << endl << "Digite 2 para modulo teste" << endl;
            cin >> aux1;
            if(aux1 == 1)
            {
                cout << "Voce escolheu modulo de analise."<< endl << "Voce pode escolher dois parametros: 20 ou 200. Qual desejas?" << endl;
                cin >> aux2;
                if(aux2==20 || aux2==200)
                {
                    BTreePerformanceTest(aux2);
                }
                else
                {
                    cout << "Nao foi inserido um valor valido" << endl;
                }

            }
            else
            if(aux1 == 2)
            {
                cout << "Voce escolheu modulo de teste." << endl;
                cout << "Insira um id para busca" << endl;
                cin >> id;
                BTreeSearchId(id, 200);
            }
            else
            {
                cout << "Nao foi inserido um valor valido" << endl;
            }

        }
        else if(aux0 == 3)
        {
            cout << "Voce escolheu sair." << endl;
        }
        else
        {
            cout << "Voce digitou um valor invalido, tente novamente" << endl;
        }
    }
}