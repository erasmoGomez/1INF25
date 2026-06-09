//
// Created by erasmo on 5/13/26.
//

#ifndef JUEGOUNDERTALE_UTILS_HPP
#define JUEGOUNDERTALE_UTILS_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Utils {
public:
    static void apertura_archivo_lectura(ifstream &, const char*);
    static void apertura_archivo_escritura(ofstream &, const char*);
};


#endif //JUEGOUNDERTALE_UTILS_HPP