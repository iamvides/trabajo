#include <iostream>
#include <string>

using namespace std;

class Movil {
public:
    string marca;
    string modelo;
    string sistema_operativo;

    Movil(string marca, string modelo, string sistema_operativo)
        : marca(marca), modelo(modelo), sistema_operativo(sistema_operativo) {
        cout << "Se ejecuta el constructor de Movil" << endl;
    }

    ~Movil() {
        cout << "Se ejecuta el destructor de Movil" << endl;
    }
};

class Telefono : public Movil {
public:
    int numero_telefono;

    Telefono(string marca, string modelo, string sistema_operativo, int numero_telefono)
        : Movil(marca, modelo, sistema_operativo), numero_telefono(numero_telefono) {
        cout << "Se ejecuta el constructor de Telefono" << endl;
    }

    ~Telefono() {
        cout << "Se ejecuta el destructor de Telefono" << endl;
    }
};

class Tablet : public Movil {
public:
    float pantalla_tactil_tamano;

    Tablet(string marca, string modelo, string sistema_operativo, float pantalla_tactil_tamano)
        : Movil(marca, modelo, sistema_operativo), pantalla_tactil_tamano(pantalla_tactil_tamano) {
        cout << "Se ejecuta el constructor de Telefono" << endl;
    }

    ~Tablet() {
        cout << "Se ejecuta el destructor de Tablet" << endl;
    }
};

int main() {
    Telefono te("Samsung", "Galaxy S22 ULTRA", "Android", 959031095);
    Tablet ta("Apple", "iPad Pro", "iOS", 10.5);

    return 0;
}
