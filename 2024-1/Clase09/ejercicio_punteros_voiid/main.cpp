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
    load_tweets(tweets, "tweets.csv");
    load_hashtags(tweets, "hashtags.csv");
    return 0;
}

