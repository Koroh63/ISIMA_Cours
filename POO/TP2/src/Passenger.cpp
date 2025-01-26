#include "Passenger.hpp"

Passenger::Passenger(const std::string& name, const std::string& phoneNum, const std::string& passport, const DateTime& birthDate)
    : name(name), phoneNum(phoneNum), passport(passport), birthDate(birthDate), tokens(0) {}

std::string Passenger::getName() const {
    return name;
}

std::string Passenger::getPhoneNum() const {
    return phoneNum;
}

std::string Passenger::getPassport() const {
    return passport;
}

DateTime Passenger::getBirthDate() const {
    return birthDate;
}

int Passenger::getTokens() const {
    return tokens;
}

void Passenger::setName(const std::string& name) {
    this->name = name;
}

void Passenger::setPhoneNum(const std::string& phoneNum) {
    this->phoneNum = phoneNum;
}

void Passenger::setPassport(const std::string& passport) {
    this->passport = passport;
}

void Passenger::setBirthDate(const DateTime& birthDate) {
    this->birthDate = birthDate;
}

void Passenger::setTokens(int tokens) {
    this->tokens = tokens;
}


