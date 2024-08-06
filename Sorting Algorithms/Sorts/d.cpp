// descending numbers array
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char** argv){
    std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    if(argc==1) n = 1;
    else n = atoi(argv[1]);
    
    int acc = 2*n;
    
    while((n--)>0){
        acc-=uniform_int_distribution<int>(0, 2)(rng);
        std::cout<<acc<<" ";
    }
    std::cout<<std::endl;
}