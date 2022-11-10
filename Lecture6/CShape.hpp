/*
Create an abstract base class "shape" and inherit classes triangle (should have 3 vectices member variables) 
and polygon from it(should have a raw pointer to vertices coordinates within to make life harder). 
The classes should have functions to calulate perimeter and to print vertice coordinates that work with runtime polymorhism.
*/
#include <iostream>
#include <cmath>

template <typename T>
struct Vectice{
    double x;
    double y;
} ;

template <typename T>
class CShape
{
public:
    Vectice<T>* coords;
    int num;

    CShape(int n, Vectice<T> *v){
        num = n;
        coords = new Vectice<T>[num];
        for(int i = 0; i<num; i++){
            coords[i] =  v[i];
        }
    }

    void print(){
        for(int i = 0; i<num; i++){
            std::cout<<"x = "<<(*(coords+i)).x<<"y = "<<(*(coords+i)).y<<std::endl;
        }
        return;
    }

    void print_address(){
        for(int i = 0;i<num;i++){
            std::cout<<(coords+i)<<std::endl;
        }
    }

    CShape (const CShape<T> &p){
        if(this != &p){
            num = p.num;
            if(p.coords==nullptr){
                coords = nullptr;
                return;
            }
            coords = new Vectice<T>[num];
            for(int i = 0; i<num;i++){
                coords[i] = p.coords[i];
            }
        }
    }

    ~CShape(){
        std::cout<<"distructor is calles"<<std::endl;
        delete[] coords;
        coords = nullptr;
        num = 0;
    }

    virtual T get_perimeter() = 0;
};


template <typename T>
class CTriangle: public CShape<T>{
private: 
    double dist(int i, int j)
    {
        double x = (CShape<T>::coords[i].x-CShape<T>::coords[j].x)*(CShape<T>::coords[i].x-CShape<T>::coords[j].x);
        double y = (CShape<T>::coords[i].y-CShape<T>::coords[j].y)*(CShape<T>::coords[i].y-CShape<T>::coords[j].y);
        return std::sqrt(x+y);
    }
public:
    double perimeter;
    CTriangle(Vectice<T> *v, double a):CShape<T>(3,v){
    }

    double get_perimeter() override{
        perimeter = 0;
        for(int i = 0; i< CShape<T>::num ;i++){
            if(i == CShape<T>::num-1)
                perimeter += dist(i,0);
            else 
                perimeter += dist(i,i+1);
        }
        return perimeter;  
    }
};


template <typename T>
class CPolygon: public CShape<T>{
private: 
    double dist(int i, int j)
    {
        double x = (CShape<T>::coords[i].x-CShape<T>::coords[j].x)*(CShape<T>::coords[i].x-CShape<T>::coords[j].x);
        double y = (CShape<T>::coords[i].y-CShape<T>::coords[j].y)*(CShape<T>::coords[i].y-CShape<T>::coords[j].y);
        return std::sqrt(x+y);
    }
public:
    double perimeter;
    CPolygon(int n, Vectice<T> *v, double a):CShape<T>(n,v){
    }

    double get_perimeter() override{
        perimeter = 0;
        for(int i = 0; i< CShape<T>::num ;i++){
            if(i == CShape<T>::num-1)
                perimeter += dist(i,0);
            else 
                perimeter += dist(i,i+1);
        }
        return perimeter;  
    }
};

