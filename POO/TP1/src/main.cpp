#include <iostream>
#include <ostream>
#include <sstream>
#include "Chef.hpp"
#include "Ouvrier.hpp"

using namespace std;

int main()
{
// std::string nom_zz = "ISIMA";
// const double latitude_zz   = 45.7592;
// const double longitude_zz  =  3.1104;

// Adresse isima;

// std::cout <<  (isima.getNom()       == nom_zz) << std::endl;
// std::cout <<  (isima.getLatitude()  == latitude_zz) << std::endl;
// std::cout <<  (isima.getLongitude() == longitude_zz) << std::endl;


// std::string   nom       = "eiffel";
// const double latitude  = 48.8585;
// const double longitude =  3.1103;

// Adresse tour(nom, latitude, longitude);

// std::cout <<  (tour.getNom()       == nom) << std::endl;
// std::cout <<  (tour.getLatitude()  == latitude) << std::endl;
// std::cout <<  (tour.getLongitude() == longitude) << std::endl;

// Adresse isima;

// // il faut inclure la bibliothèque sstream
// std::stringstream stream;

// isima.toStream(stream);
// isima.toStream(std::cout);
// isima.toStream();

// std::cout << ("ISIMA ( 45.7592 ; 3.1104 )" == stream.str()) << std::endl;

// int n = Ouvrier::getCompteur();

// std::cout << (n == Ouvrier::getCompteur()) << std::endl;
// Ouvrier o1;
// std::cout << ((n+1) == o1.getId()) << std::endl;
// Ouvrier o2;
// std::cout << ((n+1) == o1.getId()) << std::endl;
// std::cout << ((n+2) == o2.getId()) << std::endl;
// std::cout << ((n+2) == Ouvrier::getCompteur()) << std::endl;

// //const Ouvrier o;
// Ouvrier o;
// std::stringstream stream;

// o.travailler(std::cout);
// o.travailler(stream);

// // L'affichage ressemble à cela
// // "Ouvrier #1 travaille à ISIMA ( 45.7592 ; 3.1104 )"

// Ouvrier o;
// std::stringstream stream;

// o.setChantier(Adresse("notre dame", 48.8531, 2.3499));
// o.getChantier().toStream(stream);

// std::cout << ("notre dame ( 48.8531 ; 2.3499 )" == stream.str()) << std::endl;

// int n = Ouvrier::getCompteur() +1 ;
// Ouvrier * c = new Chef();

// std::cout << (n == c->getId()) << std::endl;
// std::cout << (n == Ouvrier::getCompteur()) << std::endl;

// delete c;

Ouvrier o1;
Ouvrier o2;
Ouvrier * c = new Chef();

std::cout << (o1.getChantier().getNom() == "ISIMA") << std::endl;
std::cout << (o2.getChantier().getNom() == "ISIMA") << std::endl;
std::cout << (c->getChantier().getNom() == "ISIMA") << std::endl;


c->ajouter(&o1);
c->ajouter(&o2);
c->setChantier(Adresse("notre dame", 48.8531, 2.3499));

std::cout << (o1.getChantier().getNom() == "notre dame") << std::endl;
std::cout << (o2.getChantier().getNom() == "notre dame") << std::endl;
std::cout << (c->getChantier().getNom() == "notre dame") << std::endl;


}