#include <iostream>
using namespace std;

class Vehiculo {
public:
    virtual void acelerar() {
        cout << "Acelerando el vehículo" << endl;
    }
};

class Coche : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces() {
        cout << "Luces del coche encendidas" << endl;
    }
};

class Motocicleta : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando la motocicleta" << endl;
    }
};

int main() {
    Coche coche;
    Motocicleta moto;

    coche.acelerar();      
    moto.acelerar();        
    coche.encenderLuces();  

    return 0;
}
