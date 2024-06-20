#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

// Experiencia 1
class Producto {
public:
    string nombre;
    double precio;
    int cantidad;

    // Constructor para inicializar los atributos
    Producto(string nombre, double precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }
};

// Función para escribir un producto en el archivo
void escribirProducto(Producto producto) {
    try {
        ofstream archivo("inventario.txt", ios::app);
        if (archivo.is_open()) {
            archivo << producto.nombre << "," << producto.precio << "," << producto.cantidad << "\n";
            archivo.close();
        } else {
            throw runtime_error("Error al abrir el archivo.\n");
        }
    } catch (exception& e) {
        cerr << e.what();
    }
}

// Función para leer todos los productos del archivo
array<Producto, 100> leerProductos() {
    array<Producto, 100> productos;
    try {
        ifstream archivo("inventario.txt");
        if (archivo.is_open()) {
            string linea;
            int i = 0;
            while (getline(archivo, linea)) {
                istringstream stream(linea);
                string nombre;
                double precio;
                int cantidad;
                stream >> nombre >> precio >> cantidad;
                productos[i].nombre = nombre;
                productos[i].precio = precio;
                productos[i].cantidad = cantidad;
                i++;
            }
            archivo.close();
        } else {
            throw runtime_error("Error al abrir el archivo.\n");
        }
    } catch (exception& e) {
        cerr << e.what();
    }
    return productos;
}

// Función para escribir el índice en el archivo
void escribirIndice(Producto producto, int ubicacion) {
    try {
        ofstream archivo("indices.txt", ios::app);
        if (archivo.is_open()) {
            archivo << producto.nombre << "," << ubicacion << "\n";
            archivo.close();
        } else {
            throw runtime_error("Error al abrir el archivo.\n");
        }
    } catch (exception& e) {
        cerr << e.what();
    }
}

// Función para leer el índice
array<pair<string, int>, 100> leerIndice() {
    array<pair<string, int>, 100> indice;
    try {
        ifstream archivo("indices.txt");
        if (archivo.is_open()) {
            string linea;
            int i = 0;
            while (getline(archivo, linea)) {
                istringstream stream(linea);
                string nombre;
                int ubicacion;
                stream >> nombre >> ubicacion;
                indice[i].first = nombre;
                indice[i].second = ubicacion;
                i++;
            }
            archivo.close();
        } else {
            throw runtime_error("Error al abrir el archivo.\n");
        }
    } catch (exception& e) {
        cerr << e.what();
    }
    return indice;
}

// Función para buscar un producto por nombre
Producto buscarProducto(string nombre) {
    try {
        array<pair<string, int>, 100> indice = leerIndice();
        for (int i = 0; i < 100; i++) {
            if (indice[i].first == nombre) {
                array<Producto, 100> productos = leerProductos();
                return productos[indice[i].second];
            }
        }
    } catch (exception& e) {
        cerr << e.what();
    }
    return Producto("", 0.0, 0);
}

int main() {
    // Agregar un nuevo producto
    Producto producto("Smartphone", 500.0, 10);
    escribirProducto(producto);
    escribirIndice(producto, 0);

    // Actualizar la información de un producto
    producto.nombre = "Tablet";
    producto.precio = 300.0;
    escribirProducto(producto);
    escribirIndice(producto, 1);

    // Realizar una venta
    producto.nombre = "Smartphone";
    producto.cantidad -= 1;
    escribirProducto(producto);
    escribirIndice(producto, 0);

    // Generar un informe de inventario
    array<Producto, 100> productos = leerProductos();
    for (int i = 0; i < 100; i++) {
        if (productos[i].nombre != "") {
            cout << productos[i].nombre << " - " << productos[i].precio << " - " << productos[i].cantidad << "\n";
        }
    }

    // Buscar un producto por nombre
    string nombre = "Tablet";
    Producto productoBuscado = buscarProducto(nombre);
    cout << "Producto encontrado: " << productoBuscado.nombre << " - " << productoBuscado.precio << " - " << productoBuscado.cantidad << "\n";

    return 0;
}