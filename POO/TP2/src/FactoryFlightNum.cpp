#include "FactoryFlightNum.hpp"

FlightNum FactoryFlightNum::GenFlightNum() {
    static int currentNum = 0; 
    return FlightNum(currentNum++);
}


