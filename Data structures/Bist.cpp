#include "header.hpp"
#include <iostream> 

template<class T>
Bist<T> :: Bist(T val){
    this->top = NULL;
    this->size = 0;
    add(val);
    print();
}

template<class T>
void Bist<T> :: add(T val){
    if(this->top == NULL){
        this->top = new Bode<T>(val,NULL,NULL);
        this->top->next = this->top;
        this->top->prev = this->top;
        size++;
        return;
    }
    top->prev->next = new Bode<T>(val,top,top->prev);
    top->prev = top->prev->next;
    this->size++;
    // print();
}

template<class T>
T Bist<T> :: pop(){
    if(this->top == NULL) return NULL;
    
    Bode<T>* temp = this->top->prev;
    T val = temp->val;
    
    if(this->top->next == this->top){
        this->top = NULL;
        delete(temp);
        return val;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete(temp);
    this->size--;
    // print();
    return val;
}

template<class T>
T Bist<T> :: get(int i){
    Bode<T>* iter = top;
    if(i<size/2){
        for(int j=0;j<i;j++){
            iter = iter->next;
        }
        return iter->val;
    }else{
        for(int j=0;j<size-i;j++){
            iter = iter->prev;
        }
        return iter->val;
    }
    
}

template<class T>
void Bist<T> :: merge(Bist<T>* bist){
    Bode<T>* lend = this->top->prev;
    Bode<T>* bend = bist->top->prev;
    lend->next = bist->top;
    bend->next = this->top;
    bist->top->prev = lend;
    this->top->prev = bend;
    // this->top->prev->next = bist->top;
    // bist->top->prev = this->top->prev;
    // bist->top->prev->next = this->top;
    // this->top->prev = bist->top->prev;
    this->size += bist->size;
}

template<class T>
Bist<T> :: ~Bist(){
    Bode<T>* iter = top;
    Bode<T>* nextIter;
    while(size > 0){
        nextIter = iter->next;
        delete(iter);
        iter = nextIter;
        size--;
    };
}

template<class T>
void Bist<T> :: print(){
    int size = 0+this->size;
    Bode<T>* top = this->top;
    std::cout<<"L: ";
    
    while(size > 0){
        std::cout<<top->val<<" ";
        top = top->next;
        size--;
    }

    std::cout<<std::endl;
}