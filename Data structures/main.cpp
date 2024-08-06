#include "header.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <thread>

void z1(){
    std::cout<<"Zadanie 1: Kolejka i Stos (Q, H) po 1000 elementów"<<std::endl<<std::endl;
    Queue<int>* queue = new Queue<int>(0);
    for(int i=1; i<100; i++)
        queue -> add(i);
    std::cout<<std::endl<<std::endl;

    for(int i=0; i<100; i++)
        queue -> pop();
    std::cout<<std::endl<<std::endl;

    Heap<int>* heap = new Heap<int>(1);

    for(int i=1; i<100; i++)
        heap -> add(i);
    std::cout<<std::endl<<std::endl;
    
    for(int i=0; i<100; i++)
        heap -> pop();
    std::cout<<std::endl<<std::endl;

    std::cout<<"Koniec"<<std::endl<<std::endl;
}

void measure(List<int>* list, int i, double k){
    double sum = 0;
    for(int j=0; j< k; j++){
        auto start = std::chrono::high_resolution_clock::now();
        list->get(i);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        sum += elapsed.count();
    }
    sum /= k;
    
    std::cout<<i<<": "<< sum <<std::endl;
}

void beasure(Bist<int>* list, int i, double k){
    double sum = 0;
    for(int j=0; j< k; j++){
        auto start = std::chrono::high_resolution_clock::now();
        list->get(i);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        sum += elapsed.count();
    }
    sum /= k;
    
    std::cout<<i<<": "<< sum <<std::endl;
}

void measureRand(List<int>* list, int size, double k){
    double sum = 0;
    for(int j=0; j< k; j++){
        auto start = std::chrono::high_resolution_clock::now();
        list->get(rand()%size);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        sum += elapsed.count();
    }
    sum /= k;
    
    std::cout<<"R: "<< sum <<std::endl;
}

void beasureRand(Bist<int>* list, int size, double k){
    double sum = 0;
    for(int j=0; j< k; j++){
        auto start = std::chrono::high_resolution_clock::now();
        list->get(rand()%size);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        sum += elapsed.count();
    }
    sum /= k;
    
    std::cout<<"R: "<< sum <<std::endl;
}

void z2(){
    std::cout<<"Zadanie 2: Lista jednokierunkowa, merge dwóch list 5000 - elementowych"<<std::endl;
    int size = 10000;

    List<int>* list = new List<int>(0);
    for(int i=1; i<size/2; i++)
        list -> add(rand()%size);
    List<int>* list2 = new List<int>(0);
    for(int i=1; i<size/2; i++)
        list2 -> add(rand()%size);

    list->merge(list2);
    
    measure(list, 1000, 100);
    measure(list, 7000, 100);
    measureRand(list, size, 100);
    

    std::cout<<"Koniec"<<std::endl<<std::endl;
}

void z3(){
    std::cout<<"Zadanie 3: Lista dwukierunkowa, merge dwóch list 5000 - elementowych"<<std::endl;
    int size = 10000;


    Bist<int>* list = new Bist<int>(0);
    for(int i=1; i<size/2; i++)
        list -> add(rand()%size);
    Bist<int>* list2 = new Bist<int>(0);
    for(int i=1; i<size/2; i++)
        list2 -> add(rand()%size);
    list->merge(list2);
    // list->print();
    
    beasure(list, 1000, 100);
    beasure(list, 7000, 100);
    beasureRand(list, size, 100);

    for(int i=0; i<52; i++)
        list -> pop();

    std::cout<<"Koniec"<<std::endl<<std::endl;
}

int main(){
    srand(time(NULL));
    z1();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    z2();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    z3();
}
