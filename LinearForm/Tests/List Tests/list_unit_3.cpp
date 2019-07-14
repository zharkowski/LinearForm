#include "list_unit_3.hpp"

/*
 UNIT 3: Тестирование удаления элемента из списока
 
 Список тестов:
 Тест 1: удаление элемента из списка
 Тест 2: Удаление нескольких элементов из списка
 Тест 3: Удаление элемента из пустого списка
 */

void run_list_unit_3(){
    cout<<"[LIST CLASS TESTING] UNIT 3 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<int> lst;
        lst.push(4);
        lst.pop();
        if (lst.get_length() == 0) test_ok = true;
        
        test_result(test_ok);
    }

    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);

        List<Complex> lst;
        lst.push(Complex(2,5));
        lst.push(Complex(4,2));
        lst.pop();
        if (lst[0] == Complex(2,5) && lst.get_length() == 1) test_ok = true;

        test_result(test_ok);
    }
    
    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst;
        try {
            lst.pop();
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        if (lst.get_length() != 0) test_ok = false;
        
        test_result(test_ok);
    }
    
    if (test_id == 3 && test_ok == true) {
        cout<<"\n[TESTING] Unit 3 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 3 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
