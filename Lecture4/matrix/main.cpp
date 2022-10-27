#include "matrix.hpp"

int main()
{
    CSquareMatrix<double,9> a ;
    a.read_from_file("A.txt");
    a.print();
    CSquareMatrix<double,9> b;
    b.read_from_file("B.txt");
    b.print();
    CSquareMatrix<double,9> c = a*b;
    c.print();

    
}