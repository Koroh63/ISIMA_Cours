#include "Adresse.hpp"
#include <stdexcept>
#include <string>

using namespace std ;

Adresse::Adresse(){
    
    nom = "ISIMA";
    latitude = 45.7592;
    longitude = 3.1104;
}

Adresse::Adresse(string pnom,double platitude,double plongitude){
    nom = pnom;
    latitude = platitude;
    longitude = plongitude;
}

string Adresse::getNom()const {
    return nom;
}

double Adresse::getLatitude()const{
    return latitude;
}

double Adresse::getLongitude()const{
    return longitude;
}

std::ostream & toStream(){
    ;
}
