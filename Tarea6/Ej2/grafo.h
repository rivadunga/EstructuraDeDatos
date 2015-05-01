#include<vector>
#include<iostream>
#include<map>
using namespace std;

template <class T>
class Grafo
{
    private:
         map<
            int,
            vector<
                pair<int,float> //Aristas <nodo, ponderacion>
             >
          >grafo;
         map <int,T> nodos;
         int iNodos = 0;

    public:
        void agregarNodo(T);
        void agregarArista(T,T,float);
};


template <class T>
void Grafo<T>::agregarNodo(T valor)
{
    vector<pair<int,float>> aristas;
    nodos.insert(iNodos,valor);
    grafo.insert(iNodos,aristas);
    iNodos++;
}

template <class T>
void Grafo<T>::agregarArista(T desde, T hasta, float ponderacion){

    int idDesde = nodos.find(desde);
    int idHasta = nodos.find(hasta);

    pair<int,float> arista;
    arista.first = idDesde;
    arista.second = ponderacion;
    vector<pair<int,float>> aristas = grafo.find(idDesde);
    aristas.push_back(arista);
}
