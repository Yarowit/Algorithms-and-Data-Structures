#include "header.hpp"

void print(int size, int* arr){
    if(globSize > 40) return;
    for(int i = 0;i<size;i++)
        std::cout<<" : "<<std::string((arr[i]<10),'0')<<arr[i];
    std::cout<<std::endl;
}
void printx(int size, int* arr,int start, int end){
    if(globSize > 40) return;
    for(int i = 0;i<size;i++){
        if(i==start) std::cout<<" < ";
        else if(i==end+1) std::cout<<" > ";
        else std::cout<<" : ";
        std::cout<<std::string((arr[i]<10),'0')<<arr[i];
    }
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

int quickPartition(int* arr,int start, int end, int pivot){
    std::cout<<"QuickInfo: "
    <<"S "<<start
    <<" E "<<end
    <<" P "<<pivot<<std::endl;
    printx(globSize,arr,start,end);
    int size = end+1;
    int j = start, i = start;

    swp(arr + pivot ,arr + size-1);
    while(true){
        while(i < size - 1 && !cmp(arr[i], arr[size-1]))
            i++;

        if(i >= size - 1)
            break;

        swp(arr + i++,arr + j++);
    }

    swp(arr + j, arr + size-1);
    print(globSize,arr);
    return j;
}

int RandomizedPivot(int* arr, int start, int end){
    int piv = std::uniform_int_distribution<int>(start, end)(rng);
    std::cout<<"P: "<<piv<<" | ";
    std::cout<<"S: "<<start<<" | ";
    std::cout<<"E: "<<end<<" | ";
    return quickPartition(arr,start,end,piv);
}

int RandomizedSelect(int* A, int start, int end, int i){
    if(start == end) return A[start];

    int q = RandomizedPivot(A,start,end);

    int k = q - start + 1;

    if(i == k) return A[q];
    else if(i < k) return RandomizedSelect(A,start,q-1,i); // 0 4-1 3 -> 2 3 4 4 5
    else return RandomizedSelect(A,q+1,end,i-k);
}

void MedianOfFive(int* arr, int size){
    std::cout<<"INS "; print(size,arr);
    // insertionSort
    for(int i=0; i < size; i++){
        int j = i;
        while( j > 0 && cmp(arr[j], arr[j-1])){
            swp(arr +j-1, arr + j);
            j--;
        }
    }
    std::cout<<"INSEND "; print(size,arr);
}

int MedianOfMedians(int* arr, int start, int end){
    if(end - start < 5){
        MedianOfFive(arr+start,end-start+1);
        std::cout<<"returning "<<(end-start)/2<<std::endl;
        return start+(end-start)/2;
    }
    int count = 0;
    for(int i = start; i <= end; i+=5){
        count++;
        int newEnd = i + 4;
        if(newEnd > end)
            newEnd = end;
        
        MedianOfFive(arr+i,newEnd-i+1);
        std::cout<<" -Swp "<<i+(newEnd-i+1)/2<<" & "<<start+(i-start)/5;
        swp(arr+i+(newEnd-i+1)/2, arr+start+(i-start)/5);
        //na początku mam same mediany, dokładniej n/5 median
    }std::cout<<std::endl;

    // int mid = count /2 + start + 1;
    // std::cout<<"\nM"<<start<<" "<<end;
    std::cout<<"EOMM ";
    printx(globSize,arr,start,end);
    return MedianOfMedians(arr,start,start+count-1);
}

int Select(int* A, int start, int end, int i){
    if(start == end) return A[start];

    int pivot = MedianOfMedians(A,start,end);
    int q = quickPartition(A,start,end,pivot);

    int k = q - start + 1;

    if(i == k) return A[q];
    else if(i < k) return Select(A,start,q-1,i);
    else return Select(A,q+1,end,i-k);
}