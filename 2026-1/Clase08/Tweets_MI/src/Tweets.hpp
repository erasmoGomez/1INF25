//
// Created by Erasmo on 3/09/25.
//

#ifndef TWEETS_TWEETS_HPP
#define TWEETS_TWEETS_HPP
struct Tweets{
    int * dates;
    char** tweets;
    char*** hashtags;
    int capacity;
    int n_tweets;
};
#endif //TWEETS_TWEETS_HPP
