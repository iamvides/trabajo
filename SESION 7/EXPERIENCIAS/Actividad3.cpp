#include <iostream>
#include <string>

using namespace std;

class Cliente {
protected:
    string nombre;
    string direccion;
    string telefono;
    string email;

public:
    Clientestring &n, string &d, string &t, string &e) : nombre(n), direccion(d), telefono(t), email(e) {}

    virtual ~Cliente() {
        cout << "Destructor de Cliente llamado." << endl;
    }

    string getNombre() { return nombre; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    string getEmail() { return email; }
};

class ClienteSeguro : public Cliente {
private:
    string numeroTarjeta;
    string codigoSeguridad;

public:
    ClienteSeguro(string &n, string &d, string &t, string &e, string &nt, string &cs)
        : Cliente(n, d, t, e), numeroTarjeta(nt), codigoSeguridad(cs) {}

    ~ClienteSeguro() {
        cout << "Destructor de ClienteSeguro llamado." << endl;
    }

    string getNumeroTarjeta() { return numeroTarjeta; }
    string getCodigoSeguridad() { return codigoSeguridad; }
};

int main() {
    ClienteSeguro cliente("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "1234567890123456", "123");

    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Tarjeta: " << cliente.getNumeroTarjeta() << endl;
    cout << "Codigo: " << cliente.getCodigoSeguridad() << endl;

    return 0;
}
