#include "header.hpp"
#include <cstring> //std::strcmp
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long cmpCount = 0;
long long swpCount = 0;
int globSize;

int main(int argc, char** argv){
    std::cin>>globSize;
    
    int arr[globSize];
    for(int i = 0; i<globSize; i++)
        std::cin>>arr[i];

    print(globSize,arr);
        
    if(argc == 3){
        if(!std::strcmp(argv[1],"R"))
            std::cout<<RandomizedSelect(arr,0,globSize-1,std::stoi(argv[2]))<<std::endl;
        if(!std::strcmp(argv[1],"S"))
            std::cout<<Select(arr,0,globSize-1,std::stoi(argv[2]))<<std::endl;
        // if(!std::strcmp(argv[1],"Q"))
        //     quickSort(globSize,arr);
        // if(!std::strcmp(argv[1],"D"))
        //     dualPivotQuickSort(globSize,arr);
        // if(!std::strcmp(argv[1],"H"))
        //     hybridSort(globSize,arr);
    }
    std::sort(arr,arr+globSize);
    print(globSize,arr);
    std::cout<<cmpCount<<" "<<swpCount<<std::endl;
}