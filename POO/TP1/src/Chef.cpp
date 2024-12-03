#include "Ouvrier.hpp"
#include "Chef.hpp"

using namespace std;

Chef::Chef(){
    Ouvrier();
}

void Chef::ajouter(Ouvrier o){
    this->equipe.push_back(o);
}