#include <iostream>
#include <cmath>
using namespace std;

class Circulo {
private:
    float radio;
    float diametro;

public:
    Circulo(float r) : radio(r), diametro(2 * r) {}

    friend float calcularArea(const Circulo& c);

    float obtenerRadio() const {
        return radio;
    }

    float obtenerDiametro() const {
        return diametro;
    }
};

float calcularArea(const Circulo& c) {
    float area = M_PI * pow(c.radio, 2);
    return area;
}

int main() {
    Circulo circulo1(188.9);
    Circulo circulo2(12.9);
    cout << "Área del círculo 1 con radio " << circulo1.obtenerRadio() << ": " << calcularArea(circulo1) << endl;
    cout << "Área del círculo 2 con radio " << circulo2.obtenerRadio() << ": " << calcularArea(circulo2) << endl;
    return 0;
}
