#include<iostream>
using namespace std;


const int N = 27;

void dividir(int alfombra[][N], int xIni, int xFin, int yIni, int yFin, int itAct, int itFin)
{

    if (itAct < itFin && xFin-xIni > 1)
    {
        int div3 = (xFin-xIni)/3;
        for (int j = yIni + div3; j < yIni + 2*div3; j++){
            for (int i = xIni + div3; i < xIni + 2*div3; i++){
                alfombra[i][j] = 1;
            }
        }

        itAct = itAct+1;

        dividir(alfombra,xIni,xIni+div3,yIni,yIni+div3,itAct,itFin);
        dividir(alfombra,xIni,xIni+div3,yIni+div3,yIni+2*div3,itAct,itFin);
        dividir(alfombra,xIni,xIni+div3,yIni+2*div3,yIni+3*div3,itAct,itFin);

        dividir(alfombra,xIni+div3,xIni+2*div3,yIni,yIni+div3,itAct,itFin);
        dividir(alfombra,xIni+div3,xIni+2*div3,yIni+2*div3,yIni+3*div3,itAct,itFin);

        dividir(alfombra,xIni+2*div3,xIni+3*div3,yIni,yIni+div3,itAct,itFin);
        dividir(alfombra,xIni+2*div3,xIni+3*div3,yIni+div3,yIni+2*div3,itAct,itFin);
        dividir(alfombra,xIni+2*div3,xIni+3*div3,yIni+2*div3,yIni+3*div3,itAct,itFin);

    }

}

int main()
{

    int it;
    cin >> it;

    int alfombra[N][N];
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            alfombra[i][j]  = 0;

    dividir(alfombra,0,N,0,N,0,it);

     for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cout << alfombra[j][i] << " ";
            }
            cout << endl;
     }

    return 0;
}
