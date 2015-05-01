#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include"Tuit.h"
#include"Persona.h"

using namespace std;
template <class T>
class Grafo
{
    private:
         map<T*,vector<T*>*> grafo;
         int iNodos = 0;

    public:
        void registrar(T*);
        void follow(T*,T*);
        void unFollow(T*,T*);
        vector<T*> getFollowers(T*);
        vector<T*> getFollowed(T*);
        map<T*,vector<T*>*> getGrafo();
        T* searchByName(string name);
        bool isFollower(T*,T*);
        vector<string> trendingTopics();
        vector<Tuit> getTuitsTrendingTopic(string);
};


template <class T>
void Grafo<T>::registrar(T* valor)
{
    vector<T*>* aristas = new vector<T*>;
    grafo.insert(make_pair(valor,aristas));
    iNodos++;
}

template <class T>
void Grafo<T>::follow(T* follower, T* followed){
    vector<T*>* aristas = grafo.find(followed)->second;
    aristas->push_back(follower);
}


template <class T>
void Grafo<T>::unFollow(T* follower, T* followed){
    vector<T*>* aristas = grafo.find(followed)->second;
    for (int i = 0; i < aristas->size(); i++)
    {
        if (*aristas->at(i) == *follower)
        {
            aristas->erase(aristas->begin()+i);
            return;
        }

    }
}

template <class T>
vector<T*> Grafo<T>::getFollowers(T* persona)
{
    return (*grafo.find(persona)->second);
}

template <class T>
vector<T*> Grafo<T>::getFollowed(T* persona)
{
    vector<T*> followed;
    for (typename map<T*,vector<T*>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        vector<T*> followers = getFollowers(it->first);
        for (int i = 0; i < followers.size(); i++){
            if (followers[i] == persona)
                followed.push_back(it->first);
        }
    }
    return followed;

}

template <class T>
T* Grafo<T>::searchByName(string name)
{
    T* res = nullptr;
    T* buscado = new T(name);
     for (typename map<T*,vector<T*>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        if (*it->first == *buscado)
            return (it->first);
    }
    return nullptr;


}

template <class T>
map<T*,vector<T*>*> Grafo<T>::getGrafo()
{
    return grafo;
}

template <class T>
bool Grafo<T>::isFollower(T* follower,T* followed)
{
    vector<T*> followers = getFollowers(followed);
    for (int i = 0; i < followers.size(); i++){
        if (*followers[i] == *follower)
            return true;
    }
    return false;
}

template <class T>
vector<string> Grafo<T>::trendingTopics()
{
    map <string,int> mapa;

    for (map<Persona*,vector<Persona*>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        vector<Tuit*> tuits = it->first->getTuits();

        for (int i = 0; i < tuits.size(); i++)
        {
            Tuit* tuit = tuits[i];

            string contenido = tuit->getContenido() + " ";
            string espacio = " ";

            size_t pos = 0;
            string token;
            while ((pos = contenido.find(espacio)) != std::string::npos) {
                token = contenido.substr(0, pos);

                if (token.size() > 0 && token[0] == '#')
                {
                    if (mapa.find(token) == mapa.end())
                    {
                        mapa.insert(make_pair(token,0));
                    }else{
                        mapa.find(token)->second++;
                    }
                }
                contenido.erase(0, pos + espacio.length());
            }

        }
    }

    //Ordenar topics
    vector<pair<int,string>> topicsOrdenados;
     for (map<string,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
    {
        topicsOrdenados.push_back(make_pair(it->second,it->first));
    }
    sort(topicsOrdenados.begin(), topicsOrdenados.end());


    vector<string> res;
     for (int i = topicsOrdenados.size()-1; i >= 0; i--)
        res.push_back(topicsOrdenados[i].second);

    return res;
}



template <class T>
vector<Tuit> Grafo<T>::getTuitsTrendingTopic(string topic)
{
    map <Tuit*,int> mapa;

    for (map<Persona*,vector<Persona*>*>::iterator it=grafo.begin(); it!=grafo.end(); ++it)
    {
        vector<Tuit*> tuits = it->first->getTuits();


        for (int i = 0; i < tuits.size(); i++)
        {
            if (tuits[i]->getContenido().find(topic) != -1)
            {
                if (mapa.find(tuits.at(i)) == mapa.end())
                    mapa.insert(make_pair(tuits.at(i),0));
            }
        }
    }

    vector<Tuit> res;
     for (map<Tuit*,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
        res.push_back(*it->first);
    return res;
}

