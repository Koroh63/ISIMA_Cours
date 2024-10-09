#ifndef OUVRIER_HPP
#define OUVRIER_HPP


#include "Adresse.hpp"
using namespace std;

class Ouvrier{
    private:
        static int compteur;
        int id;
        Adresse adresse;
        

    public:
        Ouvrier();
        int static getCompteur();

        int getId();
        Adresse getChantier();

        void setChantier(Adresse);


        void travailler(std::ostream &)const ;



        

};

#endif