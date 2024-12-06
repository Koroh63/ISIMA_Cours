#include "Chef.hpp"
#include "Adresse.hpp"
#include "IndisponibleException.hpp"
#include "Ouvrier.hpp"

Chef::Chef() : Ouvrier() {}

void Chef::ajouter(Ouvrier* o){
    if(!o->getAssigne()){
        o->setChantier(this->getChantier());
        equipe.push_back(*o);  // Ajoute un ouvrier à l'équipe
    }else {
        throw new IndisponibleException();
    }
}

void Chef::travailler(std::ostream& out) const {
    out << "Chef #" << getId() << " supervise une équipe de " << equipe.size() << " ouvriers.\n";
    for (const auto& ouvrier : equipe) {
        ouvrier.travailler(out);  // Appelle la méthode `travailler` de chaque ouvrier
    }
}

void Chef::setChantier(Adresse adr){
    Ouvrier::setChantier(adr);
    for (auto& o : equipe){
        o.setChantier(adr);
    }
}
