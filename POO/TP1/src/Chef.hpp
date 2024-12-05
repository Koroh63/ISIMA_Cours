#ifndef CHEF_HPP
#define CHEF_HPP

#include "Adresse.hpp"
#include "Ouvrier.hpp"
#include <list>

class Chef : public Ouvrier {  
private:
    std::list<Ouvrier> equipe; 

public:
    Chef();  
    void ajouter(Ouvrier* o) override;  
    void travailler(std::ostream& out = std::cout) const override;
    void setChantier(Adresse adr)override;
};

#endif  