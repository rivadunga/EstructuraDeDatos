#pragma once
#include<iostream>
#include "string.h"
using namespace std;

class Persona
{
	private:
		string nombre;
		string apellido;
		int edad;
		string nacimiento;

	public:
		Persona();
		Persona(string,string,int,string);

		bool operator > (Persona&);
        bool operator < (Persona&);
        bool operator == (Persona&);
        friend std::ostream & operator << (std::ostream&, Persona);

		void setnombre(string);
		string getnombre();

		void setapellido(string);
		string getapellido();

		void setedad(int);
		int getedad();

		void setnacimiento(string);
		string getnacimiento();



};

Persona::Persona()
{

}

Persona::Persona(string nombre,string apellido,int edad,string nacimiento){
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->nacimiento = nacimiento;
}


bool Persona::operator > (Persona& persona){
     if (apellido == persona.apellido && nombre > persona.nombre)
        return true;

     if (apellido > persona.apellido)
        return true;

    return false;
}
bool Persona::operator < (Persona& persona){
     if (apellido == persona.apellido && nombre < persona.nombre)
        return true;

     if (apellido < persona.apellido)
        return true;

    return false;
}
bool Persona::operator == (Persona& persona){
     if (nombre == persona.nombre && apellido == persona.apellido)
        return true;
    return false;
}

template <class T>
std::ostream & operator << (std::ostream & os, Persona & persona)
{
    os << persona.nombre;
    return os;
}

void Persona::setnombre(string nombre){ this->nombre = nombre; }
string Persona::getnombre(){ return this->nombre; }

void Persona::setapellido(string apellido){ this->apellido = apellido; }
string Persona::getapellido(){ return this->apellido; }

void Persona::setedad(int edad){ this->edad = edad; }
int Persona::getedad(){ return this->edad; }

void Persona::setnacimiento(string nacimiento){ this->nacimiento = nacimiento; }
string Persona::getnacimiento(){ return this->nacimiento; }





