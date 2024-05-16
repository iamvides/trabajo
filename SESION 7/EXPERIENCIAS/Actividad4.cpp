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

public:
    Cliente(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : nombre(n), direccion(d), telefono(t), email(e), numeroTarjeta(nt), codigoSeguridad(cs) {}

    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getTelefono() const { return telefono; }
    string getEmail() const { return email; }
    string getNumeroTarjeta() const { return numeroTarjeta; }
    string getCodigoSeguridad() const { return codigoSeguridad; }
};

// Herencia pública
class ClienteSeguroPublico : public Cliente {
private:
    string encriptar(const string &data) const {
        string encrypted = data;
        char key = 'K'; 
        for (size_t i = 0; i < data.size(); ++i) {
            encrypted[i] ^= key;
        }
        return encrypted;
    }

public:
    ClienteSeguroPublico(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : Cliente(n, d, t, e, nt, cs) {}

    string getTarjetaEncriptada() const {
        return encriptar(numeroTarjeta);
    }

    string getCodigoSeguridadEncriptado() const {
        return encriptar(codigoSeguridad);
    }

    bool verificarAutenticidad(const string &nombre, const string &codigo) const {
        return (this->nombre == nombre && this->codigoSeguridad == codigo);
    }
};

// Herencia protegida
class ClienteSeguroProtegido : protected Cliente {
private:
    string encriptar(const string &data) const {
        string encrypted = data;
        char key = 'K'; 
        for (size_t i = 0; i < data.size(); ++i) {
            encrypted[i] ^= key;
        }
        return encrypted;
    }

public:
    ClienteSeguroProtegido(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : Cliente(n, d, t, e, nt, cs) {}

    string getTarjetaEncriptada() const {
        return encriptar(numeroTarjeta);
    }

    string getCodigoSeguridadEncriptado() const {
        return encriptar(codigoSeguridad);
    }

    bool verificarAutenticidad(const string &nombre, const string &codigo) const {
        return (this->nombre == nombre && this->codigoSeguridad == codigo);
    }
};

// Herencia privada
class ClienteSeguroPrivado : private Cliente {
private:
    string encriptar(const string &data) const {
        string encrypted = data;
        char key = 'K'; 
        for (size_t i = 0; i < data.size(); ++i) {
            encrypted[i] ^= key;
        }
        return encrypted;
    }

public:
    ClienteSeguroPrivado(const string &n, const string &d, const string &t, const string &e, const string &nt, const string &cs)
        : Cliente(n, d, t, e, nt, cs) {}

    string getTarjetaEncriptada() const {
        return encriptar(numeroTarjeta);
    }

    string getCodigoSeguridadEncriptado() const {
        return encriptar(codigoSeguridad);
    }

    bool verificarAutenticidad(const string &nombre, const string &codigo) const {
        return (this->nombre == nombre && this->codigoSeguridad == codigo);
    }
};

int main() {
    // Herencia Pública
    ClienteSeguroPublico clientePublico("Alexander Velasquez", "Av. Chile 456", "123456789", "alexandra@ucsm.edu.pe", "1234567890123456", "123");

    cout << "Nombre: " << clientePublico.getNombre() << endl;
    cout << "Direccion: " << clientePublico.getDireccion() << endl;
    cout << "Telefono: " << clientePublico.getTelefono() << endl;
    cout << "Email: " << clientePublico.getEmail() << endl;
    cout << "Tarjeta Encriptada: " << clientePublico.getTarjetaEncriptada() << endl;
    cout << "Codigo Seguridad Encriptado: " << clientePublico.getCodigoSeguridadEncriptado() << endl;

    if (clientePublico.verificarAutenticidad("Alexander Velasquez", "123")) {
        cout << "Autenticidad verificada." << endl;
    } else {
        cout << "Autenticidad no verificada." << endl;
    }

    return 0;
}
