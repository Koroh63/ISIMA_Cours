#ifndef ADRESSE_HPP
#define ADRESSE_HPP

#include <ostream>

#include <iostream>
#include <string>

using namespace std;
class Adresse{
    private:
        string nom;
        double latitude;
        double longitude;

    public:
        Adresse();
        Adresse(string,double,double);
        string getNom() const;
        double getLatitude()const;
        double getLongitude()const;

        void  toStream(std::ostream & stream = cout) const;



        

};

#endif