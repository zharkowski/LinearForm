#include "list.hpp"

using namespace std;

template <typename T>
List<T>::List() {
    length = 0;
}

template <typename T>
List<T>::~List() {    
    while (length != 0) pop();
}

template <typename T>       //конструктор копирования
List<T>::List(const List &lst){
    length = 0;
    ListItem<T>* ptr_item = lst.head;
    
    if (lst.length != 0){
        while (ptr_item != 0){
            this->push(ptr_item->item);
            ptr_item = ptr_item->next;
        }
    }
}

//
// Нахождение знчения элемента списка
//
template <typename T>
T ListItem<T>::get_item(){
    return item;
}

//
// Нахождение длины списка
//
template <typename T>
int List<T>::get_length(){
    return length;
}

//
// Удаление последнего элемента в списке
//
template <typename T>
void List<T>::pop() {
    if (length < 1) {
        throw out_of_range("Out of range");
    }
    else{
        ListItem<T>* tmp_item =  this->head;
//        if (length != 1){
            for (int i = 0; i < length - 1; i++){
                tmp_item = tmp_item->next;
            }
//        }
        
        delete tmp_item;
        length--;
    }
}

//
// Добаление элемента в конец списка
//
template <typename T>
void List<T>::push(T value) {
    ListItem<T>* new_item = new ListItem<T>();
    new_item->item = value;
    
    if (length == 0){
        head = new_item;
    }
    else{
        ListItem<T>* currtent_item = head;
        for (int i = 1; i < length; i++){
            currtent_item = currtent_item->next;
        }
        currtent_item->next = new_item;
    }
    
    length++;
}

//
// Вывод списка в консоль
//
template <typename T>
void List<T>::print(){
    cout<<"\nCurrent Linear form:\nF(x) = ";
    bool is_form_null = true;       //равна ли линейная форма нулю
    
    if(this->get_length() > 0){
        for (int i = 0; i < this->get_length(); i++){   //проверка на существование ненулевых элементов в линейной форме
            if ((*this)[i] != 0){
                is_form_null = false;
                break;
            }
        }
    }
    if (is_form_null) cout<<"0";           //если в линейной форме все коэфициенты равны 0, то выводим ноль
    
    else{
        for (int i = 0; i < this->get_length(); i++){
            if ((*this)[i] != 0){
                if (i == 0)
                    cout<<(*this)[i]<<" ";
                else
                    cout<<"+ ("<<(*this)[i]<<")x"<<i<<" ";
            }
        }
    }
    cout<<endl;
}

//
// Взятие значения из списка по индексу
//
template <typename T>
T List<T>::operator[](int index){
    if ((0 > index) || (index >= length )) {
        throw std::out_of_range("Out of range");
    }
    else{
        ListItem<T>* tmp_item = head;
        
        for (int i = 0; i < index; i++){
            tmp_item = tmp_item->next;
        }

        return tmp_item->get_item();
    }
}

//
// Сложение двух списков
//
template <typename T>
void List<T>::sum_with(List<T>* sec_list){
    
    if (this->length == sec_list->length){
        ListItem<T>* current_item_1 = this->head;
        ListItem<T>* current_item_2 = sec_list->head;
        
        for (int i = 0; i < this->length; i++){
            current_item_1->item = current_item_1->item + current_item_2->item;
            current_item_1 = current_item_1->next;
            current_item_2 = current_item_2->next;
        }
    }
    else if (this->length > sec_list->length){
        ListItem<T>* current_item_1 = this->head;
        ListItem<T>* current_item_2 = sec_list->head;
        
        for (int i = 0; i < sec_list->length; i++){
            current_item_1->item = current_item_1->item + current_item_2->item;
            current_item_1 = current_item_1->next;
            current_item_2 = current_item_2->next;
        }
    }
    else {
        ListItem<T>* current_item_1 = this->head;
        ListItem<T>* current_item_2 = sec_list->head;
        
        for (int i = 0; i < this->length; i++){
            current_item_1->item = current_item_1->item + current_item_2->item;
            current_item_1 = current_item_1->next;
            current_item_2 = current_item_2->next;
        }
        for (int i = this->length; i < sec_list->length; i++){
            (*this).push(current_item_2->item);
            current_item_2 = current_item_2->next;
        }
    }
    
    (*this).correct_zeros();
}

//
// Умножение списка на число
//
template <typename T>
void List<T>::multiply_by(T cnst){
    ListItem<T>* current_item = this->head;
    
    for (int i = 0; i < this->length; i++){
        current_item->item = current_item->item * cnst;
        current_item = current_item->next;
    }
    (*this).correct_zeros();
}

//
// Проверка на наличие в конце списка нулей и корректирование списка
//
template <typename T>
void List<T>::correct_zeros(){
    while (this->length > 0 && (*this)[this->length - 1] == 0){
        (*this).pop();
    }
}

template <typename T>
T List<T>::calculate_value(List<T> x){
    if (x.length == 0 || this->length == 0) return 0;
    T val = 0;
    val += this->head->item;
    ListItem<T>* current_item = this->head;
    for (int i = 0; i < this->length - 1; i++){
        current_item = current_item->next;
        val += current_item->item * x[i];
    }
    return val;
}
