#include <iostream>

/*
Write a recursive function to print an array.
*/

void recursive_print(int *array, int pos, int size){
    if(pos == size){
        std::cout<<std::endl;
        return;
    }
    std::cout<<*(array+pos)<<" ";
    return recursive_print(array,pos+1,size);
}


int main(){
    std::cout<<"Insert 10 numbers. After each number inserted press enter"<<std::endl;
    //allocate memory for the array. *arr is a pointer to the array
    int* arr = (int*)malloc(10*sizeof(int));
    for(int i = 0;i<10;i++){
        //Initialize the values of the array. At every step I write the inserted value on memory cell indentified by value arr+i
        std::cin>>*(arr+i);
    }
    int size{sizeof(arr)};
    recursive_print(arr,0,10);
}