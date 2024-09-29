#include <iostream>
#include <chrono>


void fonction1(int n, int*a)
{
    
}

int main()
{
    int tab[10] = {0,1,2,3,4,5,6,7,8,9}; // should sum to 45

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    

    int sum = 0;
    for(int i = 0; i< 10; i++)
    {
        sum += tab[i];
    }
    
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    
    std::cout << elapsed_seconds << std::endl;
    
    std::cout << "a";
    return 0;

}