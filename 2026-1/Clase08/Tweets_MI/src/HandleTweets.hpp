//
// Created by Erasmo on 2/09/25.
//

#ifndef TWEETS_HANDLETWEETS_HPP
#define TWEETS_HANDLETWEETS_HPP

#include "Utils.hpp"
#include "AuxiliaryFunctions.hpp"
#include "Tweets.hpp"

void load_tweets(struct Tweets &tweets, const char *file_name_tweets,  const char *file_name_hashtags);

void display_tweets(int *dates, char **tweets, char ***hashtags, const char *file_name);

void display_tweets(struct Tweets tweets, const char* file_name);

void load_hashtags(int *dates, char ***&hashtags, const char *file_name);

void read_hashtags(ifstream &input, int *dates, char ***hashtags, int *n_hashtag_tweets);

#endif //TWEETS_HANDLETWEETS_HPP
