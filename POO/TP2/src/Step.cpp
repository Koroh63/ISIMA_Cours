#include "Step.hpp"

Step::Step(const std::chrono::system_clock::time_point& arrival, const std::chrono::system_clock::time_point& departure, const std::string& airport)
    : arrivalTime(arrival), departureTime(departure), airport(airport) {}

std::chrono::system_clock::time_point Step::getArrivalTime() const {
    return arrivalTime;
}

std::chrono::system_clock::time_point Step::getDepartureTime() const {
    return departureTime;
}

std::string Step::getAirport() const {
    return airport;
}

void Step::setArrivalTime(const std::chrono::system_clock::time_point& arrival) {
    arrivalTime = arrival;
}

void Step::setDepartureTime(const std::chrono::system_clock::time_point& departure) {
    departureTime = departure;
}

void Step::setAirport(const std::string& airport) {
    this->airport = airport;
}
