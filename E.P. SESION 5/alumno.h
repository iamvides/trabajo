#ifndef ALUMNO_H
#define ALUMNO_H
#include "registro.h"
using namespace std;
class Alumno{
    private:
        Registro reg;
        string universidad;
    public:
        Alumno(); // constructor
        Alumno(Registro, string); // constructor with parameters
        ~Alumno(); // destructor
        void setUniversidad(string);
        string getUniversidad();
};
Alumno::Alumno() : reg() { // initialize reg object here
    // constructor does nothing in this case
}

Alumno::Alumno(Registro r, string u) : reg(r) { // pass r to Registro constructor here
    universidad = u;
}

Alumno::~Alumno() {
    // destructor does nothing in this case
}

void Alumno::setUniversidad(string u) {
    universidad = u;
}

string Alumno::getUniversidad() {
    return universidad;
}
#endif