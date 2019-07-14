#include "list_unit_4.hpp"

/*
 UNIT 4: Тестирование сложения списков
 
 Список тестов:
 Тест 1: Сложение двух нулевых списков
 Тест 2: Сложение нулевого списка и ненулевого
 Тест 3: Сложение ненулевого списка и нулевого
 Тест 4: Сложение двух ненулевых списков разной размерности
 Тест 5: Сложение противоположных по знаку списков
 */

void run_list_unit_4(){
    cout<<"[LIST CLASS TESTING] UNIT 4 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<int> lst1;
        List<int> lst2;
        
        lst1.sum_with(&lst2);
        
        if (lst1.get_length() == 0) test_ok = true;
        
        test_result(test_ok);
    }
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst1;
        List<double> lst2;
        lst2.push(5.6);
        lst2.push(3.1);
        
        lst1.sum_with(&lst2);
        
        if (lst1.get_length() == 2)
            if (lst1[0] == 5.6)
                if (lst1[1] == 3.1) test_ok = true;
        
        test_result(test_ok);
    }
    
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<Complex> lst1;
        List<Complex> lst2;
        lst1.push(Complex(5, 6));
        lst1.push(Complex(3, 1));
        
        lst1.sum_with(&lst2);
        
        if (lst1.get_length() == 2)
            if (lst1[0] == Complex(5, 6))
                if (lst1[1] == Complex(3, 1)) test_ok = true;
        
        test_result(test_ok);
    }
    
    //    TEСТ 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst1;
        lst1.push(1);
        lst1.push(2);
        lst1.push(3);
        lst1.push(4);
        lst1.push(5);
        
        List<double> lst2;
        lst2.push(2);
        lst2.push(3);
        
        lst1.sum_with(&lst2);
        
        if (lst1.get_length() == 5)
            if (lst1[0] == 3)
                if (lst1[1] == 5)
                    if (lst1[2] == 3)
                        if (lst1[3] == 4)
                            if (lst1[4] == 5) test_ok = true;
        
        test_result(test_ok);
    }
    
    //    TEСТ 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        List<double> lst1;
        lst1.push(1);
        lst1.push(2);
        lst1.push(3);
        lst1.push(4);
        lst1.push(5);
        
        List<double> lst2;
        lst2.push(-1);
        lst2.push(-2);
        lst2.push(-3);
        lst2.push(-4);
        lst2.push(-5);
        
        lst1.sum_with(&lst2);
        
        if (lst1.get_length() == 0) test_ok = true;
        
        test_result(test_ok);
    }

    if (test_id == 5 && test_ok == true) {
        cout<<"\n[TESTING] Unit 4 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 4 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
