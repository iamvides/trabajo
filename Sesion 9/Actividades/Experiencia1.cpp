#include <iostream>
using namespace std;
class Animal {
public:
    void hacerSonido() {
        cout << "Sonido predeterminado." << endl;
    }
};
class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "GUAU GUAU!" << endl;
    }
};

int main() {
    Animal* perro1 = new Perro();
    perro1->hacerSonido();
    return 0;
}