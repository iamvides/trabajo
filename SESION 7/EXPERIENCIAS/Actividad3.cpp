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
    Cliente(const string &n, const string &d, const string &t, const string &e) : nombre(n), direccion(d), telefono(t), email(e) {}

    virtual ~Cliente() {
        cout << "Destructor de Cliente llamado." << endl;
    }

    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getTelefono() const { return telefono; }
    string getEmail() const { return email; }
};

class ClienteSeguro : public Cliente {
private:
    string numeroTarjeta;
    string codigoSeguridad;

public:
    ClienteSeguro(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : Cliente(n, d, t, e), numeroTarjeta(nt), codigoSeguridad(cs) {}

    ~ClienteSeguro() {
        cout << "Destructor de ClienteSeguro llamado." << endl;
    }

    string getNumeroTarjeta() const { return numeroTarjeta; }
    string getCodigoSeguridad() const { return codigoSeguridad; }
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
