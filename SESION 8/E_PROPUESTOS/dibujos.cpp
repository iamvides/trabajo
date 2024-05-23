#include <iostream>
using namespace std;
class Figura{
    public:
        void Dibujar(){
            cout<<"esta dibujando una cosa"<<endl;
        }
        virtual int Area()=0;
        Figura(){}
};
class Cuadrado: public Figura
{
    private:
        int area;
        int lado;
    public:
        Cuadrado(int _lado):Figura(){
            lado=_lado;
        }
        void Dibujar(){
            cout<<"esta dibujando un cuadrado"<<endl;
        }
        int Area(){
            area=lado*lado;
            return area;
        }
};
class Triangulo: public Figura
{
    private:
        int area;
        int base;
        int altura;
    public:
        Triangulo(int _base, int _altura):Figura(){
            base=_base;
            altura=_altura;
        }
        void Dibujar(){
            cout<<"esta dibujando un triangulo"<<endl;
        }
        int Area(){
            area=(base*altura)/2;
            return area;
        }
};
class Rectangulo: public Figura
{
    private:
        int area;
        int largo;
        int ancho;
    public:
        Rectangulo(int _ancho, int _largo):Figura(){
            ancho=_ancho;
            largo=_largo;
        }
        void Dibujar(){
            cout<<"esta dibujando un rectangulo"<<endl;
        }   
        int Area(){
            area=ancho*largo;
            return area;
        }
};
int main(){
    Cuadrado cuadradito(34);
    cuadradito.Dibujar();
    cout<<"el area del cuadrado es "<<cuadradito.Area()<<endl;
    Triangulo triangulito(12,5);
    triangulito.Dibujar();
    cout<<"el area del triangulo es "<<triangulito.Area()<<endl;
    Rectangulo rectangulito(12,34);
    rectangulito.Dibujar();
     cout<<"el area del rectangulo es "<<rectangulito.Area()<<endl;
}