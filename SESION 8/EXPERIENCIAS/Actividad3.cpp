#include <iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido() = 0;
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "Guau guau! " << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "Miau miau!" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido()  override {
        cout << "Mu mu" << endl;
    }
};

int main() {
    Animal* perro = new Perro();
    Animal* gato = new Gato();
    Animal* vaca = new Vaca();

    perro->hacerSonido();
    gato->hacerSonido();
    vaca->hacerSonido();
    return 0;
}