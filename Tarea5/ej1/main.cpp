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
    std::cout << std::endl;

    numeros.sumaDescendientes();

    std::cout << " ---- preOrder Sumado ----" << std::endl;
    numeros.preOrder();
    std::cout << std::endl;

    return 0;
}
