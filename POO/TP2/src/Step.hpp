#ifndef STEP_HPP
#define STEP_HPP

#include <string>
#include <chrono>

class Step {
private:
    std::chrono::system_clock::time_point arrivalTime;
    std::chrono::system_clock::time_point departureTime;
    std::string airport;

public:
    Step(const std::chrono::system_clock::time_point& arrival, const std::chrono::system_clock::time_point& departure, const std::string& airport);
    std::chrono::system_clock::time_point getArrivalTime() const;
    std::chrono::system_clock::time_point getDepartureTime() const;
    std::string getAirport() const;
    void setArrivalTime(const std::chrono::system_clock::time_point& arrival);
    void setDepartureTime(const std::chrono::system_clock::time_point& departure);
    void setAirport(const std::string& airport);
};

#endif // STEP_HPP
