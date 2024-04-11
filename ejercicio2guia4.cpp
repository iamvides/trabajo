#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Producto {
public:
    string codigo;
    string descripcion;
    double precio;
    string proveedor;

    Producto(string _codigo, string _descripcion, double _precio, string _proveedor) : codigo(_codigo), descripcion(_descripcion), precio(_precio), proveedor(_proveedor) {}
};

class Cliente {
public:
    string nombre;
    string direccion;
    string telefono;
    vector<Producto> compras_realizadas;

    Cliente(string _nombre, string _direccion, string _telefono) : nombre(_nombre), direccion(_direccion), telefono(_telefono) {}

    void agregar_compra(Producto producto) {
        compras_realizadas.push_back(producto);
    }
};

class Venta {
public:
    int numero_factura;
    time_t fecha;
    Cliente cliente;
    vector<Producto> productos_vendidos;

    Venta(int _numero_factura, Cliente _cliente) : numero_factura(_numero_factura), cliente(_cliente) {
        fecha = time(0);
    }

    void agregar_producto(Producto producto) {
        productos_vendidos.push_back(producto);
    }
};

class Pago {
public:
    Cliente cliente;
    double monto;
    time_t fecha;

    Pago(Cliente _cliente, double _monto) : cliente(_cliente), monto(_monto) {
        fecha = time(0);
    }
};

int main() {
    Cliente cliente1("Tamara Martinez", "Av. Aviacion 512 Cerro Colorado", "981237123");
    Cliente cliente2("Sebastian Chavez", "Av. España 410", "928012381");

    Producto producto1("001", "Polera Adidas", 80.50, "Adidas");
    Producto producto2("002", "Polo Nike", 100.75, "Nike");

    Venta venta1(4593, cliente1);
    venta1.agregar_producto(producto1);
    venta1.agregar_producto(producto2);

    Pago pago_cliente1(cliente1, 200.00);

    cliente1.agregar_compra(producto1);
    cliente1.agregar_compra(producto2);

    cout << "Cliente: " << cliente1.nombre << endl;
    cout << "Dirección: " << cliente1.direccion << endl;
    cout << "Teléfono: " << cliente1.telefono << endl;
    cout << "Compras realizadas:" << endl;
    for (Producto compra : cliente1.compras_realizadas) {
        cout << "  Producto: " << compra.descripcion << endl;
        cout << "  Precio: S/. " << compra.precio << endl << endl;
    }

    cout << "Venta N°: " << venta1.numero_factura << endl << "Fecha: " << ctime(&venta1.fecha) << "Cliente: " << venta1.cliente.nombre << endl << "Productos vendidos:" << endl;
    for (Producto producto : venta1.productos_vendidos) {
        cout << "  Descripción: " << producto.descripcion << endl;
        cout << "  Precio: S/. " << producto.precio << endl << endl;
    }

    cout << "Pago de S/. " << pago_cliente1.monto << " realizado por " << pago_cliente1.cliente.nombre << " el " << ctime(&pago_cliente1.fecha);

    return 0;
}
