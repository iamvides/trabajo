#include "registro.h"
#include "alumno.h"
#include <iostream>
using namespace std;
int main() {
    int option;
    string nombre, email, contra, card;
    int suscripcion;
    string uni="";
    string opc = "SI";
    string estafa = "NO";
    Registro reg;
    Alumno alum(reg, uni);
    do {
        cout << "Bienvenido al sistema de registro" << endl;
        cout << "1. Registrarse como usuario personal" << endl;
        cout << "2. Registrarse como usuario institucional" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Ingrese su nombre: "<<endl;
                cin>>nombre;
                reg.setName(nombre);
                cout << "Ingrese su correo electronico: ";
                cin>>email;
                reg.setEmail(email);
                cout << "Ingrese su contraseña: ";
                cin>>contra;
                reg.setPassword(contra),
                cout << "Desea suscribirse a un plan? SI/NO: ";
                cin>>estafa;
                if (estafa == "SI") {
                    cout << "Elija un paquete: " << endl;
                    cout << "1. Cliente" << endl;
                    cout << "2. Premium" << endl;
                    cout << "3. Premium++" << endl;
                    cout << "Ingrese su opcion: "<< endl;
                    cin >> suscripcion;
                    cout << "Ingrese los datos de su tarjeta: "<< endl;
                    cin >> card;
                break;
                case 2:
                      cout << "Ingrese su nombre: "<<endl;
                    cin>>nombre;
                    reg.setName(nombre);
                    cout << "Ingrese su correo electronico: ";
                    cin>>email;
                    reg.setEmail(email);
                    cout << "Ingrese su contraseña: ";
                    cin>>contra;
                    reg.setPassword(contra),
                    cout << "Ingrese el nombre de su universidad: "<< endl;
                    cin>> uni;
                    alum.setUniversidad(uni);
                    break;
                case 3:
                    cout << "Felicidades su inscripcion esta completa, hasta luego " <<reg.getName() << endl;
                    break;
                default:
                    cout << "Opcion invalida, intente de nuevo." << endl;
                    break;
            }
        } 
        cout << "Desea continuar? SI/NO" << endl;
        cin >> opc;
    }while (opc == "SI");
    return 0;
}