#include "Utils.hpp"
using namespace std;

bool Utils::open_read_file(ifstream& file, const string& path) {
    file.open(path);
    if (!file.is_open()) cerr << "Cannot open file for reading: " << path << '\n';
    return file.is_open();
}
bool Utils::open_write_file(ofstream& file, const string& path) {
    file.open(path);
    if (!file.is_open()) cerr << "Cannot open file for writing: " << path << '\n';
    return file.is_open();
}
bool Utils::parse_positive_int(const string& text, int& number) {
    try {
        size_t pos = 0;
        number = stoi(text, &pos);
        return pos == text.size() && number > 0;
    } catch (...) { return false; }
}
string Utils::read_text(const string& prompt) {
    cout << prompt;
    string value;
    getline(cin, value);
    return value;
}
int Utils::read_int(const string& prompt) {
    while (true) {
        string value = read_text(prompt);
        try {
            size_t pos = 0;
            int number = stoi(value, &pos);
            if (pos == value.size()) return number;
        } catch (...) {}
        if (!cin) return 0;
        cout << "Please enter a valid integer.\n";
    }
}
