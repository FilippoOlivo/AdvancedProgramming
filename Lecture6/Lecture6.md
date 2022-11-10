# **Inheritance**

We have a base class and a ... class. 

Let define the following classes:
```cpp
//base ("parent") class 
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b){ 
        width=a; height=b; 
    }
};

//derived ("child") class
class Rectangle: public Polygon {
  public:
    int area(){ 
        return width*height;
    }
};


class Triangle: public Polygon {
  public:
    int area(){ 
        return width*height/2;
    }
};
```
Derivated class can access to base class variables and methods
``protected``: child class che access but outside can't. If we put ``private`` derivated class can't access the variables. In class if I don't put anything it is private. The we can create variables of types Triangle and Rectangle and they can access also the public function as below:

```cpp
int main () {
  Rectangle rect;
  Triangle trgl;
  rect.set_values(4,5);
  trgl.set_values(4,5);
   //rect.height=10; //won't work with "protected" member
  std::cout << rect.area() << std::endl;
  std::cout << trgl.area() << std::endl;
  return 0;
}
```
## **Multiple classes inheritance**

```cpp
class Colour{
private:
    int r;
    int g;
    int b;
public: 
    Colour(){};
    Colour(const int& r0, const int& g0, const int& b0):r(r0),g(g0),b(b0){};
    void set_colour(const int& r0, const int& g0, const int& b0){
        r=r0; g=g0; b=b0;
    }
    void print_colour(){
        std::cout<< r<< " "<<g<<" "<<b<<std::endl;
    }
};
 
//another base class 
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b){ 
        width=a; height=b; 
    }
};
```
And know we can define the third class
```cpp
//derived class with 2 base/parent classes
class Rectangle: public Polygon, public Colour {
  public:
    int area(){ 
        return width*height;
    }
};
```
Compiler can create costructor for us in derivated class. If we put the constructor in the parent we must put che constructor in the derivated class.
```cpp
class Triangle: public Polygon, public Colour {
  public:
    Triangle():Colour(){};  
    Triangle(const int& r0, const int& g0, const int& b0):Colour(r0,g0,b0){};  
    int area(){ 
        return width*height/2;
    }
};
```

## **Dynamic polymorphism**

We can create a pointer to the base class from a pointer to the derivated class as below:
```cpp
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ```
Define a generic pointer to the base class but it can point to any child class. 
If we want that the generic pointer to the base class be able to call a method of the derivated class with the same name of a method in base class we have to put the keyword ``virtual`` in base class function and ``override`` in derivated class function. If I defien a function with ``virtual`` keyword is not mandatory to define a function with the same name inside the child (if not defined the function in base class is executed).

I can define an abstract class which is a class that is designed to be specifically used as a base class. An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier (= 0) in the declaration of a virtual member function in the class declaration. Below an example:

```cpp
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
   virtual int area ()=0;
  // virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    //pure virtual functions must be overriden, otherwise the child class is also abstract
};
```
Is mandatory to override all the pure virtual function in derivated classes.

Is also possible to call the base class function inside an overrided method in derivated class like below:
```cpp
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
   virtual int area (){ return 0; }
  // virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    //pure virtual functions must be overriden, otherwise the child class is also abstract
};

class Rectangle: public Polygon {
  public:
      //override helps compiler and makes sure you don't type anything wrong
    int area() override{ 
        return Polygon::area()/2;
    }
};
```

## **Distructors**

Define a base class with distructor 
```cpp
template <typename T>
class CBase1{
public:    
    T field1; 
    CBase1(const T& f0):field1(f0){};
   // virtual 
    ~CBase1(){std::cout<<"base dctor called"<<std::endl;};
};
```

and define a derivated class with his own distructor:

```cpp

template <typename T>
class CDerived1:public CBase1<T>{
public:
    T field2; 
    T* arr;
    CDerived1(const T& f0):CBase1<T>(f0){
        field2=f0;
        arr=new int[10];
    };
   ~CDerived1(){free(arr); std::cout<<"derived dctor called"<<std::endl;}
};
```
And consider the following main:
```cpp
int main(){

 CDerived1<int>* c1 = new CDerived1<int>(12);
 CBase1<int>* ptr=c1;
 delete ptr;
 
 return 0;   
} 
```
In this case the base costructor has been called (``ptr`` has CBase1 type and so the base class distructor is called).

