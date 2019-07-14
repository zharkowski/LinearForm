#include "list_unit_5.hpp"

/*
 UNIT 5: Тестирование умножения списка на число
 
 Список тестов:
 Тест 1: Умножение списка на ненулевую величину
 Тест 2: Умножение списка на 0
 */

void run_list_unit_5(){
    cout<<"[LIST CLASS TESTING] UNIT 5 :\n\n";
    int test_id = 0;
    bool test_ok = true;

    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);

        List<double> lst;
        lst.push(1);
        lst.push(2);
        lst.push(3);
        lst.push(4);
        lst.push(5);
        
        lst.multiply_by(5);

        if (lst.get_length() == 5)
            if (lst[0] == 5)
                if (lst[1] == 10)
                    if (lst[2] == 15)
                        if (lst[3] == 20)
                            if (lst[4] == 25) test_ok = true;
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst;
        lst.push(1);
        lst.push(2);
        lst.push(3);
        lst.push(4);
        lst.push(5);
        
        lst.multiply_by(0);

        if (lst.get_length() == 0) test_ok = true;
        
        test_result(test_ok);
    }

    if (test_id == 2 && test_ok == true) {
      cout<<"\n[TESTING] Unit 5 testing SUCCESSEDED.\n";
      cout<<"----------------------------------------"<<"\n\n\n";
    } else {
    cout<<"\n[TESTING] Unit 5 testing FAILED on TEST #"<<test_id<<".\n";
    cout<<"----------------------------------------"<<"\n\n\n";
    }
}
