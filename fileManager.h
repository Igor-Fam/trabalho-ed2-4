#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>   
#include <string> 
#include <fstream>  
#include <ctime> 
#include <chrono>  
using namespace std;

extern string path;

struct Review
{
    char review_id[100];
    char review_text[2000];
    char upvotes[10];
    char app_version[10];
    char posted_date[25];
};

void acessaRegistro(int i);

Review* importReviews(int N);

void processamento();

#endif