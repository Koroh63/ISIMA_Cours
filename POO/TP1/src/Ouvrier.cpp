#include "Ouvrier.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

int Ouvrier::compteur = 0;

Ouvrier::Ouvrier() {
    compteur++;
    id = compteur;
    adresse = Adresse(); 
}

int Ouvrier::getCompteur() {
    return compteur;
}

int Ouvrier::getId() const {
    return id;
}

Adresse Ouvrier::getChantier() const {
    return adresse;
}

void Ouvrier::setChantier(Adresse adr) {
    adresse = adr;
}

void Ouvrier::ajouter(Ouvrier* o){
    throw std::runtime_error("Cannot add "+ std::to_string(o->getId()));
}

void Ouvrier::travailler(std::ostream& out) const {
    out << "Ouvrier #" << id << " travaille à "
        << adresse.getNom() << " ("
        << adresse.getLatitude() << ", "
        << adresse.getLongitude() << ")" << std::endl;
}

bool Ouvrier::getAssigne()const{
    return this->estAssigne;
}
