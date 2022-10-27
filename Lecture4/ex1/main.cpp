#include <iostream>
#include "header.hpp"


int main (){
    CCoeffs<int> coeffs;
    coeffs.read_from_file();
    coeffs.print();
    coeffs.write_solution_on_file();
}
