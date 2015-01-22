#include<iostream>
using namespace std;

template<class T>
class BusquedaGenerica
{
    public:
        bool busquedaSecuencial(T[],T,int);
};

template<class T>
bool BusquedaGenerica<T>::busquedaSecuencial(T v[],T valor,int len)
{
    if (len <= 0) return false;
    for (int i = 0; i < len; i++)
        if (v[i] == valor)
            return true;
    return false;
}

