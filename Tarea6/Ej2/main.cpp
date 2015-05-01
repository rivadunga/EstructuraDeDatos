#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<
        pair<string, //Nombre
                    vector<
                        pair<int,int> //Aristas <id, ponderacion>
                    >
        >
    > grafo; //GRAFO PROPIO

    //Define nodos
    pair<string,vector<pair<int,int>>> nodo0;
    nodo0.first = "Maria";

    pair<string,vector<pair<int,int>>> nodo1;
    nodo1.first = "Javier";

    pair<string,vector<pair<int,int>>> nodo2;
    nodo2.first = "Alicia";

    pair<string,vector<pair<int,int>>> nodo3;
    nodo3.first = "Samuel";

    pair<string,vector<pair<int,int>>> nodo4;
    nodo4.first = "John";

    pair<string,vector<pair<int,int>>> nodo5;
    nodo5.first = "Daniel";

    //Crea aristas
    vector<pair<int,int>> amigosNodo0;
    pair<int,int> aristaNodo01(1,100);
    pair<int,int> aristaNodo02(2,600);
    pair<int,int> aristaNodo03(3,800);
    amigosNodo0.push_back(aristaNodo01);
    amigosNodo0.push_back(aristaNodo02);
    amigosNodo0.push_back(aristaNodo03);
    nodo0.second = amigosNodo0;

    vector<pair<int,int>> amigosNodo1;
    pair<int,int> aristaNodo10(1,700);
    pair<int,int> aristaNodo12(2,600);
    amigosNodo1.push_back(aristaNodo10);
    amigosNodo1.push_back(aristaNodo12);
    nodo1.second = amigosNodo1;

    vector<pair<int,int>> amigosNodo2;
    pair<int,int> aristaNodo20(0,200);
    pair<int,int> aristaNodo23(3,500);
    amigosNodo2.push_back(aristaNodo20);
    amigosNodo2.push_back(aristaNodo23);
    nodo2.second = amigosNodo2;

    vector<pair<int,int>> amigosNodo3;
    pair<int,int> aristaNodo30(0,200);
    pair<int,int> aristaNodo31(1,400);
    pair<int,int> aristaNodo32(2,100);
    pair<int,int> aristaNodo33(3,1000);
    amigosNodo3.push_back(aristaNodo30);
    amigosNodo3.push_back(aristaNodo31);
    amigosNodo3.push_back(aristaNodo32);
    amigosNodo3.push_back(aristaNodo33);
    nodo3.second = amigosNodo3;

    vector<pair<int,int>> amigosNodo4;
    nodo4.second = amigosNodo4;

    vector<pair<int,int>> amigosNodo5;
    nodo4.second = amigosNodo5;


    grafo.push_back(nodo0);
    grafo.push_back(nodo1);
    grafo.push_back(nodo2);
    grafo.push_back(nodo3);
    grafo.push_back(nodo4);
    grafo.push_back(nodo5);

    //Numero de amigos
    for (int j = 0; j < grafo.size(); j++){
        cout << "Amigos de: " << grafo[j].first << endl;

        for (int i = 0; i < grafo[j].second.size(); i++)
        {
            int id = grafo[j].second[i].first;
            cout << "   " << grafo[id].first << " duracion: " << grafo[j].second[i].second << endl;
        }
    }

    //Tiempo acompañado
    cout << "\n\n";
    float tiempoTotal = 265*24;
    for (int j = 0; j < grafo.size(); j++){
        float tiempoAmigo = 0;

        for (int i = 0; i < grafo[j].second.size(); i++)
            tiempoAmigo += grafo[j].second[i].second;

        cout << grafo[j].first << " :: \n";
        cout << "  Tiempo acompañado: " << tiempoAmigo/tiempoTotal * 100.0 << "%\n";
        cout << "  Tiempo solor:      " << (tiempoTotal-tiempoAmigo)/tiempoTotal * 100.0 << "%\n";
        cout << endl;
    }

    //Mas relaciones
    int iMax = 0;
    int maxRel = 0;
    for (int j = 0; j < grafo.size(); j++){
        if (maxRel < grafo[j].second.size())
        {
            maxRel = grafo[j].second.size();
            iMax = j;
        }
    }
    cout << "\n" << grafo[iMax].first << " es la persona con mas amigos (" << maxRel << ")\n\n";



    //Sin relaciones
    for (int j = 0; j < grafo.size(); j++){
        if (grafo[j].second.size() == 0)
            cout << "" << grafo[j].first << " no tiene amigos\n";
    }
    cout << "\n\n";

    //Más estable
    int iMaxEst = 0;
    float maxEst = 0;

    for (int j = 0; j < grafo.size(); j++){
        int suma = 0;
        for (int i = 0; i < grafo[j].second.size(); i++){
            suma += grafo[j].second[i].second;
        }

        if (grafo[j].second.size() > 0 && suma / grafo[j].second.size() > maxEst)
        {
            maxEst = suma / grafo[j].second.size();
            iMaxEst = j;
        }

    }
    cout << "\n" << grafo[iMaxEst].first << " es la persona más estable :: promedio (" << maxEst << ")\n\n";


    return 0;

}
