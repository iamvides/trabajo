#ifndef BASE_H
#define BASE_H

#include <iostream>
using namespace std;

// Definición de la clase Base
class Base {
    private:
        // Atributos privados de la clase
        int dni;
        string codigo;
        string nombre;
        string apellidoP;
        string apellidoM;

    public:
        // Constructor por defecto
        Base() {}

        // Constructor parametrizado
        Base(int _dni, string _codigo, string _nombre, string _apellidoP, string _apellidoM) :
            dni(_dni), codigo(_codigo), nombre(_nombre), apellidoP(_apellidoP), apellidoM(_apellidoM) {}

        // Método virtual puro para mostrar detalles, debe ser implementado por las clases derivadas
        virtual void MostrarDetalles() = 0;

        // Métodos setters para modificar los atributos
        void setDni(int d) {
            dni = d;
        }

        void setCodigo(string c) {
            codigo = c;
        }

        void setNombre(string n) {
            nombre = n;
        }

        void setApellidoP(string ap) {
            apellidoP = ap;
        }

        void setApellidoM(string am) {
            apellidoM = am;
        }

        // Métodos getters para acceder a los atributos
        int getDni() {
            return dni;
        }

        string getCodigo() {
            return codigo;
        }

        string getNombre() {
            return nombre;
        }

        string getApellidoP() {
            return apellidoP;
        }

        string getApellidoM() {
            return apellidoM;
        }
};

#endif
