//
//  BNodeDeforme.h
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 26/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinaryTree_BNodeDeforme_h
#define BinaryTree_BNodeDeforme_h

#include <iostream>
#include <vector>

namespace vcn {

    template <class T>
    class BNodeDeforme {

        BNodeDeforme<T> * parent = nullptr;
        std::vector<BNodeDeforme<T>*> sons;

        T info;

    public:

        /* Constructores */
        BNodeDeforme() { }
        BNodeDeforme(const T & _info) : info (_info) { }
        BNodeDeforme(const BNodeDeforme<T> & );

        /* Destructor */
        virtual ~BNodeDeforme();

        T getInfo() const { return info; }
        void setInfo(const T & value) { info = value; }

        BNodeDeforme<T> * getSon(int pos) const { return sons[pos]; }
        BNodeDeforme<T> * setSon(int pos, BNodeDeforme<T> * value) { sons[pos] = value; }
        std::vector<BNodeDeforme<T>*> getSons() const{ return sons; }
        BNodeDeforme<T> * getParent() const { return parent; }
        void setParent(BNodeDeforme<T> * value) { parent = value; }

        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, const BNodeDeforme<Tn>  & node);
    };

    template <class T>
    BNodeDeforme<T>::BNodeDeforme(const BNodeDeforme<T> & other)
    {
        info = other.info;
        left = other.left;
        right = other.right;
        parent = other.parent;
    }

    template <class T>
    BNodeDeforme<T>::~BNodeDeforme()
    {
    }


    template <class T>
    std::ostream & operator << (std::ostream & os, const BNodeDeforme<T>  & node)
    {
        os << node.info;

        return os;
    }

}



#endif
