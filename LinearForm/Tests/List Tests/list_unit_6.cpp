#include "list_unit_6.hpp"

/*
 UNIT 6: Тестирование вычисления значения при заданных значениях аргументов
 
 Список тестов:
 Тест 1: нахождение значения при нулвеых аргументах
 Тест 2: нахождение значения при нудевых коэфициентах
 Тест 3: нахождение значения 
 */

void run_list_unit_6(){
    cout<<"[LIST CLASS TESTING] UNIT 6 :\n\n";
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
        
        List<double> x;
        double val = lst.calculate_value(x);
        if (val == 0) test_ok = 1;
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst;
        
        List<double> x;
        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);
        x.push(5);
        
        double val = lst.calculate_value(x);
        
        if (val == 0) test_ok = 1;
        
        test_result(test_ok);
    }
    
    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst;
        lst.push(1);
        lst.push(2);
        lst.push(3);
        lst.push(4);
        lst.push(5);
        
        List<double> x;
        x.push(5);
        x.push(4);
        x.push(3);
        x.push(2);
        
        double val = lst.calculate_value(x);
        
        if (val == 45) test_ok = 1;
        
        test_result(test_ok);
    }
    
    if (test_id == 3 && test_ok == true) {
        cout<<"\n[TESTING] Unit 6 testing SUCCESSEDED.\n";
        cout<<"----------------------------------------"<<"\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 6 testing FAILED on TEST #"<<test_id<<".\n";
        cout<<"----------------------------------------"<<"\n\n\n";
    }
}
