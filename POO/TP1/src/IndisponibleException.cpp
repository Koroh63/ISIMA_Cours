#include "IndisponibleException.hpp"

IndisponibleException::IndisponibleException(){}

const char* IndisponibleException::what()const throw(){
    return "Cette ouvrier n'est pas disponible";
}