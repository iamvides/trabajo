#ifndef TAREA_H
#define TAREA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class tarea {
private:
    string name;
    string fecha;
    string receptor;

public:
    tarea(string _name, string _fecha, string _receptor) {
        name = _name;
        fecha = _fecha;
        receptor = _receptor;
    }
    void setName(string _name) {
        name = _name;
    }
    void setFecha(string _fecha) {
        fecha = _fecha;
    }
    void setReceptor(string _receptor) {
        receptor = _receptor;
    }
    virtual void Agregar() = 0;     //se iguala a 0 para señalar que es una funcion virtual
    string getName() {
        return name;
    }
    string getFecha() {
        return fecha;
    }
    string getReceptor() {
        return receptor;
    }
};

#endif