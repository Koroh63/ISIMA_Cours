#ifndef ADRESSE_HPP
#define ADRESSE_HPP

#include <ostream>
#include <sstream>
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

        std::ostream & toStream(stringstream stream);



        

};

#endif