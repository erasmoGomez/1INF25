/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
using namespace std;
char * read_str(ifstream &input, char c){
    char *str, buffer[100];
    input.getline(buffer, 100, c);
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
    tweet = read_str(input, '\n');
    createdat = new int;
    *createdat = date;
    //Reserva de memoria
    registro = new void*[4]{};
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

bool is_equal(int createdat, void *t){ //Registro
    void **registro = (void**)t;
    int *ptr_createdat;
    ptr_createdat = (int*)registro[CREATEDAT];
    return createdat == *ptr_createdat;
}

int lookup(int createdat, void **tweets){
    for(int i=0; tweets[i]; i++)
        if(is_equal(createdat,tweets[i]) ) return i;
    return -1;
}

void load_hashtags(void *&t, const char *filename){
    ifstream input(filename, ios::in);
    void **tweets = (void**)t;
    int date, index, n[50]{}, cap[50]{};
    while(true){
        input>>date;
        if(input.eof())break;
        input.get();
        index = lookup(date, tweets);
        if(index!=-1)
            add_hashtag(input, tweets[index], n[index], cap[index]);
        else
            while(input.get()!='\n');
    }
}

void add_hashtag(ifstream &input, void* t, int &n, int&c){
    void ** registro = (void**)t;
    void *hashtag;
    hashtag = read_hashtag(input);
    if(n == c)
        incrementar_memoria_hashtags(registro[HASHTAGS], n, c);
    insert_hashtag(hashtag,registro[HASHTAGS],n);
    n++;
}

void *read_hashtag(ifstream &input){
    char* hashtag;
    int* followers;
    void **registro;
    hashtag = read_str(input, ',');
    followers = new int;
    input>>*followers;
    registro = new void*[2];
    registro[HASHTAG] = hashtag;
    registro[FOLLOWERS] = followers;
    return registro;
}

void incrementar_memoria_hashtags(void *&h,int& n, int& c){
    void **hashtags = (void**)h;
    void **aux_hashtags;
    c+=INCREMENTO;
    if(hashtags == nullptr){
        hashtags = new void*[c]{};
        n=1;
    }
    else{
        aux_hashtags = new void*[c]{};
        for(int i = 0; i<n; i++)
            aux_hashtags[i] = hashtags[i];
        delete hashtags;
        hashtags = aux_hashtags;
    }
    h = hashtags;
}

void insert_hashtag(void *hashtag,void *h,int n){
    void**hashtags = (void**)h;
    hashtags[n - 1] = hashtag;
}

void display_hashtag(ofstream &out, void* h){
    void **registro = (void**)h;
    char* hashtag = (char*)registro[HASHTAG];
    int* followers = (int*)registro[FOLLOWERS];
    out<<right<<setw(40)<<hashtag<<setw(10)<<*followers<<endl;
}

void display_hashtags(ofstream& out, void*h){
    void** hashtags = (void**)h;
    for(int i=0;hashtags[i]; i++)
        display_hashtag(out, hashtags[i]);
}

void display_tweet(ofstream & out, void *t){
    void **registro = (void**)t;
    int* createdat;
    char* tweet;
    createdat = (int*)registro[CREATEDAT];
    tweet = (char*)registro[TWEET];
    out<<left<<setw(10)<<*createdat;
    out<<setw(100)<<tweet<<endl;
    if(registro[HASHTAGS])
        display_hashtags(out, registro[HASHTAGS]);
    display_stats(registro[TOTAL]);
}

void display_tweets(void* t){
    ofstream out("reporte.txt", ios::out);
    void** tweets = (void**)t;
    for(int i = 0; tweets[i]; i++)
        display_tweet(out,tweets[i]);
}

int get_followers(void *h){
    void**registro = (void**)h;
    int * followers = (int*)registro[FOLLOWERS];
    return *followers;
}

void *avg(void*h){
    void ** hashtags = (void**)h;
    int sum = 0, n = 0;
    double* average = new double;
    for(int i=0; hashtags[i]; i++){
        sum+=get_followers(hashtags[i]);
        n++;
    }
    *average = (double)sum/n;
    return average;
}

void calc_avg(void *t){
    void ** registro = (void**)t;
    if(registro[HASHTAGS])
        registro[TOTAL] = avg(registro[HASHTAGS]);
}

void calc_stats(void* t){
    void** tweets = (void**)t;
    for(int i = 0; tweets[i];i++)
        calc_avg(tweets[i]);
}

void display_stats(void *avg){
    double * average = (double*)avg;
    cout.precision(2);
    cout<<fixed;
    cout<<"AVG: "<<setw(10)<<*average<<endl;
}