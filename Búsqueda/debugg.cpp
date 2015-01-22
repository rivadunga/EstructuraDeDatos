#include<iostream>
#include <cstdlib>
#include "BusquedaGenerica.h"
using namespace std;


int main()
{
    BusquedaGenerica<int> bg;
    int tam = 100;
    int arreglo[tam];
    for (int val: arreglo) val = rand() % 100;
    cout << bg.busquedaSecuencial(arreglo, 5, tam);
    return 0;
}
