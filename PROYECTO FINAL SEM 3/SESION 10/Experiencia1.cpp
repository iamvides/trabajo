#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
double calculoDistancia(T coorx1, T coory1, T coorx2, T coory2) {
    return sqrt(pow((coorx2-coorx1),2) + pow((coory2-coory1),2));
}
template <typename T>
double tiempoEstimado(T distancia, T velocidad) {
    return distancia / velocidad;
}
template <typename T>
void generarReporte(T deliverys[], int cantidad) {
    cout << "Reporte de entregas: " << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Entrega: " << deliverys[i] << endl;
    }
}
int main() {
    double distancia = calculoDistancia(1.2, 3.2, 9.456, 7.89213);
    double tiempo = tiempoEstimado(2.4,12.8);
    string entregas[] = {"Entrega de iPhone 15 Pro Max", "Entrega de Asus TUF Gaming", "Entrega de pantalones Baggy"};
    int cantidad = sizeof(entregas) / sizeof(entregas[0]);
    generarReporte(entregas, cantidad);
    cout << distancia << endl;
    cout << tiempo << endl;
    return 0;
}