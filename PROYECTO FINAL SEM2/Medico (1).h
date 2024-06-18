#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
#include "Base.h"
using namespace std;

// Definición de la clase Medico que hereda de Base
class Medico : public Base {
    private:
        // Atributos privados específicos de Medico
        string especialidad;
        string turno;
        string sueldo;

    public:
        // Constructor parametrizado que inicializa los atributos de Base y Medico
        Medico(int _dni, string _codigo, string _nombre, 
               string _apellidoP, string _apellidoM, string _especialidad, string _turno, string _sueldo) :
               Base(_dni, _codigo, _nombre, _apellidoP, _apellidoM), 
               especialidad(_especialidad), turno(_turno), sueldo(_sueldo) {}

        // Constructor por defecto
        Medico() : Base(), especialidad(""), turno(""), sueldo("") {}

        // Métodos setters para modificar los atributos específicos de Medico
        void setEspecialidad(string e) {
            especialidad = e;
        }

        void setTurno(string t) {
            turno = t;
        }

        void setSueldo(string s) {
            sueldo = s;
        }

        // Métodos getters para acceder a los atributos específicos de Medico
        string getEspecialidad() {
            return especialidad;
        }

        string getTurno() {
            return turno;
        }

        string getSueldo() {
            return sueldo;
        }

        // Método para mostrar los detalles del Medico
        void MostrarDetalles() {
            cout << "DNI: " << getDni() << endl;
            cout << "Codigo: " << getCodigo() << endl;
            cout << "Nombre: " << getNombre() << endl;
            cout << "Apellido paterno: " << getApellidoP() << endl;
            cout << "Apellido materno: " << getApellidoM() << endl;
            cout << "Especialidad: " << getEspecialidad() << endl;
            cout << "Turno: " << getTurno() << endl;
            cout << "Sueldo: " << getSueldo() << endl;
        }
};

#endif
