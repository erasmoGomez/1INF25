//
// Created by Erasmo on 2/09/25.
//

#include "HandleTweets.hpp"

void read_tweets(ifstream &input, int *buffer_dates, char **buffer_tweets, int &n_tweets) {
    //20230410,Our team won the local soccer tournament!
    int date;
    while (true) {
        date = read_int(input);
        if (input.eof())break;
        input.get();
        buffer_dates[n_tweets] = date;
        buffer_tweets[n_tweets] = read_str(input, '\n');
        n_tweets++;
    }
}

void copy_tweets(int *&dates, int *buffer_dates,
                 char **&tweets, char **buffer_tweets, int n_tweets) {
    //Primer Paso: Reservar memoria Exacta;
    dates = new int[n_tweets + 1]{};
    tweets = new char *[n_tweets + 1]{};
    //Segundo Paso: Asignacion de valores
    for (int i = 0; i < n_tweets; i++) {
        dates[i] = buffer_dates[i];
        tweets[i] = assign_str(buffer_tweets[i]);
    }
}

void load_tweets(int *&dates, char **&tweets, const char *file_name) {
    ifstream input;
    open_file_read(input, file_name);
    //Metodo de Memoria Exacta
    int buffer_dates[MAX_TWEETS]{}, n_tweets = 0;
    char *buffer_tweets[MAX_TWEETS]{};
    read_tweets(input, buffer_dates, buffer_tweets, n_tweets);
    copy_tweets(dates, buffer_dates, tweets, buffer_tweets, n_tweets);
}

void display_tweets(int *dates, char **tweets, const char *file_name) {
    ofstream output;
    open_file_write(output, file_name);
    output << "DATES" << setw(80) << "TWEETS" << endl;
    for (int i = 0; dates[i]; i++)
        output << dates[i] << setw(100) << tweets[i] << endl;
}

void add_hashtag(ifstream &input, char **&hashtags_tweet, int &n_hashtags) {
    char *hashtag = read_str(input, '\n');
    hashtags_tweet[n_hashtags] = hashtag;
    n_hashtags++;
}

void read_hashtags(ifstream &input, int *dates, char ***hashtags, int *n_hashtag_tweets) {
    //20230408,#motivation
    int date, pos;
    while (true) {
        date = read_int(input);
        if (input.eof())break;
        input.get();
        pos = lookup_int(date, dates);
        if (pos != -1)
            add_hashtag(input, hashtags[pos], n_hashtag_tweets[pos]);
    }
}

void cut(char **&hashtags_tweet, int n_hashtags) {
    char **hashtags_temp;
    if (n_hashtags != 0) {
        hashtags_temp = new char *[n_hashtags + 1]{
        };
        //Ahora pasar la información  previa al nuevo arreglo
        for (int i = 0; i < n_hashtags; i++)
            hashtags_temp[i] = hashtags_tweet[i];
        delete hashtags_tweet;
        hashtags_tweet = hashtags_temp; //Apunto a la nueva direccion de memoria que contiene los datos
    } else {
        delete hashtags_tweet;
        hashtags_tweet = nullptr;
    }
}

void cut_hashtags(int n_tweets, char ***&hashtags, int *n_hashtag_tweets) {
    for (int i = 0; i < n_tweets; i++)
        cut(hashtags[i], n_hashtag_tweets[i]);
}

void load_hashtags(int *dates, char ***&hashtags, const char *file_name) {
    ifstream input;
    open_file_read(input, file_name);
    int n_tweets = 0;
    while (dates[n_tweets])n_tweets++;
    int n_hashtag_tweets[n_tweets]; // Arreglo de contadores de cantidad de hashtags por tweet
    //Reserva de memoria a primer nivel
    hashtags = new char **[n_tweets];
    for (int i = 0; i < n_tweets; i++) {
        n_hashtag_tweets[i] = 0;
        hashtags[i] = new char *[20];
    }


    //Lectura
    read_hashtags(input, dates, hashtags, n_hashtag_tweets);
    cut_hashtags(n_tweets, hashtags, n_hashtag_tweets);
}

void display_hashtags(ofstream &output, char **hashtags_tweet) {
    for (int i = 0; hashtags_tweet[i]; i++)
        output << right << setw(15) << hashtags_tweet[i] << endl;
    output << endl;
}

