#include "aghComplex.h"
#include <iostream>

using namespace std;

aghComplex::aghComplex() {
    this->a = 0;
    this->b = 0;
}

aghComplex::aghComplex(double a, double b) {
    this->a = a;
    this->b = b;
}

void aghComplex::show() {
    cout << this->a << " + " << this->b << "i" ;
}

aghComplex::~aghComplex() {
    
}

aghComplex aghComplex::operator+(aghComplex c) {
	return aghComplex(this->a+c.a,this->b+c.b);
}

bool aghComplex::operator==(aghComplex c) {
	return( this->a == c.a && this->b == c.b);
}

bool aghComplex::operator!=(aghComplex c) {
	return( this->a != c.a && this->b != c.b);
}

aghComplex aghComplex::operator*(aghComplex c) {
	return aghComplex(this->a*c.a-this->b*c.b,this->a*c.b+this->b*c.a);
}


std::ostream& operator<<(std::ostream &out,aghComplex &c) {
	out << c.a << "+" << c.b << "i";
	return out;
}