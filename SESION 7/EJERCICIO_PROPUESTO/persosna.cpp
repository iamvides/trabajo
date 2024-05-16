#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string name;
    int age;
    float salary;

    Persona(string _name, int _age, float _salary, string _email)
        : name(_name), age(_age), salary(_salary), email(_email) {}
    protected:
        string email;
        virtual void setemail(string _email)=0;
        virtual string getEmail()=0;
};

class Empleado : protected Persona {
public:
    string department;

    Empleado(string _name, int _age, float _salary, string _email,string _department)
        : Persona(_name, _age, _salary, _email) {
        department=_department;
    }
    void setemail(string _email)
    {
        email = _email;
    }
    string getEmail()
    {
        return email;
    }
};

class Cliente : protected Persona {
public:
    string customer_id;

    Cliente(string _name, int _age, float _salary, string _email,string _customer_id)
        : Persona(_name, _age, _salary, _email) {
            customer_id= _customer_id;
    }
    void setemail(string _email)
    {
        email = _email;
    }
    string getEmail()
    {
        return email;
    }
};

int main() {
    Empleado em("John Doe", 30, 5000.0, "johndoe@example.com","lol");
    cout << "Empleado email: " << em.getEmail() << endl;

    Cliente cli("Jane Doe", 25, 60000, "janedoe@example.com","1234343");
    cout << "Cliente email: " << cli.getEmail() << endl;

    return 0;
}
