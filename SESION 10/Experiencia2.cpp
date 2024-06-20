#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Ruta {
public:
    int id;
    string origen;
    string destino;
    
    Ruta(int id, string origen, string destino) : id(id), origen(origen), destino(destino) {}

    template <typename V>
    void asignarVehiculo(V vehiculo) {
        cout << "Vehículo asignado: " << vehiculo << endl;
    }

    template <typename T>
    double calculoDistancia(T coorx1, T coory1, T coorx2, T coory2) {
        return sqrt(pow((coorx2 - coorx1), 2) + pow((coory2 - coory1), 2));
    }
};

class Entrega {
public:
    string fecha_entrega;
    string estado;
    string cliente;
    Ruta ruta;

    Entrega(string fecha_entrega, string estado, string cliente, Ruta ruta) : fecha_entrega(fecha_entrega), estado(estado), cliente(cliente), ruta(ruta) {}

    template <typename T>
    void planificarHorario(T horario) {
        cout << "Horario planificado: " << horario << endl;
    }
};

int main() {
    Ruta ruta1(1, "Camaná", "Mollendo");
    double distancia = ruta1.calculoDistancia(1.123, 5.2341, 8.34, 9.45);
    cout << "Distancia de la ruta 1: " << distancia << endl;
    ruta1.asignarVehiculo("Aveo LT Chevrolet");
    Entrega entrega("2024-06-30", "Pendiente", "Cliente XYZ", ruta1);
    string horario = "10:00 AM";
    entrega.planificarHorario(horario);
    return 0;
}
