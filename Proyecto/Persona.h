#pragma once
#include "Tuit.h"
#include<vector>
#include<string>
class Persona
{
    private:
        vector<Tuit*> tuits;
        string nombre;

    public:
        Persona(string);
        vector<Tuit*> getTuits();
        string getNombre();
        void nuevoTuit(string);
        void nuevoTuit(Tuit*);
        bool operator == (Persona&);
};

vector<Tuit*> Persona::getTuits(){ return tuits; }
string Persona::getNombre(){ return nombre; }

Persona::Persona(string nombre){ this->nombre = nombre; }

bool Persona::operator == (Persona& persona){
     if (nombre == persona.nombre)
        return true;
    return false;
}


void Persona::nuevoTuit(string contenido){
    Tuit* tuit = new Tuit(contenido,this);
    tuits.push_back(tuit);
}

void Persona::nuevoTuit(Tuit* tuit){
    tuits.push_back(tuit);
}

