/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hero.hpp
 * Author: ASUS
 *
 * Created on November 7, 2023, 12:52 AM
 */

#ifndef HERO_HPP
#define HERO_HPP

#include "utils.hpp"
using namespace std;

class Hero {
public:
    Hero();
    Hero(const Hero& orig);
    virtual ~Hero();
    void SetAtt(double att);
    double GetAtt() const;
    void SetName(const char* name);
    void GetName(char *) const;
    void SetCode(int code);
    int GetCode() const;
    void operator = (const class Hero&);
    bool operator > (const class Hero&);
    bool operator == (const char* name);
    bool operator > (const char* name);
    bool operator < (const class Hero&);
private:
    int code;
    char *name;
    double att;
};

ifstream & operator>>(ifstream &input, class Hero & h);
//ofstream & operator<<(ofstream &output, const class Hero & h);
ostream & operator<<(ostream &output, const class Hero & h);


#endif /* HERO_HPP */

