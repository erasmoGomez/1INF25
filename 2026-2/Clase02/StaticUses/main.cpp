#include "src/Functions.hpp"

int main() {
    char comment_1[MAX_COMMENT_LENGTH] = "Im having a lot of fun here!";
    print_line(OUTPUT_WIDTH, '=');
    cout << "Tokenization Process" << endl;
    print_line(OUTPUT_WIDTH, '-');
    tokenize(comment_1, 1);
    cout << "Tokenized comments complete!" << endl;
    return 0;
}
