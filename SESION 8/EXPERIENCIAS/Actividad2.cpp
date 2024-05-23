#include <iostream>
#include <cmath>
using namespace std;

class Forma {
public:
    virtual float calcularPerimetro() = 0;
};

class Circulo : public Forma {
public:
    float radio;
    Circulo(float _radio) : radio(_radio) {}
    float calcularPerimetro() {
        return 2 * M_PI * radio;
    }
};

class Rectangulo : public Forma {
public:
    float alto;
    float ancho;
    Rectangulo(float _alto, float _ancho) : alto(_alto), ancho(_ancho) {}
    float calcularPerimetro() {
        return 2 * (alto + ancho);
    }
};

int main() {
    Circulo circulo1(12.5);
    Rectangulo rectangulo1(15.3, 4);
    cout << "Perímetro del círculo: " << circulo1.calcularPerimetro() << endl;
    cout << "Perímetro del rectángulo: " << rectangulo1.calcularPerimetro() << endl;
    return 0;
}