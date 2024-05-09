#include <iostream>

using namespace std;

class Banco {
private:
    static float tasaInteres;

public:
    static void setTasaInteres(float tasa) {
        tasaInteres = tasa;
    }

    static float getTasaInteres() {
        return tasaInteres;
    }
};

float Banco::tasaInteres = 0.0;

class CuentaBancaria {
private:
    float saldo;

public:
    CuentaBancaria(float saldoInicial = 0.0) : saldo(saldoInicial) {}

    void deposito(float cantidad) {
        saldo += cantidad;
    }

    void retiro(float cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    float calcularInteresGanado() const {
        return saldo * Banco::getTasaInteres() / 100.0;
    }

    float obtenerSaldo() const {
        return saldo;
    }
};

int main() {
    Banco::setTasaInteres(5.0); // Cambiamos la tasa de interés a 5%
    CuentaBancaria cuenta(1000);
    cuenta.deposito(500);
    cuenta.retiro(200);
    cout << "Saldo actual: $" << cuenta.obtenerSaldo() << endl;
    cout << "Interés ganado: $" << cuenta.calcularInteresGanado() << endl;
    return 0;
}
