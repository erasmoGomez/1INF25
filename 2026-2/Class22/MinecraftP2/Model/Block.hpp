//
// Created by erasmo on 10/7/26.
//

#ifndef MINECRAFTP2_BLOCK_HPP
#define MINECRAFTP2_BLOCK_HPP
#include "../Utilities/Utils.hpp"

class Block {
private:
    char sprite;
    bool transitable;

public:
    char get_sprite() const;

    void set_sprite(const char sprite);

    bool is_transitable() const;

    void set_transitable(const bool transitable);

    Block();

    Block(bool transitable);

    Block(const Block &orig);

    virtual ~Block();

    void display(ostream &out) const;
};

void operator<<(ostream &, const class Block &);

#endif //MINECRAFTP2_BLOCK_HPP
