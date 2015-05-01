#include<iostream>
#include<stack>
#include<vector>
#include <stdlib.h>
#include"Contenedor.h"
#include"Producto.h"
using namespace std;
int main()
{
    int capContenedor = 3;
    int capPila = 3;
    int capAlmacen = 3;
    vector<stack<Contenedor>> almacen;

    //Agregar 20 Contenedores random
    for (int i = 0; i < 25; i++){

        if (almacen.size() > capAlmacen) break;

        if (almacen.empty() || almacen.back().size() > capPila){
            if (!almacen.empty() && almacen.back().size() > capPila)
                almacen.back().pop();
            stack<Contenedor> pila;
            almacen.push_back(pila);

        }

        if (almacen.back().empty() || (almacen.back().top().estaLleno())){
            Contenedor contenedor(i,"E",capContenedor);
            almacen.back().push(contenedor);
        }
         almacen.back().top().agregarProducto("P",rand()%10,rand()%1000);
    }


    float costoAlmacen = 0;
    for (int j = 0; j < almacen.size(); j++)
    {
        cout << "Pila " << j << "\n\n";
        float costoPila = 0;
        stack<Contenedor> aux = almacen[j];
        while (!aux.empty()){
            cout << aux.top();
            costoPila += aux.top().getCosto();
            aux.pop();
        }
        cout << "\nCosto pila: $" << costoPila << "\n\n\n";
        costoAlmacen += costoPila;
    }

    cout << "\nCosto del almacen: $" << costoAlmacen << "\n\n";



    return 0;
}
