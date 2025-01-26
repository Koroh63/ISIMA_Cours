#ifndef BOOKING_HPP
#define BOOKING_HPP

#include <string>

class Booking {
private:
    enum class State { Pending, Paid, Confirmed, Cancelled };
    State state;
    double price;

public:
    Booking(double price);
    void confirm();
    void cancel();
    void pay();
    bool isConfirmed() const;
    std::string getState() const;
    void setState(const std::string& state);
};

#endif // BOOKING_HPP
