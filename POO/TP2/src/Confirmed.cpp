#include "Confirmed.hpp"

void Confirmed::confirm(Booking& booking) {
    if (booking.getState() == "Paid") {
        booking.setState("Confirmed");
    }
}

void Confirmed::cancel(Booking& booking) {
    if (booking.getState() == "Pending" || booking.getState() == "Paid" || booking.getState() == "Confirmed") {
        booking.setState("Cancelled");
    }
}

void Confirmed::pay(Booking& booking) {
    if (booking.getState() == "Pending") {
        booking.setState("Paid");
    }
}

bool Confirmed::isConfirmed(const Booking& booking) const {
    return booking.getState() == "Confirmed";
}
