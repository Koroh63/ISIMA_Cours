#include "City.hpp"

City::City(const std::string& name) : name(name) {}

std::string City::getName() const {
    return name;
}

void City::setName(const std::string& name) {
    this->name = name;
}


