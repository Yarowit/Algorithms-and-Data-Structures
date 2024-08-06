#include "header.hpp"
#include <iostream> 

template<class T>
Heap<T> :: Heap(T val){
    this->top = NULL;
    add(val);
    print();
}

template<class T>
void Heap<T> :: add(T val){
    this->top = new Node<T>(val, this->top);
    // print();
    std::cout<<val<<" ";
}

template<class T>
T Heap<T> :: pop(){
    if(this->top == NULL) return NULL;

    T val = this->top->val;
    Node<T>* top = this->top;
    this->top = this->top->next;
    delete(top);
    // print();
    std::cout<<val<<" ";
    return val;
}

template<class T>
Heap<T> :: ~Heap(){
    Node<T>* iter = top;
    Node<T>* nextIter;
    while(iter != NULL){
        nextIter = iter->next;
        delete(iter);
    };
}

template<class T>
void Heap<T> :: print(){
    Node<T>* top = this->top;
    std::cout<<"H: ";
    
    while(top != NULL){
        std::cout<<top->val<<" ";
        top = top->next;
    }

    std::cout<<std::endl;
}