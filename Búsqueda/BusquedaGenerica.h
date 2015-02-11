#include<iostream>
using namespace std;

template<class T>
class BusquedaGenerica
{
    public:
        int busquedaSecuencial(T[],T,int);
        int busquedaSecuencial(T*[],T,int,int);
        int busquedaBinaria   (T[],T,int,int);
};

template<class T>
int BusquedaGenerica<T>::busquedaSecuencial(T v[],T valor,int len)
{
    if (len <= 0) return -1;
    for (int i = 0; i < len; i++)
        if (v[i] == valor)
            return i;
    return -1;
}


template<class T>
int BusquedaGenerica<T>::busquedaSecuencial(T*[] v,T valor,int col,int fil)
{
    for (int j = 0; j < fil; j++)
        for (int i = 0; i < col; i++)
            if (v[i][j] == valor)
                return 1;

    return -1;

}


template<class T>
int BusquedaGenerica<T>::busquedaBinaria   (T v[],T valor,int inferior,int superior)
{
    if (inferior >= superior){
        return -1;
    }else{
        int mitad = (inferior + superior)/2; //Promedio
        if (v[mitad] == valor){
            return mitad;
        }else if (valor < v[mitad])
        {
            busquedaBinaria(v,valor,inferior,mitad);
        }else{
            busquedaBinaria(v,valor,mitad+1,superior);
        }

    }
}
