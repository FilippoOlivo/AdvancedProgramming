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
    int size{10};
    std::cout<<"Insert "<<size<<" numbers. After each number inserted press enter"<<std::endl;
    //allocate memory for the array. *arr is a pointer to the array
    int *arr = (int*)malloc(size*sizeof(int));
    for(int i = 0;i<size;i++){
        //Initialize the values of the array. At every step I write the inserted value on memory cell indentified by value arr+i
        std::cin>>*(arr+i);
    }
    recursive_print(arr,0,size);
}