#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

template <typename T, int S>
class CSquareMatrix{
public:
    int n;
    int size;
    T* mat;

    CSquareMatrix(){
        mat = new T[S];
        size = S;
        n = std::sqrt(S);
    }

    ~CSquareMatrix(){
        std::cout<<"Destructor is called"<<std::endl;
        delete[] mat;
        mat = nullptr;
        size = 0;
        n = 0;
    } //Destructor

    CSquareMatrix<T,S>& operator=(const CSquareMatrix<T,S>& p){
        std::cout<<"assignment operator called"<<std::endl;
        if(this != &p){
            size = p.size;
            n = p.n;
            if(mat != nullptr){
                delete[] mat;
                mat = nullptr;
            }

            if(p.mat ==nullptr)
            {
                mat = nullptr;
            }
            else
            {
                mat = mat = new T[S];
                for(int i = 0; i<size;i++){
                    mat[i] = p.mat[i];
                }
            }
        }
        return *this;
    } //assignment operator

    CSquareMatrix<T,S> (const CSquareMatrix<T,S>& p){
        std::cout<<"copy constructor called"<<std::endl;
        if(this != &p){
            size = p.size;
            n = p.n;
            if(mat == nullptr){
                mat = nullptr;
            }
            else{
                mat = new T[S];
                for(int i = 0; i<S;i++){
                    mat[i] = p.mat[i];
                }
            }
        }
    } //copy costructor
    

    /*CSquareMatrix<T,S> (const CSquareMatrix<T,S> &p){
        std::cout<<"move constructor called"<<std::endl;
        if(this != &p){
            size = p.size;
            p.size = 0;
            mat = p.mat;
            p.mat = nullptr;
        }
    }*/



    void read_from_file(const char *path)
    {
        std::ifstream file(path);
        for(int i = 0; i<size;i++){
            file >> mat[i];
        }
    }
    void print(){
        for(int i = 0 ;i<size;i++){
            if(i%n==0){
                std::cout<<std::endl;
            }
            std::cout<<mat[i]<<" ";

        }
        std::cout<<std::endl;
    }

    T get_single_value(const int i, const int j){
        //std::cout<<(mat[(i-1)*n+j-1])<<std::endl;
        return mat[(i-1)*n+j-1];
    }
    CSquareMatrix<T,S> operator*(const CSquareMatrix<T,S>& b);
};


template <typename T,int S>
CSquareMatrix<T,S> CSquareMatrix<T,S>::operator*(const CSquareMatrix<T,S>& b){
    CSquareMatrix<T,S> res;
    for(int h = 0; h<S;h++)
        res.mat[h] = 100;
    int n = res.n;
    for (int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) {
            res.mat[(i-1)*n+j-1]=0;
            for(int k=1;k<=n;k++)    
                res.mat[(i-1)*n+j-1]=res.mat[(i-1)*n+j-1]+mat[(i-1)*n+k-1]*b.mat[(k-1)*n+j-1];
    }
    return res;
}
