#ifndef CONFIRMED_HPP
#define CONFIRMED_HPP

#include "Booking.hpp"

class Confirmed {
public:
    void confirm(Booking& booking);
    void cancel(Booking& booking);
    void pay(Booking& booking);
    bool isConfirmed(const Booking& booking) const;
    
};

#endif 
