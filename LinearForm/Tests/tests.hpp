#ifndef tests_hpp
#define tests_hpp

#include <stdio.h>
#include <iostream>
#include "Complex Tests/complex_unit_1.hpp"
#include "Complex Tests/complex_unit_2.hpp"
#include "Complex Tests/complex_unit_3.hpp"
#include "List Tests/list_unit_1.hpp"
#include "List Tests/list_unit_2.hpp"
#include "List Tests/list_unit_3.hpp"
#include "List Tests/list_unit_4.hpp"
#include "List Tests/list_unit_5.hpp"
#include "List Tests/list_unit_6.hpp"

using namespace std;

void run_all_tests();
void run_complex_tests();
void run_linearForm_test();
void run_list_tests();
void test_prepare(int *test_id, bool *test_ok);
void test_result(bool test_ok);

#endif /* tests_hpp */
