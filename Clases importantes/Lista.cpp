#pragma once
#include <iostream>
using namespace std;

template<class T>
class Lista{
	private:
		T _datos[100];
		int _tam;
		
	public:
		Lista();
		T[] getDatos();
		void agregar(T,int);
		void eliminar(int);
		T getDato(int);		
	
}

template<class T>
Lista<T>::Lista()
{
	tam = 0;
}

template<class T>
T[] Lista<T>::getDatos()
{
	return _datos;
}

template<class T>
void Lista<T>::agregar(T dato, pos)
{
	for (int i = tam; i > pos; i--)
		datos[i] = datos[i-1];
	datos[pos] = dato;	
	tam++;
}

template<class T>
void Lista<T>::eliminar(T dato,pos)
{
	for (int i = pos+1; i < N; i++)
	datos[i] = datos[i+1];
	tam--;
}

template<class T>
T Lista::getDato(int pos)
{
	return _datos[pos];
}

