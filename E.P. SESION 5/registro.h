#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>
using namespace std;
class Registro {
    private:
        string name;
        string email;
        string password;
        string Tarjeta;
        int plan;
    public:
        Registro(); // constructor
        Registro(string, string, string, int); // constructor with parameters
        ~Registro(); // destructor
        void setName(string);
        void setEmail(string);
        void setPassword(string);
        void setTarjeta(string);
        string getTarjeta();
        string getName();
        string getEmail();
        string getPassword();
        int getPlan();
};
Registro::Registro() {
    name = "";
    email = "";
    password = "";
    plan = 0;
}
Registro::Registro(string n, string e, string p, int pl) {
    name = n;
    email = e;
    password = p;
    plan = pl;
}
Registro::~Registro() {
    // destructor does nothing in this case
}
void Registro::setName(string n) {
    name = n;
}
void Registro::setEmail(string e) {
    email = e;
}
void Registro::setPassword(string p) {
    password = p;
}
void Registro::setTarjeta(string t){
    Tarjeta=t;
}
string Registro::getTarjeta(){
    return Tarjeta;
}
string Registro::getName() {
    return name;
}
string Registro::getEmail() {
    return email;
}
string Registro::getPassword() {
    return password;
}
int Registro::getPlan() {
    return plan;
}
#endif