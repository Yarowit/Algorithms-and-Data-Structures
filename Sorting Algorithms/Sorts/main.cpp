#include <iostream>
#include <chrono>   //czas
#include <algorithm> //swap
#include <fstream>
#include <random>

long long cmpCount = 0;
long long swapCount = 0;
int globSize;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void print(int size, int* arr){
    // if(globSize > 40) return;
    // for(int i = 0;i<size;i++)
    //     std::cout<<" : "<<std::string((arr[i]<10),'0')<<arr[i];
    // std::cout<<std::endl;
}

void printCounters(int size){
    if(globSize <= 40) return;
    std::cout<<"Cmp: "<<cmpCount<<"\nSwap: "<<swapCount<<std::endl;
}

void resetCounters(){
    cmpCount = 0;
    swapCount = 0;
}

bool cmp(int a, int b){
    cmpCount++;
    return a < b;
}

void swap(int * a, int * b){
    swapCount++;
    std::swap(*a,*b);
}

void insertionSort(int size, int* arr){
    resetCounters();
    for(int i=0; i < size; i++){
        int j = i;
        while( j > 0 && cmp(arr[j],arr[j-1])){
            swap(arr +j-1, arr + j);
            j--;
        }
        print(size,arr);
    }
    printCounters(size);
}

int* merge(int size, int* arr){
    if(size == 1) return arr;

    int* left = merge(size/2, arr);
    
    int* right = merge(size - size/2, arr+(size/2));
    
    int l=0, r=0;
    int newArr[size];

    while(l < size/2 && r < size-size/2){
        if(cmp(left[l] , right[r])){
            newArr[l+r] = left[l];
            swapCount++;
            l++;
        }else{
            newArr[l+r] = right[r];
            swapCount++;
            r++;
        }
    }

    while(l < size/2){
        newArr[l+r] = left[l];
        swapCount++;
        l++;
    }

    while(r < size - size/2){
        newArr[l+r] = right[r];
        swapCount++;
        r++;
    }
    
    for(int i = 0; i < size; i++)
        arr[i] = newArr[i];

    print(size,arr);

    return arr;
}

void mergeSort(int size, int* arr){
    resetCounters();
    arr = merge(size, arr);
    printCounters(size);
}

void quick(int size, int* arr){
    if(size == 0 || size == 1) return;
    
    int j = 0, i = 0;
    int pivot = arr[size/2];

    swap(arr +size/2 ,arr + size-1);
    while(true){
        while(i < size - 1 && !cmp(arr[i],pivot))
            i++;

        if(i >= size - 1)
            break;

        swap(arr + i++,arr + j++);
    }

    swap(arr + j, arr + size-1);
    print(size,arr);
    quick(j,arr);
    quick(size-j-1,arr+j+1);
}

void quickSort(int size, int* arr){  
    resetCounters();
    quick(size,arr);
    printCounters(size);
}

void main2(int size, int * arr){
    
    int arrI[size];
    int arrM[size];
    int arrQ[size];
    for(int i=0;i<size;i++){
        arrI[i] = arr[i];
        arrM[i] = arr[i];
        arrQ[i] = arr[i];
    }

    // print(size,arrI);
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(size, arrI);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    // print(size,arrI);
    std::cout<<"Cmp: "<<cmpCount<<"\nSwap: "<<swapCount<<std::endl;
    std::cout<<"Insertion: "<<elapsed.count()<<std::endl;


    start = std::chrono::high_resolution_clock::now();
    mergeSort(size, arrM);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    // print(size, arrM);
    std::cout<<"Cmp: "<<cmpCount<<"\nSwap: "<<swapCount<<std::endl;
    std::cout<<"Merge: "<<elapsed.count()<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    quickSort(size, arrQ);  
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    // print(size, arrQ);
    std::cout<<"Cmp: "<<cmpCount<<"\nSwap: "<<swapCount<<std::endl;
    std::cout<<"Quick: "<<elapsed.count()<<std::endl;

}

int* randomArr(int size, int* arr){
    // int arr[size];
    for(int i = 0; i< size; i++)
        arr[i] = std::uniform_int_distribution<int>(0, 2*(size-1))(rng);
    return arr;
}

void dane(){
    
    // insert
    for(int k = 1; k <= 100; k*= 10){
        std::cout<<".\n";
        std::ofstream out("data/i"+std::to_string(k)+".txt");
        for(int n = 10; n <= 200; n+= 10){
            out<<std::endl;
            for(int i = 0; i < k; i++){
                int arr[n];
                randomArr(n,arr);
                insertionSort(n, arr);
                out<<cmpCount<<" "<<swapCount<<std::endl;
            }
        }
    }

    for(int k = 1; k <= 100; k*= 10){
        std::cout<<".\n";
        std::ofstream out("data/m"+std::to_string(k)+".txt");
        for(int n = 10; n <= 200; n+= 10){
            out<<std::endl;
            for(int i = 0; i < k; i++){
                int arr[n];
                randomArr(n,arr);
                mergeSort(n, arr);
                out<<cmpCount<<" "<<swapCount<<std::endl;
            }
        }
        for(int n = 1000; n <= 20000; n+= 1000){
            out<<std::endl;
            for(int i = 0; i < k; i++){
                int arr[n];
                randomArr(n,arr);
                mergeSort(n, arr);
                out<<cmpCount<<" "<<swapCount<<std::endl;
            }
        }
    }

    for(int k = 1; k <= 100; k*= 10){
        std::cout<<".\n";
        std::ofstream out("data/q"+std::to_string(k)+".txt");
        for(int n = 10; n <= 200; n+= 10){
            out<<std::endl;
            for(int i = 0; i < k; i++){
                int arr[n];
                randomArr(n,arr);
                quickSort(n, arr);
                out<<cmpCount<<" "<<swapCount<<std::endl;
            }
        }
        for(int n = 1000; n <= 20000; n+= 1000){
            out<<std::endl;
            for(int i = 0; i < k; i++){
                int arr[n];
                randomArr(n,arr);
                quickSort(n, arr);
                out<<cmpCount<<" "<<swapCount<<std::endl;
            }
        }
    }
}


int main(int argc, char** argv){
    // std::cin>>globSize;
    
    // int arr[globSize];
    // for(int i = 0; i<globSize; i++)
    //     std::cin>>arr[i];
    // print(size,arr);

    // insertionSort(size,arr);
    // print(size,arr);

    // main2(globSize, arr);
    
    dane();
}

