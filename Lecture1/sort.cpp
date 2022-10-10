#include <iostream>

int main(){
    std::cout<<"Inser the number of entries in the array: "<<std::endl;
    int n{7};
    int array[7];
    std::cout<<"Insert 7 integer numbers. After entering each number press enter"<<std::endl;
    for(int i{0};i<n;i++){
        std::cin>>array[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp{array[i]};
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for(int i = 0;i<n;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}