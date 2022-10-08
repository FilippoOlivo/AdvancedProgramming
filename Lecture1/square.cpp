#include <iostream>
#include <cmath>
struct CCoefs{
    double a;
    double b;
    double c; 
};
int main(){
    CCoefs x;
    std::cout<<"Type the coeff a,b,c separated by a space"<<std::endl;
    std::cin>>x.a;
    std::cin>>x.b;
    std::cin>>x.c;
    if(x.a==0){
        exit(1);
    }
    double delta = x.b*x.b - 4*x.a*x.c;
    double inv2a = 1/(2*x.a);
    std::cout<<delta<<std::endl;
    if(delta>=0){
        double sol1 = (-x.b + std::sqrt(delta))*inv2a;
        double sol2 = (-x.b - std::sqrt(delta))*inv2a;
        std::cout<<"Solutions 1 = "<<sol1<<"Solution 2 = "<<sol2<<std::endl;
    }
    else {
        double real = -x.b/inv2a;
        double imaginry = std::sqrt(-delta)/inv2a;
        std::cout<<"Solution 1 = "<<real<<"+"<<imaginry<<"i,"<<"Solution 2 = "<<real<<"-"<<imaginry<<"i"<<std::endl;
    }
}
