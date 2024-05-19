#include <iostream>
#include <string>
using namespace std;

class Cliente {
protected:
    string nombre;
    string direccion;
    string telefono;
    string email;
    string password;
    string respuestaC;
public:
    Cliente(string n, string d, string t, string e, string pass, string respu) : nombre(n), direccion(d), telefono(t), email(e), password(pass), respuestaC(respu) {}
    string getNombre() { return nombre; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    string getEmail() { return email; }
    string getPassword() { return password; }
    string getRespuestaC() { return respuestaC; }
    string encriptar(string data) {
        string contraEncriptada;
        for (size_t i = 0; i < data.size(); i++) {
            char c = data[i];
            if (c >= 'a' && c <= 'z') {
                contraEncriptada += 'z' - (c - 'a');
            } else if (c >= 'A' && c <= 'Z') {
                contraEncriptada += 'Z' - (c - 'A');
            }
        }
        return contraEncriptada;
    }
};
class ClienteSeguroPublico : public Cliente {
public:
    ClienteSeguroPublico(string _nombre, string _direccion, string _telefono, string _email, string _password, string _respuestac) 
        : Cliente(_nombre, _direccion, _telefono, _email, _password, _respuestac) {}

    string getPassword() {
        return encriptar(password);
    }
    string getRespuestaC() {
        return encriptar(respuestaC);
    }
    bool verificarAutenticidad(string nombre, string con) {
        if (nombre == nombre && password == con) {
            return true;
        }
        return false;
    }
};
class ClienteSeguroProtegido : protected Cliente {
public:
    ClienteSeguroProtegido(string _nombre, string _direccion, string _telefono, string _email, string _password, string _respuestac) 
    : Cliente( _nombre, _direccion, _telefono, _email, _password, _respuestac) {}

    string getPassword() {
        return encriptar(password);
    }
    string getRespuestaC() {
        return encriptar(respuestaC);
    }
    bool verificarAutenticidad(string nombre, string con) {
        if (nombre == nombre && password == con) {
            return true;
        }
        return false;
    }
};
class ClienteSeguro : public Cliente {
public:
    ClienteSeguro(string _nombre, string _direccion, string _telefono, string _email, string _password, string _respuestac) 
        : Cliente( _nombre, _direccion, _telefono, _email, _password, _respuestac) {}
    string getPassword() {
        return encriptar(password);
    }
    string getRespuestaC() {
        return encriptar(respuestaC);
    }
    bool verificarAutenticidad(string nombre, string con) {
        if (nombre == nombre && password == con) {
            return true;
        }
        return false;
    }
};
class ClienteSeguroPrivado : private Cliente {
public:
    ClienteSeguroPrivado(string _nombre, string _direccion, string _telefono, string _email, string _password, string _respuestac) 
    : Cliente( _nombre, _direccion, _telefono, _email, _password, _respuestac) {}
     string getPassword() {
        return encriptar(password);
    }
    string getRespuestaC() {
        return encriptar(respuestaC);
    }
    bool verificarAutenticidad(string nombre, string con) {
        if (nombre == nombre && password == con) {
            return true;
        }
        return false;
    }
};
int main() {
    ClienteSeguro cliente("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "123", "colorFavorito?");
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Tarjeta Encriptada: " << cliente.getPassword() << endl;
    cout << "Codigo Seguridad Encriptado: " << cliente.getRespuestaC() << endl;
    if (cliente.verificarAutenticidad("Alexander Velasquez", "123")) {
        cout << "Autenticidad verificada." << endl;
    } else {
        cout << "Autenticidad no verificada." << endl;
    }

    ClienteSeguroPublico clientePublico("Oscar Flores", "Calle 123", "987654321", "oscarf@ucsp.com", "12345678", "password");
    cout << "Nombre: " << clientePublico.getNombre() << endl;
    cout << "Direccion: " << clientePublico.getDireccion() << endl;
    cout << "Telefono: " << clientePublico.getTelefono() << endl;
    cout << "Email: " << clientePublico.getEmail() << endl;
    cout << "Tarjeta Encriptada Publica: " << clientePublico.getPassword() << endl;
    cout << "Codigo Seguridad Encriptado Publico: " << clientePublico.getRespuestaC() << endl;
    if (clientePublico.verificarAutenticidad("Oscar Flores", "12345678")) {
        cout << "Autenticidad verificada Publica." << endl;
    } else {
        cout << "Autenticidad no verificada Publica." << endl;
    }

    ClienteSeguroProtegido clienteProtegido("Tamara Martinez", "Calle Mercaderes 456", "456123789", "tamara@ucsm.com", "87654321", "hola");
    cout << "Tarjeta Encriptada Protegida: " << clienteProtegido.getPassword() << endl;
    cout << "Codigo Seguridad Encriptado Protegido: " << clienteProtegido.getRespuestaC() << endl;
    if (clienteProtegido.verificarAutenticidad("Tamara Martinez", "87654321")) {
        cout << "Autenticidad verificada Protegida." << endl;
    } else {
        cout << "Autenticidad no verificada Protegida." << endl;
    }

    ClienteSeguroPrivado clientePrivado("Miguel Bejarano", "Av España 987", "1234567890", "miguel@ucsm.com", "98765432", "adios");
    cout << "Tarjeta Encriptada Privada: " << clientePrivado.getPassword() << endl;
    cout << "Codigo Seguridad Encriptado Privado: " << clientePrivado.getRespuestaC() << endl;
    if (clientePrivado.verificarAutenticidad("Miguel Bejarano", "98765432")) {
        cout << "Autenticidad verificada Privada." << endl;
    } else {
        cout << "Autenticidad no verificada Privada." << endl;
    }
    return 0;
}
