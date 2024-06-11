#include <iostream>
using namespace std;

class Personaje {
protected:
    int vida;
    int fuerza;
    int defensa;

public:
    Personaje(int vida, int fuerza, int defensa) : vida(vida), fuerza(fuerza), defensa(defensa) {}
    virtual void atacar(Personaje* objetivo) = 0;
    virtual void defender(int damage) = 0;
    virtual void usarHabilidadEspecial() = 0;

    int getVida() { 
        return vida;
    }
};

class Guerrero : public Personaje {
public:
    Guerrero(int vida, int fuerza, int defensa) : Personaje(vida, fuerza, defensa) {}

    void atacar(Personaje* objetivo) {
        cout << "El Guerrero ataque logrando hacer un daño de " << fuerza << " contra su oponente." << endl;
        objetivo->defender(fuerza);
    }

    void defender(int damage) {
        vida -= damage;
        cout << "El Guerrero resiste el golpe, le quedan " << vida << " puntos de vida." << endl;
    }

    void usarHabilidadEspecial() {
        cout << "El Guerrero activa su habilidad especial: ¡Golpe Crítico!" << endl;
        fuerza += 10;
    }
};

// Clase Mago
class Mago : public Personaje {
public:
    Mago(int vida, int fuerza, int defensa) : Personaje(vida, fuerza, defensa) {}

    void atacar(Personaje* objetivo) {
        cout << "El Mago lanza un hechizo de fuego contra su enemigo." << endl;
        objetivo->defender(fuerza * 2);
    }

    void defender(int damage) {
        vida -= damage;
        cout << "El Mago recibe el impacto, ahora tiene " << vida << " puntos de vida." << endl;
    }

    void usarHabilidadEspecial() {
        cout << "El Mago invoca su habilidad especial: ¡Escudo Mágico!" << endl;
        defensa += 5;
    }
};

// Clase Arquero
class Arquero : public Personaje {
public:
    Arquero(int vida, int fuerza, int defensa) : Personaje(vida, fuerza, defensa) {}

    void atacar(Personaje* objetivo) {
        cout << "El Arquero dispara una flecha hacia su objetivo." << endl;
        objetivo->defender(fuerza + 5);
    }

    void defender(int damage) {
        vida -= damage;
        cout << "El Arquero esquiva por poco el ataque, quedándole " << vida << " puntos de vida." << endl;
    }

    void usarHabilidadEspecial() {
        cout << "El Arquero utiliza su habilidad especial: ¡Tiro Preciso!" << endl;
        fuerza += 5;
    }
};

int main() {
    Guerrero guerrero(100, 20, 10);
    Mago mago(80, 15, 8);
    Arquero arquero(90, 18, 12);

    guerrero.atacar(&mago);
    mago.defender(20);
    mago.usarHabilidadEspecial();
    mago.atacar(&arquero);
    arquero.defender(40);
    arquero.usarHabilidadEspecial();
    arquero.atacar(&guerrero);

    cout << "La vida restante del Guerrero es: " << guerrero.getVida() << endl;
    cout << "La vida restante del Mago es: " << mago.getVida() << endl;
    cout << "La vida restante del Arquero es: " << arquero.getVida() << endl;

    return 0;
}