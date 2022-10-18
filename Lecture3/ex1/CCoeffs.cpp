#include <iostream>
#include <cmath>

class CCoeffs{
    double a;
    double b;
    double c;
public:
    CCoeffs(){
        a = 0;b = 0;c = 0;
    }
    CCoeffs(double ai, double bi, double ci):a(ai),b(bi),c(ci){}
    void ask_for_input(){
        std::cout<<"Inser the 3 coeffs one at the time and press enter after each number"<<std::endl;
        std::cin>>a>>b>>c;
        return;
    }
    void print(){
        std::cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<std::endl;
        return;
    }
    double get_a(){
        return a;
    }
    double get_b(){
        return b;
    }
    double get_c(){
        return c;
    }
};
