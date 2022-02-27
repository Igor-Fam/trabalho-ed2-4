#include <iostream>   
#include <string> 
#include <cstring>
#include <fstream>  
#include <ctime> 
#include <chrono>  
#include "fileManager.h"
using namespace std;

#pragma warning(disable : 4996)

void acessaRegistro(int i) {
    cout << i << ". " << endl;
    Review* reg = new Review;
    ifstream file;
    file.open("tiktok_app_reviews.bin", ios::binary);
    file.seekg(0, ios::end);
    if (file) {
        file.seekg(i * sizeof(Review), ios::beg);
        file.read(reinterpret_cast<char*>(reg), sizeof(Review));
        cout << "id: ";
        cout << reg->review_id << endl;
        cout << "text: ";
        cout << reg->review_text << endl;
        cout << "upvotes: ";
        cout << reg->upvotes << endl;
        cout << "app version: ";
        cout << reg->app_version << endl;
        cout << "date: ";
        cout << reg->posted_date << endl;
        file.close();
    }
}

Review* importReviews(int N) {
    ifstream file;
    file.open("tiktok_app_reviews.bin");

    //encontra o numero de registros
    file.seekg(0, ios::end);
    int max = (file.tellg() / sizeof(Review)) - 1;
    // aloca um numero N de ponteiros de Review para os registros
    Review* regs = new Review[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        // registros aleatorios
        int random = (rand() % (max - 1));
        int cursor = random * sizeof(Review);
        file.seekg(cursor, ios::beg);
        file.read(reinterpret_cast<char*>(&regs[i]), sizeof(Review));
        //cout << " (" << file.tellg() << ") " << regs[i].review_text << endl;
        if((int)file.tellg() == -1){
            file.close();
            file.open("tiktok_app_reviews.bin");
        }
    }
    file.close();
    return regs;
}

void processamento()
{
    cout << "Lendo registros. Por favor, aguarde." << endl;
    path += "/tiktok_app_reviews.csv";
    cout << "a: " << path;
    std::ifstream ip(path, std::ifstream::binary);
    fstream op;
    op.open("tiktok_app_reviews.bin", ios::out | ios::binary);
    string aux;
    int cont = 0;
    ip.seekg(0, ip.end);
    int length = ip.tellg();
    ip.seekg(0, ip.beg);
    getline(ip, aux);
    while ((int)(ip.tellg()) != -1 && !ip.eof()) {
        //id
        Review* reg = new Review;
        string* id = new string;
        getline(ip, *id, ',');
        int i;
        for (i = 0; i < (int)id->length(); i++) {
            reg->review_id[i] = (*id)[i];
        }
        reg->review_id[i] = '\0';
        delete id;

        //text
        char c;
        ip >> c;
        if (c == '"') {
            char text[2000];
            for (i = 0; i < sizeof(reg->review_text); i++) {
                ip >> noskipws >> text[i];
                if (text[i] == '"') {
                    i++;
                    ip >> noskipws >> text[i];
                    if (text[i] == ',') {
                        text[i - 1] = '\0';
                        break;
                    }
                }
            }
            if (i == sizeof(reg->review_text)) {
                text[i - 1] = '\0';
                char* ch = new char;
                while (true) {
                    ip >> noskipws >> *ch;
                    if (*ch == '"') {
                        ip >> noskipws >> *ch;
                        if (*ch == ',')
                            break;
                    }
                }
                delete ch;
            }
            for (i = 0; i < sizeof(reg->review_text) && i < sizeof(text); i++) {
                reg->review_text[i] = text[i];
            }
        }
        else {
            string* text = new string;
            ip.seekg((int)ip.tellg() - 1);
            getline(ip, *text, ',');
            (*text)[(*text).length()] = '\0';
            for (i = 0; i < sizeof(reg->review_text) && i < (*text).length(); i++) {
                reg->review_text[i] = (*text)[i];
            }
            reg->review_text[i] = '\0';
            delete text;
        }

        //upvotes
        string* upvotes = new string;
        getline(ip, *upvotes, ',');
        for (i = 0; i < (int)(*upvotes).length(); i++) {
            reg->upvotes[i] = (*upvotes)[i];
        }
        reg->upvotes[i] = '\0';
        delete upvotes;

        //version
        string* version = new string;
        getline(ip, *version, ',');
        for (i = 0; i < (int)(*version).length(); i++) {
            reg->app_version[i] = (*version)[i];
        }
        reg->app_version[i] = '\0';
        delete version;

        //date
        char t[20];
        ip.read(t, 19);
        t[19] = '\0';
        for (i = 0; i < 20; i++) {
            reg->posted_date[i] = t[i];
        }
        string* s = new string;
        getline(ip, *s);
        delete s;

        //escrever no arquivo binário
        if (op.is_open())
        {
            if (((int)ip.tellg() == -1) || ip.eof())
                return;
            if (ip.tellg() <= length) {
                op.write(reinterpret_cast<char*>(reg), sizeof(Review));
                cont++;
            }
            else {
                break;
            }

        }
        else {
            cout << "Erro" << endl;
            exit(1);
        }
        delete reg;
    }
    op.close();
    cout << "Registros exportados para tiktok_app_reviews.bin" << endl;
    return;
}


