#ifndef GRUPO_H
#define GRUPO_H
#include <iostream>
#include "alumnos.h"
using namespace std;
class Grupo
{
    private:
        int cantidad;
        Alumno* alu = new Alumno();     //definimos un array de objetos de la clase alumno 
    public:
        Grupo(int);     //constructor
        void _str();
        void agregar_alumno(string,int,float);  //método que retorna una cadena de caracteres que representa al objeto Grupo
        void ordenar_por_promedio();
        void promedio_grupo();
        void mejor_promedio();
};
Grupo::Grupo(int _cantidad)     
{
    cantidad = _cantidad;
    alu = new Alumno[cantidad];
}
void Grupo::_str()
{
    for (int i=0;i<cantidad;i++)    
    {
        alu[i].str();   //llamamos al metodo srtde la clase alumno eh iteramos para mostrar los contenidos del array
    }
}
void Grupo::agregar_alumno(string _nombre,int _edad, float _promedio)
{
    static int contador = 0;    //cuenta cada vez que se llama a la funcion
    alu[contador] = Alumno(_nombre,_edad,_promedio);   /*el contador se usa para que cada vez que se agrega
    un nuevo alumno este tome la siguiente posicion en el array*/
    contador++;
}
void Grupo::ordenar_por_promedio()
{
   for (int i = 0; i < cantidad - 1; i++)  
    {
        for (int j = 1-i; j < cantidad - 1; j++)  
        {
            if (alu[j].promedio < alu[i].promedio) { 
                Alumno temp = alu[j];   //creamos un objeto temporal para poder cambiar los valores
                alu[j] = alu[i];
                alu[i] = temp;
            }
        }
    }
}
void Grupo::promedio_grupo()
{
    float final = 0;
    for (int i=0;i<cantidad;i++)
    {
        final+=alu[i].promedio;     //suma los promedios de los alumnos
    }
    cout << "El promedio de la clase es " << final/cantidad << endl;    //muestra por pantalla la nota final
}
void Grupo::mejor_promedio()
{  
   
   for (int i = 0; i < cantidad - 1; i++)  
    {
        for (int j = 1-i; j < cantidad - 1; j++)  
        {
            if (alu[j].promedio < alu[i].promedio) { 
                Alumno temp = alu[j];   //creamos un objeto temporal para poder cambiar los valores
                alu[j] = alu[i];
                alu[i] = temp;
            }
        }
    
    }
    cout << "el mejor promedio es " << alu[0].promedio << endl;
}
#endif