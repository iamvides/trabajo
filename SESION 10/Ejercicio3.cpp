#include <iostream>

using namespace std;

template <typename T>
class Recipiente {
private:
    T* arreglo;
    int capacidad;
    int tamano;

public:
    // Constructor
    Recipiente(int cap) : capacidad(cap), tamano(0) {
        arreglo = new T[capacidad];
    }

    // Agregar un elemento
    void agregar(T elemento) {
        if (tamano < capacidad) {
            arreglo[tamano++] = elemento;
        } else {
            cout << "Recipiente lleno. No se puede agregar el elemento." << endl;
        }
    }

    // Obtener un elemento por índice
    T obtener(int indice) {
        if (indice >= 0 && indice < tamano) {
            return arreglo[indice];
        } else {
            cout << "Índice fuera de rango" << endl;
            return T(); // Devuelve el valor por defecto del tipo T
        }
    }

    // Eliminar el último elemento
    void eliminar() {
        if (tamano > 0) {
            tamano--;
        } else {
            cout << "Recipiente vacío. No se puede eliminar el elemento." << endl;
        }
    }

    // Obtener el tamaño actual del recipiente
    int obtenerTamano() {
        return tamano;
    }

    // Ordenar el arreglo y imprimir los elementos ordenados
    void ordenarEImprimir() {
        // Implementación simple de burbuja para el ordenamiento
        for (int i = 0; i < tamano - 1; i++) {
            for (int j = 0; j < tamano - i - 1; j++) {
                if (arreglo[j] > arreglo[j + 1]) {
                    T temp = arreglo[j];
                    arreglo[j] = arreglo[j + 1];
                    arreglo[j + 1] = temp;
                }
            }
        }

        // Imprimir el arreglo ordenado
        cout << "Arreglo ordenado: ";
        for (int i = 0; i < tamano; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Crear un recipiente para enteros con capacidad de 5 elementos
    Recipiente<int> recipienteEnteros(5);

    // Agregar elementos
    recipienteEnteros.agregar(5);
    recipienteEnteros.agregar(2);
    recipienteEnteros.agregar(9);
    recipienteEnteros.agregar(1);
    recipienteEnteros.agregar(7);

    // Imprimir elementos
    for (int i = 0; i < recipienteEnteros.obtenerTamano(); i++) {
        cout << "Elemento en el índice " << i << ": " << recipienteEnteros.obtener(i) << endl;
    }

    // Ordenar e imprimir elementos
    recipienteEnteros.ordenarEImprimir();

    // Eliminar un elemento
    recipienteEnteros.eliminar();
    cout << "Tamaño después de eliminar: " << recipienteEnteros.obtenerTamano() << endl;

    return 0;
}
