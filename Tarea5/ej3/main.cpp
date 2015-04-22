#include <iostream>
#include "BinaryTree.h"

using namespace vcn;

int main(int argc, const char * argv[]) {


    BinaryTree<int> numeros;


    BNode<int> * cero = new BNode<int>(0);
    BNode<int> * uno = new BNode<int>(1);
    BNode<int> * dos = new BNode<int>(2);
    BNode<int> * tres = new BNode<int>(3);
    BNode<int> * cuatro = new BNode<int>(4);
    BNode<int> * cinco = new BNode<int>(5);
    BNode<int> * seis   = new BNode<int>(6);

    numeros.insert(nullptr,cero);
    numeros.insert(cero,uno);
    numeros.insert(cero,dos);
    numeros.insert(uno,tres);
    numeros.insert(uno,cuatro);
    numeros.insert(dos,cinco);
    numeros.insert(dos,seis);





    std::cout << " ---- preOrder ----" << std::endl;
    numeros.preOrder();

    if (numeros.esSimetrico())
        cout << "Es simetrico" << endl;
    else
        cout << "No es simetrico" << endl;


    BinaryTree<int> numeros2;

    BNode<int> * ceroB = new BNode<int>(0);
    BNode<int> * unoB = new BNode<int>(1);
    BNode<int> * unoB2 = new BNode<int>(1);
    BNode<int> * dosB = new BNode<int>(2);
    BNode<int> * dosB2 = new BNode<int>(2);
    BNode<int> * dosB3 = new BNode<int>(2);
    BNode<int> * dosB4 = new BNode<int>(2);

    numeros2.insert(nullptr,ceroB);
    numeros2.insert(ceroB,unoB);
    numeros2.insert(ceroB,unoB2);
    numeros2.insert(unoB,dosB);
    numeros2.insert(unoB,dosB2);
    numeros2.insert(unoB2,dosB3);
    numeros2.insert(unoB2,dosB4);


    std::cout << " ---- preOrder ----" << std::endl;
    numeros2.preOrder();

    if (numeros2.esSimetrico())
        cout << "Es simetrico" << endl;
    else
        cout << "No es simetrico" << endl;


    return 0;
}
