#include<iostream>
#include<string.h>
#include "Libros.h"
#include "Libro.h"
using namespace std;

void mostrarLibros();


int main()
{
    int arreglo[10] = {1,2,3,4,5,6};
    Libros libros;
    cout << "Bienvenido: " << endl << endl;
    while (true){
        cout << endl;
        cout << " [1] Agregar" << endl;
        cout << " [2] Eliminar" << endl;
        cout << " [3] Antes de" << endl;
        cout << " [4] Despues de" << endl;
        cout << " [5] Entre" << endl;
        cout << " [6] Por autor" << endl;
        cout << " [7] Por editorial" << endl;

        cout << "Selecciona una opcion: ";
        int opcion;
        cin >> opcion;
        cout << endl;

        if (opcion == 1) libros.agregar();
        if (opcion == 2) libros.eliminar();
        if (opcion == 3){
            int anio;
            cout << "Antes de: ";
            cin >> anio;
            libros.mostrarLibrosCondiciones([](Libro libro, int anioIni, int anioFin){ if (libro.getanio() < anioFin) return true; return false; },0,anio);
        }

        if (opcion == 4){
            int anio;
            cout << "Despues de: ";
            cin >> anio;
            libros.mostrarLibrosCondiciones([](Libro libro, int anioIni, int anioFin){if (libro.getanio() > anioFin) return true; return false;  },0,anio);
        }

        if (opcion == 5){
            int anioI, anioF;
            cout << "Entre ";
            cin >> anioI >> anioF;
            libros.mostrarLibrosCondiciones([](Libro libro, int anioIni, int anioFin){if (libro.getanio() > anioIni && libro.getanio() < anioFin) return true; return false;  },anioI,anioF);
        }

        if (opcion == 6){
            string autor;
            cout << "Autor ";
            cin >> autor;
            libros.mostrarLibrosCondiciones([](Libro libro, string valor){if (libro.getautor() == valor) return true; return false;  },autor);
        }

        if (opcion == 7){
            string titulo;
            cout << "Titulo ";
            cin >> titulo;
            libros.mostrarLibrosCondiciones([](Libro libro, string valor){if (libro.gettitulo() == valor) return true; return false;  },titulo);
        }




    }




}
