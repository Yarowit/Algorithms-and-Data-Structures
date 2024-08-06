#include "header.hpp"
#include <cstring> //std::strcmp

void print(int size, int* arr){
    if(globSize > 40) return;
    for(int i = 0;i<size;i++)
        std::cout<<" : "<<std::string((arr[i]<10),'0')<<arr[i];
    std::cout<<std::endl;
}

void resetCounters(){
    cmpCount = 0;
    swpCount = 0;
}

bool cmp(int a, int b){
    cmpCount++;
    return a < b;
}

void swp(int * a, int * b){
    swpCount++;
    std::swap(*a,*b);
}

int RandomizedPartition(int* A, int start, int end){
    int piv = std::uniform_int_distribution<int>(start, end)(rng);
    std::swap(A[piv], A[end]);
    return piv;
}

int RandomizedSelect(int* A, int start, int end, int i){
    if(start == end) return A[start];

    int q = RandomizedPartition(A,start,end);

    int k = q - start + 1;

    if(i == k) return A[q];
    else if(i < k) return RandomizedSelect(A,start,q-1,i);
    else return RandomizedSelect(A,q+1,end,i-k);
}

int Partition(int* A, int start, int end){
    int piv = (start+end)/2;
    std::swap(A[piv], A[end]);
    return piv;
}

int Select(int* A, int start, int end, int i){
    if(start == end) return A[start];

    int q = Partition(A,start,end);

    int k = q - start + 1;

    if(i == k) return A[q];
    else if(i < k) return Select(A,start,q-1,i);
    else return RandomizedSelect(A,q+1,end,i-k);
}

int main(int argc, char** argv){
    std::cin>>globSize;
    
    int arr[globSize];
    for(int i = 0; i<globSize; i++)
        std::cin>>arr[i];
        
    if(argc == 3){
        if(!std::strcmp(argv[1],"R"))
            std::cout<<RandomizedSelect(arr,0,globSize,std::stoi(argv[2]))<<std::endl;
        if(!std::strcmp(argv[1],"S"))
            std::cout<<Select(arr,0,globSize,std::stoi(argv[2]))<<std::endl;
        // if(!std::strcmp(argv[1],"Q"))
        //     quickSort(globSize,arr);
        // if(!std::strcmp(argv[1],"D"))
        //     dualPivotQuickSort(globSize,arr);
        // if(!std::strcmp(argv[1],"H"))
        //     hybridSort(globSize,arr);
    }
    std::cout<<cmpCount<<" "<<swpCount<<std::endl;
}