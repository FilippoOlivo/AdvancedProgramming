# Lecture 5

# Memory management

All variables are called static variable and they are allocated in stack. Stack is a very small area (8 MB) and the heap (all the rest of memory). All normal variables live on the stack (stack is fast because it is small). A big array can't live in the stack because it exeed the memory size (it will be in the heap). With pointer I can allocate new memory in the heap with new operator. 

```cpp
//I ask some memory for a int (give me enought space in heap for a int)

int* p =new int;

//new is similar than malloc in C
```

Is important to deallocate the memory allocated with new (delete). Memory leak: allcare memory but not deallocate (ones program die the OS will automatically deallocate the space)

```cpp
//Deallocate memory space referenced by p

delete p
```
When work with dynamic memory is important to use the following tool to understand if we have memory leak inside the program (give me a warning)
``` bash
valgrind --leak-check = full ./program_path
```
Normally I can ask a larger heap memoty 
```cpp
//I ask some memory for 12 ints (give me enought space in heap for a int)
int N{12}
int* p =new int[N];
...
delete[] p;
```
A dynamic array has the same syntax of any others array as shown by the followin code:
```cpp
int main(){
   int N{12};
   //I ask some memory for a int (give me enought space in heap for a int)
    int* p =new int[N];
    for(int i=0;i<N;i++){
        p[i]=i;
        std::cout<<p[i]<<" ";
    }
    std::cout<<std::endl;
    //Deallocate
    delete[] p; 
    MyClass<int> obj(10);
    return 0;
}
```
Let define the following class:
```cpp
template <typename T>
class MyClass{
public:
    T* data;
    MyClass(){};
    MyClass(const int& N);
    ~MyClass();
};

//Costructor
template<typename T> 
    MyClass<T>::MyClass(const int& N) {
    data=new T[N];
    for(int i=0;i<N;i++){
        data[i]=i;
    }    
}
```
Distructor is called when the variables goes out of scope (is like any other function):
```cpp
//Distructor
template<typename T> 
    MyClass<T>::~MyClass() {
    delete[] data;
    data=nullptr;
    std::cout<<"destructor called"<<std::endl;
}
```

``data = nullptr`` : we want to record that data points to any memory location.
DISTRUCTOR is a obligatory function in a class that dynamically allocate memory.
We want to allocate memory inside the heap for a matter of space (the stack is too small)

In this case the compiler copied the pointers from obj1 to obj2. We want a copy of the entire
```cpp
template <typename T>
class CMyClass{
public:
    T* data;
    size_t size;
    CMyClass(const int& N);
    ~CMyClass();
    void print();
  //  CMyClass& operator=(const CMyClass& p);
    
};


int main(){
   
    CMyClass<int> obj(10);
    CMyClass<int> obj2(10);
    
    obj2=obj;   
    obj2.print();
    
    return 0;
}
```
We have to create a new operator that make a copy of the object:
```cpp
template <typename T>
CMyClass<T>& CMyClass<T>::operator=(const CMyClass<T>& p){

std::cout<<"assignment operator called"<<std::endl;

//first check for self-assignment
//Am I called the same object?
if (this != &p) { //compare the pointer to the pointer of the object that have called the function
	size=p.size; //copy non-dynamic variables

    //free memory of existing dynamic variables
	if (data != nullptr){  //check data point to a memory region
		delete[] data; //free memory
		data=nullptr;
    }	

    //create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size]; //allocate memory
		for(int i=0;i<size;i++){ //copy the valued of data inside the new memory space
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
return *this;
};
```
``this``refers to the object that call the function. Now we can call the new operatori with the following lines:
```cpp
CMyClass<int> obj(10);
CMyClass<int> obj2(10);
    
obj2=obj;  //call the redefined operator  
```
In this case we pass ``CMyClass<T> obj``, a copy of the object. In this case we have to define a copy costructor that create a copy of the object to pass it to the function
```cpp
//nonsense function to see what happens 
template <typename T>
void a_function(CMyClass<T> obj){
    std::cout<<obj.size<<std::endl;
}
```
Following an example of copy-costructor function:
```cpp
template<typename T> 
CMyClass<T>::CMyClass ( const CMyClass<T>& p ) {
    std::cout<<"copy constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size];
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
    
}//copy constructor
```

Is important to define always a **copy costructor** method inside the class.

```cpp
CMyClass& operator=(const CMyClass& p) = delete;
```
A general rule is that, if you are having pointers in your class and need a destructor, you also need to overload assignment operator and the copy constructor. If you are sure that you will never use them, make them delete, otherwise you or someone else later might try to do unexpected things with your class and get a strange crash instead of a clear error message.

Sometimes you mihgt want to "move" your object instead of copying it.

```cpp
CMyClass& operator=(CMyClass&& p);
...
template<typename T> 
CMyClass<T>::CMyClass ( CMyClass<T> && p ) {
     std::cout<<"move constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
    //copy non-dynamic variables
	size=p.size;
    p.size=0;

    //create and copy dynamic variables
    data=p.data;
    p.data=nullptr;

}//of checking for self-assignment
    
}
```
To call the move constructor we have to write the following lines:
```cpp
//obj3 still exists, but assume it can't be used anymore 
auto obj5=std::move(obj3); 
```
We can also have the move assignement operator that works in the same way:
```cpp
obj5=std::move(obj2);
```
Move costructor is not safe: in this case we can't use ``obj3`` anymore (if we call that object we get an error).

## Smart pointer

We don't have to manually delete the memory referenced by the pointer; one of these smart pointer is the ``unique`` one

```cpp
std::unique_ptr<int[]> p(new int[5]);
```

Insteed to ``new`` we have to call ``data=std::make_unique<int[]>(N);``. Data reset will delete new data and reallocate new memory with the requested size.

Unique have also a move costructor already defined:
```cpp
data=std::move(p.data);
```

