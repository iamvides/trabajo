#include <iostream>
#include "Medico.h"
#include "Paciente.h"
#include <fstream>
using namespace std;

string enfermedadT;
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
    cin.ignore();
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
    enfermedadT=enfermedad;
    return true; // Si se encontró la enfermedad válida, retornar true
}

int main() {
    int dni=0,codigo;
    string password="password";
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

        while (contador < 10) {
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
            bool validar=false;
                cout<<"ingrese su dni:  ";
                cin>>dni;
                do {
                string conti="n";
                do
                {
                    try {
                    cout << "Ingrese el codigo del doctor: "; 
                    // Intentar leer un código de doctor válido
                    if (!(cin >> codigo)) {
                        throw runtime_error("Dato invalido, vuelva a intentar.");
                    }
                    else{
                        conti="s";
                    }
                    }
                    catch ( runtime_error& e) {
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
            pacientes[contador] = new Paciente(dni, codigo, nombre, apellidoP, apellidoM, fechaU, enfermedadT, especialidad, Doctores, 10);
            string filename = "Pacientes.txt";
            ofstream archivo(filename);
            if (archivo.is_open()) {
                archivo << "dni: " << pacientes[contador]->getDni() << endl;
                archivo << "codigo del doctor: " << pacientes[contador]->getCodigo() << endl;
                archivo << "nombre: " <<pacientes[contador]->getNombre() << endl;
                archivo << "apellido Paterno: " << pacientes[contador]->getApellidoP() << endl;
                archivo << "apellido Materno: " << pacientes[contador]->getApellidoM() << endl;
                archivo << "fecha de ultima visita: " << pacientes[contador]->getFechaU() << endl;
                archivo << "enfermedad: " << pacientes[contador]->getEnfermedad() << endl;
                archivo << "especialidad: " << pacientes[contador]->getEspecialidad() << endl;
                archivo.close();
            }      
            else {
                cout << "Error al crear el archivo " << filename << endl;
            }
            contador += 1;
        }
        if (ele==3){
            do
            {
                cout<<"ingrese el password para validar su identidad"<<endl;
                cin>>password;
            } while (password!="password");
            ifstream archivo("Pacientes.txt");
            if (archivo.is_open()) {
                string linea;
                while (getline(archivo, linea)) {
                    cout<<linea<<endl;
                }
                archivo.close();
            } 
            else {
                cout << "Error al abrir el archivo Pacientes.txt" << endl;
                
            }
        }
        // Preguntar si desea continuar
        cout << "Desea continuar? y or n" << endl;
        cin >> opc;
    } while (opc == "y" || opc == "Y");

    return 0;
}
