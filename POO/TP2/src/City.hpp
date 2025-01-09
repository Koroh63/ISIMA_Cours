#ifndef CITY_HPP
#define CITY_HPP

#include <string>

class City {
private:
    std::string name;

public:
    City(const std::string& name);
    std::string getName() const;
    void setName(const std::string& name);
    
};

#endif 
