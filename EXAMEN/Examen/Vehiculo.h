#pragma once
#include<iostream>
using namespace std;


class Vehiculo
{
	private:
		int codigo;
		string marca;
		string modelo;
		float kilometraje;
	public:
		Vehiculo();
        Vehiculo(int,string,string,float);

        bool operator == (Vehiculo&);

		void setcodigo(int);
		int getcodigo();

		void setmarca(string);
		string getmarca();

		void setmodelo(string);
		string getmodelo();

		void setkilometraje(float);
		float getkilometraje();


};

Vehiculo::Vehiculo()
{

}


bool Vehiculo::operator == (Vehiculo& vehiculo){
     if (codigo == vehiculo.codigo)
        return true;
    return false;
}

Vehiculo::Vehiculo(int codigo,string marca,string modelo,float kilometraje){
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->kilometraje = kilometraje;
}



void Vehiculo::setcodigo(int codigo){ this->codigo = codigo; }
int Vehiculo::getcodigo(){ return this->codigo; }

void Vehiculo::setmarca(string marca){ this->marca = marca; }
string Vehiculo::getmarca(){ return this->marca; }

void Vehiculo::setmodelo(string modelo){ this->modelo = modelo; }
string Vehiculo::getmodelo(){ return this->modelo; }

void Vehiculo::setkilometraje(float kilometraje){ this->kilometraje = kilometraje; }
float Vehiculo::getkilometraje(){ return this->kilometraje; }
