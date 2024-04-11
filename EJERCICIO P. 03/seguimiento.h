#ifndef SEGUIMIENTO_H
#define SEGUIMIENTO_H
#include <iostream>
#include <string>
#include <vector>
#include "tarea.h"
using namespace std;
class Seguimiento : public tarea {
private:
    vector<string> tareas;
    vector<string> avance;
    string porcentaje;
public:
    Seguimiento(string _name, string _fecha, string _receptor): tarea(_name, _fecha, _receptor) {
    }
    void Agregar() {
        string agregar = "La tarea " + getName() + " fue asignada para " + getReceptor() + " hasta la fecha " + getFecha();
        tareas.push_back(agregar);
    }
    vector<string> getTareas() {
        return tareas;
    }
    void setPorcentaje(string _porcentaje){
        porcentaje=_porcentaje;
    }
    string getPorcentaje(){
        return porcentaje;
    }
    void Progreso() {
        string add = getPorcentaje();
        avance.push_back(add);
    }
    vector<string> getAvance() {
        return avance;
    }
    void imprimirTareas(){
        for (size_t i = 0; i < tareas.size(); i++) {    //usamos size_t porque es un tipo de dato mas practico para los vectores
        cout << tareas[i] << endl;
    }
    }
    void resultados() {
    for (size_t i = 0; i < tareas.size(); i++) {    //usamos size_t porque es un tipo de dato mas practico para los vectores
        cout << tareas[i] << endl;
    }
    for (size_t i = 0; i < avance.size(); i++) {    //size_t asegura que se recorrera todo el vector
        cout << avance[i] << endl;
    }
}
};
#endif