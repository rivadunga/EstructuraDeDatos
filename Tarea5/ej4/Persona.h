#pragma once
#include<iostream>
#include<string.h>
using namespace std;


class Persona
{
	private:
		string nombre;
		bool fallecido;
		int fecha;

	public:
		Persona();
		Persona(string);

		bool operator > (Persona&);
        bool operator < (Persona&);
        bool operator == (Persona&);
        ostream &operator << (ostream);

		void setnombre(string);
		string getnombre();

		void setfallecido(bool);
		bool getfallecido();

		void setfecha(int);
		int getfecha();

};

Persona::Persona()
{

}

Persona::Persona(string nombre){
    this->nombre = nombre;
    this->fallecido = false;
    this->fecha = 0;
}


bool Persona::operator > (Persona& persona){
     if (fecha > persona.fecha)
        return true;
    return false;
}
bool Persona::operator < (Persona& persona){
     if (fecha < persona.fecha)
        return true;
    return false;
}
bool Persona::operator == (Persona& persona){
     if (nombre == persona.nombre)
        return true;
    return false;
}
ostream& Persona::operator << (ostream os){
    os << nombre << " ";
}

void Persona::setnombre(string nombre){ this->nombre = nombre; }
string Persona::getnombre(){ return this->nombre; }

void Persona::setfallecido(bool fallecido){ this->fallecido = fallecido; }
bool Persona::getfallecido(){ return this->fallecido; }

void Persona::setfecha(int fecha){ this->fecha = fecha; }
int Persona::getfecha(){ return this->fecha; }




