#include <iostream>
#include <cmath>
using namespace std;
class Figura {
public:
    virtual float calcularArea() = 0;
};
class Circulo : public Figura {
public:
    float radio;
    Circulo(float _radio) : radio(_radio) {}
    float calcularArea() {
        return M_PI * pow(radio, 2);
    }
};
class Rectangulo : public Figura {
public:
    float ancho, alto;
    Rectangulo(float _ancho, float _alto) : ancho(_ancho), alto(_alto) {}
    float calcularArea() {
        return ancho*alto;
    }
};
class Triangulo : public Figura {
public:
    float base, altura;
    Triangulo(float _base, float _altura) : base(_base), altura(_altura) {}
    float calcularArea() {
        return (base*altura)/2;
    }
};

int main() {
    Circulo circulo(15.6);
    Rectangulo rectangulo(10, 6);
    Triangulo triangulo(12,17);
    cout << "Área del circulo: " << circulo.calcularArea() << endl;
    cout << "Area del rectangulo: " << rectangulo.calcularArea() << endl;
    cout << "Área del triangulo: " << triangulo.calcularArea() << endl;
    return 0;
}