#include <exception>
using namespace std ;

class IndisponibleException : public exception{
    public:
        IndisponibleException();
        const char* what() const throw();
};