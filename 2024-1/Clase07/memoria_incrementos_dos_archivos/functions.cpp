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
    //quick_sort()
}