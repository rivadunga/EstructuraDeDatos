#include<iostream>
using namespace std;


bool simetrico = true;
string cadena;
void verificar(int pos){
    if (pos < cadena.length()/2)
    {
        if (cadena[pos] != cadena[cadena.length() - 1 - pos])
            simetrico = false;

        verificar((pos+1));
    }
}

int main()
{
    string cadena;
    cin >> cadena;
    verificar(0);
    cout << simetrico;
}
