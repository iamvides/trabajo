#include <iostream>
#include "Medico.h"
#include "Paciente.h"
#include <fstream>
#include <vector>
using namespace std;

string enfermedadT;  // Variable global para almacenar la enfermedad

// Plantilla de función para buscar y comparar dos valores
template<typename N>
bool find(N buscar, N econ) {
    if (buscar == econ) {
        return true;
    }
    return false;
}

// Función para validar la enfermedad basada en la especialidad del médico
bool validarEnfermedad(string especialidad) {
    string archivoNombre;

    // Determinar el archivo de texto según la especialidad
    if (especialidad == "cardiologia") {
        archivoNombre = "Cardiologia.txt";
    } else if (especialidad == "pediatria") {
        archivoNombre = "Pediatria.txt";
    } else if (especialidad == "traumatologia") {
        archivoNombre = "Traumatologia.txt";
    } else if (especialidad == "ginecologia") {
        archivoNombre = "Ginecologia.txt";
    } else if (especialidad == "general") {
        archivoNombre = "MedicinaGeneral.txt";
    } else {
        cout << "Especialidad no válida." << endl;
        return false;  // Retornar falso si la especialidad no es válida
    }

    vector<string> Enfermedades;  // Vector para almacenar las enfermedades
    ifstream archivo(archivoNombre);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            Enfermedades.push_back(linea);  // Leer enfermedades del archivo
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo " << archivoNombre << endl;
        return false;  // Retornar falso si no se pudo abrir el archivo
    }

    cin.ignore();  // Limpiar el buffer de entrada
    bool valido = false;
    string enfermedad;

    do {
        // Solicitar al usuario que ingrese la enfermedad
        cout << "Ingrese de que padece: " << endl;
        getline(cin, enfermedad);

        // Comparar la enfermedad ingresada con las enfermedades del archivo
        for (const auto& enfermedadLeida : Enfermedades) {
            if (find(enfermedad, enfermedadLeida)) {
                valido = true;
                break;  // Salir del bucle si se encuentra la enfermedad
            }
        }

        if (!valido) {
            cout << "Enfermedad no valida para esta especialidad. Intente nuevamente." << endl;
        }
    } while (!valido);  // Repetir hasta que se ingrese una enfermedad válida

    enfermedadT = enfermedad;  // Guardar la enfermedad validada
    return true;  // Retornar verdadero si la enfermedad es válida
}

