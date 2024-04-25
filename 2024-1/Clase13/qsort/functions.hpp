/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: ASUS
 *
 * Created on April 24, 2024, 8:10 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
enum reg_tweet {CREATEDAT, TWEET, HASHTAGS, TOTAL};
enum reg_hashtag {HASHTAG, FOLLOWERS};
#define INCREMENTO 5
// int (*)(const void *, const void *)
int cmp_int(const void *, const void *);
void read_tweets(void *&, int&, const char *);
int cmp_void_str(const void *, const void *);
void display_tweets(void *, const char *);

#endif /* FUNCTIONS_HPP */

