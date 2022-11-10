#include <iostream>
#include <fstream>

template <typename T>
class CNode{
public:
    CNode<T>* next;
    T element;
    CNode(T el){
        element = el;
        next = nullptr;
    }
    void set_node(CNode<T>* n){
        next = n;
        return;
    }
};


template <typename T>
class CLinkedList{
public:

    CNode<T>* first_node;

    CLinkedList(){
        first_node = nullptr;
    }

    void push_back(T el){
        CNode<T> * new_node = new CNode<T>(el);
        if(first_node == nullptr){
            first_node = new_node;
            return;
        }
        CNode<T>** next_node = &(*first_node).next;
        while(1){
            if(*next_node == nullptr){
                *next_node = new_node;
                return;
            }
            CNode<T>* address_next = *next_node;
            next_node = &(*address_next).next; 
        }
        return;
    }

    CLinkedList(const char* path){
        std::ifstream file(path);
        T v;
        first_node = nullptr;
        while(file >> v){
            std::cout<<v<<std::endl;
            push_back(v);
        }
    } 


    CLinkedList (const CLinkedList<T>& p){
        std::cout<<"copy constructor called"<<std::endl;
        if(this != &p){
            first_node = nullptr;
        if(p.first_node == nullptr){
            
            return;
        }
        int done = 0;
        
        CNode<T>* next_node_p = p.first_node;
        int cont = 0;
        while(1){
            T temp = (*next_node_p).element;
            push_back(temp);
            CNode<T>* address_next = next_node_p;
            next_node_p = (*address_next).next; 
            if(next_node_p == nullptr){
                std::cout<<std::endl;
                return;
            }
            cont++;
        }
        }
    } //copy costructor


    void print(){
        if(first_node == nullptr){
            std::cout<<"No element inside the list"<<std::endl;
            return;
        }
        int done = 0;
        CNode<T>* next_node = first_node;
        int cont = 0;
        while(1){
            std::cout<<(*next_node).element<<" ";
            CNode<T>* address_next = next_node;
            next_node = (*address_next).next; 
            if(next_node == nullptr){
                std::cout<<std::endl;
                return;
            }
            cont++;
        }
    }
    

    ~CLinkedList() {
        CNode<T>* next_node = first_node;
        int cont =0;
        while(1){
            CNode<T>* actual_node = next_node;
            CNode<T>* address_next = next_node;
            next_node = (*address_next).next; 
            delete actual_node;
            if(next_node == nullptr){
                delete next_node;
                std::cout<<std::endl;
                return;
            }
            cont++;
        }
        first_node = nullptr;
    }
};