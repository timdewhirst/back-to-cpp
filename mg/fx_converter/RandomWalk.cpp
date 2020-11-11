#include <unordered_map>
#include <string>
#include <ctime> 
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

#include "RandomWalk.hpp"



int randomWalk(unordered_map<string, unordered_map<string, double>>& ubid,unordered_map<string,unordered_map<string, double>>& uask){
    mutex mu;
    double t;
    double x=(0.10/sqrt((24*60*60)/t))*(rand()/RAND_MAX-0.5)*4;
    
    this_thread::sleep_for(std::chrono::seconds(2));

    double price_change=exp(x-1);
    //unique_lock<mutex> p= (mu);

    

    return 0;
}

int main(){
    unordered_map<string, unordered_map<string, double>> ubid;
    unordered_map<string,unordered_map<string, double>> uask;
    randomWalk(ubid,uask);
        
    thread t1();
};