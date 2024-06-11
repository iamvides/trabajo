#include <iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido() = 0;
};
class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "GUAU GUAU!" << endl;
    }
};
class Gato : public Animal {
public:
    void hacerSonido() {
        cout << "Miau!!" << endl;
    }
};
class Vaca : public Animal {
public:
    void hacerSonido() {
        cout << "Muuuu!" << endl;
    }
};
int main() {
    int numAnimales = 3;
    Animal* animales[numAnimales];
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();
    for (int i = 0; i < numAnimales; ++i) {
        animales[i]->hacerSonido();
    }
    return 0;
}
