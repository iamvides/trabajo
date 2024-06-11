#include <iostream>
using namespace std;
class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }
    double sumar(double a, double b) {
        return a + b;
    }
    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculadora calc;
    int suma1 = calc.sumar(12,14);
    double suma2 = calc.sumar(12.3454,19.2141);
    int suma3 = calc.sumar(15,30,45);
    cout << "Resultados de las sumas: " << endl << suma1 << endl << suma2 << endl << suma3 << endl;
    return 0;
 }