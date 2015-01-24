#include<iostream>
using namespace std;


int N, M;
int matriz[100][100];
int numCaminos = 0;

void recorrer(int x, int y)
{
    if ( (x < N && y < M) && (x >= 0 && y >= 0) &&   //No recorre si se sale de las dimensiones del tablero
         (matriz[x][y] != 8)
       )
    {
        if (x == N-1 && y == M-1)
            numCaminos++;

        matriz[x][y] = 8;
        recorrer(x+3,y); //Derecha
        recorrer(x,y+2); //Abajo
        matriz[x][y] = 0; //Si ya recorrió en todas las direcciones reinicia la casilla
    }
}


int main()
{
    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;
    recorrer(0,0);

    cout << "Num caminos: " << numCaminos << endl;
    if (numCaminos == 0)
        cout << "Tip: Prueba con multiplos de 3 y 2 + 1, ejemplo 10,7" << endl;

}
