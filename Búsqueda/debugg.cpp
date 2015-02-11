#include<iostream>
#include <cstdlib>
#include "BusquedaGenerica.h"
#include "Libro.h"
using namespace std;


int main()
{
    //Generica
    BusquedaGenerica<Libro> bg;
    int tam = 100;
    Libro arreglo[tam];

    for (int i = 0; i < tam; i++)
        arreglo[i]._isbn = i+"";

    Libro lb;
    lb._isbn = "6";
    cout << bg.busquedaSecuencial(arreglo, lb , tam) << endl;
    cout << bg.busquedaBinaria(arreglo,lb,0,tam) << endl;

    BusquedaGenerica<int> bgb;
    int arregloB[tam];
     for (int i = 0; i < tam; i++)
        arregloB[i] = i;

    cout << bgb.busquedaSecuencial(arregloB,45,tam) << endl;
    cout << bgb.busquedaBinaria(arregloB,45,0,tam) << endl;

    int matriz[tam][tam];
    for (int j = 0; j < tam; j++)
        for (int i = 0; i < tam; i++)
            matriz[i][j] = i*j;

    bgb.busquedaSecuencial(matriz,5,tam,tam)
    return 0;
}
