# Lecture 5
# Templates
```cpp
int mysum(const int& a, const int& b){
    return a+b
}
'''
'''
int mysum(const double& a, const int& b){
    return a+b
}
'''
int mysum(const double& a, const double& b){
    return a+b
}
```
Does blocks of code perform the same operation (sum two numbers) with different type but it is still the same function. 
In C++ we have templates and so we don't have to do that. We can replace all the previous blocks of code with the block above:
```cpp
template <typename T>
T mySum(const T&a , const T&b){
    return a + b;
}
```
Instees typename we can write class. T is the name of the template.
We can write a generic function that can print all the types of variable:
```cpp
template <typename T>
void print(const T&x){
    std::cout<<x<<std::endl;
}
```
We can also use a function with more than one templated variable as below  (we have to list the variable separated by a ','):
```cpp
template <typename T1, typename T2>
void weird_function(T1& a, T2& b){
    a = a+1;
    b = b+1;
}
```
To call a function with a templated variable we have to write the following code:
```cpp
...
int a{5};
print(a);
...
```
and the compiler understand that we want to use the type 'int'. The compiler so will create a function for the variable type.
If I want to be sure I can instanciate manually the type that I want for my function

```cpp
...
print<int>(a)
...
```
If I have a function with two parameter templated is better to specify the types:
```cpp
...
auto c = mySum<double>(a,b);
...
```
Problem when I do program structure (use header file and program file). I can write a file named "function.hpp" where I define all my functions:
```cpp
#pragma once

template <typename T>
void print(const T&x){
    std::cout<<x<<std::endl;

template <typename T>
T mySum(const T&a , const T&b){
    return a + b;
```
```cpp
#include "function.hpp"

int main(){
    int a{8};
    double b{9.7};
    print<int>(b)
}
```
If I try to compile the file main.cpp (with the make file) the compile will complain because it tries to compile before the function (and he want to create some object) but it doesn't know the type of the templated variable. 
So we have to declare whitch type we will use in the program:
```cpp
...
template int sum<int>(const int&, const &int);
template double sum(const double&, const double&);
template void print(const int&)
template void weird_function(int&, double&)
...
```
Template every thing and put everything in .hpp file; that make more easier the things.

## Class templates 
I can create a class and said that the type of the variable inside the class are of type T.
```cpp
template CMyClass{
public:
    T field1;
    T field2;
    CMyClass(const T& a, const T& b);
    //A function inside the class that is templated with something else
    template <typename M>
    void print_extra(const M& val);
}
```
To write the full definition of the function:
```cpp
template<typename T>
CMyClass<T>::CMyClass (const T& a, const T& b){
    field1 = a;
    field2 = b;
}
```
```cpp
template<typename T>
template<typename M>
void CMyClass<T>::print_extra (const T& a, const T& b){
    std::cout<<field1<<" "<<field2<<" "<<val<<std::endl;
}
```
To create an istance of the class and to call a function inside the class I have to write the following code:
```cpp
int main(){
    CMyClass<int> var(7,8);
    var.print_extra(9.1);
}
```
We can template also numbers (only mathematical integer numbers that could be int, short int, long int, ...) as follow:
```cpp
template<typename T, short int N>
void add_number(T& var){
    var = var + N;
}

int main(){
    double b{4.7};
    add_number<double,7>(b);
    std::cout<<b<<std::endl;
    return 0;
}
```
## Variadic template

Used to work with many arguments. Example: print many parameters in a recursive way. I define a print funcion. We define the template Types with the variadic template (typename... Types) that can store a variable number of arguments of a variable type

```cpp

template <typename T>
void myPrint(const &T arg){
    //when I have only one parameter of variable type this function was called
    std::cout<<arg<<std::endl;
}

//first value stored in T, others valued stored in Types (variadic variable) 
template <typename T, typename... Types> 
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPring(args...);
}
```
Following code to test the previuos functions:
```cpp
int main(){
    myPrint(1,2,3,4,4.2,"ciao");
    return 0;
}
```
## Specialize template
We want to do different things depending of the type of templated variable. I have to compare templated type with standard type with the following expression:

```cpp 
constexpr(std::is_same_v<int,T>)
```
What is inside constexpr() is evaluated at compile time. We need to put that because templated function must be evaluated at compiled time. Notice that constexpr has been introduced in C++17 so is mandatory to add -std=c++17 to compile the code (not enabled by default).
```cpp
template <typename T>
class CMyClass{
public:    
    void Function();
    
};


template <typename T>
void CMyClass<T>::Function()
{
    if constexpr(std::is_same_v<int,T>){
        std::cout<<"we are dealing with int"<<std::endl;
    }
    if constexpr(std::is_same_v<double,T>){
        std::cout<<"we are dealing with double"<<std::endl;
    }
    if constexpr(std::is_integral_v<T>){
        std::cout<<"something \"integer\" "<<std::endl;
    }else{
        std::cout<<"something non \"integer\" "<<std::endl;
    }
}
```
and afer a method to call create an instance of the class and test the method:
```cpp
int main()
{
    CMyClass<long long> var;
    var.Function();
}
```

# Vector
In C++ is a built type of array:
```cpp
#include <array>
...
std::array<int,5> arr;
...
```
We neet to specify the type. 
Difference between array and vector: size in array could be change and mustn't to be known at compilation time.
```cpp
#include <vector>
...
std::vector<int>  vec;
...
```
std::vector does all memory menagement (very easy). If a programmer want to forget about memory management he can use vector.
Problem: push_bach() is a function thant add element at the end of the vector
```cpp
int main(){
    
    std::array<int,5> arr;//need to specify the number of elements
    std::vector<int>  vec;
    vec.resize(5);
    //reserve memory
    vec.reserve(100000);//now you can do push_backs, but still better not
    
    vec.push_back(8);//avoid if you can in hpc!
    
```
When push_back the vector try to have more memory at the end (vector is contiguous). At the inizialization the vector allocate a small piece of memory. If we continuously use the push_back function and at one point there is no enought space near. The vector ask to reallocate the in another space of memory and copy all the values previously initialize. Is it better to resize the array at the beginning with all the mwmory that I expect to use.

Is important to pass the reference in the functions that use vectors or an array:
```cpp
//Vector
template <typename T>
void print_vector(const std::vector<T>& v){
    //printing with a "normal" loop
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
    //"ranged-based" loop
    //can't use this if we explicitly need an index

    //range based loop: for all element in vector (like in Python)
    for(const auto& el:v){
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;


//Array
template <typename T, int N>
void print_array(const std::array<T,N>& v){
    //printing with a "normal" loop
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
    //"ranged-based" loop
    //can't use this if we explicitly need an index
    for(const auto& el:v){
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;
}
}
```

An example of bad code (if the passed values isn't a vector the program will crash):
```cpp
//the next is a very "unsafe" function, we have to trust that the passed variable v is a vector
//actually has .size() and [] access operator
//it's for you, as a programmer, to decide if you want this
template <typename T>
void print_whatever(const T& v){
    //printing with a "normal" loop
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
    //"ranged-based" loop
    //can't use this if we explicitly need an index
    for(const auto& el:v){
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;
}
```
With array is it possible to work also in "C style":
```cpp
//C-style function
void printC(int* arr, int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}//printC
```
Some usefull methos for vectors:
```cpp
vec.size() //numeber of initialized valued
vec.capacity() //amount of reserved memory
```
