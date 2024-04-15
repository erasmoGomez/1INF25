/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define INCREMENTO 5
#include "functions.hpp"
using namespace std;
int lookup(int date, int *dates){
    for(int i=0; dates[i];i++)
        if(dates[i] == date) return i;
    return -1;
}

char *read_str(ifstream &in) {
    char* str;
    char buffer[100];
    in.getline(buffer, 100);
    str = new char[strlen(buffer) + 1] {};
    strcpy(str, buffer);
    return str;
}

void read_tweets(int *&dates, char**&tweets, const char *filename) {
    int tweet_size = 0, capacity = 0, date;
    char* tweet;
    ifstream input(filename, ios::in);
    dates = nullptr;
    tweets = nullptr;
    while(true){
        input>>date;
        if(input.eof()) break;
        input.get(); // la coma
        tweet = read_str(input);
        // agregar memoria x incrementos
        if(capacity == tweet_size)
            reserva_memoria_incrementos(dates, tweets,tweet_size, capacity);
        dates[tweet_size-1] = date;
        tweets[tweet_size-1] = tweet;
        tweet_size++;
    }
    
}

void reserva_memoria_incrementos(int *&dates,char**&tweets,int &tweets_size,int &capacity){
    int* aux_dates;
    char** aux_tweets;
    capacity += INCREMENTO;
    if(dates == nullptr){
        dates = new int[capacity]{}; // No olvidar
        tweets = new char*[capacity]{}; //No olvidar
        tweets_size = 1;
    }
    else{
        aux_dates = new int[capacity]{}; // No olvidar // tiene 10 espacios
        aux_tweets = new char*[capacity]{}; //No olvidar // tiene 10 espacios
        for(int i=0; i<tweets_size;i++){
            aux_dates[i] = dates[i]; // tienen 5 espacios
            aux_tweets[i] = tweets[i]; // tienen 5 espacios
        }
        delete dates;
        delete tweets;
        dates = aux_dates;
        tweets = aux_tweets;
    }
}

void reserva_memoria_incrementos(char**&hashtags,int &n,int &capacity){
    char** aux_hashtags;
    capacity += INCREMENTO;
    if(hashtags == nullptr){
        hashtags = new char*[capacity]{}; //No olvidar
        n = 1;
    }
    else{
        aux_hashtags = new char*[capacity]{}; //No olvidar // tiene 10 espacios
        for(int i=0; i<n;i++){
            aux_hashtags[i] = hashtags[i]; // tienen 5 espacios
        }
        delete hashtags;
        hashtags = aux_hashtags;
    }
}

void add_hashtags(ifstream & input, char**&hashtags ,int & n, int & c){
    char* hashtag;
    hashtag = read_str(input);
    if(n == c)
        reserva_memoria_incrementos(hashtags, n, c);
    hashtags[n -1] = hashtag;
    n++;
}

void read_hashtags(int *dates, char***&hashtags, const char* filename){
    int pos, tweets_size = 0, n_hashtags_row[20]{}, capacity_row[20]{}, date;
    while(dates[tweets_size])tweets_size++;
    hashtags = new char**[tweets_size +1]{}; //Reserva de memoria vertical
    ifstream input(filename, ios::in);
    while(true){
        input>>date;
        if(input.eof()) break;
        input.get(); // Para la coma
        pos = lookup(date, dates);
        if (pos!=-1)
            add_hashtags(input, hashtags[pos], n_hashtags_row[pos], capacity_row[pos]);
        else
            while(input.get()!='\n');
    }
}

void display_hashtags(char** hashtags, ofstream &out){
    for(int i=0;hashtags[i];i++)
        out<<right<<setw(20)<<hashtags[i]<<endl;
}

void display_tweets(int *dates, char**tweets, char***hashtags, const char *filename){
    ofstream out(filename,ios::out);
    for(int i=0; dates[i] ;i++){
        out<<left<<setw(10)<<dates[i]<<tweets[i]<<endl;
        if(hashtags[i])
            display_hashtags(hashtags[i], out);
        else
            out<<"No tiene hashtags"<<endl;
    }
}

void sort_tweets(int* dates, char**tweets, char***hashtags){
    int n = 0;
    while(dates[n]) n++;
    quick_sort(dates, tweets, hashtags,0 /*Indice izquierdo*/, n-1 /*indice derecho*/);
    
}

void quick_sort(int*dates, char**tweets, char***hashtags, int izq, int der){
    int limit, pivot;
    if(izq >= der) return;
    pivot = (izq + der)/2;
    swap2(dates[izq], dates[pivot], tweets[izq],tweets[pivot],hashtags[izq],hashtags[pivot]);
    limit = izq;
    for(int i=izq+1; i<=der; i++){
        if(strcmp(tweets[i], tweets[izq])<0){ //Alfabeticamente tweets
            limit++;
            swap2(dates[limit], dates[i], tweets[limit],tweets[i],hashtags[limit],hashtags[i]);
        }
    }
    swap2(dates[limit], dates[izq], tweets[limit],tweets[izq],hashtags[limit],hashtags[izq]);
    quick_sort(dates, tweets, hashtags, izq, limit - 1);
    quick_sort(dates, tweets, hashtags, limit + 1, der);
}

void swap2(int &date1, int &date2,char *&tweet1, char*&tweet2, char**&hashtags1, char**&hashtags2){
    int aux_date;
    char *aux_tweet;
    char **aux_hashtags;
    
    aux_date = date1;
    date1 = date2;
    date2 = aux_date;
    
    aux_tweet = tweet1;
    tweet1 = tweet2;
    tweet2 = aux_tweet;
    
    aux_hashtags = hashtags1;
    hashtags1 = hashtags2;
    hashtags2 = aux_hashtags;
}    