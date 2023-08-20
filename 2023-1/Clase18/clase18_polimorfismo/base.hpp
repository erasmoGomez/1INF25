/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   base.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:06 PM
 */

#ifndef BASE_HPP
#define BASE_HPP
class Base{
private:
    int b;
public:
    void SetB(int);
    int GetB();
    virtual void imprime(); 
};


#endif /* BASE_HPP */

