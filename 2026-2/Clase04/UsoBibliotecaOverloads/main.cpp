#include "Libraries/Controller/ReviewController.hpp"

int main() {
    struct Review* reviews{};
    int n_reviews = 0;
    int stats[3]{}; //0 -> negativos 1-> neutrales 2-> positivos
    load_reviews("Data/reviews.csv", reviews, n_reviews);
    print_reviews("Reports/reviews_report.txt", reviews, n_reviews);
    fill_stats(reviews, n_reviews, stats);
    print_stats(stats, n_reviews);

    return 0;
}
