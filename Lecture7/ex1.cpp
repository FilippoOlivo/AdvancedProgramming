#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <cmath>
#include <thread> //the easiest platform-independent way to make your program sleep


//to type less and maybe change clocks if needed
using CHRONO = std::chrono::steady_clock;
using TIME_UNIT = std::chrono::seconds;

struct Timer_Data{
  unsigned int n_calls;
  TIME_UNIT elapsed;
};

std::ostream& operator<<(std::ostream& os, const Timer_Data& t){
  os << t.n_calls << "\t" << std::chrono::duration_cast<TIME_UNIT>(t.elapsed).count();
  return os;
}

class CTimer{
  std::map<std::string, Timer_Data> table;
  std::chrono::time_point<CHRONO> t_start;
  void print_table(){
    for (const auto& p : table)
      std::cout << p.first << "\t" << p.second  << std::endl;
  }
public:
  CTimer() : t_start{CHRONO::now()} {}
  ~CTimer() noexcept { print_table(); }
  friend class CScoped_Timer;
};

class CScoped_Timer{
  CTimer& timer;
  std::chrono::time_point<CHRONO> t_start;
  std::string section;
  void update_table(){
    auto t_end = CHRONO::now();
    auto tot = (t_end - t_start);
    ++timer.table[section].n_calls;
    timer.table[section].elapsed += std::chrono::duration_cast<TIME_UNIT>(tot);
  }
public:
  CScoped_Timer(CTimer& t, std::string s): timer{t},
					 t_start{CHRONO::now()},
					 section{s} {}
  ~CScoped_Timer() noexcept { update_table();}
};

//we need a global variable
//if you are using headers (as you should), you can put this declaration into some "global.hpp" file, or declare it after the timer class
CTimer the_timer;

template <typename T>
class CMatrix{
public:

    std::vector<T>* mat = nullptr;
    int dim;

    CMatrix(int d){
        dim = d;
        mat = new std::vector<T>(dim*dim);
    }

    CMatrix(int d, T def){
        dim = d;
        mat = new std::vector<T>(dim*dim);
        for(int i = 0;i<dim*dim;i++){
            (*mat)[i] = def;
        }
    }

    ~CMatrix(){
        delete mat;
        std::cout<<"Distructor called"<<std::endl;
        dim = 0;
    }

    void print(){
        for(int i = 0 ;i<dim*dim;i++){
            if(i%dim==0){
                std::cout<<std::endl;
            }
            std::cout<<(*mat)[i]<<"\t";

        }
        std::cout<<std::endl;
    }
    double randMToN(double M, double N){
        return M+(rand()/( RAND_MAX / (N-M)));  
    }

    void random_fill(){
        for(int i = 0; i<dim*dim;i++){
            (*mat)[i] = randMToN(-100,100);

        }
    }

    CMatrix<T> operator*(const CMatrix<T>& b);
};


template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& b){
    CMatrix<T> res(dim);
    for(int h = 0; h<dim;h++)
        (*res.mat)[h] = 100;
    int n = res.dim;
    for (int i=1;i<=dim;i++) 
        for(int j=1;j<=dim;j++) {
            (*res.mat)[(i-1)*dim+j-1]=0;
            for(int k=1;k<=dim;k++)    
                (*res.mat)[(i-1)*dim+j-1]=(*res.mat)[(i-1)*dim+j-1]+(*mat)[(i-1)*dim+k-1]*(*b.mat)[(k-1)*dim+j-1];
    }
    return res;
}


int main(int argc, char *argv[]){
    if(argc<2){
        std::cout<<"Few parameters"<<std::endl;
        return 0;
    }
    int n = atoi(argv[1]);
    CMatrix<double> a(n,1); 
    {CScoped_Timer t{the_timer, "fill a"};
    a.random_fill();
    }
    CMatrix<double> b(n,2); 
    {CScoped_Timer t{the_timer, "fill b"};
    b.random_fill();
    }
    {CScoped_Timer t{the_timer, "product"};
    CMatrix<double> c = a*b;
    }
    return 0;
}