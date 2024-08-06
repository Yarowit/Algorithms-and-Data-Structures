#include "header.hpp"
#include <algorithm>
#include <random>
#include <cstdlib>
// #include <iostream>
#include <time.h>

void testAsc(int start, int stop, int step, int reps){
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    for(int n = start; n < stop; n+= step){
        for(int k = 0; k < reps; k++){
            std::vector<int> order(n);
            Tree BST;
            
            for(int i = 0; i < n; i++){
                order[i] = i;
                BST.insert(i);
            }
            std::shuffle(std::begin(order), std::end(order), rng);

            for(int i : order){
                BST.remove(i);
            }
            std::cout<<BST.cmpCount<<BST.swpCount<<BST.heightSum<<std::endl;
        }
    }
    

    
}

void testDet(){
    SplayTree tree;
    int numbers = 6;
    int vals[numbers] = {8,3,7,4,6,5};
    int dels[numbers] = {5,4,6,7,3,8};
    for(int i = 0; i< numbers; i++){
        int val = vals[i];
        std::cout<<val<<std::endl;
        tree.insert(val);
        std::cout<<" ---------------------------------\n";
        // std::cout<<"Conn: "<<tree.checkConnections()<<std::endl;
        std::cout<<tree.draw()<<std::endl;
    }
    std::cout<<"###################################\n";
    for(int i = 0; i< numbers; i++){
        int val = dels[i];
        std::cout<<" ---------------------------------\n";
        std::cout<<"Ser: "<<val<<std::endl;
        tree.search(val);
        std::cout<<tree.draw()<<std::endl;
    }
}
int main2(){
    testDet();
    return 0;
}
int main(){
    srand(time(0));
  
    // RBTree tree;
    Tree n;
    SplayTree tree;

    std::vector<int> vals;
    int numbers = 10;
    for(int i = 0; i< numbers; i++){
        int val = rand() % 10;
        vals.push_back(val);
        // int val = arr[i];
        std::cout<<val;
        tree.insert(val);
        std::cout<<" ---------------------------------\n";
        // std::cout<<"Conn: "<<tree.checkConnections()<<std::endl;
        std::cout<<tree.draw()<<std::endl;
    }
    std::cout<<"###################################\n";
    std::random_shuffle(vals.begin(),vals.end());
    for(int i = 0; i< numbers; i++){
        int val = vals[i];
        std::cout<<" ---------------------------------\n";
        std::cout<<"Del: "<<val<<std::endl;
        tree.remove(val);
        std::cout<<tree.draw()<<std::endl;
    }
    return 0;
}