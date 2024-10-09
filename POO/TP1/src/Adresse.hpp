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
        string getNom();
        double getLatitude();
        double getLongitude();

        std::ostream & toStream(stringstream stream);



        

};

#endif