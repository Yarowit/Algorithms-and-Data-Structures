#include "header.hpp"
#include <algorithm>
#include <random>
#include <cstdlib>
// #include <iostream>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <chrono>

void BST(int start, int end, int step, int K, bool ascending){
    srand(time(0));
    std::random_device rd;
    // auto rd = std::random_device; 
    auto rng = std::default_random_engine { rd() };
    
    for(int n = start; n <= end; n+=step){
        const int max = 2*n-1;
        for(int k = 0; k < K; k++){
            unsigned long long heightSum = 0;
            int heightMax = 0;
            Tree tree;
            std::vector<int> v(n);
            
            // insertion
            if(ascending){
                for(int i = 0; i < n; i++){
                    v[i] = i;
                    tree.insert(i);
                    std::cout<<"Ins: "<<i<<" ---------------------------------\n";
                    std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    int h = tree.height();
                    if(h > heightMax) heightMax = h;
                    heightSum += h;
                }
            }else{
                for(int i = 0; i < n; i++){
                    v[i] = rand()%max;
                    tree.insert(v[i]);
                    std::cout<<"Ins: "<<i<<" ---------------------------------\n";
                    std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    int h = tree.height();
                    if(h > heightMax) heightMax = h;
                    heightSum += h;
                }
            }

            std::shuffle(std::begin(v), std::end(v), rng);
            // std::cout<<"Jestem"<<std::endl;

            // deletion
            for(int i : v){
        //         std::cout<<i<<" ---------------------------------\n";
        // // std::cout<<"Conn: "<<tree.checkConnections()<<std::endl;
        // std::cout<<tree.draw()<<std::endl;
                tree.remove(i);
                std::cout<<"Del: "<<i<<" ---------------------------------\n";
                std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                int h = tree.height();
                if(h > heightMax) heightMax = h;
                heightSum += h;
            }
            std::cout<<n<<" "<<tree.cmp<<" "<<tree.swp<<" "<<heightSum / (2*n)<<" "<<heightMax<<std::endl;
        }
    }
} 

void RBT(int start, int end, int step, int K, bool ascending){
    srand(time(0));
    // auto rd = std::random_device {}; 
    std::random_device rd; 
    auto rng = std::default_random_engine { rd() };

    for(int n = start; n <= end; n+=step){
        const int max = 2*n-1;
        for(int k = 0; k < K; k++){
            unsigned long long heightSum = 0;
            int heightMax = 0;
            RBTree tree;
            std::vector<int> v(n);

            // insertion
            if(ascending){
                for(int i = 0; i < n; i++){
                    v[i] = i;
                    tree.insert(i);
                    std::cout<<"Ins: "<<i<<" ---------------------------------\n";
                    std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    int h = tree.height();
                    if(h > heightMax) heightMax = h;
                    heightSum += h;
                }
            }else{
                for(int i = 0; i < n; i++){
                    v[i] = rand()%max;
                    tree.insert(v[i]);
                    std::cout<<"Ins: "<<i<<" ---------------------------------\n";
                    std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    int h = tree.height();
                    if(h > heightMax) heightMax = h;
                    heightSum += h;
                }
            }

            std::shuffle(std::begin(v), std::end(v), rng);
            // std::cout<<"Jestem"<<std::endl;

            // deletion
            for(int i : v){
                tree.remove(i);
                std::cout<<"Del: "<<i<<" ---------------------------------\n";
                std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                int h = tree.height();
                if(h > heightMax) heightMax = h;
                heightSum += h;
            }
            std::cout<<n<<" "<<tree.cmp<<" "<<tree.swp<<" "<<heightSum / (2*n)<<" "<<heightMax<<std::endl;
        }
    }
} 

void SPT(int start, int end, int step, int K, bool ascending){
    srand(time(0));
    std::random_device rd; 
    // auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };

    for(int n = start; n <= end; n+=step){
        const int max = 2*n-1;
        for(int k = 0; k < K; k++){
            unsigned long long heightSum = 0;
            int heightMax = 0;
            SplayTree tree;
            std::vector<int> v(n);
            // std::cout<<heightSum<<std::endl;

            // insertion
            if(ascending){
                for(int i = 0; i < n; i++){
                    v[i] = i;
                    tree.insert(i);
                    std::cout<<"Ins: "<<i<<" ---------------------------------\n";
                    std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    int h = tree.height();
                    if(h > heightMax) heightMax = h;
                    heightSum += h;
                }
            }else{
                for(int i = 0; i < n; i++){
                    v[i] = rand()%max;
                    tree.insert(v[i]);
                    std::cout<<"Ins: "<<i<<" ---------------------------------\n";
                    std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    int h = tree.height();
                    if(h > heightMax) heightMax = h;
                    heightSum += h;
                }
            }

            std::shuffle(std::begin(v), std::end(v), rng);
            // std::cout<<"Jestem"<<std::endl;

            // deletion
            for(int i : v){
                tree.remove(i);
                std::cout<<"Del: "<<i<<" ---------------------------------\n";
                std::cout<<tree.draw()<<std::endl;
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                int h = tree.height();
                if(h > heightMax) heightMax = h;
                heightSum += h;
            }
            std::cout<<n<<" "<<tree.cmp<<" "<<tree.swp<<" "<<heightSum / (2*n)<<" "<<heightMax<<std::endl;
        }
    }
} 

int main(){
    std::cout<<"############# BST asc #############"<<std::endl;
    BST(50,50,1,1,true);
    std::cout<<"############# BST rand #############"<<std::endl;
    BST(50,50,1,1,false);
    std::cout<<"############# RBT asc #############"<<std::endl;
    RBT(50,50,1,1,true);
    std::cout<<"############# RBT rand #############"<<std::endl;
    RBT(50,50,1,1,false);
    std::cout<<"############# SPT asc #############"<<std::endl;
    SPT(50,50,1,1,true);
    std::cout<<"############# SPT rand #############"<<std::endl;
    SPT(50,50,1,1,false);
}