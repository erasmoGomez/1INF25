#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

class Utils {
public:
    static bool open_read_file(ifstream& file, const string& path);
    static bool open_write_file(ofstream& file, const string& path);
    static bool parse_positive_int(const string& text, int& number);
    static string read_text(const string& prompt);
    static int read_int(const string& prompt);
};
