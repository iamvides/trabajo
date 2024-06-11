#include <iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido()=0;
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