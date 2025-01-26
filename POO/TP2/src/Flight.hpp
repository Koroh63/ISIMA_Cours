#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <vector>
#include "FlightNum.hpp"
#include "Booking.hpp"
#include "Route.hpp"

class Flight {
private:
    enum class Status { Open, Closed, Cancelled };
    Status status;
    FlightNum flightNum;
    int capacity;
    std::vector<Booking> bookings;
    Route route;

public:
    Flight(const FlightNum& flightNum, int capacity);
    void open();
    void close();
    void cancel();
    void newBooking(const Booking& booking);
    std::string getStatus() const;
};

#endif // FLIGHT_HPP
