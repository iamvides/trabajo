#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <string>
#include <vector>
using  namespace std;

class Control {
    private:
        string partir;
        string descripcion;
    public:
        Control(string _partir, string _descripcion) {
            partir=_partir;
            descripcion=_descripcion;
        }
        virtual void Commet()=0;
        virtual void Repartir()=0;  
        virtual void Compartir()=0;
};
#endif