#include "MiningStack.hpp"
#include <iostream>
using namespace std;
MiningStack::MiningStack() = default;
MiningStack::~MiningStack() = default;
void MiningStack::push(const string& block) {
    blocks.push_back(block);
}
bool MiningStack::pop(string& removed) {
    if (blocks.empty()) return false;
    removed = blocks.back();
    blocks.pop_back();
    return true;
}
bool MiningStack::top(string& block) const {
    if (blocks.empty()) return false;
    block = blocks.back();
    return true;
}
bool MiningStack::empty() const {
    return blocks.empty();
}
void MiningStack::display() const {
    cout << "Mining stack (top -> bottom):\n";
    if (blocks.empty()) cout << "  (empty)\n";
    for (auto it = blocks.crbegin(); it != blocks.crend(); ++it)
        cout << "  " << *it << '\n';
}
