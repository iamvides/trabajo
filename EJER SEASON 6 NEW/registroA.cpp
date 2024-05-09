#include <iostream>
#include "alumnos.h"
#include "grupito.h"
using namespace std;
int main()
{
    Grupo grupo(5); //creamos un objeto de la clase grupo
    grupo.agregar_alumno("Alice", 20, 14.3);
    grupo.agregar_alumno("Bob", 22, 18.9);
    grupo.agregar_alumno("Charlie", 21, 9.99);
    grupo.agregar_alumno("David", 23, 10.13);
    grupo.agregar_alumno("Eve", 19,19.4);
    grupo._str();
    grupo.promedio_grupo();
    grupo.mejor_promedio();
    return 0;
}