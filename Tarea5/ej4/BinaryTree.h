#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"
#include<vector>


namespace vcn {

    template <class T>
    class BinaryTree {
    private:
        BNode<T> * root = nullptr;

    public:
        BinaryTree() {}
        virtual ~BinaryTree();

        bool empty();

        void clear();
        void clear(BNode<T> * node);

        BNode<T> * getRoot() const;
        void setRoot(BNode<T> * node);

        bool insert(BNode<T> * parent, T value);
        bool insert(BNode<T> * parent, BNode<T> * value);

        void preOrder() const;
        void preOrder(BNode<T> * node, bool(*)(BNode<T>*)) const;
        void preOrder(BNode<T> * node) const;

        void inOrder() const;
        void inOrder(BNode<T> * node) const;

        void postOrder() const;
        void postOrder(BNode<T> * node) const;

        void isLeaf() const;
        void isLeaf(BNode<T> * node) const;

        void ancestors(BNode<T> * node) const;
        bool isBrother(BNode<T> * node) const;
        void cousins(BNode<T> * node) const;
        bool isAncestor(BNode<T> * node) const;
        void sons(BNode<T> * node) const;
        void deep(BNode<T> * node) const;

        void primosyHermanos(BNode<T> * node);
        std::vector<T> nodosNivel(std::vector<T> primos, BNode<T> * node, int nivAct, int nivel);
        BNode<T> * search(T value);
        BNode<T> * search(BNode<T> * node,T value,BNode<T> * res);

    };

    template<class T>
    void BinaryTree<T>::primosyHermanos(BNode<T> * node){
        int nivel = 0;
        BNode<T> * nodeAux = node;
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
    std::vector<T> BinaryTree<T>::nodosNivel(std::vector<T> nodos, BNode<T> * node, int nivAct, int nivel)
    {
        if (node && nivAct < nivel) {

            std::vector<T> lef = nodosNivel(nodos,node->getLeft(),(nivAct+1),nivel);
            std::vector<T> rig = nodosNivel(nodos,node->getRight(),(nivAct+1),nivel);
            if (!lef.empty()) nodos.insert( nodos.end(), lef.begin(), lef.end() );
            if (!rig.empty()) nodos.insert( nodos.end(), rig.begin(), rig.end() );
        }else{
            if (nivel == nivAct && node)
                nodos.push_back(node->getInfo());
        }

        return nodos;

    }



    template<class T>
    BNode<T> * BinaryTree<T>::search(BNode<T> * node,T value, BNode<T> * res)
    {
        if (node) {
            if (node->getInfo() == value)
            {
                res = node;
            }
            res = search(node->getLeft(),value,res);
            res = search(node->getRight(),value,res);
        }
        return res;

    }

    template<class T>
    BNode<T> * BinaryTree<T>:: search(T value)
    {
         return search(root,value,nullptr);
    }

    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        clear();
    }

    template <class T>
    bool BinaryTree<T>::empty()
    {
        return root == nullptr;
    }

    template <class T>
    void BinaryTree<T>::clear()
    {
        clear(root);
    }

    template <class T>
    void BinaryTree<T>::clear(BNode<T> * node)
    {
        if (node) {
            clear(node->getLeft());
            clear(node->getRight());

            delete node;
        }
    }

    template <class T>
    BNode<T> * BinaryTree<T>::getRoot() const
    {
        return root;
    }

    template <class T>
    void BinaryTree<T>::setRoot(BNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }

    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, T value)
    {
        BNode<T> * node = new BNode<T>(value);
        bool inserted = insert(parent, node);

        if (!inserted) delete node;

        return inserted;
    }

    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
    {
        bool inserted = false;

        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            if (!parent->getLeft()) {
                parent->setLeft(value);
                value->setParent(parent);
                inserted = true;
            }
            else if (!parent->getRight()) {
                parent->setRight(value);
                value->setParent(parent);
                inserted = true;
            }
        }

        return inserted;
    }

    template <class T>
    void BinaryTree<T>::preOrder() const
    {
        preOrder(root);
    }

    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node) const
    {
        preOrder(node,[](BNode<T>* node){return true; });
    }

    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node, bool condicion(BNode<T>*)) const
    {
        if (node) {
            /* Procesar el nodo */
            if (condicion(node))
                std::cout << node->getInfo().getnombre() << std::endl;

            /* Invocar a los hijos */
            preOrder(node->getLeft());
            preOrder(node->getRight());

        }

    }

    template <class T>
    void BinaryTree<T>::inOrder() const
    {
        inOrder(root);
    }

    template <class T>
    void BinaryTree<T>::inOrder(BNode<T> * node) const
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
    void BinaryTree<T>::postOrder() const
    {
        postOrder(root);
    }

    template <class T>
    void BinaryTree<T>::postOrder(BNode<T> * node) const
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
    void BinaryTree<T>::isLeaf() const
    {
        isLeaf(root);
    }

    template <class T>
    void BinaryTree<T>::isLeaf(BNode<T> * node) const
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
    void BinaryTree<T>::ancestors(BNode<T> * node) const
    {
        if (node) {
            std::cout << node->getInfo().getnombre() << " -> ";
            ancestors(node->getParent());
        }
    }



}

#endif
