#pragma once
#include<iostream>
#include<string>
using namespace std;



class Producto
{
	private:
		string descripcion;
		int cantidad;
		float precio;

	public:
		Producto();
		Producto(string,int,float);
        friend ostream &operator << (ostream & os, Producto & producto)
        {
             os << producto.descripcion << "  " << producto.cantidad << "  $ "<< producto.precio << endl;
        }

		void setdescripcion(string);
		string getdescripcion();

		void setcantidad(int);
		int getcantidad();

		void setprecio(float);
		float getprecio();
};

Producto::Producto()
{

}

Producto::Producto(string descripcion,int cantidad,float precio){
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
}




void Producto::setdescripcion(string descripcion){ this->descripcion = descripcion; }
string Producto::getdescripcion(){ return this->descripcion; }

void Producto::setcantidad(int cantidad){ this->cantidad = cantidad; }
int Producto::getcantidad(){ return this->cantidad; }

void Producto::setprecio(float precio){ this->precio = precio; }
float Producto::getprecio(){ return this->precio; }

