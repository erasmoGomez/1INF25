#pragma once
#include <string>
#include <vector>
using namespace std;
class MiningStack {
private:
    vector<string> blocks;
public:
    MiningStack();
    ~MiningStack();
    void push(const string& block);
    bool pop(string& removed);
    bool top(string& block) const;
    bool empty() const;
    void display() const;
};
