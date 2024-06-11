#include <iostream>
using namespace std;

class Producto {
public:
    Producto() {}
    virtual double calcularValorTotal() = 0;
    virtual void aplicarDescuento(double descuento) = 0;
    virtual void mostrarInformacion() = 0;
};

class Electronico : public Producto {
private:
    double precio;
public:
    Electronico(double precio) : precio(precio) {}
    double calcularValorTotal() {
        return precio;
    }
    void aplicarDescuento(double descuento) {
        precio -= precio * descuento / 100;
    }
    void mostrarInformacion() {
        cout << "Producto: Electronico" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Valor total: $" << calcularValorTotal() << endl;
    }
};

class Ropa : public Producto {
private:
    double precio;
public:
    Ropa(double precio) : precio(precio) {}
    double calcularValorTotal() {
        return precio;
    }
    void aplicarDescuento(double descuento) {
        precio -= precio * descuento / 100;
    }
    void mostrarInformacion() {
        cout << "Producto: Ropa" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Valor total: $" << calcularValorTotal() << endl;
    }
};

class Alimento : public Producto {
private:
    double precio;
    int cantidad;
public:
    Alimento(double precio, int cantidad) : precio(precio), cantidad(cantidad) {}
    double calcularValorTotal() {
        return precio * cantidad;
    }
    void aplicarDescuento(double descuento) {
        precio -= precio * descuento / 100;
    }
    void mostrarInformacion() {
        cout << "Producto: Alimento" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Valor total: $" << calcularValorTotal() << endl;
    }
};

int main() {
    Electronico electronico(500.0);
    Ropa ropa(200.0);
    Alimento alimento(10.0, 5);

    cout << "Sistema de Gestión de Inventario" << endl;
    cout << "---------------------------" << endl;

    cout << "Producto: Electronico" << endl;
    electronico.mostrarInformacion();
    cout << "Aplicar descuento del 10%..." << endl;
    electronico.aplicarDescuento(10);
    cout << "Valor total con descuento: $" << electronico.calcularValorTotal() << endl;
    cout << endl;

    cout << "Producto: Ropa" << endl;
    ropa.mostrarInformacion();
    cout << "Aplicar descuento del 15%..." << endl;
    ropa.aplicarDescuento(15);
    cout << "Valor total con descuento: $" << ropa.calcularValorTotal() << endl;
    cout << endl;

    cout << "Producto: Alimento" << endl;
    alimento.mostrarInformacion();
    cout << "Aplicar descuento del 20%..." << endl;
    alimento.aplicarDescuento(20);
    cout << "Valor total con descuento: $" << alimento.calcularValorTotal() << endl;
    cout << endl;

    return 0;
}