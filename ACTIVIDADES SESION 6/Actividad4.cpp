#include <iostream>

using namespace std;

class Vector2D {
private:
    float x;
    float y;

public:
    Vector2D(float _x = 0.0, float _y = 0.0) : x(_x), y(_y) {}
    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }
    Vector2D operator-(const Vector2D& otro) const {
        return Vector2D(x - otro.x, y - otro.y);
    }
    friend ostream& operator<<(ostream& os, const Vector2D& vec);
};

ostream& operator<<(ostream& os, const Vector2D& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);
    Vector2D suma = v1 + v2;
    Vector2D resta = v1 - v2;
    cout << "La suma de los vectores v1 y v2 es: " << suma << endl;
    cout << "La resta de los vectores v1 y v2 es: " << resta << endl;
    return 0;
}
