#pragma once
#include<string>

class Persona;
class Tuit
{
    private:
        string contenido;
        Persona* usuario;
    public:
        string getContenido();
        Persona* getUsuario();
        Tuit(string,Persona*);
};

string   Tuit::getContenido(){ return contenido; }
Persona* Tuit::getUsuario(){ return usuario; }

Tuit::Tuit(string contenido, Persona* usuario){
    this->contenido = contenido;
    this->usuario   = usuario;
}
