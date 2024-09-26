/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 15, 2024, 4:59 PM
 */

#include "functions.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void* tweets;
    load_tweets(tweets, "tweets.csv"); // Por memoria exacta
    display_tweets(tweets, "prueba_lectura_tweets.txt");
    load_hashtags(tweets, "hashtags.csv");
    display_tweets(tweets, "prueba_lectura_tweets_contador_hashtags.txt");
    calc_stats(tweets);
    display_tweets(tweets, "calcula_stats.txt");
    sort2(tweets);
    display_tweets(tweets, "ordena_tweets.txt");
    delete_tweets(tweets);
    return 0;
}

