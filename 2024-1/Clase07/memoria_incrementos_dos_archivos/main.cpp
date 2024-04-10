/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 8, 2024, 4:58 PM
 */

#include "functions.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *dates;
    char **tweets;
    char ***hashtags;
    read_tweets(dates,tweets, "tweets.csv");
    read_hashtags(dates,hashtags, "hashtags.csv");
    display_tweets(dates, tweets, hashtags, "reporte.txt");
    sort_tweets(dates, tweets, hashtags);
    display_tweets(dates, tweets, hashtags, "reporte_ordenado.txt");
    return 0;
}

