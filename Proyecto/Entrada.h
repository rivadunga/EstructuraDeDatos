#include<iostream>
using namespace std;
class Entrada
{
    public:

        bool entero(int &valor, int ini, int fin)
        {
            try{
                string aux;
                getline(cin,aux);
                if (aux.size() > 0 && aux.size() < 2)
                {
                    if (aux.at(0) - '0' >= ini && aux.at(0) - '0' <= fin)
                    {
                        valor = aux.at(0)-'0';
                        return true;
                    }
                }
            }catch(int e){ return false; }
            return false;
        }

        bool cadena (string &valor)
        {
            try{
                string aux;
                getline(cin,aux);
                if (aux.size() > 0){
                    valor = aux;
                    return true;
                }
            }catch(int e){ return false; }
            return false;
        }

        void cualquierTecla()
        {
            try{
                string aux;
                getline(cin,aux);
            }catch(int e){}
        }


};
