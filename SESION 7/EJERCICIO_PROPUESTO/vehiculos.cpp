#include <iostream>
#include <string>
using namespace std;
class Vehiculo {
public:
    string marca;
    string modelo;
    int year;
    float precio;

    Vehiculo(string m, string md, int y, float p) :
        marca(m), modelo(md), year(y), precio(p) {}
};

class Automovil : public Vehiculo {
public:
    int numPuertas;
    string tipoCombustible;

    Automovil(string _marca, string _modelo, int _year, float _price, int np, string tc) :
        Vehiculo(_marca, _modelo, _year, _price), numPuertas(np), tipoCombustible(tc) {}
};

class Motocicleta : public Vehiculo {
public:
    float cilindrada;

    Motocicleta(string _marca, string _modelo, int _year, float _price, float c) :
        Vehiculo(_marca, _modelo, _year, _price), cilindrada(c) {}
};

int main() {
    Automovil autoExample("Toyota", "Corolla", 2020, 20000.0, 4, "Gasoline");
    Motocicleta motoExample("Honda", "CBR600RR", 2019, 15000.0, 599.0);

    std::cout << "Automovil: " << autoExample.marca << ", " << autoExample.modelo <<
        ", " << autoExample.year << ", " << autoExample.precio << ", " <<
        autoExample.numPuertas << ", " << autoExample.tipoCombustible << std::endl;

    std::cout << "Motocicleta: " << motoExample.marca << ", " << motoExample.modelo <<
        ", " << motoExample.year << ", " << motoExample.precio << ", " <<
        motoExample.cilindrada << std::endl;

    return 0;
}