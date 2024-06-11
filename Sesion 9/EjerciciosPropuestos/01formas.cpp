#include <iostream>
using namespace std;

class Figura{
    public:
        Figura(){};
        virtual double area()=0;
        virtual double perimetro()=0;
        virtual void mostrar()=0;
};

class Cuadrado:public Figura{
    private:
        double lado;
    public:
        Cuadrado(double _lado){
            lado = _lado;
        }
        double area() { 
            return lado * lado; 
        }
        double perimetro() { 
            return 4 * lado; 
        }
        void mostrar() {
            cout << "Figura: Cuadrado" << endl;
            cout << "Numero de lados: 4" << endl;
            cout << "Lado: " << lado << endl;
            cout << "Area: " << area() << endl;
            cout << "Perimetro: " << perimetro() << endl;
        }
};

class Triangulo:public Figura{
    private:
        double base;
        double altura;
        double lado1, lado2, lado3;
    public:
        Triangulo(double _base, double _altura, double _lado1, double _lado2, double _lado3){
            base = _base;
            altura = _altura;
            lado1 = _lado1;
            lado2 = _lado2;
            lado3 = _lado3;
        }
        double area() {
            return (base * altura)/2;
        }
        double perimetro() { 
            return lado1 + lado2 + lado3;
        }
        void mostrar() {
            cout << "Figura: Triangulo" << endl;
            cout << "Numero de lados: 3" << endl;
            cout << "Base: " << base << endl;
            cout << "Altura: " << altura << endl;
            cout << "Lado 1: " << lado1 << endl;
            cout << "Lado 2: " << lado2 << endl;
            cout << "Lado 3: " << lado3 << endl;
            cout << "Area: " << area() << endl;
            cout << "Perimetro: " << perimetro() << endl;
        }
};

class Rectangulo:public Figura{
    private:
        double ancho;
        double alto;
    public:
        Rectangulo(double _ancho, double _alto){
            ancho = _ancho;
            alto = _alto;
        }
        double area() {
            return ancho * alto; 
        }
        double perimetro() { 
            return 2 * (ancho + alto); 
        }
        void mostrar() {
            cout << "Figura: Rectangulo" << endl;
            cout << "Numero de lados: 4" << endl;
            cout << "Ancho: " << ancho << endl;
            cout << "Alto: " << alto << endl;
            cout << "Area: " << area() << endl;
            cout << "Perimetro: " << perimetro() << endl;
        }
};

int main(){
    Cuadrado cuadrado(5.0);
    Triangulo triangulo(3.0, 4.0, 5.0, 6.0, 7.0);
    Rectangulo rectangulo(4.0, 6.0);

    cuadrado.mostrar();
    cout << endl;
    triangulo.mostrar();
    cout << endl;
    rectangulo.mostrar();

    return 0;
}