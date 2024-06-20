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

    public:
        // Constructor parametrizado que inicializa los atributos de Base y Medico
        Medico(int _dni, int _codigo, string _nombre, 
               string _apellidoP, string _apellidoM, string _especialidad, string _turno) :
               Base(_dni, _codigo, _nombre, _apellidoP, _apellidoM), 
               especialidad(_especialidad), turno(_turno) {}

        // Constructor por defecto
        Medico() : Base(), especialidad(""), turno("") {}

        // Métodos setters para modificar los atributos específicos de Medico
        void setEspecialidad(string e) {
            especialidad = e;
        }

        void setTurno(string t) {
            turno = t;
        }


        // Métodos getters para acceder a los atributos específicos de Medico
        string getEspecialidad() {
            return especialidad;
        }

        string getTurno() {
            return turno;
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

        }
};

#endif
