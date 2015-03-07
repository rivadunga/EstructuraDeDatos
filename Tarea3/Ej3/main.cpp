#include <iostream>
#include "OrderedLinkedList.h"
#include "LinkedList.h"
#include "Persona.h"
#include "BusquedaGenerica.h"
using namespace std;

int main()
{

   OrderedLinkedList<Persona>*  lista = new OrderedLinkedList<Persona>();
    while (true)
    {
        int opc;
        cout << endl << endl;
        cout << "[1] Anadir persona " << endl;
        cout << "[2] Buscar persona " << endl;
        cout << "[3] Borrar persona " << endl;
        cout << "[4] Visualizar datos" << endl;
        cout << "[5] Borrar " << endl;
        cout << "[6] Determinar cantidad " << endl;

        cout << "Escoge una opcion: ";
        cin >> opc;
        cout << endl;

        if (opc == 1)
        {
            string nombre, apellido, nacimiento;
            int edad;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            cout << "Edad: ";
            cin >> edad;
            cout << "Nacimiento: ";
            cin >> nacimiento;
            Persona persona(nombre,apellido,edad,nacimiento);
            lista->insertBack(persona);
            cout << "Registro agregado" << endl;
        }

        if (opc == 2)
        {
            string nombre, apellido;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            Persona persona(nombre,apellido,0,"");
            Persona* personas = lista->getData();

            int i = BusquedaGenerica<Persona>::busquedaSecuencialPosicion(personas,persona,lista->size());
            if (i != -1)
                cout << "Se encuentra en la posicion: " << i+1 << endl;
            else
                cout << "No se encuentra" << endl;
        }

        if (opc == 3){
            string nombre, apellido;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            Persona persona(nombre,apellido,0,"");
            Persona* personas = lista->getData();
            int i = BusquedaGenerica<Persona>::busquedaSecuencialPosicion(personas,persona,lista->size());
            if (i != -1){
                lista->remove(i);
                cout << "Registro eliminado " << endl;
            }else{
                cout << "No se encuentra" << endl;
            }
        }

        if (opc == 4)
        {
            Persona* persona = lista->getData();
            for (int i = 0; i < lista->size(); i++){
                cout << " - " << persona[i].getnombre() << " " << persona[i].getapellido() << "  ( Edad: " << persona[i].getedad() << " )" << endl;
            }
        }

        if (opc == 5) { lista->clear(); cout << "Lista borrada" << endl; }
        if (opc == 6)  cout << "Total: " << lista->size();


    }


    return 0;
}

