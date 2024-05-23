#include <iostream>
using namespace std;
class Reproductor{
    public:
        virtual void pausar()=0;
        virtual void reproducir()=0;
        virtual void detener()=0;
        Reproductor(){};
};
class ReproductorMP3 : public Reproductor {
    private:
        string song;
    public:
        ReproductorMP3(string _song):Reproductor(){
            song=_song;
        }
        void reproducir() override {
            cout << "Reproduciendo "<< song<< endl;
        }
        void pausar() override {
            cout << "Pausando reproduccion" <<endl;
        }
        void detener() override {
            cout << "Deteniendo reproduccion" << endl;
        }
};
int main() {
    ReproductorMP3 reproductor("in the end ");
    reproductor.reproducir();
    reproductor.pausar();
    reproductor.detener();

    return 0;
}