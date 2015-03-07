#include "Persona.h"
#include "Node.h"
#include "LinkedList.h"
#include "OrdenamientoGenerico.h"
using namespace std;

template <class T>
class OrderedLinkedList : LinkedList<T>{ //IMPORTANTE
    public:
        void insert(T, int);
        void insertFront(T);
        void insertBack(T);
        void remove(int);
        void removeFront();
        void removeBack();
        T* getData();
        int size();
        void setData(T*,int);
        void clear();

};


    template  <class T>
    void OrderedLinkedList<T>::insert(T element, int position)
    {
        /* Crear el nuevo nodo a insertar */
        Node<T> * newnode = new Node<T>(element);

        LinkedList<T>::insert(newnode, position);
        T* data = getData();
        Ordenamiento<T>::burbuja(data,size(),Ordenamiento<T>::asc);
        setData(data,size());
    }


    template  <class T>
    void OrderedLinkedList<T>::insertFront(T element)
    {
        insert(element, 0);
    }


    template  <class T>
    void OrderedLinkedList<T>::insertBack(T element)
    {
        insert(element, LinkedList<T>::size());
    }




    template  <class T>
    void OrderedLinkedList<T>::remove(int position)
    {
        LinkedList<T>::remove(position);
    }

    template  <class T>
    void OrderedLinkedList<T>::removeFront()
    {
        LinkedList<T>::removeFront();
    }

    template  <class T>
    void OrderedLinkedList<T>::removeBack()
    {
        LinkedList<T>::insertBack();
    }


    template  <class T>
    T* OrderedLinkedList<T>::getData()
    {
        return LinkedList<T>::getData();
    }

    template <class T>
    void OrderedLinkedList<T>::setData(T* data, int N)
    {
        LinkedList<T>::setData(data,N);

    }

    template  <class T>
    int OrderedLinkedList<T>::size()
    {
        return LinkedList<T>::size();
    }


    template  <class T>
    void OrderedLinkedList<T>::clear()
    {
        LinkedList<T>::clear();
    }
