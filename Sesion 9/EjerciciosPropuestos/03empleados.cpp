#include <iostream>
using namespace std;

class Empleado {
public:
    Empleado() {}
    virtual double calcularSalario() = 0;
    virtual void mostrarInformacion() = 0;
};

class EmpleadoPorHora : public Empleado {
private:
    double salarioPorHora;
    int horasTrabajadas;
public:
    EmpleadoPorHora(double salarioPorHora, int horasTrabajadas) : salarioPorHora(salarioPorHora), horasTrabajadas(horasTrabajadas) {}
    double calcularSalario() {
        return salarioPorHora * horasTrabajadas;
    }
    void mostrarInformacion() {
        cout << "Empleado por hora:" << endl;
        cout << "Salario por hora: $" << salarioPorHora << endl;
        cout << "Horas trabajadas: " << horasTrabajadas << endl;
        cout << "Salario total: $" << calcularSalario() << endl;
    }
};

class EmpleadoFijo : public Empleado {
private:
    double salarioFijo;
public:
    EmpleadoFijo(double salarioFijo) : salarioFijo(salarioFijo) {}
    double calcularSalario() {
        return salarioFijo;
    }
    void mostrarInformacion() {
        cout << "Empleado fijo:" << endl;
        cout << "Salario fijo: $" << salarioFijo << endl;
        cout << "Salario total: $" << calcularSalario() << endl;
    }
};

class EmpleadoComision : public Empleado {
private:
    double salarioBase;
    double comision;
public:
    EmpleadoComision(double salarioBase, double comision) : salarioBase(salarioBase), comision(comision) {}
    double calcularSalario() {
        return salarioBase + (salarioBase * comision / 100);
    }
    void mostrarInformacion() {
        cout << "Empleado por comision:" << endl;
        cout << "Salario base: $" << salarioBase << endl;
        cout << "Comision (%): " << comision << endl;
        cout << "Salario total: $" << calcularSalario() << endl;
    }
};

int main() {
    EmpleadoPorHora empleadoPorHora(20.0, 40);
    EmpleadoFijo empleadoFijo(5000.0);
    EmpleadoComision empleadoComision(3000.0, 10);

    cout << "Sistema de Nómina de Empleados" << endl;
    cout << "---------------------------" << endl;

    cout << "Empleado por hora:" << endl;
    empleadoPorHora.mostrarInformacion();
    cout << endl;

    cout << "Empleado fijo:" << endl;
    empleadoFijo.mostrarInformacion();
    cout << endl;

    cout << "Empleado por comision:" << endl;
    empleadoComision.mostrarInformacion();
    cout << endl;

    return 0;
}