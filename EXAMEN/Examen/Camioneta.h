#pragma once
#include<iostream>
using namespace std;

class Camioneta:Vehiculo
{
	private:
		string traccion;
    public:
        void settraccion(string);
        string gettraccion();
};


void Camioneta::settraccion(string traccion){ this->traccion = traccion; }
string Camioneta::gettraccion(){ return this->traccion; }
