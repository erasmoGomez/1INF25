//
// Created by erasmo on 9/29/26.
//

#ifndef MINECRAFTP2_UTILS_HPP
#define MINECRAFTP2_UTILS_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Utils {
public:
    static void open_read_file(ifstream &input, const char *filename);

    static void open_write_file(ofstream &output, const char *filename);
};


#endif //MINECRAFTP2_UTILS_HPP
