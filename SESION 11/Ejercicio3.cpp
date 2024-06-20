#include <iostream>
#include <string>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>

using namespace std;

class Persona {
public:
    Persona() {}
    Persona(string nombre, int edad, string direccion) : nombre(nombre), edad(edad), direccion(direccion) {}

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getDireccion() { return direccion; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setDireccion(string direccion) { this->direccion = direccion; }

private:
    string nombre;
    int edad;
    string direccion;

    // Funciones de serialización y deserialización
    template <class Archive>
    void serialize(Archive& archive) {
        archive(cereal::make_nvp("nombre", nombre), cereal::make_nvp("edad", edad), cereal::make_nvp("direccion", direccion));
    }
};

int main() {
    // Crear un objeto Persona
    Persona persona("Juan", 25, "Calle 123");

    // Serializar el objeto Persona en un archivo binario
    {
        std::ofstream archivo("persona.bin", std::ios::binary);
        cereal::BinaryOutputArchive archivoBinario(archivo);
        archivoBinario(persona);
    }

    // Deserializar el objeto Persona desde el archivo binario
    {
        std::ifstream archivo("persona.bin", std::ios::binary);
        cereal::BinaryInputArchive archivoBinario(archivo);
        Persona personaDeserializada;
        archivoBinario(personaDeserializada);

        // Mostrar los atributos del objeto deserializado
        cout << "Nombre: " << personaDeserializada.getNombre() << endl;
        cout << "Edad: " << personaDeserializada.getEdad() << endl;
        cout << "Dirección: " << personaDeserializada.getDireccion() << endl;
    }

    return 0;
}