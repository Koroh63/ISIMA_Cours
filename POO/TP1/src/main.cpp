#include <iostream>
#include <sstream>
#include "Ouvrier.hpp"

using namespace std;

int main()
{

int n = Ouvrier::getCompteur() +1 ;
Ouvrier * c = new Chef();

std::cout << (n == c->getId())) << std::endl;
std::cout << (n == Ouvrier::getCompteur()) << std::endl;;

delete c;

}