#include <iostream>
#include "alumnos.h"
#include "grupito.h"
using namespace std;
int main()
{
    Alumno alumno1("Alice", 20, 14.3);
    Alumno alumno2("Bob", 22, 18.9);
    Alumno alumno3("Charlie", 21, 9.99);
    Alumno alumno4("David", 23, 10.13);
    Alumno alumno5("Eve", 19, 19.4);
    Grupo grupo(alumno1, alumno2, alumno3, alumno4, alumno5, 5);
    grupo._str();
    grupo.promedio_grupo();
    grupo.mejor_promedio();
    return 0;
}