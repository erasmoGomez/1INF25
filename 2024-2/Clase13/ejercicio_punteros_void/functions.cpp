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
    int *createdat, date, *cantidad;
    char* tweet;
    //Lectura
    input>>date;
    if (input.eof())return nullptr;
    input.get();
    tweet = read_str(input, '\n');
    createdat = new int;
    *createdat = date;
    cantidad = new int;
    *cantidad = 0; //Esto para llevar la cantidad de hashtags
    //Reserva de memoria
    registro = new void*[5] {};
    //Asignacion
    registro[CREATEDAT] = createdat; //020202024 - INT* - INT
    registro[TWEET] = tweet; //hola q tal - CHAR*
    registro[HASHTAG_SIZE] = cantidad;
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

void load_tweets(void *&t, const char *filename) {
    ifstream input(filename, ios::in);
    void **tweets, *tweet;
    void *buffer_tweets[20]{};
    int tweets_size = 0;
    //20230401,Just saw the most beautiful sunset today!
    while (true) {
        tweet = read_reg(input);
        if (input.eof())break;
        buffer_tweets[tweets_size] = tweet;
        tweets_size++;
    }
    //cout<<tweets_size<<endl;
    tweets = new void*[tweets_size+1]{};
    for(int i = 0; i < tweets_size; i++)
        tweets[i] = buffer_tweets[i];
    t = tweets;
}

bool is_equal(int createdat, void *t) { //Registro
    void **registro = (void**) t;
    int *ptr_createdat;
    ptr_createdat = (int*) registro[CREATEDAT];
    return createdat == *ptr_createdat; //Comparo la fecha que viene como parametro
                                        //Vs la fechar de referenciada en el puntero
}

int lookup(int createdat, void **tweets) {
    for (int i = 0; tweets[i]; i++)
        if (is_equal(createdat, tweets[i])) return i;
    return -1;
}

void load_hashtags(void *&t, const char *filename) {
    ifstream input(filename, ios::in);
    void **tweets = (void**) t; //aterrizada
    int date, index, n[50]{}, cap[50]{};
    //20230404,#travelphotography,3835
    //Como se me pide hacer una busqueda, primero debo leer el elemento a buscar
    while (true) {
        input>>date;
        if (input.eof())break;
        input.get(); //Lee coma
        index = lookup(date, tweets);
        if (index != -1) //Lo he encontrado
            add_hashtag(input, tweets[index], n[index], cap[index]);
        else //No lo he encontrado
            while (input.get() != '\n');
    }
}

void * incrementar_contador_void(void* contador){
    int* ptr_contador = (int*)contador;
    (*ptr_contador)++; // Primero dereferenciarlo y luego incrementarlo
    return ptr_contador;
}

void add_hashtag(ifstream &input, void* t, int &n, int&c) {
    void ** registro = (void**) t;
    void *hashtag;
    hashtag = read_hashtag(input);
    if (n == c)
        incrementar_memoria_hashtags(registro[HASHTAGS], n, c);
    insert_hashtag(hashtag, registro[HASHTAGS], n);
    registro[HASHTAG_SIZE] = incrementar_contador_void(registro[HASHTAG_SIZE]);
    n++;
}

