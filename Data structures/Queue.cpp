#include "header.hpp"
#include <iostream> 

// pop- front->...->...->back -add

template<class T>
Queue<T> :: Queue(T val){
    this->back = NULL;
    this->front = NULL;
    add(val);
    // print();
}

template<class T>
void Queue<T> :: add(T val){
    if(this->back == NULL){
        this->back = new Node<T>(val,NULL);
        this->front = this->back;
        return;
    }

    this->back->next = new Node<T>(val,NULL);
    this->back = this->back->next;
    std::cout<<val<<" ";
    // print();
}

template<class T>
T Queue<T> :: pop(){
    if(this->front == NULL) return NULL;

    T val = this->front->val;
    Node<T>* front = this->front;
    this->front = this->front->next;
    delete(front);
    // print();
    std::cout<<val<<" ";
    return val;
}

template<class T>
void Queue<T>:: print(){
    Node<T>* front = this->front;
    std::cout<<"Q: ";
    
    while(front != NULL){
        std::cout<<front->val<<" ";
        front = front->next;
    }

    std::cout<<std::endl;
}

template<class T>
Queue<T> :: ~Queue(){
    Node<T>* iter = front;
    Node<T>* nextIter;
    while(iter != NULL){
        nextIter = iter->next;
        delete(iter);
        iter = nextIter;
    };
}