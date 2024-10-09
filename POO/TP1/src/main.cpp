#include <iostream>
#include <sstream>
#include "Adresse.hpp"

using namespace std;

int main()
{

//     char  const * const nom_zz = "ISIMA";
// const double latitude_zz   = 45.7592;
// const double longitude_zz  =  3.1104;
    
// Adresse isima;

// std::cout <<  ((isima.getNom())      == nom_zz) << std::endl;
// std::cout <<  ((isima.getLatitude()) == latitude_zz) << std::endl;
// std::cout <<  ((isima.getLongitude())== longitude_zz) << std::endl;
    
// const char * nom       = "eiffel";
// const double latitude  = 48.8585;
// const double longitude =  3.1103;

// Adresse tour(nom, latitude, longitude);

// std::cout <<  ((tour.getNom())      == nom) << std::endl;
// std::cout <<  ((tour.getLatitude()) == latitude) << std::endl;
// std::cout <<  ((tour.getLongitude())== longitude) << std::endl;

Adresse isima;

stringstream stream;

// isima.toStream(stream);
// isima.toStream(std::cout);
// isima.toStream();

std::cout << ("ISIMA ( 45.7592 ; 3.1104 )" == stream.str()) << std::endl;
}