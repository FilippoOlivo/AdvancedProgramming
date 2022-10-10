#include <iostream>
#include <cmath>

/*
1.  Add a contructor to your class of coefficients to initialize them all to zero. 
2.  Add a class member function that prints the coefficients. 
3.  Add a class member function that asks the user to input the coefficients. 
4.  Write a function that takes a variable of your coefficient class as input and solves the equation (this function should also print solutions).
*/

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

void solve_quadratic_equation(CCoeffs x){
    if(x.a==0){
        exit(1);
    }
    double delta = x.b*x.b - 4*x.a*x.c;
    double inv2a = 1/(2*x.a);
    if(delta>=0){
        double sol1 = (-x.b + std::sqrt(delta))*inv2a;
        double sol2 = (-x.b - std::sqrt(delta))*inv2a;
        if(delta == 0){
            std::cout<<"The single solution is x = "<<sol1<<std::endl;
            return;
        }
        std::cout<<"The solutions are x1 = "<<sol1<<", x2 = "<<sol2<<std::endl;
    }
    else {
        double real = -x.b/inv2a;
        double imaginry = std::sqrt(-delta)/inv2a;
        std::cout<<"The solutions are x1 = "<<real<<"+"<<imaginry<<"i,"<<", x2 = "<<real<<"-"<<imaginry<<"i"<<std::endl;
    }
}

int main (){
    CCoeffs coeffs;
    coeffs.ask_for_input();
    coeffs.print();
    solve_quadratic_equation(coeffs);
}