#ifndef CHEF_HPP
#define CHEF_HPP

#include "Ouvrier.hpp"
#include <list>

using namespace std ;

class Chef : Ouvrier{

    private:
        list<Ouvrier> equipe;

    public:
        Chef();
        void travailler(std::ostream &)const;
        void ajouter(Ouvrier);

};


#endif