#include <iostream>
#include <ostream>
#include <sstream>
#include "Chef.hpp"
#include "Ouvrier.hpp"

using namespace std;

int main()
{

// Ouvrier o;
// std::stringstream stream;

// o.setChantier(Adresse("notre dame", 48.8531, 2.3499));
// o.getChantier().toStream(stream);

// std::cout << "notre dame ( 48.8531 ; 2.3499 )"<< std::endl;
// std::cout << stream.str() << std::endl;

int n = Ouvrier::getCompteur() +1 ;
Ouvrier * c = new Chef();

std::cout << (n == c->getId()) << std::endl;
std::cout << (n == Ouvrier::getCompteur()) << std::endl;

delete c;
}