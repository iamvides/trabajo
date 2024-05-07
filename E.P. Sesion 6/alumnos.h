#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <iostream>
using namespace std;
class Alumno
{
    public:
        string nombre;
        int edad;
        float promedio;
        Alumno();
        Alumno(string,int,float);       //constructor
        void str();             //muestra los atributos
        bool it(float);   //método que compara el promedio del objeto actual con el promedio del objeto otro
};
Alumno::Alumno() : nombre(""), edad(0), promedio(0.0) {}
Alumno::Alumno(string _nombre, int _edad, float _promedio)
{
    nombre=_nombre;
    edad=_edad;
    promedio=_promedio;
}
void Alumno::str()
{
    cout<<nombre<<" "<<edad<<" "<<promedio<<endl;
}
bool Alumno::it(float _promedio)
{
    if(_promedio>promedio){
        return true;
    }
    return false;
}
#endif