/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.hpp
 * Author: ASUS
 *
 * Created on November 7, 2023, 12:57 AM
 */

#ifndef NODE_HPP
#define NODE_HPP
#include "Hero.hpp"
class Node {
public:
    Node();
    Node(const Node& orig);
    virtual ~Node();
    friend class Arbol;
private:
    class Hero dato;
    class Node *izq;
    class Node *der;
    
};

#endif /* NODE_HPP */

