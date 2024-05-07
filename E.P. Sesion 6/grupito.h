#ifndef GRUPO_H
#define GRUPO_H
#include <iostream>
#include "alumnos.h"
using namespace std;
class Grupo
{
    private:
        int cantidad;
        Alumno alu[6];
    public:
        Grupo(Alumno obj1,Alumno obj2,Alumno obj3,Alumno obj4,Alumno obj5, int);
        void _str();
        void agregar_alumno(string,int,float);  //método que retorna una cadena de caracteres que representa al objeto Grupo
        void ordenar_por_promedio();
        void promedio_grupo();
        void mejor_promedio();
};
Grupo::Grupo(Alumno obj1, Alumno obj2, Alumno obj3, Alumno obj4, Alumno obj5, int _cantidad)
: cantidad(_cantidad)
{
    alu[0] = obj1;
    alu[1] = obj2;
    alu[2] = obj3;
    alu[3] = obj4;
    alu[4] = obj5;
}
void Grupo::_str()
{
    for (int i=0;i<5;i++)
    {
        cout<<alu[i].nombre<<" "<<alu[i].edad<<" "<<alu[i].promedio<<endl;
    }
}
void Grupo::agregar_alumno(string _nombre,int _edad, float _promedio)
{
    alu[5]=Alumno(_nombre,_edad,_promedio);
}
void Grupo:: ordenar_por_promedio()
{
   for (int i = 0; i < 5; i++)  
    {
        for (int j = 0; j < 5 - i; j++)  
        {
            if (alu[j].promedio < alu[j + 1].promedio) { 
                Alumno temp = alu[j];
                alu[j] = alu[j + 1];
                alu[j + 1] = temp;
            }
        }
    }
}
void Grupo:: promedio_grupo()
{
    float final;
    for (int i=0;i<5;i++)
    {
        final+=alu[i].promedio;
    }
    cout<<"El promedio de la clase es "<<final/4<<endl;
}
void Grupo:: mejor_promedio()
{  
   for (int i = 0; i < 5; i++)  
    {
        for (int j = 0; j < 5 - i; j++)  
        {
            if (alu[j].promedio < alu[j + 1].promedio) { 
                Alumno temp = alu[j];
                alu[j] = alu[j + 1];
                alu[j + 1] = temp;
            }
        }
    }
    cout<<"el mejor promedio es "<<alu[1].promedio<<endl;
}
#endif