// random number array
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char** argv){
    std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    if(argc==1) n = 2;
    else n = atoi(argv[1]);
    std::cout<<n<<" ";
    int i = n;
    
    while((i--)>0)
        std::cout<<uniform_int_distribution<int>(0, 2*(n-1))(rng)<<" ";
    std::cout<<std::endl;
}