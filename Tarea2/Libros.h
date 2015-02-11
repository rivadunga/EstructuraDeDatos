#pragma once
#include <iostream>
#include<string.h>
#include "Lista.h"
#include "Libro.h"

using namespace std;

class Libros
{
    private:
        Lista<Libro> libros;

    public:
        void agregar();
        void eliminar();
		void mostrarLibrosCondiciones(bool(*)(Libro,int,int), int,int);
		void mostrarLibrosCondiciones(bool(*)(Libro,string), string);
};

void Libros::agregar()
{
    string titulo,autor,edicion,editorial;
    int numPag, anio;
    cout << "Titulo: ";
    cin >> titulo;
    cout << "Autor: ";
    cin >> autor;
    cout << "Numero Paginas: ";
    cin >> numPag;
    cout << "Edicion: ";
    cin >> edicion;
    cout << "Editorial: ";
    cin >> editorial;
    cout << "Anio: ";
    cin >> anio;
    Libro libro(titulo,autor,numPag,edicion,editorial,anio);
    libros.agregar(libro);
    cout << "Libro agregado" << endl << endl;
}

void Libros::eliminar()
{
    string titulo;
    cout << "Titulo: ";
    cin >> titulo;

    for (int i = 0; i < libros.getNumElementos(); i++){
        if (libros.getElemento(i).gettitulo() == titulo){
            libros.eliminar(i);
            cout << "Libro eliminado" << endl << endl;
            return;
        }
    }
    cout << "Libro no encontrado" << endl << endl;

}

void Libros::mostrarLibrosCondiciones(bool comparar(Libro,int,int),int anioIni, int anioFin)
{
    for (int i = 0; i < libros.getNumElementos(); i++){
        if (comparar(libros.getElemento(i),anioIni,anioFin)){
            cout << "Titulo: "  << libros.getElemento(i).gettitulo() << ", Autor: " << libros.getElemento(i).getautor() << " (" << libros.getElemento(i).getanio() << ")" <<endl;
        }
    }
    cout << endl;
}

void Libros::mostrarLibrosCondiciones(bool comparar(Libro,string),string buscar)
{
    for (int i = 0; i < libros.getNumElementos(); i++){
        if (comparar(libros.getElemento(i),buscar)){
            cout << "Titulo: "  << libros.getElemento(i).gettitulo() << ", Autor: " << libros.getElemento(i).getautor() << " (" << libros.getElemento(i).getanio() << ")" <<endl;
        }
    }
    cout << endl;
}


