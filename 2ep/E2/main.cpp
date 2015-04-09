#include <iostream>
#include "LinkedList.h"
using namespace std;
using namespace vcn;

int main()
{
    LinkedList<int> principal;
    LinkedList<int> res;

    principal.insertBack(1);
    principal.insertBack(1);
    principal.insertBack(5);
    principal.insertBack(3);
    principal.insertBack(3);
    principal.insertBack(5);


    for (int i = 0; i < principal.size(); i++){
        for (int j = i+1; j < principal.size(); j++){
            if (principal.at(i)->getInfo() ==  principal.at(j)->getInfo()
                && res.searchAndReturnPosition(i) == -1
                ){
                res.insertBack(principal.at(i)->getInfo());
            }
        }
    }

   cout << res;
}
