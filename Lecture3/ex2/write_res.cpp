#include "header.hpp"

void write_solution_on_file(CCoeffs x){
    std::ofstream wfile("result.txt",std::ios_base::app);
    double a = x.get_a();
    double b = x.get_b();
    double c = x.get_c();
    wfile<<a<<"x^2 + "<<b<<"x + "<<c;
    if(a==0){
        exit(1);
    }
    double delta = b*b - 4*a*c;
    double inv2a = 1/(2*a);
    if(delta>=0){
        double sol1 = (-b + std::sqrt(delta))*inv2a;
        double sol2 = (-b - std::sqrt(delta))*inv2a;
        if(delta == 0){
            wfile<<" --> x = "<<sol1<<std::endl;
            return;
        }
        wfile<<" --> x1 = "<<sol1<<", x2 = "<<sol2<<std::endl;
    }
    else {
        double real = -b/inv2a;
        double imaginry = std::sqrt(-delta)/inv2a;
        wfile<<" --> x1 = "<<real<<"+"<<imaginry<<"i,"<<", x2 = "<<real<<"-"<<imaginry<<"i"<<std::endl;
    }
    wfile.close();
};