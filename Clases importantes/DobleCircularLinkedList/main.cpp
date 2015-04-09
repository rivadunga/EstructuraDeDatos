
#include<iostream>
#include "DobleCircularLinkedList.h"

using namespace std;
using namespace vcn;

void imprimir(DobleCircularLinkedList<int> lista)
{

    for (int i = 0; i < lista.size(); i++)
    {
        int anterior  = -1;
        int actual    = -1;
        int siguiente = -1;

        actual = lista.at(i)->getInfo();

        if (i > 0)
            anterior = lista.at(i)->getPrevious()->getInfo();

        if (i < lista.size()-1)
            siguiente = lista.at(i)->getNext()->getInfo();

        cout << anterior << " " << actual << " " << siguiente << endl;

    }
}


int main()
{

    DobleCircularLinkedList<int> lista;
    lista.insert(1,1);
    lista.insert(2,2);
    lista.insert(3,1);
    lista.insert(4,4);
    lista.insert(5,1);
    lista.insert(6,6);
    lista.insert(9,1);

    /*
    lista.remove(0);
    lista.remove(0);
    lista.remove(0);
    lista.remove(2);
    */


    imprimir(lista);

    cout << endl;
   // lista.remove(1);

  //  imprimir(lista);






    return 0;
}
