#include "Airport.hpp"

Airport::Airport(const std::string& name, const std::string& code) : name(name), code(code) {}

std::string Airport::getName() const {
    return name;
}

std::string Airport::getCode() const {
    return code;
}

std::vector<City> Airport::getServedCities() const {
    return servedCities;
}

void Airport::addServedCity(const City& city) {
    servedCities.push_back(city);
}

void Airport::setName(const std::string& name) {
    this->name = name;
}

void Airport::setCode(const std::string& code) {
    this->code = code;
}


