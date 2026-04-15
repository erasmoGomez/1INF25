#include "src/HandleTweets.hpp"

int main() {
    int* dates;
    char** tweets;
    char*** hashtags;
    load_tweets(dates, tweets, "Data/tweets.csv");
    display_tweets(dates, tweets, "Reports/tweets.txt");
    load_hashtags(dates, hashtags, "Data/hashtags.csv");
    display_tweets(dates, tweets, hashtags, "Reports/tweets_complete.txt");
    return 0;
}
