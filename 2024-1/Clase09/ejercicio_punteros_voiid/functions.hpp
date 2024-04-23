/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: ASUS
 *
 * Created on April 15, 2024, 6:03 PM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "utils.hpp"
using namespace std;
void load_tweets(void *&, const char *);
void load_hashtags(void *&, const char *);
void display_tweeets(void *, const char *);
char * read_str(ifstream & , char = '\n');
void add_hashtag(ifstream &input, void* t, int &n, int&c);
void *read_hashtag(ifstream &input);
void incrementar_memoria_hashtags(void *&h,int& n, int& c);
void insert_hashtag(void *hashtag,void *h,int n);
void display_tweets(void* tweets);
void calc_stats(void* tweets);
void sort2(void*&tweets);
void delete_tweets(void* tweets);
#endif /* FUNCTIONS_HPP */

