#include<iostream>
#include<cstdlib>
#include<string>
#include "OrdenamientoGenerico.h"
using namespace std;

int main(){
    string datos[100];
    for (int j = 0; j < 100; j++){
        int lonCadena = 10+rand()%15;
        string dato = "";
        for (int i = 0; i < lonCadena; i++){
            dato += (char)(rand()%26+'a');
        }
        datos[j] = dato;
    }

    int tipoOrd;
    int asc;
    cout << "Burbuja[1], Insercion[2], Seleccion[3]: ";
    cin >> tipoOrd;
    cout << "Asc[1] Des[2]: ";
    cin >> asc;


    if (tipoOrd == 1){
        if (asc == 1)  Ordenamiento<string>::ordenar(datos,100,Ordenamiento<string>::asc,Ordenamiento<string>::burbuja);
        else           Ordenamiento<string>::ordenar(datos,100,Ordenamiento<string>::desc,Ordenamiento<string>::burbuja);
    }
    if (tipoOrd == 2){
        if (asc == 1)  Ordenamiento<string>::ordenar(datos,100,Ordenamiento<string>::asc,Ordenamiento<string>::insercion);
        else           Ordenamiento<string>::ordenar(datos,100,Ordenamiento<string>::desc,Ordenamiento<string>::insercion);
    }
    if (tipoOrd == 3){
        if (asc == 1)  Ordenamiento<string>::ordenar(datos,100,Ordenamiento<string>::asc,Ordenamiento<string>::seleccion);
        else           Ordenamiento<string>::ordenar(datos,100,Ordenamiento<string>::desc,Ordenamiento<string>::seleccion);
    }

    cout << endl;
    for (int i = 0; i < 100; i++){
       cout << datos[i] << endl;
    }

}
