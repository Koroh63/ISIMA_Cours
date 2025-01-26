#include "Payed.hpp"
#include "Booking.hpp"

void Payed::confirm(Booking& booking) {
    if (booking.getState() == "Paid") {
        booking.setState("Confirmed");
    }
}

void Payed::cancel(Booking& booking) {
    if (booking.getState() == "Paid") {
        booking.setState("Cancelled");
    }
}

void Payed::pay(Booking& booking) {
    if (booking.getState() == "Pending") {
        booking.setState("Paid");
    }
}
