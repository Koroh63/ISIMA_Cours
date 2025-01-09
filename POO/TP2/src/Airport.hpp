#ifndef AIRPORT_HPP
#define AIRPORT_HPP

#include <string>
#include <vector>
#include "City.hpp"

class Airport {
private:
    std::string name;
    std::string code; 
    std::vector<City> servedCities;

public:
    Airport(const std::string& name, const std::string& code);
    std::string getName() const;
    std::string getCode() const;
    std::vector<City> getServedCities() const;
    void addServedCity(const City& city);
    void setName(const std::string& name);
    void setCode(const std::string& code);
    
};

#endif 
