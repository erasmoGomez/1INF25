/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tweet.hpp
 * Author: ASUS
 *
 * Created on March 31, 2024, 3:59 PM
 */

#ifndef TWEET_HPP
#define TWEET_HPP
struct Tweet{
    int created_at;
    char* message;
    char** list_hashtags;
};
  


#endif /* TWEET_HPP */

