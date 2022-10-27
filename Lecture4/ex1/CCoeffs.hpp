#include <iostream>
#include <cmath>

template <typename T> 
class CCoeffs{
    T a;
    T b;
    T c;
public:
    CCoeffs(){
        a = 0;b = 0;c = 0;
    }
    CCoeffs(T ai, T bi, T ci):a(ai),b(bi),c(ci){}
    void ask_for_input(){
        std::cout<<"Inser the 3 coeffs one at the time and press enter after each number"<<std::endl;
        std::cin>>a>>b>>c;
        return;
    }
    void read_from_file(){
        std::ifstream rfile("coeff.txt");
        rfile>>a>>b>>c;
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

    void write_solution_on_file(){
    std::ofstream wfile("result.txt",std::ios_base::app);
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
    }
};
