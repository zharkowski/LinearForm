#include "complex.hpp"

using namespace std;

Complex::Complex(double r, double i){
    re = r;
    im = i;
}

Complex::Complex(double r){
    re = r;
    im = 0;
}

Complex::Complex(){
    re = 0;
    im = 0;
}

Complex::~Complex(){}

double Complex::return_re(){
    return this->re;
}

double Complex::return_im(){
    return this->im;
}

Complex Complex::operator+ (Complex com){
    return Complex(this->re + com.re, this->im + com.im);
}

Complex Complex::operator+= (Complex com){
    return Complex(this->re = this->re + com.re,this->im = this->im + com.im);
}

Complex Complex::operator*(Complex com){
    return Complex(this->re * com.re - this->im * com.im, this->re * com.im + this->im * com.re);
}

Complex Complex::operator+ (double db){
    return Complex(this->re + db, this->im);
}

Complex Complex::operator+= (double db){
    return Complex(this->re = this->re + db, this->im);
}

Complex Complex::operator* (double db){
    return Complex(this->re * db, this->im * db);
}

Complex Complex::operator*= (double db){
    return Complex(this->re = this->re * db,this->im =  this->im * db);
}

bool Complex::operator==(Complex com){
    return this->re == com.re && this->im == com.im;
}

bool Complex::operator!=(Complex com){
    return this->re != com.re || this->im != com.im;
}

bool Complex::operator==(double db){
    return this->re == db && this->im == 0;
}

bool Complex::operator!=(double db){
    return this->re != db || this->im != 0;
}

bool Complex::operator< (Complex com){
    if (this->re < com.re || (this->re == com.re && this->im < com.im)) return true;
    else return false;
}

bool Complex::operator<= (Complex com){
    if (this->re <= com.re || (this->re == com.re && this->im <= com.im)) return true;
    else return false;
}

bool Complex::operator> (Complex com){
    if (!(this->re <= com.re || (this->re == com.re && this->im <= com.im))) return true;
    else return false;
}

bool Complex::operator>= (Complex com){
    if (!(this->re < com.re || (this->re == com.re && this->im < com.im))) return true;
    else return false;
}

void Complex::print(){
    if (this->im >= 0)  cout<<this->re<<" + "<<this->im<<"i\n";
    else cout<<this->re<<" - "<<-(this->im)<<"i\n";
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
    if (c.im == 0) os<<"("<<c.re<<" ";
    else os<<"("<<c.re<<(c.im > 0 ? "+" : "-")<<abs(c.im)<<"i)";
    return os;
}
