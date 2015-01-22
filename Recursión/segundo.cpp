#include <iostream>
using namespace std;

int N = 5;
int arreglo[100];

int suma(int i){
    if (i < N)
        return arreglo[i] + suma((i+1));
    else
        return 0;
}

int main(){

   for (int i = 0; i < N; i++)
       arreglo[i] = 1;

   cout << suma(0) << endl;

   return 0;

}
