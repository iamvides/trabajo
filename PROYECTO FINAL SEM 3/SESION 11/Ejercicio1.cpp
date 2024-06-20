#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Solicitar el nombre del archivo al usuario
    string nombreArchivo;
    cout << "Introduce el nombre del archivo: ";
    cin >> nombreArchivo;

    // Leer el contenido del archivo
    string contenido;
    try {
        ifstream archivo(nombreArchivo);
        if (!archivo) {
            throw runtime_error("Error: El archivo no existe.");
        }
        string linea;
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();

        // Mostrar el contenido del archivo
        cout << "Contenido del archivo:\n";
        cout << contenido;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}