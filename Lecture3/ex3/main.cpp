#include <iostream>
#include "header.hpp"

int main (){
    CCoeffs coeffs;
    coeffs.read_from_file();
    coeffs.print();
    write_solution_on_file(coeffs);
}
