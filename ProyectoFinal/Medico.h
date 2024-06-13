#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include "Base.h"
using namespace std; 
class Medico: public Base {
    private:
        string especialidad;
        string turno;
        string sueldo;
    public:
        Medico(string _dni, string _codigo, string _nombre, 
        string _apellidoP, string _apellidoM, string _especialidad, string _turno, string _sueldo):
        Base(_dni,_codigo, _nombre,_apellidoP,_apellidoM), especialidad(_especialidad), turno(_turno), sueldo(_sueldo) {}

        Medico(string _dni, string _codigo, string _nombre, string _segundo, 
        string _apellidoP, string _apellidoM, string _especialidad, string _turno, string _sueldo):
        Base(_dni,_codigo, _nombre, _segundo, _apellidoP,_apellidoM), especialidad(_especialidad), turno(_turno), sueldo(_sueldo){}
        
        Medico() : Base("", "", "", "", ""), especialidad(""), turno(""), sueldo("") {}
        void setEspecialidad(string e) {
            especialidad = e;
        }
        void setTurno(string t) {
            turno = t;
        }
        void setSueldo(string s) {
            sueldo = s;
        }

        string getEspecialidad() {
            return especialidad;
        }
        string getTurno() {
            return turno;
        }
        string getSueldo() {
            return sueldo;
        }

        void MostrarDetalles() {
            cout << "DNI: " << getDni() << endl;
            cout << "Código: " << getCodigo() << endl;
            cout << "Nombre: " << getNombre() << endl;
            cout << "segundo nombre" << getSegundo() <<endl;
            cout << "Apellido paterno: " << getApellidoP() << endl;
            cout << "Apellido materno: " << getApellidoM() << endl;
            cout << "Especialidad: " << getEspecialidad() << endl;
            cout << "Turno: " << getTurno() << endl;
            cout << "Sueldo: " << getSueldo() << endl;
        }
};
#endif
