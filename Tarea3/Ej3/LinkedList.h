#pragma once
#include "Node.h"

    template <class T>
    class LinkedList {
        Node<T> * _first = nullptr;
        int _size = 0;


        class Iterator {
            LinkedList<T> * _data;
            int _position;

        public:
            Iterator(LinkedList<T> * _adata, int _aposition)
            : _data(_adata), _position(_aposition) {}

            Node<T> operator *() const { return *(_data->at(_position)); }
            const  Iterator & operator ++() { ++_position; return *this; }
            bool operator != (const Iterator & it) const { return _position != it._position; }
        };

    public:
        LinkedList() {}
        virtual ~LinkedList();

        Node<T> * first();
        int size();
        bool empty();

        void insert(T, int);
        void insert(Node<T> *, int);

        void insertFront(T);
        void insertBack(T);

        void remove(int);
        void removeFront();
        void removeBack();

        void clear();

        int search(Node<T>*);
        Node<T> * at(int);
		T atVal(int);

        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, LinkedList<Tn> &);

        Iterator begin() { return { this, 0}; }
        Iterator end() {return {this, _size }; }

        T* getData();
        void setData(T*,int);
        T operator [](const int);

    };

    template  <class T>
    LinkedList<T>::~LinkedList()
    {
        clear();
    }

    template  <class T>
    Node<T> * LinkedList<T>::first()
    {
        return _first;
    }

    template  <class T>
    int LinkedList<T>::size()
    {
        return _size;
    }

    template  <class T>
    bool LinkedList<T>::empty()
    {
        return _size == 0;
    }

    /* Si position < 0 se inserta al inicio
     * Si position > _size se inserta al final
     * en cualquier otro caso, se inserta en la posición dada
     */
    template  <class T>
    void LinkedList<T>::insert(T element, int position)
    {
        /* Crear el nuevo nodo a insertar */
        Node<T> * newnode = new Node<T>(element);

        insert(newnode, position);
    }

    template  <class T>
    void LinkedList<T>::insert(Node<T> * newnode, int position)
    {
        /* Cuando la lista está vacía o position < 0*/
        if (empty() || position <= 0) {
            newnode->setNext(_first);
            _first = newnode;
        }
        /* Cuando se inserta en cualquier posición diferente del inicio */
        else {

            if (position > _size) { position = _size; }

            Node<T> * tmp = at(position-1);

            newnode->setNext(tmp->getNext());
            tmp->setNext(newnode);
        }

        /* Incrementar el tamaño de la lista */
        ++_size;
    }

    template  <class T>
    void LinkedList<T>::insertFront(T element)
    {
        insert(element, 0);
    }


    template  <class T>
    void LinkedList<T>::insertBack(T element)
    {
        insert(element, _size);
    }


    template  <class T>
    void LinkedList<T>::remove(int position)
    {
        /*TODO debug
        if (empty() || (position < 0 || position >= _size )) {
            return nullptr;
        }*/

        Node<T> * removenode;

        /* Eliminar el primer nodo de la lista */
        if (position == 0) {
            removenode = _first;
            _first = _first->getNext();

        }
        /* Eliminar cualquier otro nodo */
        else {
            Node<T> * prev = at(position-1);
            removenode = prev->getNext();
            prev->setNext(removenode->getNext());
        }

        /* Establecer el siguiente en nullptr */
        removenode->setNext(nullptr);

        /* Decrementar el tamaño de la lista */
        --_size;
    }

    template  <class T>
    void LinkedList<T>::removeFront()
    {
        remove(0);
    }

    template  <class T>
    void LinkedList<T>::removeBack()
    {
        remove(_size - 1);
    }

    template  <class T>
    void LinkedList<T>::clear()
    {
        Node<T> * tmp = _first;

        while (tmp != nullptr) {
            _first = _first->getNext();
            delete tmp;
            tmp = _first;
        }

        _size = 0;

        _first = nullptr;
    }


     template  <class T>
    Node<T> *  LinkedList<T>::at(int position)
    {
        if (empty() || (position < 0 || position >= _size )) {
            return nullptr;
        }

        int pos = 0;
        Node<T> * tmp = _first;

        while (tmp != nullptr && pos++ < position)
        {
            tmp = tmp->getNext();
        }

        return tmp;

    }


    template  <class T>
    int LinkedList<T>::search(Node<T> * node)
    {
        if (empty() || node == nullptr) {
            return -1;
        }

        int pos = 0;
        Node<T> * tmp = _first;

        while (tmp != nullptr && tmp != node)
        {
            tmp = tmp->getNext();
            ++pos;
        }

        if (pos == _size){ return -1; }

        return pos;
    }

	template <class T>
	T LinkedList<T>::atVal(int position){
		return at(position)->getInfo();
	}

    template  <class T>
    T* LinkedList<T>::getData()
    {
       T* res = new T[_size];
       for (int i = 0; i < _size; i++){
            res[i] = at(i)->getInfo();
       }
       return res;
    }

    template <class T>
    void LinkedList<T>::setData(T* data, int N)
    {
        clear();
        for (int i = 0; i < N; i++){
            insertBack(data[i]);
        }

    }



    template <class T>
    std::ostream & operator <<(std::ostream & os, LinkedList<T> & list)
    {
        for (auto node : list )
        {
            os << node << " ";
        }

        return os;
    }

    template  <class T>
    T LinkedList<T>::operator [](const int position)
    {
        return at(position)->getInfo();
    }

