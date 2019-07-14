#ifndef complex_hpp
#define complex_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Complex{
private:
    double re, im;
    
public:
    Complex (double, double);
    Complex (double);
    Complex();
    ~Complex();
    
    double return_re();
    double return_im();
    
    Complex operator+ (Complex);
    Complex operator+= (Complex);
    Complex operator* (Complex);
    Complex operator+ (double);
    Complex operator* (double);
    Complex operator+= (double);
    Complex operator*= (double);
    bool operator== (Complex);
    bool operator!= (Complex);
    bool operator== (double);
    bool operator!= (double);
    bool operator< (Complex);
    bool operator<= (Complex);
    bool operator> (Complex);
    bool operator>= (Complex);
    
    void print();

    friend std::ostream & operator<<(std::ostream &os, const Complex &c);
};

#endif /* complex_hpp */
