#ifndef BASE.H
#define BASE.H
#include <iostream>
using namespace std;  
class Base{
    private:
        string dni;
        string codigo;
        string nombre;
        string segundo;
        string apellidoP;
        string apellidoM;
    public:
        Base(string _dni, string _codigo, string _nombre, string _apellidoP, string _apellidoM):
        dni(_dni), codigo(_codigo), nombre(_nombre), segundo(""), apellidoP(_apellidoP),apellidoM(_apellidoM){}
        Base(string _dni, string _codigo, string _nombre,string _segundo, string _apellidoP, string _apellidoM):
        dni(_dni), codigo(_codigo), nombre(_nombre), segundo(_segundo), apellidoP(_apellidoP),apellidoM(_apellidoM){}
        
        virtual void MostrarDetalles()=0;
        
        void setDni(string d) {
            dni = d;
        }
        void setCodigo(string c) {
            codigo = c;
        }
        void setNombre(string n) { 
            nombre = n;
        }
        void setSegundo(string s) {
            segundo = s;
        }
        void setApellidoP(string ap) {
            apellidoP = ap;
        }
        void setApellidoM(string am) {
            apellidoM = am;
        }
        string getDni(){
            return dni;
        }
        string getCodigo() {
            return codigo;
        }
        string getNombre(){
            return nombre;
        }
        string getSegundo(){
            return segundo; 
        }
        string getApellidoP(){
            return apellidoP; 
        }
        string getApellidoM() {
            return apellidoM; 
        }
};
#endif