#pragma once
#include<iostream>
using namespace std;

/**
	DATOS

	Comprador
	TIPO_N
	ATTR N
	OBJ_CLASE
	ATTR_KEY


*/

class Comprador
{
	private:
		string apellido;
		string nombre;
		string ife;

	public:
		Comprador();
		Comprador(string,string,string);

		bool operator == (Comprador&);

		void setapellido(string);
		string getapellido();

		void setnombre(string);
		string getnombre();

		void setife(string);
		string getife();


};

Comprador::Comprador()
{

}

bool Comprador::operator == (Comprador& comprador){
     if (nombre == comprador.nombre && apellido == comprador.apellido)
        return true;
    return false;
}

Comprador::Comprador(string apellido,string nombre,string ife){
    this->apellido = apellido;
    this->nombre = nombre;
    this->ife = ife;
}




void Comprador::setapellido(string apellido){ this->apellido = apellido; }
string Comprador::getapellido(){ return this->apellido; }

void Comprador::setnombre(string nombre){ this->nombre = nombre; }
string Comprador::getnombre(){ return this->nombre; }

void Comprador::setife(string ife){ this->ife = ife; }
string Comprador::getife(){ return this->ife; }









