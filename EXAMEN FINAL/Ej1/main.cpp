#include<iostream>
#include<vector>
#include "Grafo.h"
using namespace std;

void imprimir(bool completo)
{
    cout << "Este grafo es: ";
    if (completo)
        cout << "Un grafo completo" << endl;
    else
        cout << "Un grafo incompleto" << endl;

}

int main()
{
    Grafo<int> grafo;
    int* dato1 = new int(1);
    int* dato2 = new int(2);
    int* dato3 = new int(3);
    int* dato4 = new int(4);

    grafo.agregarNodo(dato1);
    grafo.agregarNodo(dato2);
    grafo.agregarNodo(dato3);
    grafo.agregarNodo(dato4);

    grafo.agregarArista(dato1,dato2,0);
    grafo.agregarArista(dato1,dato3,0);
    grafo.agregarArista(dato1,dato4,0);

    grafo.agregarArista(dato2,dato1,0);
    grafo.agregarArista(dato2,dato3,0);
    grafo.agregarArista(dato2,dato4,0);

    grafo.agregarArista(dato3,dato1,0);
    grafo.agregarArista(dato3,dato2,0);
    grafo.agregarArista(dato3,dato4,0);

    grafo.agregarArista(dato4,dato1,0);


    imprimir(grafo.grafoCompleto());

    grafo.agregarArista(dato4,dato2,0);
    imprimir(grafo.grafoCompleto());

    grafo.agregarArista(dato4,dato3,0);
    imprimir(grafo.grafoCompleto());


    grafo.borrarArista(dato1,dato3);
    imprimir(grafo.grafoCompleto());

    grafo.agregarArista(dato1,dato3,0);
    imprimir(grafo.grafoCompleto());



    return 0;


}
