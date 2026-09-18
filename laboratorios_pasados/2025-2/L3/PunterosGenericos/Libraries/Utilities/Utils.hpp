//
// Created by erasmo on 9/17/26.
//

#ifndef PUNTEROSGENERICOS_UTILS_HPP
#define PUNTEROSGENERICOS_UTILS_HPP
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define NOT_FOUND (-1)
#define INCREMENT 5
#define REPORT_WIDTH 80
#define N_COLUMNS 2
#define MAX_STREAMERS 300
enum StreamerFields {ACCOUNT, FOLLOWERS, CATEGORY, COMMENTS};
enum CommentFields {CODE, TEXT, SENDER, RECEIVER};
enum StreamerCommentFields {COMMENT_RECEIVER, COMMENT_TEXT};
#endif //PUNTEROSGENERICOS_UTILS_HPP