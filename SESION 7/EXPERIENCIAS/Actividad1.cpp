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
};
class ClienteSeguro : public Cliente {
private:
    string encriptar(string contrasena) {
    string contraEncriptada;
    for (size_t i = 0; i < contrasena.size(); i++) {
        char c = contrasena[i];
        if (c >= 'a' && c <= 'z') {
            contraEncriptada += 'z' - (c - 'a');
        } else if (c >= 'A' && c <= 'Z') {
            contraEncriptada += 'Z' - (c - 'A');
        }
    }
    return contraEncriptada;
    }
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
        if (nombre == nombre && getPassword() == con)
       {
        return true;
       }
       return false;
    }
};

int main() {
    ClienteSeguro cliente("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "holamundo", "colorFavorito?");
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Contraseña Encriptada: " << cliente.getPassword() << endl;
    cout << "Codigo Seguridad Encriptado: " << cliente.getRespuestaC() << endl;
    if (cliente.verificarAutenticidad("Alexander", "123")) {
        cout << "Autenticidad verificada." << endl;
    } else {
        cout << "Autenticidad no verificada." << endl;
    }
    return 0;
}
