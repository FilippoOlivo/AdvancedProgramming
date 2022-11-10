#include "CShape.hpp"

class CTriangle: public CShape{
    public:

    CTriangle(const Vectice<T> *v){
        for(int i = 0;i<n;i++){
            coords[i] = v[i];
        }
    }
}