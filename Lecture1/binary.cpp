#include <iostream>

//Excercise 2
//Write a program to convert integers to a binary system

int main(){
    int n{123456};
    int binary[64]; 
    int counter{0};
    int r{0};
    while(n!=0){
        r = n%2;
        n = n/2;
        binary[counter] = r;
        counter++;
    }
    for(int i{counter-1};i>=0;i--){
        std::cout<<binary[i];
    }
    std::cout<<std::endl;
    return 0;
}
