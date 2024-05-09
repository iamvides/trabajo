#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Estudiante {
public:
    string nombre;
    int edad;
    vector<float> notas;

    Estudiante(string nombre, int edad, vector<float> notas) {
        this->nombre = nombre;
        this->edad = edad;
        this->notas = notas;
    }

    float calcularPromedio() const {
        float suma = 0;
        for (float nota : notas) {
            suma += nota;
        }
        return suma / notas.size();
    }
};

bool compararPorPromedio(const Estudiante& estudiante1, const Estudiante& estudiante2) {
    return estudiante1.calcularPromedio() > estudiante2.calcularPromedio();
}

void estudiantesMejorProm(const vector<Estudiante>& estudiantes, float notaMinima) {
    cout << "Estudiantes con promedio mayor a " << notaMinima << ":" << endl;
    for (const Estudiante& estudiante : estudiantes) {
        if (estudiante.calcularPromedio() > notaMinima) {
            cout << "Nombre: " << estudiante.nombre << ", Edad: " << estudiante.edad << ", Promedio: " << estudiante.calcularPromedio() << endl;
        }
    }
}

int main() {
    vector<Estudiante> estudiantes;
    estudiantes.push_back(Estudiante("Tamara Martinez", 17, { 15.5, 17.6, 14.3 }));
    estudiantes.push_back(Estudiante("Alexander Velasquez", 30, { 18.3, 16.9, 15.4 }));
    estudiantes.push_back(Estudiante("Miguel Bejarano", 18, { 19.3, 10.4, 18.5 }));
    sort(estudiantes.begin(), estudiantes.end(), compararPorPromedio);
    estudiantesMejorProm(estudiantes, 8.0);

    return 0;
}
