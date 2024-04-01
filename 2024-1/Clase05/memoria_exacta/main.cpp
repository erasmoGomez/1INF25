/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 1, 2024, 12:10 AM
 */

#include "functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int * dates; //Dado q quiero almacenar una lista de enteros
    char** messages; //Dado q quiero almacenar una lista de char*
    char*** hashtags_messages; //Dado q quiero almacenar una lista de char**
    read_tweets(dates, messages, hashtags_messages, "tweets.csv");
    display_tweets(dates, messages, hashtags_messages, "reporte_tweets.txt");
    return 0;
}

