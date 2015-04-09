#include<iostream>
#include<vector>
#include<stack>
#include<Math.h>
using namespace std;


vector<int> ejecutarOperacionLineal(vector<char>);
vector<int> obtenerConjunto(vector<char>);
bool noRep(vector<int>, int);
vector<int> interseccion(vector<int>, vector<int> );
vector<int> unionV(vector<int> N, vector<int> M);



int main()
{
   string cadena;
   vector<char> principal;
   cadena = "{1,2,3,4}";


   for (int k = 0; k < cadena.length(); k++){
        principal.push_back(cadena.at(k));
   }


    stack<int> parentesisPos;
    vector<vector<int>> conjuntosEnParentesis;

    for (int i = 0; i < principal.size(); i++){




        char c = cadena.at(i);
        if (c == '('){
            parentesisPos.push(i); //Guarda la primera posicion del parentesis
        }
        else if (c == ')'){

            int posInicial = parentesisPos.top();
            parentesisPos.pop();
            int posFinal = i-1; //La posicion final es la del ) -1
            vector<char> cadenaLineal; //Cadena lineal {4,5,6,7}+{23,3}
            for (int i = posInicial; i < posFinal; i++){
                cadenaLineal.push_back(cadena.at(i));
                vector<int> operacionLineal = ejecutarOperacionLineal(cadenaLineal);
                conjuntosEnParentesis.push_back(operacionLineal);
            }
        }
    }

    //Solo falta ejecutar una operacionLineal de los parentesis
    //Ejemplo V(A) + V(B)) * V(C) + V(D)
}



vector<int> ejecutarOperacionLineal(vector<char> cad)
{
   vector<int> resPar;
   bool iniciaConjunto = false;
   bool unionF = false;
   bool interseccionF = false;
   for (int i = 0; i < cad.size(); i++){
        vector<char> conjuntoStr;
        vector<int> conjunto;

        if (iniciaConjunto && cad.at(i) != '{' && cad.at(i) != '}' && cad.at(i) == '+' && cad.at(i) == '*')
        {
            conjuntoStr.push_back(cad.at(i)); //Agregar elementosStr al vector, siempre y cuando no sean operadores
        }

        if (cad.at(i) == '{'){ //Inicia a leer la cadena del conjunto
            iniciaConjunto = true;
        }

        if (cad.at(i) == '}'){
            conjunto = obtenerConjunto(conjuntoStr); //De String a vector
            if (unionF){
                resPar = unionV(resPar,conjunto); //Ejecuta la operacion ACUMULATIVA
            }
            if (interseccionF){
                resPar = interseccion(resPar,conjunto);
            }

            //Reinicia las banderas
            interseccionF = false;
            unionF = false;
        }

        if (cad.at(i) == '+'){
            interseccionF = true;
        }

        if (cad.at(i) == '-'){
            unionF = true;
        }

   }
   return resPar;


}


vector<int> obtenerConjunto(vector<char> a) //Ejemplo de 1,2,3,4 obtener [1][2][3][4]
{

    vector<int> res;

    for (int i = 0; i < a.size(); i++)
    {
        vector<int> aux;
        if (a.at(i) == ','){
            int num = 0;

            //Cadena a decimal
            for (int i = 0; i < aux.size(); i++){
                num += aux.at(i) * pow(10,i);
            }
            res.push_back(num);

            aux.clear(); //Reinicia el numero
        }else{
            //Obtiene todos los que no son ','
            int c = a.at(i)-'0';
            aux.push_back(c);
        }
    }

    return res;
}


bool noRep(vector<int> ll, int val){
    for (int i = 0; i < ll.size(); i++)
        if (ll.at(i) == val)
            return false;
    return true;
}

vector<int> interseccion(vector<int> N, vector<int> M)
{
    vector<int> RES;
    for (int j = 0; j < N.size(); j++){
        bool valido = false;
        for (int i = 0; i < M.size(); i++){
            if (N.at(j) == M.at(i)) valido = true;
        }
        if (valido && noRep(RES,N.at(j)))
            RES.push_back(N.at(j));
    }
    return RES;
}

vector<int> unionV(vector<int> N, vector<int> M)
{
    vector<int> RES;
     for (int i = 0; i < N.size(); i++)
       if (noRep(RES,N.at(i)))
           RES.push_back(N.at(i));

    for (int i = 0; i < M.size(); i++)
       if (noRep(RES,M.at(i)))
           RES.push_back(M.at(i));

    return RES;
}
