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

bool get_next_token(const char *input_string, char *word) {
    static char working_string[MAX_COMMENT_LENGTH]{};
    static int current_pos = 0;
    static size_t length = 0;

    // This resets everything when a new input string is provided
    if (strcmp(working_string, input_string) != 0) {
        strcpy(working_string, input_string);
        current_pos = 0;
        length = strlen(working_string);
    }

    int word_pos = 0;
    // First, skip leading spaces
    while (current_pos < length and working_string[current_pos] == ' ')
        current_pos++;

    // Copy the word
    while (current_pos < length and working_string[current_pos] != ' ') {
        word[word_pos] = working_string[current_pos];
        word_pos++;
        current_pos++;
    }
    word[word_pos] = 0;
    return word[0] == 0;
}

char* get_next_token(const char *input_string) {
    static char working_string[MAX_COMMENT_LENGTH]{};
    static int current_pos = 0;
    static size_t length = 0;
    char current_token[MAX_TOKEN_LENGTH]{}, *token;

    // This resets everything when a new input string is provided
    if (strcmp(working_string, input_string) != 0) {
        strcpy(working_string, input_string);
        current_pos = 0;
        length = strlen(working_string);
    }

    int word_pos = 0;
    // First, skip leading spaces
    while (current_pos < length and working_string[current_pos] == ' ')
        current_pos++;

    // Copy the word
    while (current_pos < length and working_string[current_pos] != ' ') {
        current_token[word_pos] = working_string[current_pos];
        word_pos++;
        current_pos++;
    }
    current_token[word_pos] = 0;
    token = new char[strlen(current_token) + 1];
    strcpy(token, current_token);
    return (word_pos == 0) ? nullptr : token;
}

void tokenize(const char *input_string, int n_token, bool use_pointer) {
    char token[MAX_TOKEN_LENGTH], *token_word = nullptr;

    cout << "comment_" << n_token << ": " << input_string << endl;
    cout << "Tokens for comment_" << n_token << ": " << endl;
    while (true) {
        if (use_pointer) {
            token_word = get_next_token(input_string);
            if (!token_word) {
                delete[] token_word;
                break;
            }
            cout << token_word << endl;
            delete[] token_word;      // free allocated memory to avoid leak
        } else {
            if (get_next_token(input_string, token)) break;
            cout << token << endl;
        }
    }
    print_line(REPORT_WIDTH, '=');
}
#pragma clang diagnostic pop