#ifndef COMPANY_HPP
#define COMPANY_HPP

#include <string>
#include <vector>
#include "Flight.hpp"

class Company {
private:
    std::string name;
    std::vector<Flight> flights;

public:
    Company(const std::string& name);
    void addFlight(const Flight& flight);
    
};

#endif 
