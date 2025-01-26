#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <string>
#include "DateTime.hpp"

class Passenger {
private:
    std::string name;
    std::string phoneNum;
    std::string passport;
    DateTime birthDate;
    int tokens;

public:
    Passenger(const std::string& name, const std::string& phoneNum, const std::string& passport, const DateTime& birthDate);
    std::string getName() const;
    std::string getPhoneNum() const;
    std::string getPassport() const;
    DateTime getBirthDate() const;
    int getTokens() const;
    void setName(const std::string& name);
    void setPhoneNum(const std::string& phoneNum);
    void setPassport(const std::string& passport);
    void setBirthDate(const DateTime& birthDate);
    void setTokens(int tokens);

};

#endif // PASSENGER_HPP
