//
// Created by Erasmo on 20/08/25.
//

#include "Functions.hpp"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
void print_line(size_t n, char c) {
    for (int i = 0; i < n; i++) cout << c;
    cout << endl;
}

bool get_next_token(const char *input_string, char *token) {
    static char working_string[MAX_COMMENT_LENGTH]{};
    static int current_pos = 0;
    static size_t length = 0;

    char current_token[MAX_TOKEN_LENGTH]{};

    // Reset when a new input string is provided
    if (strcmp(working_string, input_string) != 0) {
        strcpy(working_string, input_string);
        current_pos = 0;
        length = strlen(working_string);
    }

    int word_pos = 0;

    // Skip leading spaces
    while (current_pos < length and working_string[current_pos] == ' ')
        current_pos++;

    // No more tokens
    if (current_pos >= length)
        return false;

    // Copy the current word
    while (current_pos < length and working_string[current_pos] != ' ') {
        current_token[word_pos] = working_string[current_pos];
        word_pos++;
        current_pos++;
    }

    current_token[word_pos] = '\0';

    // Allocate exactly the memory needed for the token
    //const auto token = new char[word_pos + 1];
    strcpy(token, current_token);
    return true;
}

void tokenize(const char *input_string, const int n_token) {
    cout << "comment_" << n_token << ": " << input_string << endl;
    cout << "Tokens for comment_" << n_token << ":" << endl;

    char token[20]{};

    while (get_next_token(input_string, token)) {
        cout << token << endl;
    }

    print_line(OUTPUT_WIDTH, '=');
}
