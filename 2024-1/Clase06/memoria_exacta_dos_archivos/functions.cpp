/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Utils.hpp"
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
    int buffer_dates[20]{}, tweets_size = 0, date;
    char* buffer_tweets[20]{};
    ifstream input(filename, ios::in);
    while (true) {
        input>>date;
        if (input.eof())break;
        input.get(); //Para la coma
        buffer_dates[tweets_size] = date;
        buffer_tweets[tweets_size] = read_str(input);
        tweets_size++;
    }
    dates = new int[tweets_size + 1] {};
    tweets = new char*[tweets_size + 1] {};
    for (int i = 0; i < tweets_size; i++) {
        dates[i] = buffer_dates[i];
        tweets[i] = buffer_tweets[i];
    }
}

void add_hashtags(ifstream & input, char** hashtags ,int & n){
    char* hashtag;
    hashtag = read_str(input);
    hashtags[n] = hashtag;
    n++;
//    hashtags[n++] = read_str(input);
}

void cut(char **&hashtags, int n){
    char** hashtags_aux;
    if(n!=0){
        hashtags_aux = new char*[n+1]{};
        for(int i=0;i<n;i++)
            hashtags_aux[i] = hashtags[i];
        delete hashtags;
        hashtags = hashtags_aux;
    }
    else{
        delete hashtags;
        hashtags = nullptr;
    }
}

void read_hashtags(int *dates, char***&hashtags, const char* filename){
    ifstream input(filename,ios::in);
    int n_hashtags_row[20]{}, tweets_size = 0, date, pos;
    char aux[60];
    while(dates[tweets_size])tweets_size++;
    //Reserva de memoria de hashtags
    hashtags = new char**[tweets_size+1]{};
    for(int i = 0; i<tweets_size;i++)
        hashtags[i] = new char*[20];
    //Lectura
    while(true){
        input>>date;
        if(input.eof()) break;
        input.get();
        pos = lookup(date, dates);
        if (pos!=-1)
            add_hashtags(input, hashtags[pos],n_hashtags_row[pos]);
        else
            input.getline(aux, 60);
    }    
        
    //Recorte de memoria    
    for(int i=0; hashtags[i];i++)
        cut(hashtags[i],n_hashtags_row[i]);
    
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