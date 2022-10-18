#include <iostream>
#include "header.hpp"

int main (){
    CCoeffs coeffs;
    coeffs.ask_for_input();
    coeffs.print();
    solve_quadratic_equation(coeffs);
}
