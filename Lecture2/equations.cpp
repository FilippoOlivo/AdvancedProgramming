#include <iostream>
#include <cmath>
class CComplex{
    double im;
    double real;
public:
    CComplex (double i, double r):im(i),real(r){}
    CComplex(){
        im = 0;
        real = 0;
    }
    void print(){
        if(im<0){
            std::cout<<real<<im<<"i"<<std::endl;
            return;
        }
        std::cout<<real<<"+"<<im<<"i"<<std::endl;
    }
    void set_value(double r, double i){
        real = r;
        im = i;
        return;
    }
};


class CCoeffs{
public:
    double a;
    double b;
    double c;

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


};

class CQuadratic_Equation{
public:
    CComplex x1;
    CComplex x2;
    CCoeffs coeffs;

    void solve(){
        if(coeffs.a==0){
        exit(1);
        }
        double delta = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;
        double inv2a = 1/(2*coeffs.a);
        if(delta>=0){
                double x1r = (-coeffs.b + std::sqrt(delta))*inv2a;
                double x2r = (-coeffs.b - std::sqrt(delta))*inv2a;
                x1.set_value(x1r,0);
                x2.set_value(x2r,0);
        }
        else {
            double real = -coeffs.b/inv2a;
            double imaginry = std::sqrt(-delta)/inv2a;
            x1.set_value(real,imaginry);
            x2.set_value(real,-imaginry);
        }
    }

    void print_solutions(){
        x1.print();
        x2.print();
        return;
    }
};

int main(){
    CQuadratic_Equation eq;
    eq.coeffs.ask_for_input();
    eq.coeffs.print();
    eq.solve();
    eq.print_solutions();
}

