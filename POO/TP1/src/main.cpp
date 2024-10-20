#include <iostream>
#include <ostream>
#include <sstream>
#include "Ouvrier.hpp"

using namespace std;

int main()
{

Ouvrier o;
std::stringstream stream;

o.setChantier(Adresse("notre dame", 48.8531, 2.3499));
o.getChantier().toStream(stream);

std::cout << "notre dame ( 48.8531 ; 2.3499 )"<< std::endl;
std::cout << stream.str() << std::endl;
}