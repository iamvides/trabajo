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
        cout << "Movil constructor called" << endl;
    }

    ~Movil() {
        cout << "Movil destructor called" << endl;
    }
};

class Telefono : public Movil {
public:
    int numero_telefono;

    Telefono(string marca, string modelo, string sistema_operativo, int numero_telefono)
        : Movil(marca, modelo, sistema_operativo), numero_telefono(numero_telefono) {
        cout << "Telefono constructor called" << endl;
    }

    ~Telefono() {
        cout << "Telefono destructor called" << endl;
    }
};

class Tablet : public Movil {
public:
    float pantalla_tactil_tamano;

    Tablet(string marca, string modelo, string sistema_operativo, float pantalla_tactil_tamano)
        : Movil(marca, modelo, sistema_operativo), pantalla_tactil_tamano(pantalla_tactil_tamano) {
        cout << "Tablet constructor called" << endl;
    }

    ~Tablet() {
        cout << "Tablet destructor called" << endl;
    }
};

int main() {
    Telefono te("Samsung", "Galaxy S22 ULTRA", "Android", 959031095);
    Tablet ta("Apple", "iPad Pro", "iOS", 10.5);

    return 0;
}