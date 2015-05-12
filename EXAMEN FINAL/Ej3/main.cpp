#include<iostream>
#include<vector>
#include<string>
#include "BinaryTree.h"
#include "BNode.h"
using namespace std;
using namespace vcn;


void obtener(BinaryTree<char>* arbol, vector<char> restantes, vector<char> preorden, BNode<char>* padre){


    if (restantes.size() > 0)
    {
        char siguiente;
        bool siguienteAsignado = false;
        for (int j = 0; j < preorden.size(); j++){
            for (int i = 0; i < restantes.size(); i++){
                if (preorden.at(j) == restantes.at(i))
                {
                    if (!siguienteAsignado){
                        siguiente = preorden.at(j);
                        siguienteAsignado = true;
                    }
                }
            }
        }

        BNode<char>* siguienteNodo = new BNode<char>(siguiente);
        arbol->insert(padre,siguienteNodo);

        vector<char> izquierda;
        vector<char> derecha;


        int posSiguienteNodo = 0;
        for (int i = 0; i < restantes.size(); i++){
            if (restantes[i] == siguiente)
                posSiguienteNodo = i;
        }

        for (int i = 0; i < posSiguienteNodo; i++)
        {
            izquierda.push_back(restantes[i]);
        }


        for (int i = posSiguienteNodo+1; i < restantes.size(); i++)
        {
            derecha.push_back(restantes[i]);
        }

        obtener(arbol,izquierda,preorden,siguienteNodo);
        obtener(arbol,derecha,preorden,siguienteNodo);


    }


}


int main()
{
    vector<char> preorden;
    vector<char> inorden;
    string preStr, inStr;

    cin >> preStr >> inStr;
    for (int i = 0; i < preStr.length(); i++)
        preorden.push_back(preStr.at(i));

    for (int i = 0; i < inStr.length(); i++)
        inorden.push_back(inStr.at(i));

    BinaryTree<char>* arbol = new BinaryTree<char>;

    obtener(arbol,inorden,preorden,nullptr);

    cout << endl;
    arbol->preOrder();
    cout << endl;
    arbol->inOrder();

}