void display_tweets(int *dates, char **tweets, char ***hashtags, const char *file_name) {
    ofstream output;
    open_file_write(output, file_name);
    output << "DATES" << setw(80) << "TWEETS" << endl;
    for (int i = 0; dates[i]; i++) {
        output << dates[i] << setw(100) << tweets[i] << endl;
        output << "List of Hashtags:" << setw(80) << endl;
        if (hashtags[i])
            display_hashtags(output, hashtags[i]);
        else
            output << "WE COULDN'T FIND ANY HASHTAGS!" << endl;
    }

}

void reservar_memoria_incrementos(struct Tweets &tweets) {
    int *aux_dates;
    char **aux_tweets;
    tweets.capacity += INCREMENTO;
    if (tweets.dates == nullptr and tweets.tweets == nullptr) { //Cuando no hay elementos en los arreglos
        tweets.dates = new int[tweets.capacity]{};
        tweets.tweets = new char *[tweets.capacity]{};
        tweets.n_tweets = 1; //Para considerar el tope
    } else { //Cuando si hay elementos en los arreglos
        aux_dates = new int[tweets.capacity]{};
        aux_tweets = new char *[tweets.capacity]{};
        for (int i = 0; i < tweets.n_tweets; i++) {
            aux_dates[i] = tweets.dates[i];
            aux_tweets[i] = tweets.tweets[i];
        }
        delete tweets.dates;
        delete tweets.tweets;
        tweets.dates = aux_dates;
        tweets.tweets = aux_tweets;
    }
}

void load_tweets_incremental(struct Tweets &tweets, const char *file_name_tweets) {
    tweets.capacity = 0;
    tweets.n_tweets = 0;
    int date = 0;
    char *tweet = nullptr;
    ifstream input;
    open_file_read(input, file_name_tweets);
    tweets.dates = nullptr;
    tweets.tweets = nullptr;
    while (true) {
        date = read_int(input);
        if (input.eof())break;
        input.get();
        tweet = read_str(input, '\n');
        if (tweets.capacity == tweets.n_tweets)
            reservar_memoria_incrementos(tweets);
        tweets.dates[tweets.n_tweets - 1] = date;
        tweets.tweets[tweets.n_tweets - 1] = tweet;
        tweets.n_tweets++;
    }
}

void reservar_memoria_incrementos(char **&hashtags_tweet, int &cantidad, int &capacidad) {
    char **aux_hashtags;
    capacidad += INCREMENTO;
    if (hashtags_tweet == nullptr) {
        hashtags_tweet = new char *[capacidad]{};
        cantidad = 1;
    } else {
        aux_hashtags = new char *[capacidad]{};
        for (int i = 0; i < cantidad; i++)
            aux_hashtags[i] = hashtags_tweet[i];
        delete hashtags_tweet; //Rompo conexion a segundo nivel
        hashtags_tweet = aux_hashtags; //Vuelvo a conectar a segundo nivel
    }
}

void add_hashtag(ifstream &input, char **&hashtags_tweet, int &cantidad, int &capacidad) {
    char *hashtag;
    hashtag = read_str(input, '\n');
    if (cantidad == capacidad)
        reservar_memoria_incrementos(hashtags_tweet, cantidad, capacidad);
    hashtags_tweet[cantidad - 1] = hashtag;
    cantidad++;
}

void load_hashtags_incremental(struct Tweets &tweets, const char *file_name_hashtags) {
    ifstream input;
    open_file_read(input, file_name_hashtags);
    tweets.hashtags = new char **[tweets.n_tweets + 1]{};
    int cantidades[50]{}, capacidades[50]{};
    int date, pos;
    while (true) {
        date = read_int(input);
        if (input.eof())break;
        input.get();
        pos = lookup_int(date, tweets.dates);
        if (pos != -1) {
            add_hashtag(input, tweets.hashtags[pos], cantidades[pos], capacidades[pos]);
        } else
            while (input.get() != '\n');
    }

}

void load_tweets(struct Tweets &tweets, const char *file_name_tweets, const char *file_name_hashtags) {
    load_tweets_incremental(tweets, file_name_tweets);
    load_hashtags_incremental(tweets, file_name_hashtags);
}

void display_tweets(struct Tweets tweets, const char *file_name) {
    display_tweets(tweets.dates, tweets.tweets, tweets.hashtags, file_name);
}
