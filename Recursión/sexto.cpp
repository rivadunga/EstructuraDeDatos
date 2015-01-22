#include<iostream>
#include<string.h>
using namespace std;


bool simetrico = true;
string cadena;

void verificar(int pos, int len){
    if (pos < (len/2))
    {
        if (cadena[pos] != cadena[len - 1 - pos])
             simetrico = false;

        verificar((pos+1),len);
    }
}

int main()
{
    cadena;
    cin >> cadena;
    verificar(0, cadena.length());
    if (simetrico)
        cout << "palindromo !!!";
    else
        cout << "no palindromo D:";

    return 0;
}
