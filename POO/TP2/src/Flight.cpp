#include "Flight.hpp"

Flight::Flight(const FlightNum& flightNum, int capacity)
    : flightNum(flightNum), capacity(capacity), status(Status::Closed) {}

void Flight::open() {
    status = Status::Open;
}

void Flight::close() {
    status = Status::Closed;
}

void Flight::cancel() {
    status = Status::Cancelled;
    for(auto& booking : bookings) {
        booking.cancel();
    }
}

void Flight::newBooking(const Booking& booking) {
    if (status == Status::Open && bookings.size() < capacity) {
        bookings.push_back(booking);
    } else {
        return
    }
}

std::string Flight::getStatus() const {
    switch (status) {
        case Status::Open: return "Open";
        case Status::Closed: return "Closed";
        case Status::Cancelled: return "Cancelled";
    }
    return "Unknown";
}
