#include <iostream>
#include "Vehiculo.h"
#include "Registro.h"
#include "Comprador.h"
#include "BusquedaGenerica.h"
#include "OrdenamientoGenerico.h"

using namespace std;

int main()
{
    Vehiculo vehiculos[4];
    Comprador compradores[4];
    Registro registros[100];
    int      numRegistros = 0;

    compradores[0] = Comprador("Erick","Rivas","IFE1");
    compradores[1] = Comprador("Vicente","Cubells","IFE2");
    compradores[2] = Comprador("Margot","Duek","IFE3");
    compradores[3] = Comprador("Raul","Hernandez","IFE4");

    vehiculos[0] = Vehiculo(100,"Ford","M1",0);
    vehiculos[1] = Vehiculo(200,"Chevrolet","M2",10000);
    vehiculos[2] = Vehiculo(300,"Audi","M3",2000);
    vehiculos[3] = Vehiculo(400,"Porche","M4",10);



    cout << "Concesionaria ErickCar" << endl;
    while (true){
        cout << "1.- Agregar compra:" << endl;
        cout << "2.- Imprimir ventas:" << endl;
        cout << "3.- Imprimir vehiculo:" << endl;
        cout << "4.- Salir:" << endl;
        cout << "Selecciona una opcion: ";
        int opc;
        cin >> opc;


        if (opc == 4) break;
        if (opc == 1)
        {

            string nombre;
            string apellido;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;

            Comprador compradorABuscar(nombre,apellido,"");
            int indComp = BusquedaGenerica<Comprador>::busquedaSecuencial(compradores,compradorABuscar,4);
            if (indComp == -1){ cout << "No existe ese usuario\n"; continue; }

            int codigo;
            cout << "Codigo: ";
            cin >> codigo;
            Vehiculo vehiculoABuscar(codigo,"","",0);
            int indVeh = BusquedaGenerica<Vehiculo>::busquedaSecuencial(vehiculos,vehiculoABuscar,4);
            if (indVeh == -1){ cout << "No existe ese codigo\n"; continue; }

            int monto;
            cout << "Monto: ";
            cin >> monto;

            registros[numRegistros] = Registro(monto,&vehiculos[indVeh],compradores[indComp]);
            numRegistros++;

        }


        if (opc == 2)
        {
            Ordenamiento<Registro>::burbuja(registros,numRegistros,Ordenamiento<Registro>::desc);
            for (int i = 0;i < numRegistros; i++){
                cout << "Monto: " << registros[i].getmonto() << endl;
                cout << "Comprador: " << registros[i].getcomprador().getnombre() + " " + registros[i].getcomprador().getapellido() << endl;
                cout << "Vehiculo: " << registros[i].getvehiculo()->getmarca() + " " + registros[i].getvehiculo()->getmodelo() << endl;
            }
        }

        if (opc == 3)
        {
            string nombre;
            string apellido;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            Comprador compradorABuscar(nombre,apellido,"");
            int indComp = BusquedaGenerica<Comprador>::busquedaSecuencial(compradores,compradorABuscar,4);
            if (indComp == -1){ cout << "No existe ese usuario\n"; continue; }

            for (int i = 0;i < numRegistros; i++){
                if (registros[i].getcomprador() == compradorABuscar)
                {
                    cout << "Monto: " << registros[i].getmonto() << endl;
                    cout << "Vehiculo: " << registros[i].getvehiculo()->getmarca() + " " + registros[i].getvehiculo()->getmodelo() << endl;
                }

            }


        }

    }
    cout << "Hello world!" << endl;
    return 0;
}
