#include "FlightNum.hpp"

FlightNum::FlightNum(int num) : number(num) {}

int FlightNum::getNumber() const {
    return number;
}

void FlightNum::setNumber(int num) {
    number = num;
}


