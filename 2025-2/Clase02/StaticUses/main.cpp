#include "src/Functions.hpp"

int main() {
    char comment_1[MAX_COMMENT_LENGTH] = "Im having a lot of fun here";
    char comment_2[MAX_COMMENT_LENGTH] = "I dont like this stream";
    print_line(REPORT_WIDTH, '=');
    cout << "Tokenization Process" << endl;
    print_line(REPORT_WIDTH, '-');
    tokenize(comment_1, 1);
    tokenize(comment_2, 2, true);
    cout << "Tokenized comments complete!" << endl;
    return 0;
}
