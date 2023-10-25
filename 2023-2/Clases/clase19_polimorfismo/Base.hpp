/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Base.hpp
 * Author: ASUS
 *
 * Created on October 24, 2023, 9:25 AM
 */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    Base();
    Base(const Base& orig);
    virtual ~Base();
    void SetB(int b);
    int GetB() const;
    virtual void mostrar();
private:
    int b;
};

#endif /* BASE_HPP */

