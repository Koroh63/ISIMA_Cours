#include <iostream>
#include "Company.hpp"
#include "Flight.hpp"
#include "Booking.hpp"
#include "Confirmed.hpp"
#include "Route.hpp"
#include "Jump.hpp"
#include "FlightNum.hpp"
#include "FactoryFlightNum.hpp"
#include "Passenger.hpp"
#include "Customer.hpp"
#include "FactoryBookingNum.hpp"
#include "Airport.hpp"
#include "City.hpp"
#include "DateTime.hpp"

int main() {
    // Création de villes et aéroports
    City paris("Paris");
    City london("London");
    
    Airport cdg("Charles de Gaulle", "CDG");
    cdg.addServedCity(paris);

    Airport lhr("Heathrow", "LHR");
    lhr.addServedCity(london);

    // Création de compagnies et de vols
    Company airFrance("Air France");
    FlightNum flightNum1 = FactoryFlightNum::GenFlightNum();
    Flight flight1(flightNum1, 150);
    
    airFrance.addFlight(flight1);
    
    // Création de routes et d'escales
    DateTime departureTime("2025-01-10 08:00");
    DateTime arrivalTime("2025-01-10 10:00");
    
    Step step1(departureTime, arrivalTime, cdg.getCode());
    Step step2(departureTime, arrivalTime, lhr.getCode());
    
    DateTime duration("2 hours");
    Jump jump1(duration, step1, step2);
    
    Route route(duration);
    
    // Création de clients et de réservations
    Customer customer1("John Doe", "123456789", "BankInfo123");
    Booking booking1(100.0);
    
    flight1.open();
    flight1.newBooking(booking1);
    
    Confirmed confirmed;
    confirmed.pay(booking1);
    confirmed.confirm(booking1);

    // Affichage des états
    std::cout << "Flight Status: " << flight1.getStatus() << std::endl;
    std::cout << "Booking Status: " << booking1.getState() << std::endl;
    
    return 0;
}
