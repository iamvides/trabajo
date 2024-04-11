#ifndef ACCIONES_H
#define ACCIONES_H
#include <iostream>
#include <string>
#include <vector>
#include "control.h"
using  namespace std;
class Acciones : public Control {
    private:
        string compartir;
    public:
        Acciones(string _compartir, string _partir, string _descripcion): Control(_partir, _descripcion) { // Initialize base class with appropriate arguments
            compartir = _compartir;
        }
    void Commet(){
        vector<string>comentario;
        string con;
        cout<<"ingrese algun comentario de las tareas "<<endl;
        cin >> con;
        comentario.push_back(con);
    }
    void Repartir(){
        vector<string>partes;
        string part;
        cout<<"en cuantas partes se dividira el trabajo"<<endl;
        cin>>part;
        partes.push_back(part);   
    } 
    void setCompartir(string _compartir){
        compartir=_compartir;
    }
    string getCompartir(){
        return compartir;
    }
    void Compartir(){
        cout<<"usted esta compartiendo su tarea con "+getCompartir()<<endl;
    }
};
#endif