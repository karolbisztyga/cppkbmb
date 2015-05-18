#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H

#include <ostream>

class aghComplex {
public:
    aghComplex();
    aghComplex(double,double);
    ~aghComplex();

    aghComplex operator+(aghComplex);
    bool operator==(aghComplex);
    bool operator!=(aghComplex);
    aghComplex operator*(aghComplex);

    friend std::ostream& operator<<(std::ostream&,aghComplex&);
    
    void show();
    
private:
    double a,b;
};

#endif