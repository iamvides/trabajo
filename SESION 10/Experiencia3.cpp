#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Clase para gestionar las rutas
template <typename T>
class GestorDeRutas {
private:
    T rutas[100][2]; // Arreglo para almacenar las coordenadas (x, y) de las rutas
    int tamano;

    // Método para ordenar las rutas manualmente
    void ordenarRutas() {
        for (int i = 0; i < tamano - 1; ++i) {
            for (int j = i + 1; j < tamano; ++j) {
                if (calculoDistancia(rutas[i][0], rutas[i][1], rutas[j][0], rutas[j][1]) >
                    calculoDistancia(rutas[j][0], rutas[j][1], rutas[i][0], rutas[i][1])) {
                    swap(rutas[i], rutas[j]);
                }
            }
        }
    }

    // Método para calcular la distancia entre dos puntos (simulación)
    double calculoDistancia(T coorx1, T coory1, T coorx2, T coory2) {
        return sqrt(pow((coorx2 - coorx1), 2) + pow((coory2 - coory1), 2));
    }

public:
    GestorDeRutas() : tamano(0) {}

    // Método para añadir una ruta con coordenadas (x, y)
    void agregarRuta(T x, T y) {
        if (tamano < 100) { // Verificar que no se exceda el tamaño máximo del arreglo
            rutas[tamano][0] = x;
            rutas[tamano][1] = y;
            ++tamano;
        } else {
            cout << "No se pueden agregar más rutas. Arreglo completo." << endl;
        }
    }

    // Método para eliminar una ruta
    void eliminarRuta(T x, T y) {
        for (int i = 0; i < tamano; ++i) {
            if (rutas[i][0] == x && rutas[i][1] == y) {
                for (int j = i; j < tamano - 1; ++j) {
                    rutas[j][0] = rutas[j + 1][0];
                    rutas[j][1] = rutas[j + 1][1];
                }
                --tamano;
                break;
            }
        }
    }

    // Método para mostrar las rutas
    void mostrarRutas() {
        for (int i = 0; i < tamano; ++i) {
            cout << "Ruta " << i + 1 << ": (" << rutas[i][0] << ", " << rutas[i][1] << ")" << endl;
        }
    }

    // Método para optimizar las rutas por distancia
    void optimizarRutas() {
        ordenarRutas();
    }

    // Método para obtener las rutas (nuevo método)
    T (*obtenerRutas())[2] {
        return rutas;
    }

    // Método para obtener el tamaño actual de las rutas
    int obtenerTamano() {
        return tamano;
    }
};

// Clase principal del sistema de gestión de rutas
class SistemaDeEntrega {
private:
    GestorDeRutas<double> gestorDeRutas; // Tipo double para las coordenadas

public:
    // Función para añadir una ruta de entrega
    void agregarRutaDeEntrega(double x, double y) {
        gestorDeRutas.agregarRuta(x, y);
    }

    // Función para eliminar una ruta de entrega
    void eliminarRutaDeEntrega(double x, double y) {
        gestorDeRutas.eliminarRuta(x, y);
    }

    // Función para optimizar las rutas de entrega
    void optimizarRutasDeEntrega() {
        gestorDeRutas.optimizarRutas();
    }

    // Función para mostrar las rutas de entrega
    void mostrarRutasDeEntrega() {
        gestorDeRutas.mostrarRutas();
    }

    // Función para obtener las rutas de entrega (nuevo método)
    double (*obtenerRutasDeEntrega())[2] {
        return gestorDeRutas.obtenerRutas();
    }

    // Función para obtener el tamaño actual de las rutas de entrega
    int obtenerTamanoRutasDeEntrega() {
        return gestorDeRutas.obtenerTamano();
    }
};

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "Sistema de Entrega" << endl;
    cout << "1. Agregar ruta de entrega" << endl;
    cout << "2. Eliminar ruta de entrega" << endl;
    cout << "3. Mostrar rutas de entrega" << endl;
    cout << "4. Optimizar rutas de entrega (por distancia)" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";
}

int main() {
    SistemaDeEntrega sistemaDeEntrega;
    int opcion;
    double x, y;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese las coordenadas (x y) de la ruta de entrega: ";
            cin >> x >> y;
            sistemaDeEntrega.agregarRutaDeEntrega(x, y);
            break;
        case 2:
            cout << "Ingrese las coordenadas (x y) de la ruta de entrega a eliminar: ";
            cin >> x >> y;
            sistemaDeEntrega.eliminarRutaDeEntrega(x, y);
            break;
        case 3:
            cout << "Rutas de entrega:" << endl;
            sistemaDeEntrega.mostrarRutasDeEntrega();
            break;
        case 4:
            sistemaDeEntrega.optimizarRutasDeEntrega();
            cout << "Rutas optimizadas por distancia." << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }

        // Imprimir las rutas
        if (opcion == 3 || opcion == 4) {
            cout << "Rutas actuales:" << endl;
            double (*rutas)[2] = sistemaDeEntrega.obtenerRutasDeEntrega();
            int tamano = sistemaDeEntrega.obtenerTamanoRutasDeEntrega();
            for (int i = 0; i < tamano; ++i) {
                cout << "(" << rutas[i][0] << ", " << rutas[i][1] << ") ";
            }
            cout << endl;
        }

    } while (opcion != 5);

    return 0;
}
