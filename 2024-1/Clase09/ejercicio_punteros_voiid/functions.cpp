/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
using namespace std;
char * read_str(ifstream &input){
    char *str, buffer[100];
    input.getline(buffer, 100, '\n');
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

void * read_reg(ifstream &input){
    void **registro;
    int *createdat,date;
    char* tweet;
    //Lectura
    input>>date;
    if(input.eof())return nullptr;
    input.get();
    tweet = read_str(input);
    createdat = new int;
    *createdat = date;
    //Reserva de memoria
    registro = new void*[2]{};
    //Asignacion
    registro[CREATEDAT] = createdat;//020202024 - INT* - INT
    registro[TWEET] = tweet;//hola q tal - CHAR*
    return registro;
}

void incrementar_memoria(void **&tweets, int &n, int &c){
    void **aux_tweets;
    c += INCREMENTO;
    if(tweets == nullptr){
        tweets = new void*[c]{};
        n = 1;
    }
    else{
        aux_tweets = new void*[c]{};
        for(int i=0; i<n; i++)
            aux_tweets[i] = tweets[i];
        delete tweets;
        tweets = aux_tweets;
    }
}

void load_tweets(void *&t, const char *filename){
    ifstream input(filename, ios::in);
    void ** tweets, *reg;
    int tweet_size = 0, cap = 0;
    tweets = nullptr;
    while(true){
        reg = read_reg(input);
//        if(reg == nullptr) break;
        if(input.eof()) break;
        if(cap == tweet_size) incrementar_memoria(tweets,tweet_size, cap);
        tweets[tweet_size - 1] = reg;
        tweet_size++;
    }
    t = tweets;
}

void load_hashtags(void *&t, const char *filename){
    ifstream input(filename, ios::in);
    void **tweets = (void**)t;
}
