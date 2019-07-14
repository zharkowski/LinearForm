#pragma once
#ifndef linear_form_hpp
#define linear_form_hpp

#include <stdio.h>
#include "list.hpp"

using namespace std;

template <typename T>
class LinearForm{
private:
    List<T> a;
    
public:
    LinearForm();
    LinearForm(List<T> list);
    ~LinearForm();
    
    LinearForm<T> operator+ (LinearForm<T> sec_lform);
    
    LinearForm<T> operator* (double cnst);
    
    
    void print();
    
    T linearForm_calculate_value(List<T> x);
};

#include "linear_form.cpp"

#endif /* linear_form_hpp */
