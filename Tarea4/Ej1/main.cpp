#include<iostream>
#include<string>
#include "Stack.h"
using namespace std;
using namespace vcn;

int main()
{
    Stack<char> pila;
    string cadena;
    cout << "Inserta una cadena: ";
    getline(cin,cadena);

    bool valido = true;
    for (int i = 0; i <cadena.length(); ++i){
        char c = cadena.at(i);
        if (c == '('){
            pila.push(c);
        }
        else if (c == ')'){
            if (pila.empty()){
                valido = false;
                break;
            }
            pila.pop();
        }
    }

    if (!pila.empty())
        valido = false;

    if (valido)
        cout << "Cadena valida" << endl;
    else
        cout << "Cadena invalida" << endl;

    return 0;
}
