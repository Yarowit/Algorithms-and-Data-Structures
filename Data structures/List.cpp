#include "header.hpp"
#include <iostream> 

template<class T>
List<T> :: List(T val){
    this->top = NULL;
    add(val);
    print();
}

template<class T>
void List<T> :: add(T val){
    if(this->top == NULL){
        this->top = new Node<T>(val,NULL);
        return;
    }
    Node<T>* iter = this->top;
    while(iter->next != NULL){
        iter = iter->next;
    };
    iter->next = new Node<T>(val, NULL);
    // print();
}

template<class T>
T List<T> :: pop(){
    if(this->top == NULL) return NULL;
    
    Node<T>* iterBef = NULL;
    Node<T>* iter = this->top;
    while(iter->next != NULL){
        iterBef = iter;
        iter = iter->next;
    };

    if(iterBef != NULL) iterBef->next = NULL;

    T val = iter->val;
    if(this->top == iter) this->top = NULL;
    delete(iter);
    // print();
    return val;
}

template<class T>
T List<T> :: get(int i){
    Node<T>* iter = top;
    for(int j=0;j<i;j++){
        if(iter == NULL) return NULL;
        iter = iter->next;
    }
    if(iter == NULL) return NULL;
    return iter->val;
}

template<class T>
void List<T> :: merge(List<T>* list){
    Node<T>* iter = top;
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = list->top;
}

template<class T>
List<T> :: ~List(){
    Node<T>* iter = top;
    Node<T>* nextIter;
    while(iter != NULL){
        nextIter = iter->next;
        delete(iter);
        iter = nextIter;
    };
}

template<class T>
void List<T> :: print(){
    Node<T>* top = this->top;
    std::cout<<"L: ";
    
    while(top != NULL){
        std::cout<<top->val<<" ";
        top = top->next;
    }

    std::cout<<std::endl;
}