void *read_hashtag(ifstream &input) {
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

void incrementar_memoria_hashtags(void *&h, int& n, int& c) {
    void **hashtags = (void**) h;
    void **aux_hashtags;
    c += INCREMENTO;
    if (hashtags == nullptr) {
        hashtags = new void*[c] {};
        n = 1;
    } else {
        aux_hashtags = new void*[c] {};
        for (int i = 0; i < n; i++)
            aux_hashtags[i] = hashtags[i];
        delete hashtags;
        hashtags = aux_hashtags;
    }
    h = hashtags;
}

void insert_hashtag(void *hashtag, void *h, int n) {
    void**hashtags = (void**) h;
    hashtags[n - 1] = hashtag;
}

void display_hashtag(ofstream &out, void* h) {
    void **registro = (void**) h;
    char* hashtag = (char*) registro[HASHTAG];
    int* followers = (int*) registro[FOLLOWERS];
    out << right << setw(40) << hashtag << setw(10) << *followers << endl;
}

void display_hashtags(ofstream& out, void*h) {
    void** hashtags = (void**) h;
    for (int i = 0; hashtags[i]; i++)
        display_hashtag(out, hashtags[i]);
}

void display_stats(ofstream &out, void*total) {
    int*sum = (int*) total;
    out << endl << "La cantidad total de followeres es: " << setw(6) << *sum << endl << endl;
}

void display_tweet(ofstream & out, void *t) {
    void **registro = (void**) t;
    int* createdat;
    char* tweet;
    int* cantidad;
    createdat = (int*) registro[CREATEDAT];
    tweet = (char*) registro[TWEET];
    cantidad = (int*) registro[HASHTAG_SIZE];
    out << left << setw(10) << *createdat;
    out << setw(100) << tweet;
    out << setw(10) << *cantidad << endl;
    if (registro[HASHTAGS]) {
        display_hashtags(out, registro[HASHTAGS]);
        if (registro[TOTAL])
            display_stats(out, registro[TOTAL]);
    }
}

void display_tweets(void* t, const char*filename) {
    ofstream out(filename, ios::out);
    void** tweets = (void**) t;
    for (int i = 0; tweets[i]; i++){
        display_tweet(out, tweets[i]);
    }
}

int get_followers(void *h) {
    void**registro = (void**) h;
    int *followers = (int*) registro[FOLLOWERS];
    return *followers;
}

void *avg(void*h) {
    void **hashtags = (void**) h;
    int n = 0, sum = 0;
    double *average = new double;
    for (int i = 0; hashtags[i]; i++) {
        sum += get_followers(hashtags[i]);
        n++;
    }
    *average = (double) sum / n;
    return average;
}

void *suma(void*h) {
    void **hashtags = (void**) h;
    int n = 0, sum = 0;
    int *suma = new int;
    for (int i = 0; hashtags[i]; i++) {
        sum += get_followers(hashtags[i]);
    }
    *suma = sum;
    return suma;
}

void calc_avg(void *t) { // A 2do nivel
    void **registro = (void**) t;
    if (registro[HASHTAGS])
        registro[TOTAL] = avg(registro[HASHTAGS]);
}

void calc_total_followers(void *t){ // A 2do nivel
    void **registro = (void**) t;
    if (registro[HASHTAGS])
        registro[TOTAL] = suma(registro[HASHTAGS]);
}
void calc_stats(void* t) { // A 1er nivel
    void **tweets = (void**) t;
    for (int i = 0; tweets[i]; i++)
        calc_total_followers(tweets[i]);
}

void display_stats(void *avg) {
    double * average = (double*) avg;
    cout.precision(2);
    cout << fixed;
    cout << "AVG: " << setw(10) << *average << endl;
}

bool is_greater(void *hi, void *hj) {
    //Sin el salto extra x q yo controlo la funcion de ordenamiento
    void**hashtag_i = (void**) hi;
    void**hashtag_j = (void**) hj;
    char *hash_i = (char*) hashtag_i[HASHTAG];
    char *hash_j = (char*) hashtag_j[HASHTAG];
    return strcmp(hash_i, hash_j) < 0;
}

bool is_lower(void *ti, void *tj) {
    void**tweet_i = (void**) ti;
    void**tweet_j = (void**) tj;
    int *createdat_i = (int*) tweet_i[CREATEDAT];
    int *createdat_j = (int*) tweet_j[CREATEDAT];
    return *createdat_i>*createdat_j;
}

void swap(void *&i, void *&j) {
    void *aux;
    aux = i;
    i = j;
    j = aux;
}

void qsort2(void **hashtags, int izq, int der) {
    int limite, pivote;
    if (izq >= der) return;
    pivote = (izq + der) / 2;
    swap(hashtags[izq], hashtags[pivote]); //intercambio o cambiar
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (is_greater(hashtags[i], hashtags[izq])) {
            limite++;
            swap(hashtags[limite], hashtags[i]);
        }
    swap(hashtags[izq], hashtags[limite]);
    qsort2(hashtags, izq, limite - 1);
    qsort2(hashtags, limite + 1, der);
}

void qsort1(void **tweets, int izq, int der) {
    int limite, pivote;
    if (izq >= der) return;
    pivote = (izq + der) / 2;
    swap(tweets[izq], tweets[pivote]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (is_lower(tweets[i], tweets[izq])) {
            limite++;
            swap(tweets[limite], tweets[i]);
        }
    swap(tweets[izq], tweets[limite]);
    qsort1(tweets, izq, limite - 1);
    qsort1(tweets, limite + 1, der);
}

void sort_hashtags(void*t) {
    void**registro = (void**) t;
    void**hashtags = (void**) registro[HASHTAGS]; //Ojo, lo q voy a sacar es TODA la estructura hashtags
    int *ptr_n = (int*)registro[HASHTAG_SIZE];
    qsort2(hashtags, 0, (*ptr_n) - 1);
}

void sort2(void* &t) { //Como voy a mover los elementos, debe pasar con &
    void**tweets = (void**) t;
    int n = 0;
    //Ordenar a segundo nivel
    for (; tweets[n]; n++) {
        sort_hashtags(tweets[n]);
    }
    //Ordenar a primer nivel
    qsort1(tweets, 0, n - 1);
}

void delete_hashtag(void *h) {
    void**registro = (void**) h;
    int* followers = (int*) registro[FOLLOWERS];
    char* hashtag = (char*) registro[HASHTAG];

    delete followers;
    delete hashtag;
    delete registro;
}

void delete_hashtags(void *h) {
    void**hashtags = (void**) h;
    for (int i = 0; hashtags[i]; i++)
        delete_hashtag(hashtags[i]);
    delete hashtags;
}

void delete_tweet(void *t) {
    void**registro = (void**) t;
    int* createdat = (int*) registro[CREATEDAT];
    char* tweet = (char*) registro[TWEET];
    int* total = (int*) registro[TOTAL];
    int* contador = (int*) registro[HASHTAG_SIZE];

    delete createdat;
    delete tweet;
    //delete nullptr; //Grave error de concepto
    if (total != nullptr) {
        delete total;
        delete contador;
        delete_hashtags(registro[HASHTAGS]);
    }
    delete registro;
}

void delete_tweets(void *t) {
    void**tweets = (void**) t;
    for (int i = 0; tweets[i]; i++) //1er nivel
        delete_tweet(tweets[i]);
    delete tweets;
//    void**tweets = (void**) t;
//    delete tweets;
}