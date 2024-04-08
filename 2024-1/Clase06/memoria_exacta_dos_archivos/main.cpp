/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 3, 2024, 7:04 AM
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
    return 0;
}

