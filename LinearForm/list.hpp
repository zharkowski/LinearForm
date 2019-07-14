#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
struct ListItem {
    T item;
    ListItem* next;
    
    T get_item();
};

template <typename T>
class List{
private:
    ListItem<T>* head;
    int length;
    
public:
    List();
    ~List();
    List(const List &lst); //конструктор копирования
    
    int get_length();
    void push(T value);
    void pop();
    void print();
    void sum_with(List<T>* sec_list);
    void multiply_by(T cnst);
    void correct_zeros();
    
    T operator[](int index);
//    List<T> operator+ (List<T> sec_list);
    T calculate_value(List<T> x);
};

#include "list.cpp"

#endif /* list_hpp */

