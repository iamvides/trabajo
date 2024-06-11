#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {}
    virtual void comer() = 0;
    virtual void dormir() = 0;
    virtual void hacerRuido() = 0;
    virtual void mostrarInformacion() = 0;
};

class Perro : public Animal {
public:
    Perro() {}
    void comer() {
        cout << "El perro come croquetas." << endl;
    }
    void dormir() {
        cout << "El perro duerme en su cama." << endl;
    }
    void hacerRuido() {
        cout << "El perro ladra." << endl;
    }
    void mostrarInformacion() {
        cout << "Soy un perro." << endl;
        cout << "Mi comportamiento:" << endl;
        comer();
        dormir();
        hacerRuido();
        cout << endl;
    }
};

class Gato : public Animal {
public:
    Gato() {}
    void comer() {
        cout << "El gato come atun." << endl;
    }
    void dormir() {
        cout << "El gato duerme en el sofa." << endl;
    }
    void hacerRuido() {
        cout << "El gato maulla." << endl;
    }
    void mostrarInformacion() {
        cout << "Soy un gato." << endl;
        cout << "Mi comportamiento:" << endl;
        comer();
        dormir();
        hacerRuido();
        cout << endl;
    }
};

class Pajaro : public Animal {
public:
    Pajaro() {}
    void comer() {
        cout << "El pajaro come semillas." << endl;
    }
    void dormir() {
        cout << "El pajaro duerme en su nido." << endl;
    }
    void hacerRuido() {
        cout << "El pajaro canta." << endl;
    }
    void mostrarInformacion() {
        cout << "Soy un pajaro." << endl;
        cout << "Mi comportamiento:" << endl;
        comer();
        dormir();
        hacerRuido();
        cout << endl;
    }
};

int main() {
    Perro perro;
    Gato gato;
    Pajaro pajaro;

    cout << "Simulador de Animales" << endl;
    cout << "---------------------" << endl;

    cout << "Perro:" << endl;
    perro.mostrarInformacion();
    cout << endl;

    cout << "Gato:" << endl;
    gato.mostrarInformacion();
    cout << endl;

    cout << "Pajaro:" << endl;
    pajaro.mostrarInformacion();
    cout << endl;

    return 0;
}
