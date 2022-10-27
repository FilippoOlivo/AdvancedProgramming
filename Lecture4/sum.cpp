//Write a function that can sum an arbitrary number of arguments using variadic templates.
#include <iostream>
template <typename T>
void sum(double& s, const T& a ){
    s = s + a;
    return;
}


template <typename T, typename... Types >
void sum(double& s, const T& a, const Types&... args  ){
    s = s + a;
    sum(s , args...);
    return;
}

int main(){
    double s = 0;
    sum(s,1,2,3,4,5,6,7,8,9);
    std::cout<<s<<std::endl;
    return 0;
}