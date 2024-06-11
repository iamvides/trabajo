#include <iostream>
#include <cmath>
using namespace std;
class FiguraGeometrica {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPer() = 0;
};
class Circulo : public FiguraGeometrica {
public:
    double radio;
    Circulo(double r) : radio(r) {}
    double calcularArea() {
        return M_PI * pow(radio, 2);
    }    
    double calcularPer() {
        return 2 * M_PI * radio;
    }
};
class Rectangulo : public FiguraGeometrica {
public:
    double base, altura;
    Rectangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() {
        return base * altura;
    }
    double calcularPer() {
        return 2 * (base + altura);
    }
};

class Triangulo : public FiguraGeometrica {
public:
    double base, altura, lado1, lado2, lado3;
    Triangulo(double b, double a, double l1, double l2, double l3) : base(b), altura(a), lado1(l1), lado2(l2), lado3(l3) {}
    double calcularArea() {
        return (base * altura)/2;
    }
    double calcularPer() {
        return lado1 + lado2 + lado3;
    }
};
int main() {
    const int numFiguras = 3;
    FiguraGeometrica* figuras[numFiguras];
    figuras[0] = new Circulo(5.4);
    figuras[1] = new Rectangulo(5.6, 9.8);
    figuras[2] = new Triangulo(6.7, 8.3, 5.1, 7.2, 4.9);
    for (int i = 0; i < numFiguras; ++i) {
        cout << "Figura " << i + 1 << ":" << endl;
        cout << "Área: " << figuras[i]->calcularArea() << endl;
        cout << "Perímetro: " << figuras[i]->calcularPer() << endl;
    }
    return 0;
}
