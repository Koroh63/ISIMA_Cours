#include "Booking.hpp"

Booking::Booking(double price) : price(price), state(State::Pending) {}

void Booking::confirm() {
    if (state == State::Paid) {
        state = State::Confirmed;
    }
}

void Booking::cancel() {
    if (state == State::Pending || state == State::Paid || state == State::Confirmed) {
        state = State::Cancelled;
    }
}

void Booking::pay() {
    if (state == State::Pending) {
        state = State::Paid;
    }
}

bool Booking::isConfirmed() const {
    return state == State::Confirmed;
}

std::string Booking::getState() const {
    switch (state) {
        case State::Pending: return "Pending";
        case State::Paid: return "Paid";
        case State::Confirmed: return "Confirmed";
        case State::Cancelled: return "Cancelled";
    }
    return "Unknown";
}

void Booking::setState(const std::string& state) {
    if (state == "Pending") {
        this->state = State::Pending;
    } else if (state == "Paid") {
        this->state = State::Paid;
    } else if (state == "Confirmed") {
        this->state = State::Confirmed;
    } else if (state == "Cancelled") {
        this->state = State::Cancelled;
    }
}
