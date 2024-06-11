#include <iostream>
#include <cmath>
using namespace std;

class Figura {
public:
    virtual double calcularArea() = 0;
};

class Circulo : public Figura {
public:
    double radio;
    Circulo(double r) : radio(r) {}
    double calcularArea()  {
        return M_PI * pow(radio, 2);
    }
};

class Rectangulo : public Figura {
public:
    double base, altura;
    Rectangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() {
        return base * altura;
    }
};

class Triangulo : public Figura {
public:
    double base, altura;
    Triangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() {
        return (base * altura) / 2;
    }
};

int main() {
    int numFiguras = 3;
    Figura* figuras[numFiguras];
    figuras[0] = new Circulo(5.4);
    figuras[1] = new Rectangulo(5.6, 9.8);
    figuras[2] = new Triangulo(6.7, 8.3);
    for (int i = 0; i < numFiguras; i++) {
        cout << "El área de la figura " << i + 1 << " es " << figuras[i]->calcularArea() << endl;
    }
    return 0;
}
