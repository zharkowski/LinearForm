#include "list_unit_1.hpp"

/*
 UNIT 1: Тестирование создания списка
 
 Список тестов:
 Тест 1: Cоздание пустого списка
 */

void run_list_unit_1(){
    cout<<"[LIST CLASS TESTING] UNIT 1 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<int> lst;
        if (lst.get_length() == 0) test_ok = true;
        else test_ok = false;
        
        test_result(test_ok);
        
    }
    
    if (test_id == 1 && test_ok == true) {
        cout<<"\n[TESTING] Unit 1 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 1 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}

