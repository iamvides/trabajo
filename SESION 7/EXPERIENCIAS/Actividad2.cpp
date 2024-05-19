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
    string encriptar(string data) {
        string encrypted;
        for (size_t i = 0; i < data.size(); i++) {
            char c = data[i];
            if (c >= 'a' && c <= 'z') {
                encrypted += 'z' - (c - 'a');
            } else if (c >= 'A' && c <= 'Z') {
                encrypted += 'Z' - (c - 'A');
            } else {
                encrypted += c; // No encriptar otros caracteres
            }
        }
        return encrypted;
    }

public:
    Cliente(string n, string d, string t, string e, string pass, string respu)
        : nombre(n), direccion(d), telefono(t), email(e), password(pass), respuestaC(respu) {}

    string getNombre() { return nombre; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    string getEmail() { return email; }
    string getPassword() { return password; }
    string getRespuestaC() { return respuestaC; }
};

class ClienteSeguro : public Cliente {
public:
    ClienteSeguro(string _nombre, string _direccion, string _telefono, string _email, string _password, string _respuestac)
        : Cliente(_nombre, _direccion, _telefono, _email, _password, _respuestac) {}

    string getPasswordencriptado() {
        return encriptar(password);
    }

    string getRespuestaCencriptada() {
        return encriptar(respuestaC);
    }

    bool verificarAutenticidad(string nombre, string con) {
        return (nombre == this->nombre && getPassword() == con);
    }
};

int main() {
    ClienteSeguro cliente("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "holamundo", "colorFavorito?");
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Contraseña Encriptada: " << cliente.getPasswordencriptado() << endl;
    cout << "Codigo Seguridad Encriptado: " << cliente.getRespuestaCencriptada() << endl;
    if (cliente.verificarAutenticidad("Alexander Velasquez", "holamundo")) {
        cout << "Autenticidad verificada." << endl;
    } else {
        cout << "Autenticidad no verificada." << endl;
    }
    return 0;
}


