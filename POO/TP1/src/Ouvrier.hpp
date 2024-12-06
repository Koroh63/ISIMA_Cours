#ifndef OUVRIER_HPP
#define OUVRIER_HPP

#include "Adresse.hpp"
#include <iostream>

class Ouvrier {
private:
    static int compteur;  // Compteur global
    int id;               // Identifiant unique
    Adresse adresse;      // Chantier assigné
    bool estAssigne = false;

public:
    Ouvrier();  
    virtual ~Ouvrier() = default;

    static int getCompteur();  
    int getId() const;         
    Adresse getChantier() const;  

    bool getAssigne()const;

    virtual void ajouter(Ouvrier* o);

    virtual void setChantier(Adresse adr);  

    virtual void travailler(std::ostream& out = std::cout) const;  
};

#endif  
