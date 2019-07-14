#include "linear_form.hpp"

using namespace std;

template <typename T>
LinearForm<T>::LinearForm() {
    a = List<T>();
}

template <typename T>
LinearForm<T>::LinearForm(List<T> lst) {
    a = lst;
}

template <typename T>
LinearForm<T>::~LinearForm() {
    while (a.get_length() != 0) {
        a.pop();
    }
}

template <typename T>
LinearForm<T> LinearForm<T>::operator+ (LinearForm<T> sec_lform){
    ((*this).a).sum_with(sec_lform.a);
    return *this;
}

template <typename T>
void LinearForm<T>::print(){
    cout<<"\nCurrent Linear form:\nF(x) = ";
    bool is_form_null = true;       //равна ли линейная форма нулю
    
    if((this->a).get_length() > 0){
        for (int i = 0; i < (this->a).get_length(); i++){   //проверка на существование ненулевых элементов в линейной форме
            if ((this->a)[i]){
                is_form_null = false;
                break;
            }
        }
    }
    if (is_form_null) cout<<"0";           //если в линейной форме все коэфициенты равны 0, то выводим ноль
    
    else{
        for (int i = 0; i < (this->a).get_length(); i++){
            if ((this->a)[i] != 0){
                if (i == 0)
                    cout<<(this->a)[i];
                else
                    if ((this->a)[i] > 0) cout<<"+ "<<(this->a)[i]<<"*x"<<i<<" ";
                    else cout<<"- "<<(-1)*(this->a)[i]<<"*x"<<i<<" ";
            }
        }
    }
    cout<<endl;
}
