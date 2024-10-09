// EX1ProgSys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

// 2 queue envoie et reception 
// 1 mutex par client 

// client envoie dans queue 
//serv lit les messages et les renvoie à tout le monde 
// client lit ses messages 

#define SIZE 100000

using namespace std;

void fonction1(int i,queue<string> *channelsend,queue<string> *channelreceive,mutex *mutex)
{
    std::cout << "Bienvenue au sein du thread : " << i << std::endl;

    while(true){

        this_thread::sleep_for(chrono::seconds(rand()%5));
        mutex->lock();
        channelsend->push("hey i'm " + to_string(i));
        while(!channelreceive->empty()){
            cout << channelreceive->front();
            channelreceive->pop();
        }
        mutex->unlock();
    }

}

int main()
{
    queue<string> channel[6];
    mutex mutex[3];
    vector<thread> thr;

    for(int i=0;i<3;i++){
        thr.push_back(thread(fonction1,i,&channel[i*2],&channel[(i*2)-1],&mutex[i]));
    };

    while(true){
        this_thread::sleep_for(chrono::seconds(rand()%5));
        for(int i=0;i>3;i++){
            while(!channel[i*2].empty())
        }
    }



    for(int i=2;i>=0;i--){
        thr.at(i).join();
        thr.pop_back();

    }
  
    
    // thr.join();

   

    

    return 0;

}