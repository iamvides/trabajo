#include <iostream>
#include <string>

using namespace std;

class Cliente {
protected:
    string nombre;
    string direccion;
    string telefono;
    string email;
    string numeroTarjeta;
    string codigoSeguridad;

protected:
    string encriptar(const string &data) const {
        string encrypted = data;
        char key = 'K'; 
        for (size_t i = 0; i < data.size(); ++i) {
            encrypted[i] ^= key;
        }
        return encrypted;
    }

public:
    Cliente(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : nombre(n), direccion(d), telefono(t), email(e), numeroTarjeta(nt), codigoSeguridad(cs) {}

    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getTelefono() const { return telefono; }
    string getEmail() const { return email; }
    string getNumeroTarjeta() const { return numeroTarjeta; }
    string getCodigoSeguridad() const { return codigoSeguridad; }

    void encriptarInformacion() {
        numeroTarjeta = encriptar(numeroTarjeta);
        codigoSeguridad = encriptar(codigoSeguridad);
    }
};

class ClienteSeguro : public Cliente {
public:
    ClienteSeguro(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : Cliente(n, d, t, e, nt, cs) {}

    bool verificarAutenticidad(const string &nombre, const string &codigo) const {
        return (this->nombre == nombre && this->codigoSeguridad == codigo);
    }
};

int main() {
    ClienteSeguro cliente("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "1234567890123456", "123");
    cliente.encriptarInformacion();

    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Direccion: " << cliente.getDireccion() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Tarjeta Encriptada: " << cliente.getNumeroTarjeta() << endl;
    cout << "Codigo Seguridad Encriptado: " << cliente.getCodigoSeguridad() << endl;

    if (cliente.verificarAutenticidad("Alexander Velasquez", "123")) {
        cout << "Autenticidad verificada." << endl;
    } else {
        cout << "Autenticidad no verificada." << endl;
    }

    return 0;
}
