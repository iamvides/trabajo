#include <iostream>
#include <string>
#include <vector>
#include "tarea.h"
#include "seguimiento.h"
#include "control.h"
#include "control.h"
#include "acciones.h"
using namespace std;
int main(){ 
    string nombre;
    string date;
    string destinatario;
    string porcentaje;
    string opc="SI";
    Seguimiento task("", "", "");
    Acciones acciones("","","");
    int elec;
    do
    {
        do{
            cout << "elija una opcion " <<endl;
            cout << "1. agregar trabajos " <<endl;
            cout << "2. modificar porcentaje de avance " <<endl;
            cout << "3. ver el estado del trabajo " <<endl;
            cout << "4. gestionar el trabajo " <<endl;
            cout << "5. hacer un comentario " <<endl;
            cout << "6. compartir " <<endl;
            cin >> elec;
        } while (elec<0 || elec>6);
        if (elec==1){
            cout << "ingrese el nombre del trabajo ";
            cin >> nombre;
            task.setName(nombre);
            cout << "ingrese hasta que fecha se puede enviar el trabajo ";
            cin >> date;
            task.setFecha(date);
            cout << "ingrese para quien es el trabajo ";
            cin >> destinatario;
            task.setReceptor(destinatario);
            task.Agregar();
            
        }
        if (elec==2){
            cout << "ingrese el porcentaje de avance de los proyectos";
            cin >> porcentaje;
            task.setPorcentaje(porcentaje);
            task.Progreso();
        }
        if (elec==3){
            task.resultados();
        }
        if (elec==4){
            task.imprimirTareas();
            acciones.Repartir();
        }
        if (elec==5){
            acciones.Commet();
        }
        if (elec==6){
            string compa;
            cout << "con quien va a compartir el trabajo?"<<endl;
            cin >> compa;
            acciones.setCompartir(compa);
            acciones.Compartir();
        }
        cout << "Desea seguir enviando tareas? (SI o NO)";
        cin >> opc;
    } while (opc=="SI");
    return 0;
}
