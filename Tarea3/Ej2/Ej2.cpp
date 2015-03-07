#include<iostream>
#include "LinkedList.h"
using namespace std;
using namespace vcn;



bool noRep(LinkedList<int>&,int);

int main()
{
    int n,m;
    LinkedList<int> N;
    LinkedList<int> M;
    LinkedList<int> P;

    cout << "Tam N: ";
    cin >> n;
    cout << "Tam M: ";
    cin >> m;
    int aux;
    cout << "Inserta N: ";
    for (int i = 0; i < n; i++){ cin >> aux; N.insertBack(aux); }
    cout << "Inserta M: ";
    for (int i = 0; i < m; i++){ cin >> aux; M.insertBack(aux); }




    //DESPLEGAR MATRICES

    cout << "N: " << N << endl;
    cout << "M: " << M << endl;



    //UNION

    for (int i = 0; i < N.size(); i++)
       if (noRep(P,N.atVal(i)))
           P.insertBack(N.atVal(i));

    for (int i = 0; i < M.size(); i++)
       if (noRep(P,M.atVal(i)))
           P.insertBack(M.atVal(i));

    cout << "N U M: " << P << endl;



    //N - M

    P.clear();
    for (int j = 0; j < N.size(); j++){
        bool valido = true;
        for (int i = 0; i < M.size(); i++){
            if (N.atVal(j) == M.atVal(i)) valido = false;
        }
        if (valido)
            P.insertBack(N.atVal(j));
    }
    cout << "N - M: " << P << endl;



    //M - N

    P.clear();
    for (int j = 0; j < M.size(); j++){
        bool valido = true;
        for (int i = 0; i < N.size(); i++){
            if (M.atVal(j) == N.atVal(i)) valido = false;
        }
        if (valido)
            P.insertBack(M.atVal(j));
    }
    cout << "M - N: " << P << endl;



    //N * M

     P.clear();
     for (int j = 0; j < N.size(); j++){
        for (int i = 0; i < M.size(); i++){
            P.insertBack(N.atVal(j) *M.atVal(i));
        }
    }
    cout << "N * M: " << P << endl;



    //INTERCEPCION

    P.clear();
    for (int j = 0; j < N.size(); j++){
        bool valido = false;
        for (int i = 0; i < M.size(); i++){
            if (N.atVal(j) == M.atVal(i)) valido = true;
        }
        if (valido && noRep(P,N.atVal(j)))
            P.insertBack(N.atVal(j));
    }

    cout << "N ^ M: " << P;


    return 0;
}



bool noRep(LinkedList<int>& ll, int val){
    for (int i = 0; i < ll.size(); i++)
        if (ll.atVal(i) == val)
            return false;
    return true;
}
