#include <iostream>
#include "Medico.h"
#include "Paciente.h"
#include <fstream>
using namespace std;

// Plantilla de función para buscar y comparar dos valores
template<typename N>
bool find(N buscar, N econ) {
    if (buscar == econ) {
        return true;
    }
    return false;
}

bool validarEnfermedad(string especialidad) {
    string archivoNombre;
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
        return false;  // Si la especialidad no es válida, retornar falso
    }
    
    string Enfermedades[10]; // Arreglo para almacenar las enfermedades
    int contador = 0; // Contador para el número de enfermedades encontradas
    
    ifstream archivo(archivoNombre);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea) && contador < 10) {
            Enfermedades[contador] = linea;
            contador++;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo " << archivoNombre << endl;
        return false; // Si no se pudo abrir el archivo, retornar falso
    }
    
    bool valido = false;
    string enfermedad;
    do {
        // Pedir al usuario que ingrese la enfermedad que desea validar
        cout << "Ingrese de que padece: "<<endl;
        getline(cin, enfermedad);
        
        // Realizar la comparación de la enfermedad ingresada con las enfermedades leídas
        for (int i = 0; i < contador; i++) {
            if (find(enfermedad, Enfermedades[i])) {
                valido = true;
                break; // Si encuentra la enfermedad, salir del bucle for
            }
        }
        
        if (!valido) {
            cout << "Enfermedad no valida para esta especialidad. Intente nuevamente." << endl;
        }
    } while (!valido); // Repetir hasta que se ingrese una enfermedad válida
    
    return true; // Si se encontró la enfermedad válida, retornar true
}

int main() {
    int dni,codigo;
    string password;
    string  nombre, apellidoP, apellidoM, fechaU, enfermedad, especialidad;
    Medico* Doctores[10]; // Arreglo de 10 punteros a objetos Medico
    // Creación de objetos Medico
    Paciente** pacientes = new Paciente*[10];
    string opc = "y";
    int contador = 0;
    ifstream archivo("medicos.txt");

    if (archivo.is_open()) {  
        Medico tempDoctores[10]; // Arreglo de 10 objetos Medico
        
        int contador = 0;

        while (contador < 10 && archivo) {
            int dni, codigo;
            string nombre, apellidoP, apellidoM, especialidad, turno;

            // Leer datos del archivo
            archivo >> dni >> codigo >> nombre >> apellidoP >> apellidoM >> especialidad >> turno;

            // Crear objeto Medico y almacenarlo en el arreglo
            tempDoctores[contador].setDni(dni);
            tempDoctores[contador].setCodigo(codigo);
            tempDoctores[contador].setNombre(nombre);
            tempDoctores[contador].setApellidoP(apellidoP);
            tempDoctores[contador].setApellidoM(apellidoM);
            tempDoctores[contador].setEspecialidad(especialidad);
            tempDoctores[contador].setTurno(turno);

            // Asignar el puntero al objeto Medico al arreglo de punteros
            Doctores[contador] = &tempDoctores[contador];

            contador++;
        }
        archivo.close();
    }
    // Arreglo de punteros a objetos Paciente
    
    do {
        int ele;
        // Menú de opciones
        do {
            cout << "Ingrese su eleccion" << endl;
            cout << "1. Ver doctores y especialidad" << endl;
            cout << "2. Sacar cita" << endl;
            cout << "3. ver la informacion del paciente"<<endl;
            cin >> ele;
        } while (ele < 1 || ele > 3);

        if (ele == 1) {
            // Mostrar doctores y sus especialidades
            for (int i = 0; i < 5; i++) {
                cout << Doctores[i]->getNombre() << "   " << Doctores[i]->getEspecialidad() << endl;
            }
        } 
        if(ele==2) {
            // Proceso para sacar una cita
            bool validar = false;

            // Ingresar datos del paciente
            cout<<"ingrese su dni: ";
            cin>>dni;
            do {
                try {
                    cout << "Ingrese el codigo del doctor: ";
                    // Intentar leer un código de doctor válido
                    if (!(cin >> codigo)) {
                        throw runtime_error("Dato invalido, vuelva a intentar.");
                    }
                    validar = false;
                    for (int i = 0; i < 10; i++) {
                        if (Doctores[i] != nullptr) {
                            validar = find(codigo, Doctores[i]->getCodigo());
                            if (validar) {
                                break;
                            }
                        }
                    }
                } catch ( runtime_error& e) {
                    cerr << e.what() << endl;
                    // Limpiar el error de entrada
                    cin.clear();
                    cin.ignore();
                    validar = false;
                }
            } while (validar == false);
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
                cin>>especialidad;
                for (int i = 0; i < 10; i++) {
                    validar = find(especialidad, Doctores[i]->getEspecialidad());
                    if (validar == true) {
                        break;
                    }
                }
            } while (validar == false);

            validar = validarEnfermedad(especialidad);
           
            // Crear un nuevo objeto Paciente y agregarlo al arreglo
            pacientes[contador] = new Paciente(dni, codigo, nombre, apellidoP, apellidoM, fechaU, enfermedad, especialidad, "", "", Doctores, 10);
            contador += 1;
        }
        if (ele==3){
            do
            {
                cout<<"ingrese laconraseña para validar su identidad"<<endl;
                cin>>password;
            } while (password!="contraseña");
            for (int i=0;i<contador;i++){
                pacientes[i]->MostrarDetalles();
            }
        }
        // Preguntar si desea continuar
        cout << "Desea continuar? y or n" << endl;
        cin >> opc;
    } while (opc == "y" || opc == "Y");

    return 0;
}
