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
        if(im == 0){
            std::cout<<real<<std::endl;
            return;
        }
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

    double get_real(){
        return real;
    }
    double get_im(){
        return im;
    }
};


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

class CQuadratic_Equation{
    CComplex x1;
    CComplex x2;
public:
    CCoeffs coeffs; //need to be here for the calls eq.coeffs.ask_for_input(); and eq.coeffs.print();


    void solve(){
        double a = coeffs.get_a();
        double b = coeffs.get_b();
        double c = coeffs.get_c();
        if(a==0){
        exit(1);
        }
        double delta = b*b - 4*a*c;
        double inv2a = 1/(2*a);
        if(delta>=0){
                double x1r = (-b + std::sqrt(delta))*inv2a;
                double x2r = (-b - std::sqrt(delta))*inv2a;
                x1.set_value(x1r,0);
                x2.set_value(x2r,0);
        }
        else {
            double real = -b/inv2a;
            double imaginry = std::sqrt(-delta)/inv2a;
            x1.set_value(real,imaginry);
            x2.set_value(real,-imaginry);
        }
    }

    void print_solutions(){
        if(x1.get_real()==x2.get_real() && x1.get_im() == x2.get_im()){
            std::cout<<"The equation has only one solution x = ";
            x1.print();
            return;
        }
        std::cout<<"The equation has two solutions:"<<std::endl<<"x1 = ";
        x1.print();
        std::cout<<"x2 = ";
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

