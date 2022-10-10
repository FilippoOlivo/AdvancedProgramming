#include <iostream>
#include <cmath>
#include <unistd.h>

/*
Find a root of equation x^3-6x^2+11x-6=0 at the interval [-10,10] by the following method:

    check the signs of the function at the borders of the interval and its middle
    modify the interval such that the function has different signs at borders (middle becomes one of the new borders)
    repeat until the interval is smaller than 10^(-9)
*/

struct Interval{
    double upper;
    double lower;
    double avg;
    double ev_upper;
    double ev_lower;
};

double evaluate_function(double x){

    return(x*x*x-6*x*x+11*x-6);

};

int main(){
    const double ref{1e-9};
    Interval v; 
    v.upper = 10; 
    v.lower = -10; 
    v.avg = (v.lower+v.upper)/2;
    double fl = evaluate_function(v.lower);
    double fu = evaluate_function(v.upper);
    if(fl*fu>0){
        std::cout<<"Error: can't find a 0 in the interval [-10;10]"<<std::endl;
        exit(1);
    }
    while(std::fabs(v.upper-v.lower)>ref){
        v.ev_upper = evaluate_function(v.upper);
        v.ev_lower = evaluate_function(v.lower);
        if(std::fabs(v.ev_upper)<ref){
            v.avg = v.upper;
            break;
        }
        if(std::fabs(v.ev_lower)<ref){
            v.avg = v.lower;
            break;
        }
        if(evaluate_function(v.avg)*v.ev_lower<0){
            v.upper = v.avg;
        } else{
            v.lower = v.avg;
        }
        v.avg = (v.upper+v.lower)/2;
    }
    std::cout<<"A root for the equarion x^3-6x^2+11x-6 is close to x =  "<<v.avg<<std::endl;
}
