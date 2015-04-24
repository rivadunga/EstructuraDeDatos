#include <iostream>
#include <string.h>
#include "Persona.h"
#include "BinaryTreeDeforme.h"
using namespace vcn;


BinaryTreeDeforme<Persona> arbol;
void agregarHijo();
void verDescendientes();
void verHermanosYPrimos();
void verAncestros();
void establecerFallecido();
void visualizarFallecidos();
void visualizarVivos();

int main(int argc, const char * argv[]) {

    while (true)
    {
        cout << "[1] Agregar hijo"<< endl;
        cout << "[2] Ver descendientes"<< endl;
        cout << "[3] Ver hermanos y primos"<< endl;
        cout << "[4] Ver ancestros"<< endl;
        cout << "[5] Establecer fallecido"<< endl;
        cout << "[6] Visualizar fallecidos"<< endl;
        cout << "[7] Visualizar vivos"<< endl;

        int opc;
        cin >> opc;
        if (opc == 1) agregarHijo();
        else if (opc == 2) verDescendientes();
        else if (opc == 3) verHermanosYPrimos();
        else if (opc == 4) verAncestros();
        else if (opc == 5) establecerFallecido();
        else if (opc == 6) visualizarFallecidos();
        else if (opc == 7) visualizarVivos();
        else break;

    }

    return 0;
}



void agregarHijo()
{
    string padreNom;
    string hijoNom;

    cout << "Padre: ";
    cin >> padreNom;
    cout << "Hijo: ";
    cin >> hijoNom;

    Persona padre(padreNom);
    Persona hijo(hijoNom);


    BNodeDeforme<Persona> * padreNode = arbol.search(padre);
    BNodeDeforme<Persona> * hijoNode = new BNodeDeforme<Persona>(hijo);

    arbol.insert(padreNode,hijoNode);
    arbol.preOrder();
}
void verDescendientes()
{
    string padreNom;
    cout << "Padre: ";
    cin >> padreNom;
    Persona padre(padreNom);
    BNodeDeforme<Persona> * padreNode = arbol.search(padre);
    arbol.preOrder(padreNode);
}
void verHermanosYPrimos()
{
    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    Persona persona(nombre);
    BNodeDeforme<Persona> * nodo = arbol.search(persona);
    arbol.primosyHermanos(nodo);
}
void verAncestros()
{
    string padreNom;
    cout << "Padre: ";
    cin >> padreNom;
    Persona padre(padreNom);
    BNodeDeforme<Persona> * padreNode = arbol.search(padre);
    arbol.ancestors(padreNode);
}
void establecerFallecido()
{
    string nombre;
    cout << "Nombre fallecido: ";
    cin >> nombre;
    int fecha;
    cout << "Fecha (Formato DDMMAAAA): ";
    cin >> fecha;

    Persona nombreP(nombre);
    BNodeDeforme<Persona> * nodo = arbol.search(nombreP);

    if (nodo == nullptr){
        cout << "No se encontro" << endl;
    }else{
        Persona nuevaPersona = nodo->getInfo();
        nuevaPersona.setfallecido(true);
        nuevaPersona.setfecha(fecha);
        nodo->setInfo(nuevaPersona);
        cout << "Status modificado" << endl;
    }

}
void visualizarFallecidos()
{
    int fecha;
    cout << "Fecha de defunsión menor a (Formato DDMMAAAA): ";
    cin >> fecha;
    arbol.preOrder(arbol.getRoot(),
                   [](BNodeDeforme<Persona>* nodo){
                        if (nodo->getInfo().getfallecido() && nodo->getInfo().getfecha() < 12123) return true; return false; });

}
void visualizarVivos()
{
    arbol.preOrder(arbol.getRoot(),
                   [](BNodeDeforme<Persona>* nodo){
                        if (!nodo->getInfo().getfallecido()) return true; return false; });
}
