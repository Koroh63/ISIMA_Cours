// EX1ProgSys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>


#define SIZE 100000





void fonction1(int *tab, int* sum)
{
    std::cout << "Bienvenue au sein du thread !" << std::endl;
    for (int i = SIZE/2; i < SIZE; i++)
    {
        *sum += tab[i];
    }

}

int main()
{
    int tab[SIZE]; 
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int ref_sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum;
    
    for (int j = 0; j < SIZE; j++)
    {
        tab[j] = rand() % 10;
        
    }

    start = std::chrono::system_clock::now();
    for (int k = 0; k < SIZE; k++) {
        ref_sum += tab[k];
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << ref_sum << std::endl;
    std::cout << elapsed_seconds.count() << std::endl;




    start = std::chrono::system_clock::now();



    std::thread thr(fonction1,tab,&sum2);

    for (int i = 0; i < SIZE/2; i++)
    {
        sum1 += tab[i];
    }

    end = std::chrono::system_clock::now();

    thr.join();

    elapsed_seconds = end - start;

    sum = sum1 + sum2;

    std::cout << sum << std::endl;
    std::cout << elapsed_seconds.count() << std::endl;

    return 0;

}