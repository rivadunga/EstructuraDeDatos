#pragma once
#include<iostream>
using namespace std;

class Motocicleta: public Vehiculo
{
	private:
		string cilindraje;
    public:
        void setcilindraje(string);
        string getcilindraje();
};


void Motocicleta::setcilindraje(string cilindraje){ this->cilindraje = cilindraje; }
string Motocicleta::getcilindraje(){ return this->cilindraje; }
