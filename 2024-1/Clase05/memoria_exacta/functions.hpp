/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: ASUS
 *
 * Created on April 1, 2024, 12:26 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "Utils.hpp"
using namespace std;
void read_tweets(int *&, char**&, char***&, const char*);
void display_tweets(int *, char**, char***, const char*);
char * read_message(ifstream &);
char * read_hashtag(ifstream &);
char ** read_list_hashtags(ifstream &);
void display_hashtags(char **, ofstream &);

#endif /* FUNCTIONS_HPP */

