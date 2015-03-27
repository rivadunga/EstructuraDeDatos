#include<iostream>
#include<string.h>
#include"Node.h"
#include"CircularLinkedList.h"
using namespace std;
using namespace vcn;


void imprimirConfiguracion(CircularLinkedList<bool>* equipos, string str)
{
    for (int i = 0; i < equipos->size(); i++)
        if (equipos->at(i)->getInfo())
            cout << str << " ";
        else
            cout << "." <<  " ";
    cout << endl << endl;

}


int main()
{


    CircularLinkedList<bool> * equipos = new CircularLinkedList<bool>();
    int numEquipos = 0;
    cout << "Numero de equipos: ";
    cin >> numEquipos;
    for (int i = 0; i < numEquipos-1; i++){
        equipos->LinkedList::insert(false,0);
    }
    equipos->LinkedList::insert(true,0);

    cout << "Configuracion inicial" << endl;
    imprimirConfiguracion(equipos,"t");
    Node<bool> * node = equipos->at(true);
    int posToken = equipos->LinkedList::at(node)-1;


    cout << "Enviar un paquete desde la computadora: ";
    int ini,fin;
    cin >> ini;
    cout << "Enviar un paquete hacia la computadora: ";
    cin >> fin;
    ini--;
    fin--;

    cout << endl;
    for (int i = 0; i < equipos->size(); i++)
        cout << i+1 << " ";
    cout << endl;

    imprimirConfiguracion(equipos,"t");
    while (posToken%equipos->size() != ini){
        equipos->at(posToken%equipos->size())->setInfo(false);
        equipos->at((posToken+1)%equipos->size())->setInfo(true);
        imprimirConfiguracion(equipos,"t");
        posToken++;
    }

    imprimirConfiguracion(equipos,">");
    while (posToken%equipos->size() != fin){
        equipos->at(posToken%equipos->size())->setInfo(false);
        equipos->at((posToken+1)%equipos->size())->setInfo(true);
        imprimirConfiguracion(equipos,">");
        posToken++;
    }

    return 0;

}
