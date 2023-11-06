/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.hpp
 * Author: ASUS
 *
 * Created on October 31, 2023, 8:55 AM
 */

#ifndef NODE_HPP
#define NODE_HPP
#include "hero.hpp"
#include "Lista.hpp"
class Node {
public:
    Node();
    friend class Lista;
private:
    class hero dato;
    class Node* sig;
    
};

#endif /* NODE_HPP */

