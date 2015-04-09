#pragma once
#include <iostream>
using namespace std;



template<class Elemento>
class Lista{
    private:
       Elemento* lista;
       int tam;
       int num_elementos;
        
    
    public: 
        Lista();
        Lista(Elemento* lista, int tam);
        void agregar(Elemento valor);
        void eliminar(int pos);
        Elemento& getElemento(int pos);   //IMPORTANTE &
        void setElemento(int pos, Elemento valor);
        int getNumElementos();
};



template<class Elemento>
Lista<Elemento>::Lista(){
    lista = new Elemento[50];
    tam = 50;
    num_elementos = 0;
}

template<class Elemento>
Lista<Elemento>::Lista(Elemento* lista, int tam){
    this->lista = lista;
    this->tam  = tam;
    num_elementos = 0;
}




template<class Elemento>
void ampliar_memoria(Elemento*& lista, int& tam){

    tam = tam+1;
    Elemento* lista_aux = new Elemento[tam];
    for (int i = 0; i < tam-1; i++){
        lista_aux[i] = lista[i];
    }
    delete lista; //Libera el espacio del arreglo
    lista = lista_aux; //Se le asigna al original la direccion del nuevo arreglo
    lista_aux = NULL;
}


template<class Elemento>
void Lista<Elemento>::agregar(Elemento valor){
    if (num_elementos >= tam)
        ampliar_memoria(lista,tam);
    lista[num_elementos] = valor;
    num_elementos++;
}




template<class Elemento>
void Lista<Elemento>::eliminar(int pos){
    if (pos > 0) pos--;
    for (int i = pos; i < tam-1; i++)
        lista[i] = lista[i+1];
    num_elementos--;
}

template<class Elemento>
Elemento& Lista<Elemento>::getElemento(int pos){
    return lista[pos];
    
}

template<class Elemento>
void Lista<Elemento>::setElemento(int pos, Elemento elemento)
{
    lista[pos] = elemento;
}

template<class Elemento>
int Lista<Elemento>::getNumElementos(){
    return num_elementos;
    
}

