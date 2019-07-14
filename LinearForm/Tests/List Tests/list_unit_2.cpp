#include "list_unit_2.hpp"

/*
 UNIT 2: Тестирование добавления элемента в список
 
 Список тестов:
 Тест 1: добавление элемента в пустой список
 Тест 2: добавление элемента в непустой список
 */

void run_list_unit_2(){
    cout<<"[LIST CLASS TESTING] UNIT 2 :\n\n";
    int test_id = 0;
    bool test_ok = true;

    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);

        List<int> lst;
        lst.push(4);
        if (lst[0] == 4 && lst.get_length() == 1) test_ok = true;

        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<Complex> lst;
        lst.push(Complex(2,5));
        lst.push(Complex(4,2));
        if (lst[1] == Complex(4,2) && lst.get_length() == 2) test_ok = true;
        
        test_result(test_ok);
    }

    if (test_id == 2 && test_ok == true) {
        cout<<"\n[TESTING] Unit 2 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 2 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
