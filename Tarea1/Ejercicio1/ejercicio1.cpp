#include<iostream>
using namespace std;


int potencia2(int potencia)
{
    int res = 1;
    for (int i = 0; i < potencia; i++)
        res *= 2;
    return res;
}


int matriz[100][100];

void generarMatriz(int ren, int col, int tam)
{
    if (ren < tam){
        if (col < tam){

            if (col < ren)
                matriz[col][ren] = potencia2(col);
            else
                matriz[col][ren] = potencia2(ren);

            generarMatriz(ren,(col+1),tam);

        }else{
            generarMatriz((ren+1),0,tam);
        }
    }
}

int main()
{
    int N;
    cout << "N: ";
    cin >> N;
    generarMatriz(0,0,N);

    for (int j = 0; j < N; j++){
        for (int i = 0; i < N; i++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
