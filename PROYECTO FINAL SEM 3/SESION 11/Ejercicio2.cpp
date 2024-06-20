#include <iostream>
#include <stdexcept>

using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: No se puede dividir por cero.");
    }
    return a / b;
}

int main() {
    try {
        cout << "Resultado de 10 / 2: " << divide(10, 2) << endl;
        cout << "Resultado de 20 / 4: " << divide(20, 4) << endl;
        cout << "Resultado de 15 / 0: " << divide(15, 0) << endl;
    } catch (runtime_error e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}