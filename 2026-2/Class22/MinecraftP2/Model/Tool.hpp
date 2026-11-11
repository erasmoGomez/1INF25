//
// Created by erasmo on 10/21/26.
//

#ifndef MINECRAFTP2_TOOL_HPP
#define MINECRAFTP2_TOOL_HPP

#include "Item.hpp"

class Tool : public Item {
private:
    int mining_speed;

public:
    Tool();
    void mine();
    void read(ifstream&input);
    int use();
    void print(ofstream&output) const;
};


#endif //MINECRAFTP2_TOOL_HPP
