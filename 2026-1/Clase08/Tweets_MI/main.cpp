#include "src/HandleTweets.hpp"

int main() {
    struct Tweets tweets{};
    load_tweets(tweets, "Data/tweets.csv", "Data/hashtags.csv");
    display_tweets(tweets, "Reports/tweets_mi.txt");
    return 0;
}
