#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <memory>

template <typename T, int S>
class CSquareMatrix{
public:
    int n;
    int size;
    std::unique_ptr<T[]> mat;

    CSquareMatrix(){
        mat = std::make_unique<T[]>(S);;
        size = S;
        n = std::sqrt(S);
    }

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
