#pragma once
#include"Producto.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Contenedor
{
	private:
		int numero;
		string empresa;
		int tamano;
		vector<Producto> productos;

	public:
		Contenedor();
		Contenedor(int,string,int);


        friend ostream &operator << (ostream & os, Contenedor & contenedor)
        {
            os << "   Contenedor no " << contenedor.numero << endl;
            for (int i = 0; i < contenedor.getproductos().size(); i++){
                os << "      " << contenedor.getproductos()[i];
            }
            os << "   Costo del contenedor: $" << contenedor.getCosto() << endl;
        }



		void setnumero(int);
		int getnumero();

		void setempresa(string);
		string getempresa();

		void settamano(int);
		int gettamano();

		void setproductos(vector<Producto>);
		vector<Producto> getproductos();

		void agregarProducto(string, int, float);
		bool estaLleno();
		float getCosto();

};

Contenedor::Contenedor()
{

}

Contenedor::Contenedor(int numero,string empresa,int tamano){
    this->numero = numero;
    this->empresa = empresa;
    this->tamano = tamano;
}




void Contenedor::setnumero(int numero){ this->numero = numero; }
int Contenedor::getnumero(){ return this->numero; }

void Contenedor::setempresa(string empresa){ this->empresa = empresa; }
string Contenedor::getempresa(){ return this->empresa; }

void Contenedor::settamano(int tamano){ this->tamano = tamano; }
int Contenedor::gettamano(){ return this->tamano; }

void Contenedor::setproductos(vector<Producto> productos){ this->productos = productos; }
vector<Producto> Contenedor::getproductos(){ return this->productos; }

bool Contenedor::estaLleno(){ if (productos.size() < tamano) return false; return true; }

void Contenedor::agregarProducto(string descripcion, int cantidad, float precio){
    Producto producto(descripcion,cantidad,precio);
    productos.push_back(producto);
}

float Contenedor::getCosto()
{
    float costo = 0;
    for (int i = 0; i < productos.size(); i++){
        costo += productos[i].getprecio() * productos[i].getcantidad();
    }
    return costo;
}
