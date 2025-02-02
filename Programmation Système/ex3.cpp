#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ostream>
#include <vector>
#include <thread>
#include <mutex>

#define N 20
#define M 30

using namespace std;

void laneFunction(vector<vector<char>> *vec,int indice,int vitesseTapis,int vitesseMachine,mutex *mutex,int* runner){
    bool onMachine =false;
    
    mutex->lock();
    vec->at(indice).at(0) = 'X';
    mutex->unlock();
    
    
    for (int i = 0;i<M-1;i++){
        if(onMachine){
            onMachine = false;
            this_thread::sleep_for(chrono::milliseconds(vitesseMachine));
            mutex->lock();
            vec->at(indice).at(i) = 'O';
            vec->at(indice).at(i+1) = 'X';
            mutex->unlock();

        }else {
            this_thread::sleep_for(chrono::milliseconds(vitesseTapis));
            mutex->lock();
            if(vec->at(indice).at(i+1) == 'O'){
                onMachine = true;
            }
            vec->at(indice).at(i) = '=';
            vec->at(indice).at(i+1) = 'X';
            mutex->unlock();
        }
    }

    *runner=*runner-1;
    return;
    
}

void gridInit(vector<vector<char>> &vec,int n,int m){
    

    for(int i=0;i<n;i++){
        int machinePlace = rand() % (m - 1);
        for(int j = 0; j<m;j++){
            if(j == machinePlace){
                vec[i][j] = 'O';
            }else{
                vec[i][j] = '=';
            }
        }
    }
    
    
}
int main()
{
    mutex mutex;
    vector<thread> thr;
    int runner = 0;
    
    vector<vector<char>> myVec(N, vector<char>(M));
    gridInit(myVec,N,M);

    for(int i=0;i<N;i++){
        thr.push_back(thread(laneFunction,&myVec,i,rand()%400 +100,rand()%1300+700,&mutex,&runner));
        runner++;
    }

    while (runner>0){
        this_thread::sleep_for(chrono::milliseconds(50));
        for(int k=0;k<N;k++){
            for(int l=0;l<M;l++){
                cout << myVec[k][l];
            }
            cout << endl;
        }
        cout << "--------------------------------------------------" << endl;

    }

    for (int nbThr = N-1; nbThr >=0;nbThr --){
        thr.at(nbThr).join();
        thr.pop_back();
    }
}
