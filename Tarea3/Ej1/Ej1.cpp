#include<iostream>
#include "LinkedList.h"
using namespace std;
using namespace vcn;
int main()
{
    int n,p,q;
    LinkedList<int>* listaOriginal = new LinkedList<int>;
    LinkedList<int>* listaPrimos   = new LinkedList<int>;

    cin >> n >> p >> q;

    for (int i = 0; i <= q; ++i)
        listaOriginal->insertBack(i);

    if (p < 2) p = 2;

    for (int j = p; j <= q; ++j){
        bool valido = true;
        for (int i = 2; i <= j-1; ++i){
            if (listaOriginal->atVal(j) % listaOriginal->atVal(i) == 0)
                valido = false;
        }
        if (valido && listaPrimos->size() < n)
            listaPrimos->insertBack(listaOriginal->atVal(j));
    }

    for (int i = listaPrimos->size()-1; i >= 0; --i)
        cout << listaPrimos->atVal(i) << " ";

    return 0;
}
