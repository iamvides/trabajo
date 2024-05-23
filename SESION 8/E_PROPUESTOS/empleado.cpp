#include <iostream>
using namespace std;
class Empleado{
    public:
    Empleado(){};
    virtual float calcularSalario()=0;
};
class EmpleadoTiempoCompleto: public Empleado{
    private:
        int horasT;
        float salario;
        float pagoH=15.5;
    public:
        EmpleadoTiempoCompleto(int _horasT):Empleado(){
            horasT=_horasT;
        }
        float calcularSalario(){
            salario=horasT*pagoH;
            return salario;
        }
};
class EmpleadoMedioTiempo: public Empleado{
    private:
        int horasT;
        float salario;
        float pagoH=8.7;
    public:
        EmpleadoMedioTiempo(int _horasT):Empleado(){
            horasT=_horasT;
        }
        float calcularSalario(){
            salario=horasT*pagoH;
            return salario;
        }
};
int main(){
    EmpleadoTiempoCompleto empleado1(40);
    EmpleadoMedioTiempo empleado2(20);

    cout << "El salario del empleado a tiempo completo es: $" << empleado1.calcularSalario() << endl;
    cout << "El salario del empleado a medio tiempo es: $" << empleado2.calcularSalario() << endl;

    return 0;
}