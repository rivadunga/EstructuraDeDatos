#include<vector>
#include<iostream>
#include<map>
using namespace std;

template <class T>
class Grafo
{
    private:
         map<T*,vector<pair<T*,float>>*>grafo;

    public:
        void agregarNodo(T*);
        void agregarArista(T*,T*,float);
        void borrarNodo(T*);
        void borrarArista(T*,T*);
        vector<pair<T*,float>> getHijos(T*);
        vector<pair<T*,float>> getPadres(T*);
        T* searchByAttribute(int attr);
        bool grafoCompleto();
};


template <class T>
void Grafo<T>::agregarNodo(T* valor)
{
    vector<pair<T*,float>>* aristas = new vector<pair<T*,float>>;
    grafo.insert(make_pair(valor,aristas));
}

template <class T>
void Grafo<T>::agregarArista(T* padre, T* hijo, float ponderacion)
{
    vector<pair<T*,float>>* aristas = grafo.find(padre)->second;
    aristas->push_back(make_pair(hijo,ponderacion));
}


template <class T>
void Grafo<T>::borrarArista(T* padre, T* hijo)
{
    vector<pair<T*,float>>* aristas = grafo.find(padre)->second;
    for (int i = 0; i < aristas->size(); i++)
    {
        if (*aristas->at(i).first == *hijo)
        {
            aristas->erase(aristas->begin()+i);
            return;
        }
    }
}

template <class T>
void Grafo<T>::borrarNodo(T* borrado)
{
    vector<pair<T*,float>> hijos = getHijos(borrado);
    vector<pair<T*,float>> padres = getPadres(borrado);

    for (int i = 0; i < hijos.size(); i++)
        borrarArista(borrado,hijos[i].first);

    for (int i = 0; i < padres.size(); i++)
        borrarArista(padres[i].first,borrado);

}




template <class T>
vector<pair<T*,float>> Grafo<T>::getHijos(T* padre)
{
    return (*grafo.find(padre)->second);
}

template <class T>
vector<pair<T*,float>> Grafo<T>::getPadres(T* hijo)
{
    vector<pair<T*,float>> padres;

    for (typename map<T*,vector<pair<T*,float>>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        vector<pair<T*,float>> hijos = getHijos(it->first);
        for (int i = 0; i < hijos.size(); i++){
            if (hijos[i].first == hijo){
                padres.push_back(make_pair(it->first,hijos[i].second));
            }
        }
    }
    return padres;
}


template <class T>
T* Grafo<T>::searchByAttribute(int attr)
{
    T* res = nullptr;
    T* buscado = new T(attr);
     for (typename map<T*,vector<pair<T*,float>>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        if (*it->first == *buscado)
            return (it->first);
    }
    return nullptr;
}

template <class T>
bool Grafo<T>::grafoCompleto()
{
    vector<T*> nodos;
    for (typename map<T*,vector<pair<T*,float>>*>::iterator itAux=grafo.begin(); itAux!=grafo.end(); ++itAux)
        nodos.push_back(itAux->first); //Guarda nodos


    for (typename map<T*,vector<pair<T*,float>>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        vector<pair<T*,float>> hijos = getHijos(it->first);
        for (int j = 0; j < nodos.size(); j++){ //Evala todos los nodos verificando que tengan una relación con el nodo de iteración
            bool relacion = false;
            for (int i = 0; i < hijos.size(); i++){ //En caso de que haya relación o el nodo a verificar sea el mismo de la iteracion
                if (hijos[i].first == nodos[j] || nodos[j] == it->first){
                    relacion = true;
                }
            }
            if (relacion == false)  return false; //Si no hay relación automaticamente se sale del ciclo
        }
    }


    return true;
}



