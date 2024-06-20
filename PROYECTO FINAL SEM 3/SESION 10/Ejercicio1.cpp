#include <iostream>
#include <string>

using namespace std;

// Clase para gestionar las rutas
class GestorDeRutas {
private:
    string rutas[100]; // Arreglo para almacenar las rutas
    int tamano;

    // Método para ordenar las rutas manualmente (burbuja)
    void ordenarRutas() {
        for (int i = 0; i < tamano - 1; ++i) {
            for (int j = 0; j < tamano - i - 1; ++j) {
                if (rutas[j] > rutas[j + 1]) {
                    string temp = rutas[j];
                    rutas[j] = rutas[j + 1];
                    rutas[j + 1] = temp;
                }
            }
        }
    }

public:
    GestorDeRutas() : tamano(0) {}

    // Método para añadir una ruta
    void agregarRuta(string ruta) {
        if (tamano < 100) { // Verificar que no se exceda el tamaño máximo del arreglo
            rutas[tamano++] = ruta;
        } else {
            cout << "No se pueden agregar más rutas. Arreglo completo." << endl;
        }
    }

    // Método para mostrar las rutas
    void mostrarRutas() {
        for (int i = 0; i < tamano; ++i) {
            cout << rutas[i] << endl;
        }
    }

    // Método para ordenar las rutas y luego imprimir
    void ordenarEImprimir() {
        ordenarRutas();
        for (int i = 0; i < tamano; ++i) {
            cout << rutas[i] << " ";
        }
        cout << endl;
    }

    // Método para obtener las rutas
    string* obtenerRutas() {
        return rutas;
    }

    // Método para obtener el tamaño actual de las rutas
    int obtenerTamano() {
        return tamano;
    }
};

int main() {
    GestorDeRutas gestor;

    // Agregar algunas rutas de prueba
    gestor.agregarRuta("Zaragoza");
    gestor.agregarRuta("Barcelona");
    gestor.agregarRuta("Madrid");
    gestor.agregarRuta("Valencia");

    cout << "Rutas ordenadas alfabéticamente:" << endl;
    gestor.ordenarEImprimir();

    return 0;
}