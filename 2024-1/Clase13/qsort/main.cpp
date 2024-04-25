/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 24, 2024, 7:59 AM
 */

#include <cstdlib>
#include "functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    int a[50] = {10,5,6,3,76,2,34,56,6,8};
//    int n=10;
//    //void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
//    qsort(a,n,sizeof(int), cmp_int);
//    for(int i=0;i<n;i++)
//        cout<<setw(4)<<a[i];
    void * tweets;
    int tweets_size =0;
    read_tweets(tweets, tweets_size, "tweets.csv");
    display_tweets(tweets, "reporte_tweets.txt");
    qsort(tweets, tweets_size-1, sizeof(void*), cmp_void_str);
    display_tweets(tweets, "reporte_tweets_ordenado.txt");
    return 0;
}

