#include "header.hpp"

void solve_quadratic_equation(CCoeffs x){
    double a = x.get_a();
    double b = x.get_b();
    double c = x.get_c();
    if(a==0){
        exit(1);
    }
    double delta = b*b - 4*a*c;
    double inv2a = 1/(2*a);
    if(delta>=0){
        double sol1 = (-b + std::sqrt(delta))*inv2a;
        double sol2 = (-b - std::sqrt(delta))*inv2a;
        if(delta == 0){
            std::cout<<"The single solution is x = "<<sol1<<std::endl;
            return;
        }
        std::cout<<"The solutions are x1 = "<<sol1<<", x2 = "<<sol2<<std::endl;
    }
    else {
        double real = -b/inv2a;
        double imaginry = std::sqrt(-delta)/inv2a;
        std::cout<<"The solutions are x1 = "<<real<<"+"<<imaginry<<"i,"<<", x2 = "<<real<<"-"<<imaginry<<"i"<<std::endl;
    }
};