If we put the distructor virtual:
```cpp

template <typename T>
class CBase1{
public:    
    T field1; 
    CBase1(const T& f0):field1(f0){};
   // virtual 
    ~CBase1(){std::cout<<"base dctor called"<<std::endl;};
};

template <typename T>
class CDerived1:public CBase1<T>{
public:
    T field2; 
    T* arr;
    CDerived1(const T& f0):CBase1<T>(f0){
        field2=f0;
        arr=new int[10];
    };
   ~CDerived1(){free(arr); std::cout<<"derived dctor called"<<std::endl;}
};

```
The  derivated distructor is called before the base class distructor (note that is important to kill the dericared class first)

## **Template

If we have a base classe templated the compiler is not smart enoight to understand that the two are the same and so is mandatory to put the keyword this to access the variable 

```cpp
template <typename T>
class CBase1{
public:    
    T field1; 
    CBase1(const T& f0):field1(f0),field2{f0},field3(f0){};
    ~CBase1(){std::cout<<"base1 dctor called"<<std::endl;};
    void say_hi(){std::cout<<"hi"<<std::endl;};
protected:
    T field2;
private: 
    T field3;    
};

class CBase2{
public:    
    int field0; 
    CBase2(const int& f0):field0(f0){};
    ~CBase2(){std::cout<<"base2 dctor called"<<std::endl;};
protected:
    int field01;
private: 
    int field02;    
};
 
template <typename T>
class CDerived1:public CBase1<T>, public CBase2{
public:
    T field4; 
    CDerived1(const T& f0):CBase1<T>(f0),CBase2(f0){
        field4=f0;
    };
   ~CDerived1(){std::cout<<"derived dctor called"<<std::endl;}
   void test_function(){
       std::cout<<field0<<" "<<field01<<" "<<std::endl;
       //using "this" is one of the ways to get around templates 
      std::cout<<this->field1<<" "<<this->field2<<" "<<std::endl;   
    };
};
```

# **Errors**
``errno``: variable to keep the error code (an integer).
```cpp
#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;

  d = 0;

  errno = 0;

  return 0;
}
```
Is not nice to work with errno variable and so in C++ is implemented an error handling mechanism

Create a class inherited from ``std::exception`` and override the function what()
```cpp
class CMyException: public std::exception{
  const char* what() const noexcept override{
    return "My exception happened";
  }
};
```

In main we have to put the try block
```cpp
try
{
    //code
}
catch (std::exception& e){
    std::cout<<e.what()<<std::endl;
}

```

If we want to throw an exception we have to write the following code:
```cpp
throw exception_code/class
```
There exists a list of standart exceptions

```cpp
std::exception& e //dynamic polymorfism
```
If an error happen inside the try catch block the execution proceed. 

``noexcept``: The function does not throw an exception. When an exception is thrown from a function that is declared noexcept or noexcept(true), std::terminate is invoked. If a function is not supposed to crach always put this keyword

try1

It is also possile to catch some particular values of error like in the following code:
```cpp

try
{
    //code
}
catch(const error_code)
{
    //do something
}
```

Another possibility is to catch in different way different error code:
```cpp
try
{
    //code
}
catch(first_error_code)
{
    //do something
}
catch(second_error_code)
{
    //do sometghing else
}
catch(...) //catch all others errors
{
    //do a third thing
}
```

``AP_ERROR`` is a macro to throw errors. We use a macro because c++_macro is able to identify very wekk the line and the file of the error

``AP_ASSERT`` extra check when we want to test the code. If debug is turnet of the assert keyword are ignored. Very useful in test fase: we want to test all possible conditions and correct parameters. When you put yuor code in production compile with ``-DNDEBUG`` option

When deal with dynamic memory: remeber to delete data when you catch something (with unique pointer we don't need to delete allocated memory).



