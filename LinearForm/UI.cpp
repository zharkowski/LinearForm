#include "UI.hpp"

using namespace std;

int cin_int(){
    int N;
    while (true) {
        cout<<flush;//очистка потока
        if ((cin >> N).good()) return N;
        if (cin.fail()) {
            cin.clear();//очищает флаг ошибки, но часть введенной строки при этом остается
            cout << "Invalid input.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропустить все символы в потоке до \n, после этого можно начинать считывать новое значение
    }
}

double cin_double(){
    double N;
    while (true) {
        cout<<flush;//очистка потока
        if ((cin >> N).good()) return N;
        if (cin.fail()) {
            cin.clear();//очищает флаг ошибки, но часть введенной строки при этом остается
            cout << "Invalid input.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропустить все символы в потоке до \n, после этого можно начинать считывать новое значение
    }
}

void run_UI(){
    List<double> db_lform;
    List<Complex> com_lform;
    int dim = 0;
    int type = 0;
    
    int menu_item = 0;
    while (menu_item != 7){
        cout<<"\nPress\n";
        cout<<" 1. to create new linear form\n";
        cout<<" 2. to add form with another form\n";
        cout<<" 3. to multiply by the number\n";
        cout<<" 4. to calculate value\n";
        cout<<" 5. to show current linear form\n";
        cout<<" 6. to run tests\n";
        cout<<" 7. to exit\n";
        menu_item = cin_int();
        switch (menu_item) {
            case 1:     //создание линейной формы
            {
                cout<<endl<<"Select type of linear form:\n";
                cout<<" 1. Real\n";
                cout<<" 2. Complex\n";
                
                type = cin_int();
                
                while (type != DOUBLE && type != COMPLEX){
                    cout<<endl<<"Incorrect type."<<endl;
                    cout<<endl<<"Select type of linear form:\n";
                    cout<<" 1. Real\n";
                    cout<<" 2. Complex\n";
                
                    type = cin_int();
                }
                
                if (type == DOUBLE) {
                    db_lform = List<double>();
                }
                else {
                    com_lform = List<Complex>();
                }
                cout<<endl<<"Enter number of dimention:\n";
                dim = cin_int();
                
                while (dim < 0) {
                    cout<<endl<<"Incorrect number."<<endl;
                    cout<<endl<<"Enter number of dimention:\n";
                    dim = cin_int();
                }
                if (type == DOUBLE){
                    for (int i = 0; i <= dim; i++) {
                        double a = 0;
                        cout<<"\nEnter a"<<i<<":\n";
                        a = cin_double();
                        db_lform.push(a);
                    }
                    db_lform.print();
                }
                
                if (type == COMPLEX){
                    for (int i = 0; i <= dim; i++) {
                        double a_re = 0;
                        double a_im = 0;
                        cout<<"\nEnter real part of a"<<i<<":\n";
                        a_re = cin_double();
                        cout<<"\nEnter imaginary part of a"<<i<<":\n";
                        a_im = cin_double();
                        com_lform.push(Complex(a_re, a_im));
                    }
                    com_lform.print();
                }
                
            }
                break;
                
            case 2:     //сложение двух динейных форм
            {
                if (type == 0) {
                    cout<<"\nThe first linear form doesn't exist.\n\n";
                    break;
                }
                
                if (type == DOUBLE) {
                    List<double> sec_lform = List<double>();
                    int sec_dim = 0;
                    cout<<endl<<"Enter number of dimention of the second linear form:\n";
                    sec_dim = cin_int();
                    
                    while (sec_dim < 0) {
                        cout<<endl<<"Incorrect number."<<endl;
                        cout<<endl<<"Enter number of dimention:\n";
                        sec_dim = cin_int();
                    }
                    
                    for (int i = 0; i <= dim; i++) {
                        double a = 0;
                        cout<<"\nEnter a"<<i<<":\n";
                        a = cin_double();
                        sec_lform.push(a);
                    }
                    
                    db_lform.sum_with(&sec_lform);
                    db_lform.print();
                }
                
                if (type == COMPLEX){
                    List<Complex> sec_lform = List<Complex>();
                    int sec_dim = 0;
                    cout<<endl<<"Enter number of dimention of the second linear form:\n";
                    sec_dim = cin_int();
                    
                    while (sec_dim < 0) {
                        cout<<endl<<"Incorrect number."<<endl;
                        cout<<endl<<"Enter number of dimention:\n";
                        sec_dim = cin_int();
                    }
                    
                    for (int i = 0; i <= dim; i++) {
                        double a_re = 0;
                        double a_im = 0;
                        cout<<"\nEnter real part of a"<<i<<":\n";
                        a_re = cin_double();
                        cout<<"\nEnter imaginary part of a"<<i<<":\n";
                        a_im = cin_double();
                        sec_lform.push(Complex(a_re, a_im));
                    }
                    
                    com_lform.sum_with(&sec_lform);
                    com_lform.print();
                }
            }
                break;
                
            case 3:     //умножение линейной формы на константу
            {
                if (type == 0) {
                    cout<<"\nThe first linear form doesn't exist.\n\n";
                    break;
                }
                
                if (type == DOUBLE) {
                    double cnst = 1;
                    cout<<"\nEnter real constant:\n";
                    cnst = cin_double();
                    db_lform.multiply_by(cnst);
                    db_lform.print();
                }
                
                if (type == COMPLEX){
                    double cnst_re = 1;
                    double cnst_im = 0;
                    cout<<"\nEnter complex constant:\n";
                    cout<<" Enter the real part:\n";
                    cnst_re = cin_double();
                    cout<<" Enter the imaginary part:\n";
                    cnst_im = cin_double();
                    com_lform.multiply_by(Complex(cnst_re, cnst_im));
                    com_lform.print();
                }
            }
                break;
                
            case 4:     //вычисление значения линейной формы при известных аргументах
            {
                if (type == 0) {
                    cout<<"\nThe first linear form doesn't exist.\n\n";
                    break;
                }
                
                if (type == DOUBLE){
                    double val = 0;
                    List<double> x_list = List<double>();
                    for (int i = 1; i <= dim; i++){
                        double x = 0;
                        cout<<"\nEnter x"<<i<<":\n";
                        x = cin_double();
                        x_list.push(x);
                    }
                    
                    val = db_lform.calculate_value(x_list);
                    cout<<"Value = "<<val;
                }
                
                if (type == COMPLEX){
                    Complex val = 0;
                    List<Complex> x_list = List<Complex>();
                    for (int i = 1; i <= dim; i++){
                        double x_re = 0;
                        double x_im = 0;
                        cout<<"\nEnter real part of x"<<i<<":\n";
                        x_re = cin_double();
                        cout<<"\nEnter imaginary part of x"<<i<<":\n";
                        x_im = cin_double();
                        x_list.push(Complex(x_re, x_im));
                    }
                    
                    val = com_lform.calculate_value(x_list);
                    cout<<"Value = "<<val;
                }
            }
                break;
                
            case 5:     //вывести текущую линейну форму в консоль
            {
                if (type == DOUBLE) db_lform.print();
                if (type == COMPLEX) com_lform.print();
            }
                break;
                
            case 6:     //запустить тесты
            {
                run_all_tests();
            }
                break;
                
            case 7:     //выйти их программы
                break;
                
            default:
                cout<<"Invalid command\n\n";
                break;
        }
    }
}
