#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include "Medico.h"
#include "Base.h"
using namespace std;

// Definición de la clase Paciente que hereda de Base
class Paciente : public Base {
    private:
        // Atributos privados específicos de Paciente
        string fechaU = "primera vez";
        string enfermedad = "";
        string especialidad = "general";
        string examenU = "";
        string operacionN = "";
        Medico** Doctores; // Arreglo de punteros a objetos Medico
        int numDoctores; // Número de doctores asignados

    public:
        // Constructor por defecto
        Paciente() : Base(), fechaU(""), enfermedad(""), especialidad(""), examenU(""), operacionN(""), Doctores(new Medico*[1]), numDoctores(0) {}

        // Constructor parametrizado
        Paciente(int _dni, string _codigo, string _nombre, string _apellidoP, string _apellidoM,
                 string _fechaU, string _enfermedad, string _especialidad, string _examenU, string _operacionN, Medico** _Doctores, int _numDoctores)
                 : Base(_dni, _codigo, _nombre, _apellidoP, _apellidoM),
                   fechaU(_fechaU), enfermedad(_enfermedad), especialidad(_especialidad), examenU(_examenU), operacionN(_operacionN) {
            Doctores = new Medico*[_numDoctores];
            for (int i = 0; i < _numDoctores; i++) {
                Doctores[i] = _Doctores[i];
            }
            numDoctores = _numDoctores;
        }

        // Métodos setters para modificar los atributos específicos de Paciente
        void setFechaU(string f) {
            fechaU = f;
        }

        void setEnfermedad(string e) {
            enfermedad = e;
        }

        void setExamenU(string ex) {
            examenU = ex;
        }

        void setOperacionN(string op) {
            operacionN = op;
        }

        // Métodos getters para acceder a los atributos específicos de Paciente
        string getFechaU() {
            return fechaU;
        }

        string getEnfermedad() {
            return enfermedad;
        }

        string getExamenU() {
            return examenU;
        }

        string getOperacionN() {
            return operacionN;
        }

        string getEspecialidad() {
            return especialidad;
        }

        // Método para mostrar los detalles del Paciente
        void MostrarDetalles() {
            cout << "Detalles del paciente:" << endl;
            cout << "DNI: " << getDni() << endl;
            cout << "Código: " << getCodigo() << endl;
            cout << "Nombre: " << getNombre() << endl;
            cout << "Apellido Paterno: " << getApellidoP() << endl;
            cout << "Apellido Materno: " << getApellidoM() << endl;
            cout << "Fecha de última visita: " << getFechaU() << endl;
            cout << "Enfermedad: " << getEnfermedad() << endl;
            cout << "Especialidad: " << getEspecialidad() << endl;
            cout << "Examen de urgencia: " << getExamenU() << endl;
            cout << "Operación necesaria: " << getOperacionN() << endl;
            cout << "Médicos asignados: " << endl;
            for (int i = 0; i < numDoctores; i++) {
                // Muestra el nombre de los médicos asignados con la misma especialidad
                if (getEspecialidad() == Doctores[i]->getEspecialidad()) {
                    cout << Doctores[i]->getNombre() << endl;
                }
            }
        }
};

#endif
