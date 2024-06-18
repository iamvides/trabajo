#include <iostream>
#include "Medico.h"
#include "Paciente.h"
using namespace std;

// Plantilla de función para buscar y comparar dos valores
template<typename N>
bool find(N buscar, N econ) {
    if (buscar == econ) {
        return true;
    }
    return false;
}

int main() {
    int dni;
    string codigo, nombre, apellidoP, apellidoM, fechaU, enfermedad, especialidad;

    // Creación de objetos Medico
    Medico medico1(12, "M001", "juan", "perez", "gonzalez", "cardiologia", "morning", "5000");
    Medico medico2(13, "M002", "maria", "lopez", "rodriguez", "pediatria", "tarde", "4500");
    Medico medico3(14, "M003", "pedro", "garcia", "sanchez", "traumatologia", "noche", "6000");
    Medico medico4(15, "M004", "ana", "diaz", "fernandez", "ginecologia", "morning", "5500");
    Medico medico5(16, "M005", "luis", "hernandez", "martinez", "general", "tarde", "6500");

    // Arreglo de punteros a objetos Medico
    Medico** Doctores = new Medico*[5];
    Doctores[0] = &medico1;
    Doctores[1] = &medico2;
    Doctores[2] = &medico3;
    Doctores[3] = &medico4;
    Doctores[4] = &medico5;

    // Arreglo de punteros a objetos Paciente
    Paciente** pacientes = new Paciente*[10];
    string opc = "y";
    int contador = 0;

    do {
        int ele;
        // Menú de opciones
        do {
            cout << "Ingrese su elección" << endl;
            cout << "1. Ver doctores y especialidad" << endl;
            cout << "2. Sacar cita" << endl;
            cin >> ele;
        } while (ele < 1 || ele > 2);

        if (ele == 1) {
            // Mostrar doctores y sus especialidades
            for (int i = 0; i < 5; i++) {
                cout << Doctores[i]->getNombre() << "   " << Doctores[i]->getEspecialidad() << endl;
            }
        } else {
            // Proceso para sacar una cita
            bool validar = false;
            do {
                // Validar el DNI del doctor
                cout << "Ingrese el DNI del doctor: ";
                cin >> dni;
                for (int i = 0; i < 5; i++) {
                    validar = find(dni, Doctores[i]->getDni());
                    if (validar == true) {
                        break;
                    }
                }
            } while (validar == false);

            // Ingresar datos del paciente
            cout << "Ingrese su codigo: ";
            cin >> codigo;
            cout << "Ingrese su nombre: ";
            cin >> nombre;
            cout << "Ingrese su apellido paterno: ";
            cin >> apellidoP;
            cout << "Ingrese su apellido materno: ";
            cin >> apellidoM;
            cout << "Ingrese su fecha de ultima visita: ";
            cin >> fechaU;
            cout << "Ingrese su enfermedad: ";
            cin >> enfermedad;

            do {
                // Validar la especialidad deseada
                cout << "Ingrese la especialidad que desea" << endl;
                cin >> especialidad;
                for (int i = 0; i < 5; i++) {
                    validar = find(especialidad, Doctores[i]->getEspecialidad());
                    if (validar == true) {
                        break;
                    }
                }
            } while (validar == false);

            // Crear un nuevo objeto Paciente y agregarlo al arreglo
            pacientes[contador] = new Paciente(dni, codigo, nombre, apellidoP, apellidoM, fechaU, enfermedad, especialidad, "", "", Doctores, 5);
            contador += 1;
        }

        // Preguntar si desea continuar
        cout << "¿Desea continuar? y or n" << endl;
        cin >> opc;
    } while (opc == "y" || opc == "Y");

    return 0;
}
