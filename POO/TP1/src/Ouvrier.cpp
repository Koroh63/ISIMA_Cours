#include "Ouvrier.hpp"
#include "Adresse.hpp"
#include <iostream>

using namespace std;

Ouvrier::Ouvrier(){
    compteur++;
    id = compteur;
    adresse = Adresse();
    
}

int Ouvrier::getCompteur(){
    return compteur;
}

int Ouvrier::compteur = 0;

int Ouvrier::getId(){
    return id;
}

void Ouvrier::travailler(ostream & out = cout)const {
    out << "Ouvrier #" << id <<" travaille à " <<adresse.getNom() << " ( "<<adresse.getLatitude() << " ; " << adresse.getLongitude() << " )" << endl;
}

Adresse Ouvrier::getChantier(){
    return adresse;
}

void Ouvrier::setChantier(Adresse adr){
    adresse = adr;
}