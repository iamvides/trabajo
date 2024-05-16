#include <iostream>
#include <string>
using namespace std;
class Vehiculo {
public:
    string marca;
    string modelo;
    int ano;
    float precio;

    Vehiculo(string m, string md, int a, float p) :
        marca(m), modelo(md), ano(a), precio(p) {}
};

class Automovil : public Vehiculo {
public:
    int numPuertas;
    string tipoCombustible;

    Automovil(string _marca, string _modelo, int _ano, float _precio, int np, string tc) :
        Vehiculo(_marca, _modelo, _ano, _precio), numPuertas(np), tipoCombustible(tc) {}
};

class Motocicleta : public Vehiculo {
public:
    float cilindrada;

    Motocicleta(string _marca, string _modelo, int _ano, float _precio, float c) :
        Vehiculo(_marca, _modelo, _ano, _precio), cilindrada(c) {}
};

int main() {
    Automovil autoExample("Toyota", "Corolla", 2020, 20000.0, 4, "Gasoline");
    Motocicleta motoExample("Honda", "CBR600RR", 2019, 15000.0, 599.0);

    cout << "Automovil: " << autoExample.marca << ", " << autoExample.modelo <<
        ", " << autoExample.ano << ", " << autoExample.precio << ", " <<
        autoExample.numPuertas << ", " << autoExample.tipoCombustible << endl;

    cout << "Motocicleta: " << motoExample.marca << ", " << motoExample.modelo <<
        ", " << motoExample.ano << ", " << motoExample.precio << ", " <<
        motoExample.cilindrada << endl;

    return 0;
}
