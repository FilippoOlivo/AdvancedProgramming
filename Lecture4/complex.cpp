#include <iostream>
template <typename T>
class CComplex{
    T r;
    T i;
public:
    CComplex(){
    }
    CComplex(const T& re, const T& im){
        r = re;
        i = im;
    }

    CComplex operator+(const CComplex& b);
    CComplex operator-(const CComplex& b);
    CComplex operator*(const CComplex& b);
    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const CComplex<O> c);

    void print(){
        if(i == 0){
            std::cout<<r<<std::endl;
            return;
        }
        if(i<0){
            std::cout<<r<<i<<"i"<<std::endl;
            return;
        }
        std::cout<<r<<"+"<<i<<"i"<<std::endl;
    }
};

template <typename T>
CComplex<T> CComplex<T>::operator+(const CComplex<T>& b){
    CComplex<T> res(0,0);
    res.r = b.r+r;
    res.i = b.i+i;
    return res;
};

template <typename T>
CComplex<T> CComplex<T>::operator-(const CComplex<T>& b){
    CComplex<T> res(0,0);
    res.r = r-b.r;
    res.i = i-b.i;
    return res;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const CComplex<T> c){
    if(c.i>0){
        os<<c.r<<"+"<<c.i<<"i";
    } else if(c.i<0){
         os<<c.r<<"-"<<c.i<<"i";
    }
    else {
        os<<c.r;
    }
    return os;
};

template <typename T>
CComplex<T> CComplex<T>::operator*(const CComplex<T>& b){
    CComplex<T> res(0,0);
    res.r = r*b.r-i*b.i;
    res.i = r*b.i+i*b.r;
    return res;
};


int main(){
    CComplex<int> a(1,1);
    CComplex<int> b(2,2);
    CComplex<int> c = a+b;
    std::cout<<c<<std::endl;
    CComplex<int> d = a-b;
}