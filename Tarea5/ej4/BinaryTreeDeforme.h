#ifndef BinaryTreeDeforme_BinaryTreeDeforme_h
#define BinaryTreeDeforme_BinaryTreeDeforme_h

#include "BNodeDeforme.h"
#include<vector>


namespace vcn {

    template <class T>
    class BinaryTreeDeforme {
    private:
        BNodeDeforme<T> * root = nullptr;

    public:
        BinaryTreeDeforme() {}
        virtual ~BinaryTreeDeforme();

        bool empty();

        void clear();
        void clear(BNodeDeforme<T> * node);

        BNodeDeforme<T> * getRoot() const;
        void setRoot(BNodeDeforme<T> * node);

        bool insert(BNodeDeforme<T> * parent, T value);
        bool insert(BNodeDeforme<T> * parent, BNodeDeforme<T> * value);

        void preOrder() const;
        void preOrder(BNodeDeforme<T> * node, bool(*)(BNodeDeforme<T>*)) const;
        void preOrder(BNodeDeforme<T> * node) const;

        void inOrder() const;
        void inOrder(BNodeDeforme<T> * node) const;

        void postOrder() const;
        void postOrder(BNodeDeforme<T> * node) const;

        void isLeaf() const;
        void isLeaf(BNodeDeforme<T> * node) const;

        void ancestors(BNodeDeforme<T> * node) const;
        bool isBrother(BNodeDeforme<T> * node) const;
        void cousins(BNodeDeforme<T> * node) const;
        bool isAncestor(BNodeDeforme<T> * node) const;
        void sons(BNodeDeforme<T> * node) const;
        void deep(BNodeDeforme<T> * node) const;

        void primosyHermanos(BNodeDeforme<T> * node);
        std::vector<T> nodosNivel(std::vector<T> primos, BNodeDeforme<T> * node, int nivAct, int nivel);
        BNodeDeforme<T> * search(T value);
        BNodeDeforme<T> * search(BNodeDeforme<T> * node,T value,BNodeDeforme<T> * res);

    };

    template<class T>
    void BinaryTreeDeforme<T>::primosyHermanos(BNodeDeforme<T> * node){
        int nivel = 0;
        BNodeDeforme<T> * nodeAux = node;
        while (nodeAux != nullptr){
            nodeAux = nodeAux->getParent();
            nivel++;
        }
        --nivel;
        std::vector<T> primosHermanos;
        primosHermanos.clear();
        primosHermanos = this->nodosNivel(primosHermanos,root,0,nivel);
        for (int i = 0; i < primosHermanos.size(); i++){
            cout << primosHermanos[i].getnombre() << endl;
        }
    }

    template<class T>
    std::vector<T> BinaryTreeDeforme<T>::nodosNivel(std::vector<T> nodos, BNodeDeforme<T> * node, int nivAct, int nivel)
    {
        if (node && nivAct < nivel) {

            for (int i = 0; i < node->getSons().size(); i++)
            {
                 std::vector<T> subNodos = nodosNivel(nodos,node->getSon(i),(nivAct+1),nivel);
                 if (!subNodos.empty()) nodos.insert( nodos.end(), subNodos.begin(), subNodos.end() );
            }

        }else{
            if (nivel == nivAct && node)
                nodos.push_back(node->getInfo());
        }

        return nodos;

    }



    template<class T>
    BNodeDeforme<T> * BinaryTreeDeforme<T>::search(BNodeDeforme<T> * node,T value, BNodeDeforme<T> * res)
    {
        if (node) {
            if (node->getInfo() == value)
            {
                res = node;
            }
            for (int i = 0; i < node->getSons().size(); i++)
            {
                res = search(node->getSon(i),value,res);
            }
        }
        return res;

    }

    template<class T>
    BNodeDeforme<T> * BinaryTreeDeforme<T>:: search(T value)
    {
         return search(root,value,nullptr);
    }

    template <class T>
    BinaryTreeDeforme<T>::~BinaryTreeDeforme()
    {
        clear();
    }

    template <class T>
    bool BinaryTreeDeforme<T>::empty()
    {
        return root == nullptr;
    }

    template <class T>
    void BinaryTreeDeforme<T>::clear()
    {
        clear(root);
    }

    template <class T>
    void BinaryTreeDeforme<T>::clear(BNodeDeforme<T> * node)
    {
        if (node) {
            for (int i = 0; i < node->getSons().size(); i++)
            {
                clear(node->getSon(i));
            }

            delete node;
        }
    }

    template <class T>
    BNodeDeforme<T> * BinaryTreeDeforme<T>::getRoot() const
    {
        return root;
    }

    template <class T>
    void BinaryTreeDeforme<T>::setRoot(BNodeDeforme<T> * node)
    {
        root = node;
    }

    template <class T>
    bool BinaryTreeDeforme<T>::insert(BNodeDeforme<T> * parent, T value)
    {
        BNodeDeforme<T> * node = new BNodeDeforme<T>(value);
        bool inserted = insert(parent, node);

        if (!inserted) delete node;

        return inserted;
    }

    template <class T>
    bool BinaryTreeDeforme<T>::insert(BNodeDeforme<T> * parent, BNodeDeforme<T> * value)
    {
        bool inserted = false;

        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            for (int i = 0; i < parent->getSons().size(); i++)
            {
                if (!parent->getSon(i)) {
                    parent->setSon(i,value);
                    value->setParent(parent);
                    return true;
                }
            }
        }

        return false;
    }

    template <class T>
    void BinaryTreeDeforme<T>::preOrder() const
    {
        preOrder(root);
    }

    template <class T>
    void BinaryTreeDeforme<T>::preOrder(BNodeDeforme<T> * node) const
    {
        preOrder(node,[](BNodeDeforme<T>* node){return true; });
    }

    template <class T>
    void BinaryTreeDeforme<T>::preOrder(BNodeDeforme<T> * node, bool condicion(BNodeDeforme<T>*)) const
    {
        if (node) {
            /* Procesar el nodo */
            if (condicion(node))
                std::cout << node->getInfo().getnombre() << std::endl;

            for (int i = 0; i < node->getSons().size(); i++)
            {
                preOrder(node->getSon(i));
            }

        }

    }

    template <class T>
    void BinaryTreeDeforme<T>::inOrder() const
    {
        inOrder(root);
    }

    template <class T>
    void BinaryTreeDeforme<T>::inOrder(BNodeDeforme<T> * node) const
    {
        if (node) {

            /* Invocar al hijo izquierdo */
            inOrder(node->getLeft());

            /* Procesar el nodo */
            std::cout << *node << std::endl;

            /* Invocar al hijo derecho */
            inOrder(node->getRight());
        }
    }

    template <class T>
    void BinaryTreeDeforme<T>::postOrder() const
    {
        postOrder(root);
    }

    template <class T>
    void BinaryTreeDeforme<T>::postOrder(BNodeDeforme<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            postOrder(node->getLeft());
            postOrder(node->getRight());

            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }

    template <class T>
    void BinaryTreeDeforme<T>::isLeaf() const
    {
        isLeaf(root);
    }

    template <class T>
    void BinaryTreeDeforme<T>::isLeaf(BNodeDeforme<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }

    template <class T>
    void BinaryTreeDeforme<T>::ancestors(BNodeDeforme<T> * node) const
    {
        if (node) {
            std::cout << node->getInfo().getnombre() << " -> ";
            ancestors(node->getParent());
        }
    }



}

#endif
