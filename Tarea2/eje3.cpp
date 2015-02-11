#include<iostream>
#include "Libro.h"
#include "OrdenamientoGenerico.h"

using namespace std;

int main()
{
    Libro libros[100];
    libros[0].settitulo("Titulo3");
    libros[1].settitulo("Titulo1");
    libros[2].settitulo("Titulo2");

    libros[0].setanio(2010);
    libros[1].setanio(2012);
    libros[2].setanio(2011);

    libros[0].setedicion("1era");
    libros[1].setedicion("2da");
    libros[2].setedicion("3era");


    int tipoOrd;
    int asc;
    int parametro;

    cout << "Tipo de ordenamiento [1] Burbuja, [2] Insercion, [3] Seleccion: ";
    cin >> tipoOrd;
    cout << "Orden: [1] asc, [2] desc: ";
    cin >> asc;
    cout << "Parametro: [1] tit, [2] anio, [3] edicion: ";
    cin >> parametro;


    if (tipoOrd == 1){
        if (asc == 1){
            if (parametro == 1) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.gettitulo() > b.gettitulo()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
            if (parametro == 2) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getanio() > b.getanio()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
            if (parametro == 3) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getedicion() > b.getedicion()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
        }else{
             if (parametro == 1) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.gettitulo() < b.gettitulo()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
             if (parametro == 2) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getanio() < b.getanio()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
             if (parametro == 3) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getedicion() < b.getedicion()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
        }
    }

    if (tipoOrd == 2){
        if (asc == 1){
            if (parametro == 1) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.gettitulo() > b.gettitulo()) return true; return false;  }, Ordenamiento<Libro>::insercion);
            if (parametro == 2) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getanio() > b.getanio()) return true; return false;  }, Ordenamiento<Libro>::insercion);
            if (parametro == 3) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getedicion() > b.getedicion()) return true; return false;  }, Ordenamiento<Libro>::insercion);
        }else{
             if (parametro == 1) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.gettitulo() < b.gettitulo()) return true; return false;  }, Ordenamiento<Libro>::seleccion);
             if (parametro == 2) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getanio() < b.getanio()) return true; return false;  }, Ordenamiento<Libro>::seleccion);
             if (parametro == 3) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getedicion() < b.getedicion()) return true; return false;  }, Ordenamiento<Libro>::seleccion);
        }
    }

    if (tipoOrd == 3){
        if (asc == 1){
            if (parametro == 1) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.gettitulo() > b.gettitulo()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
            if (parametro == 2) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getanio() > b.getanio()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
            if (parametro == 3) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getedicion() > b.getedicion()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
        }else{
             if (parametro == 1) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.gettitulo() < b.gettitulo()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
             if (parametro == 2) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getanio() < b.getanio()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
             if (parametro == 3) Ordenamiento<Libro>::ordenar(libros,3, [](Libro a, Libro b){ if (a.getedicion() < b.getedicion()) return true; return false;  }, Ordenamiento<Libro>::burbuja);
        }
    }



    for(int i = 0; i < 3; i++){
        cout << "Titulo: "  << libros[i].gettitulo() << endl;
        cout << "Anio: "  << libros[i].getanio() << endl;
        cout << "Edicion: "  << libros[i].getedicion() << endl;
        cout << endl;
    }






}