int main() {
    int dni = 0, codigo;
    string password = "password";
    string nombre, apellidoP, apellidoM, fechaU, enfermedad, especialidad;
    Medico* Doctores[10];  // Arreglo de 10 punteros a objetos Medico

    Paciente** pacientes = new Paciente*[10];  // Arreglo de punteros a objetos Paciente
    string opc = "y";
    int contador = 0;

    ifstream archivo("medicos.txt");  // Leer datos de médicos desde el archivo

    if (archivo.is_open()) {
        Medico tempDoctores[10];  // Arreglo de 10 objetos Medico

        int contador = 0;

        while (contador < 10) {
            int dni, codigo;
            string nombre, apellidoP, apellidoM, especialidad, turno;

            // Leer datos del archivo
            archivo >> dni >> codigo >> nombre >> apellidoP >> apellidoM >> especialidad >> turno;

            // Asignar valores al objeto Medico y almacenar en el arreglo
            tempDoctores[contador].setDni(dni);
            tempDoctores[contador].setCodigo(codigo);
            tempDoctores[contador].setNombre(nombre);
            tempDoctores[contador].setApellidoP(apellidoP);
            tempDoctores[contador].setApellidoM(apellidoM);
            tempDoctores[contador].setEspecialidad(especialidad);
            tempDoctores[contador].setTurno(turno);

            Doctores[contador] = &tempDoctores[contador];  // Asignar puntero al objeto Medico

            contador++;
        }
        archivo.close();
    }

    do {
        int ele;

        // Menú de opciones
        do {
            cout << "Ingrese su eleccion" << endl;
            cout << "1. Ver doctores y especialidad" << endl;
            cout << "2. Sacar cita" << endl;
            cout << "3. Ver la informacion del paciente" << endl;
            cin >> ele;
        } while (ele < 1 || ele > 3);

        if (ele == 1) {
            // Mostrar doctores y sus especialidades
            for (int i = 0; i < 5; i++) {
                cout << Doctores[i]->getNombre() << "   " << Doctores[i]->getEspecialidad() << endl;
            }
        } 

        if (ele == 2) {
            bool validar = false;
            cout << "Ingrese su dni:  ";
            cin >> dni;

            do {
                string conti = "n";
                do {
                    try {
                        cout << "Ingrese el codigo del doctor: "; 
                        // Intentar leer un código de doctor válido
                        if (!(cin >> codigo)) {
                            throw runtime_error("Dato invalido, vuelva a intentar.");
                        } else {
                            conti = "s";
                        }
                    } catch (runtime_error& e) {
                        cin.clear();
                        cin.ignore();
                    }
                } while (conti != "s");

                validar = false;
                for (int i = 0; i < 10; i++) {
                    validar = find(codigo, Doctores[i]->getCodigo());
                    if (validar) {
                        break;
                    }
                }

            } while (validar == false);

            // Solicitar datos del paciente
            cout << "Ingrese su nombre: ";
            cin >> nombre;
            cout << "Ingrese su apellido paterno: ";
            cin >> apellidoP;
            cout << "Ingrese su apellido materno: ";
            cin >> apellidoM;
            cout << "Ingrese su fecha de ultima visita: ";
            cin >> fechaU;

            do {
                // Validar la especialidad deseada
                cout << "Ingrese la especialidad que desea: ";
                cin >> especialidad;
                for (int i = 0; i < 10; i++) {
                    validar = find(especialidad, Doctores[i]->getEspecialidad());
                    if (validar == true) {
                        break;
                    }
                }
            } while (validar == false);

            validar = validarEnfermedad(especialidad);  // Validar enfermedad

            // Crear un nuevo objeto Paciente y agregarlo al arreglo
            pacientes[contador] = new Paciente(dni, codigo, nombre, apellidoP, apellidoM, fechaU, enfermedadT, especialidad, Doctores, 10);

            // Guardar información del paciente en un archivo
            string filename = "Pacientes.txt";
            ofstream archivo(filename);
            if (archivo.is_open()) {
                archivo << "dni: " << pacientes[contador]->getDni() << endl;
                archivo << "codigo del doctor: " << pacientes[contador]->getCodigo() << endl;
                archivo << "nombre: " << pacientes[contador]->getNombre() << endl;
                archivo << "apellido Paterno: " << pacientes[contador]->getApellidoP() << endl;
                archivo << "apellido Materno: " << pacientes[contador]->getApellidoM() << endl;
                archivo << "fecha de ultima visita: " << pacientes[contador]->getFechaU() << endl;
                archivo << "enfermedad: " << pacientes[contador]->getEnfermedad() << endl;
                archivo << "especialidad: " << pacientes[contador]->getEspecialidad() << endl;
                archivo.close();
            } else {
                cout << "Error al crear el archivo " << filename << endl;
            }
            contador += 1;
        }

        if (ele == 3) {
            // Verificar identidad del usuario
            do {
                cout << "Ingrese el password para validar su identidad" << endl;
                cin >> password;
            } while (password != "password");

            // Mostrar información del paciente desde el archivo
            ifstream archivo("Pacientes.txt");
            if (archivo.is_open()) {
                string linea;
                while (getline(archivo, linea)) {
                    cout << linea << endl;
                }
                archivo.close();
            } else {
                cout << "Error al abrir el archivo Pacientes.txt" << endl;
            }
        }

        // Preguntar si desea continuar
        cout << "Desea continuar? y or n" << endl;
        cin >> opc;
    } while (opc == "y" || opc == "Y");

    return 0;
}
