#include <iostream>
#include "Medico.h"
#include "Paciente.h"
using namespace std;
int main() {
    Medico medico1("12345678", "M001", "Juan", "Pérez", "González", "Cardiología", "Mañana", "5000");
    Medico medico2("23456789", "M002", "María", "López", "Rodríguez", "Pediatría", "Tarde", "4500");
    Medico medico3("34567890", "M003", "Pedro", "García", "Sánchez", "Traumatología", "Noche", "6000");
    Medico medico4("45678901", "M004", "Ana", "Lucia", "Díaz", "Fernández", "Ginecología", "Mañana", "5500");
    Medico medico5("56789012", "M005", "Luis", "Hernández", "Martínez", "general", "Tarde", "6500");
    Medico** Doctores = new Medico*[5];
    Doctores[0] = &medico1;
    Doctores[1] = &medico2;
    Doctores[2] = &medico3;
    Doctores[3] = &medico4;
    Doctores[4] = &medico5;
    Paciente paciente1("11111111", "P001", "Sofía", "Gómez", "Hernández", "2022-01-01", "Cardiopatía", "Cardiología", "Electrocardiograma", "Cirugía de bypass", Doctores, 5);
    Paciente paciente2("22222222", "P002", "Alejandro", "Sánchez", "López", "2022-02-02", "Neumonía", "Pediatría", "Radiografía", "", Doctores, 5);
    Paciente paciente3("33333333", "P003", "Laura", "Díaz", "García", "2022-03-03", "Fractura de pierna", "Traumatología", "Radiografía", "", Doctores, 5);
    Paciente paciente4("44444444", "P004", "Carlos", "Rodríguez", "Pérez", "2022-04-04", "Infección urinaria", "Ginecología", "Análisis de orina", "", Doctores, 5);
    Paciente paciente5("55555555", "P005", "Elena", "Martínez", "González", "2022-05-05", Doctores, 5,929733050);

    paciente1.MostrarDetalles();
    paciente2.MostrarDetalles();
    paciente3.MostrarDetalles();
    paciente4.MostrarDetalles();
    paciente5.MostrarDetalles();
    return 0;
}