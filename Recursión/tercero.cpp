#include <iostream>
using namespace std;

int N = 6;
int M = 5;
int matriz[100][100];

int suma(int fil,int col){
    if (fil < N)
    {
        if (col < N)
           return matriz[fil][col] + suma(fil,(col+1));
        else
            return matriz[fil][col] + suma((fil+1),0);
    }else
    {
        return 0;
    }
}

int main()
{
   for (int j = 0; j < M; j++)
      for (int i = 0; i < N; i++)
          matriz[i][j] = 1;

   cout << suma(0,0) << endl;

}

