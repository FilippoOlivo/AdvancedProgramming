#include <iostream>

class CComplex{
    double r;
    double i;
public:
    CComplex(){
    }
    CComplex(double re, double im){
        r = re;
        i = im;
    }

    CComplex operator+(const CComplex& b);
    CComplex operator-(const CComplex& b);
    CComplex operator*(const CComplex& b);
    friend std::ostream& operator<<(std::ostream& os, const CComplex c);

    void print(){
        if(i == 0){
            std::cout<<r<<std::endl;
            return;
        }
        if(i<0){
            std::cout<<r<<i<<"i"<<std::endl;
            return;
        }
        std::cout<<r<<"+"<<i<<"i"<<std::endl;
    }
};

CComplex CComplex::operator+(const CComplex& b){
    CComplex res(0,0);
    res.r = b.r+r;
    res.i = b.i+i;
    return res;
};

CComplex CComplex::operator-(const CComplex& b){
    CComplex res(0,0);
    res.r = r-b.r;
    res.i = i-b.i;
    return res;
};


std::ostream& operator<<(std::ostream& os, const CComplex c){
    if(c.i>0){
        os<<c.r<<"+"<<c.i<<"i";
    } else if(c.i<0){
         os<<c.r<<"-"<<c.i<<"i";
    }
    else {
        os<<c.r;
    }
    return os;
};

CComplex CComplex::operator*(const CComplex& b){
    CComplex res(0,0);
    res.r = r*b.r-i*b.i;
    res.i = r*b.i+i*b.r;
    return res;
};


int main(){
    CComplex a(1,1);
    CComplex b(2,2);
    CComplex c = a+b;
    std::cout<<c<<std::endl;
    CComplex d = a-b;
}