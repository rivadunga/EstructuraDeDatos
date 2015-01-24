#include<iostream>
#include <cstdlib>

using namespace std;



int N;
int matriz[100][100];
bool encontrado = false;

void recorrer(int x, int y)
{
    if ( (x < N && y < N) && (x >= 0 && y >= 0) &&   //No recorre si se sale de las dimensiones del tablero
         (matriz[x][y] != -1 && matriz[x][y] != 8) && //El número 8 es para marcar por donde paso
          !encontrado
       )
    {
        if (x == N-1 && y == N-1)
            encontrado = true;

        matriz[x][y] = 8;
        recorrer(x+1,y); //Arriba
        recorrer(x,y+1); //Izquierda
        recorrer(x-1,y); //Abajo
        recorrer(x,y-1); //Derecha
        if (!encontrado)
            matriz[x][y] = 0; //Si ya recorrió en todas las direcciones reinicia la casilla
    }
}


int main()
{
    cout << "Tamano de matriz: ";
    cin >> N;

    //Llenar matriz
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            if (rand() % 4 == 0 &&
                !(i == N-1 && j == N-1))
                matriz[i][j] = -1;

    recorrer(0,0);

    cout << endl;
    if (encontrado)
        cout << "Ruta sugerida " << endl << endl;
    else
        cout << "No existe ninguna ruta" << endl << endl;


    for (int j = 0; j < N; j++){
        for (int i = 0; i < N; i++){
            if (matriz[i][j] == -1) cout << "o ";
            if (matriz[i][j] == 8)  cout << "# ";
            if (matriz[i][j] == 0)  cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "o = pared" << endl;
    cout << "# = camino" << endl;

}
