#include "CShape.hpp"
#include <iostream>


int main(){
    int n = 5;
    Vectice<double> v[n];
    v[0].x = 0; v[0].y = 3;
    v[1].x = 3; v[1].y = 6;
    v[2].x = 6; v[2].y = 6;
    v[3].x = 5; v[3]. y = 4; 
    v[3].x = 0; v[3]. y = 3; 
    CPolygon<double> test(n,v,0);
    CShape<double>* test2 = &test;
    std::cout<<"print test"<<std::endl;
    test.print();
    std::cout<<test.get_perimeter()<<std::endl;
    std::cout<<"print test2"<<std::endl;
    (*test2).print();
    std::cout<<(*test2).get_perimeter()<<std::endl;
    return 0;
}
