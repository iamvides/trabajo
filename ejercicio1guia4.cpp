#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
class Libro {
private:
    int isbn;
    string titulo;
    int anioPub;
    int cantidadEjm;
    class Autor* autor;
public:
    Libro(int _isbn, string _titulo, int _anioPub, int _cantidadEjm, class Autor* _autor) : isbn(_isbn), titulo(_titulo), anioPub(_anioPub), cantidadEjm(_cantidadEjm), autor(_autor) {}
    string getTitulo() {
        return titulo;
    }
};
class Autor {
private:
    string nombre;
    string nacionalidad;
    vector<Libro*> librosEscritos;
public:
    Autor(string _nombre, string _nacionalidad) : nombre(_nombre), nacionalidad(_nacionalidad) {}
    void agregar_libro(class Libro* libro) {
        librosEscritos.push_back(libro);
    }
    string getNombre() {
        return nombre;
    }
};

class Usuario {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Libro*> librosPrestados;
    vector<time_t> fechasPrestamo;
public:
    Usuario(string _nombre, string _direccion, string _telefono) : nombre(_nombre), direccion(_direccion), telefono(_telefono) {}
    void prestar_libro(class Libro* libro) {
        librosPrestados.push_back(libro);
        time_t now = time(0);
        fechasPrestamo.push_back(now);
    }
    void mostrar_informacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Teléfono: " << telefono << endl;
        cout << "Libros prestados:" << endl;
        for (size_t i = 0; i < librosPrestados.size(); i++) {
            cout << "  Título: " << librosPrestados[i]->getTitulo() << endl;
            cout << "  Fecha de préstamo: " << ctime(&fechasPrestamo[i]) << endl;
        }
    }
};

int main() {
    Autor* autor1 = new Autor("Mario Vargas Llosa", "Perú");
    Autor* autor2 = new Autor("Gabriel García Márquez", "Colombia");

    Libro* libro1 = new Libro(9788420469959, "Travesuras de niña mala", 2006, 10, autor1);
    Libro* libro2 = new Libro(9788420471839, "100 años de soledad", 1967, 15, autor2);
    Usuario* usuario = new Usuario("Miguel Bejarano", "Calle Los Andes 312 Alto Selva Alegre", "987654321");
    usuario->prestar_libro(libro1);
    usuario->prestar_libro(libro2);
    cout << "Datos del usuario: " << endl;
    usuario->mostrar_informacion();
    return 0;
}
