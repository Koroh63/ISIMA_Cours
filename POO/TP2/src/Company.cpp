#include "Company.hpp"

Company::Company(const std::string& name) : name(name) {}

void Company::addFlight(const Flight& flight) {
    flights.push_back(flight);
}


