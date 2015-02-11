#pragma once
#include<iostream>
using namespace std;

class Libro
{
	private:
		string titulo;
		string autor;
		int numPag;
		string edicion;
		string editorial;
		int anio;

	public:
		Libro();
		Libro(string,string,int,string,string,int);

        bool operator > (Libro&);
        bool operator < (Libro&);
        bool operator == (Libro&);
        ostream &operator << (ostream);

		void settitulo(string);
		string gettitulo();

		void setautor(string);
		string getautor();

		void setnumPag(int);
		int getnumPag();

		void setedicion(string);
		string getedicion();

		void seteditorial(string);
		string geteditorial();

		void setanio(int);
		int getanio();




};

Libro::Libro()
{

}

Libro::Libro(string titulo,string autor,int numPag,string edicion,string editorial,int anio){

    this->titulo  = titulo;
	this->autor   = autor;
	this->numPag  = numPag ;
    this->edicion = edicion;
    this->editorial = editorial;
    this-> anio     = anio;

}


bool Libro::operator > (Libro& libro){
     if (anio > libro.anio)
        return true;
    return false;
}
bool Libro::operator < (Libro& libro){
     if (anio < libro.anio)
        return true;
    return false;
}
bool Libro::operator == (Libro& libro){
     if (titulo == libro.titulo)
        return true;
    return false;
}
ostream& Libro::operator << (ostream os){
    os << anio << endl;
}

void Libro::settitulo(string titulo){ this->titulo = titulo; }
string Libro::gettitulo(){ return this->titulo; }

void Libro::setautor(string autor){ this->autor = autor; }
string Libro::getautor(){ return this->autor; }

void Libro::setnumPag(int numPag){ this->numPag = numPag; }
int Libro::getnumPag(){ return this->numPag; }

void Libro::setedicion(string edicion){ this->edicion = edicion; }
string Libro::getedicion(){ return this->edicion; }

void Libro::seteditorial(string editorial){ this->editorial = editorial; }
string Libro::geteditorial(){ return this->editorial; }

void Libro::setanio(int anio){ this->anio = anio; }
int Libro::getanio(){ return this->anio; }







