/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
using namespace std;
char * read_str(ifstream &input, char c) {
    char *str, buffer[100];
    input.getline(buffer, 100, c);
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void * read_reg(ifstream &input) {
    void **registro;
    int *createdat, date;
    char* tweet;
    //Lectura
    input>>date;
    if (input.eof())return nullptr;
    input.get();
    tweet = read_str(input, '\n');
    createdat = new int;
    *createdat = date;
    //Reserva de memoria
    registro = new void*[4] {
    };
    //Asignacion
    registro[CREATEDAT] = createdat; //020202024 - INT* - INT
    registro[TWEET] = tweet; //hola q tal - CHAR*
    return registro;
}

void incrementar_memoria(void **&tweets, int &n, int &c) {
    void **aux_tweets;
    c += INCREMENTO;
    if (tweets == nullptr) {
        tweets = new void*[c] {
        };
        n = 1;
    } else {
        aux_tweets = new void*[c] {
        };
        for (int i = 0; i < n; i++)
            aux_tweets[i] = tweets[i];
        delete tweets;
        tweets = aux_tweets;
    }
}

void read_tweets(void *&t, int &tweet_size,  const char *filename) {
    ifstream input(filename, ios::in);
    void ** tweets, *reg;
    int cap = 0;
    tweets = nullptr;
    while (true) {
        reg = read_reg(input);
                if(reg == nullptr) break;
        if (input.eof()) break;
        if (cap == tweet_size) incrementar_memoria(tweets, tweet_size, cap);
        tweets[tweet_size - 1] = reg;
        tweet_size++;
    }
    t = tweets;
}

int cmp_int(const void *a, const void *b){
    int*ai = (int*)a;
    int*bi = (int*)b;
    cout<<*ai<<"   "<<*bi<<endl;
    return *ai-*bi;
}

int cmp_void_str(const void *a, const void *b){
    void**ai = (void**)a;
    void**bi = (void**)b;
    void**registro_a = (void**)(*ai);
    void**registro_b = (void**)(bi[0]);
    char*tweet_a,*tweet_b;
    tweet_a = (char*)registro_a[TWEET];
    tweet_b = (char*)registro_b[TWEET];
    cout<<tweet_a<<setw(50)<<tweet_b<<endl;
    return strcmp(tweet_a, tweet_b);
}

void display_tweet(ofstream & out, void *t) {
    void **registro = (void**) t;
    int* createdat;
    char* tweet;
    createdat = (int*) registro[CREATEDAT];
    tweet = (char*) registro[TWEET];
    out << left << setw(10) << *createdat;
    out << setw(100) << tweet << endl;
}

void display_tweets(void* t, const char*filename) {
    ofstream out(filename, ios::out);
    void** tweets = (void**) t;
    for (int i = 0; tweets[i]; i++)
        display_tweet(out, tweets[i]);
}