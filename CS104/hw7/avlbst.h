#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    char getBalance () const;
    void setBalance (char balance);
    void updateBalance(char diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    char balance_;
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor and setting
* the color to red since every new node will be red when it is first inserted.
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
char AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(char balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(char diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void insertHelper (const std::pair<const Key, Value> &new_item, AVLNode<Key,Value>* current);
    void insert_fix(AVLNode<Key,Value>* child, AVLNode<Key,Value>* parent);  
    void RotateLeft(AVLNode<Key,Value>* parent);
    void RotateRight(AVLNode<Key,Value>* parent);
    void removeFix(AVLNode<Key,Value>* parent, char diff);

};

template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    if(this->root_ == NULL)
    {
        AVLNode<Key,Value>* new_node = new AVLNode<Key,Value>(new_item.first, new_item.second, NULL);
        this->root_ = new_node;
        return;
    }
    else
    {
        insertHelper(new_item, static_cast<AVLNode<Key, Value>*>(this->root_));
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::insertHelper (const std::pair<const Key, Value> &new_item, AVLNode<Key,Value>* current)
{
    if(new_item.first == current->getKey())
    {
        current->setValue(new_item.second);
        return;
    }
    else if(new_item.first < current->getKey())
    {
        if(current->getLeft() == NULL)
        {
            AVLNode<Key,Value>* new_node = new AVLNode<Key,Value>(new_item.first, new_item.second, current);
            current->setLeft(new_node);
            if(static_cast<AVLNode<Key, Value>*>(current)->getBalance() != 0)
            {
                static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                return;
            }
            else
            {
                static_cast<AVLNode<Key, Value>*>(current)->updateBalance(-1);
                insert_fix(new_node, current);
                return;
            }
        }
        else
        {
            insertHelper(new_item, current->getLeft());
        }
    }
    else if(new_item.first > current->getKey())
    {
        if(current->getRight() == NULL)
        {
            AVLNode<Key,Value>* new_node = new AVLNode<Key,Value>(new_item.first, new_item.second, current);
            current->setRight(new_node);
            if(static_cast<AVLNode<Key, Value>*>(current)->getBalance() != 0)
            {
                static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                return;
            }
            else
            {
                static_cast<AVLNode<Key, Value>*>(current)->updateBalance(1);
                insert_fix(new_node, current);
                return;
            }
        }
        else
        {
            insertHelper(new_item, current->getRight());
        }
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::insert_fix(AVLNode<Key,Value>* child, AVLNode<Key,Value>* parent)
{
    if(parent == NULL)
    {
        return;
    }
    else if(parent->getParent() == NULL)
    {
        return;
    }
    else
    {
        AVLNode<Key, Value>* grandparent = parent->getParent();
        if(grandparent->getLeft() == parent)
        {
            static_cast<AVLNode<Key, Value>*>(grandparent)->updateBalance(-1);
            if(static_cast<AVLNode<Key, Value>*>(grandparent)->getBalance() == 0)
            {
                return;
            }
            else if(static_cast<AVLNode<Key, Value>*>(grandparent)->getBalance() == -1)
            {
                insert_fix(parent, grandparent);
            }
            else if(static_cast<AVLNode<Key, Value>*>(grandparent)->getBalance() == -2)
            {
                if(parent->getLeft() == child)
                {
                    RotateRight(parent);
                    if(parent->getParent() == NULL)
                    {
                        this->root_ = parent;
                    }
                    static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(0);
                    static_cast<AVLNode<Key, Value>*>(parent)->setBalance(0);
                }
                else if(parent->getRight() == child)
                {
                    RotateLeft(child);
                    RotateRight(child);
                    if(child->getParent() == NULL)
                    {
                        this->root_ = child;
                    }
                    if(static_cast<AVLNode<Key, Value>*>(child)->getBalance() == -1)
                    {
                        static_cast<AVLNode<Key, Value>*>(parent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(1);
                        static_cast<AVLNode<Key, Value>*>(child)->setBalance(0);
                    }
                    else if(static_cast<AVLNode<Key, Value>*>(child)->getBalance() == 0)
                    {
                        static_cast<AVLNode<Key, Value>*>(parent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(child)->setBalance(0);
                    }
                    else
                    {
                        static_cast<AVLNode<Key, Value>*>(parent)->setBalance(-1);
                        static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(child)->setBalance(0);
                    }
                }
            }
        }
        else
        {
            static_cast<AVLNode<Key, Value>*>(grandparent)->updateBalance(1);
            if(static_cast<AVLNode<Key, Value>*>(grandparent)->getBalance() == 0)
            {
                return;
            }
            else if(static_cast<AVLNode<Key, Value>*>(grandparent)->getBalance() == 1)
            {
                insert_fix(parent, grandparent);
            }
            else if(static_cast<AVLNode<Key, Value>*>(grandparent)->getBalance() == 2)
            {
                if(parent->getRight() == child)
                {
                    RotateLeft(parent);
                    if(parent->getParent() == NULL)
                    {
                        this->root_ = parent;
                    }
                    static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(0);
                    static_cast<AVLNode<Key, Value>*>(parent)->setBalance(0);
                }
                else if(parent->getLeft() == child)
                {
                    RotateRight(child);
                    RotateLeft(child);
                    if(child->getParent() == NULL)
                    {
                        this->root_ = child;
                    }
                    if(static_cast<AVLNode<Key, Value>*>(child)->getBalance() == 1)
                    {
                        static_cast<AVLNode<Key, Value>*>(parent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(-1);
                        static_cast<AVLNode<Key, Value>*>(child)->setBalance(0);
                    }
                    else if(static_cast<AVLNode<Key, Value>*>(child)->getBalance() == 0)
                    {
                        static_cast<AVLNode<Key, Value>*>(parent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(child)->setBalance(0);
                    }
                    else
                    {
                        static_cast<AVLNode<Key, Value>*>(parent)->setBalance(1);
                        static_cast<AVLNode<Key, Value>*>(grandparent)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(child)->setBalance(0);
                    }
                }
            }                    
        }
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::RotateLeft(AVLNode<Key,Value>* parent)
{
    AVLNode<Key,Value>* grandparent = parent->getParent();
    grandparent->setRight(parent->getLeft());
    parent->setParent(grandparent->getParent());
    if(parent->getLeft() != NULL)
    {
        parent->getLeft()->setParent(grandparent);
    }
    parent->setLeft(grandparent);
    grandparent->setParent(parent);
    if(parent->getParent() != NULL)
    {
        if(parent->getParent()->getLeft() == grandparent)
        {
            parent->getParent()->setLeft(parent); 
        }
        else
        {
            parent->getParent()->setRight(parent);
        }
    }

}


template<class Key, class Value>
void AVLTree<Key, Value>::RotateRight(AVLNode<Key,Value>* parent)
{
    AVLNode<Key,Value>* grandparent = parent->getParent();
    parent->setParent(grandparent->getParent());
    if(grandparent->getParent() != NULL)
    {
        if(grandparent->getParent()->getLeft() == grandparent)
        {
            grandparent->getParent()->setLeft(parent);
        }
        else
        {
            grandparent->getParent()->setRight(parent);
        }
    }

    grandparent->setLeft(parent->getRight());
    if(parent->getRight() != NULL)
    {
        parent->getRight()->setParent(grandparent);
    }
    parent->setRight(grandparent);
    
    grandparent->setParent(parent);
}


template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    AVLNode<Key,Value>* target_node = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::internalFind(key));
    if(target_node != NULL)
    {
        if(target_node->getLeft() != NULL && target_node->getRight() != NULL)
        {
            nodeSwap(target_node, static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::predecessor(target_node)));
        }
        AVLNode<Key,Value>* parent = target_node->getParent();
        
        char diff = 0;
        if(parent != NULL)
        {
            if(parent->getLeft() == target_node)
            {
                diff = 1;
            }
            else
            {
                diff = -1;
            }
        }

        if(target_node->getLeft() == NULL && target_node->getRight() == NULL)
        {
            if(parent == NULL)
            {
                BinarySearchTree<Key, Value>::clear();
            }
            else if(parent->getLeft() == target_node)
            {
                parent->setLeft(NULL);
                delete target_node;
            }
            else
            {
                parent->setRight(NULL);
                delete target_node;
            }
        }
        else if(target_node->getLeft() == NULL || target_node->getRight() == NULL)
        { 
            if(target_node->getLeft() == NULL)
            {
                AVLNode<Key,Value>* right_child = target_node->getRight();
                if(target_node == this->root_)
                {
                    right_child->setParent(NULL);
                    this->root_ = right_child;
                    delete target_node;
                }
                else if(parent->getLeft() == target_node)
                {
                    right_child->setParent(parent);
                    parent->setLeft(right_child);
                    delete target_node;
                }
                else if(parent->getRight() == target_node)
                {
                    right_child->setParent(parent);
                    parent->setRight(right_child);
                    delete target_node;
                }
            }
            else if(target_node->getRight() == NULL)
            {
                AVLNode<Key,Value>* left_child = target_node->getLeft();
                if(target_node == this->root_)
                {
                    left_child->setParent(NULL);
                    this->root_ = left_child;
                    delete target_node;
                }
                else if(parent->getLeft() == target_node)
                {
                    left_child->setParent(parent);
                    parent->setLeft(left_child);
                    delete target_node;
                }
                else if(parent->getRight() == target_node)
                {
                    left_child->setParent(parent);
                    parent->setRight(left_child);
                    delete target_node;
                }
            }
        }
        removeFix(parent, diff);
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key,Value>* current, char diff)
{
    if(current == NULL)
    {
        return;
    }
    else
    {
        AVLNode<Key,Value>* parent = current->getParent();
        char ndiff = 0;
        if(parent != NULL)
        {
            if(parent->getLeft() == current)
            {
                ndiff = 1;
            }
            else
            {
                ndiff = -1;
            }
        }
        if(diff == -1)
        {
            if(static_cast<AVLNode<Key, Value>*>(current)->getBalance()+diff == -2)
            {
                AVLNode<Key,Value>* taller_child = current->getLeft();
                if(static_cast<AVLNode<Key, Value>*>(taller_child)->getBalance() == -1)
                {
                    RotateRight(taller_child);
                    static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                    static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(0);
                    if(taller_child->getParent() == NULL)
                    {
                        this->root_ = taller_child;
                    }
                    removeFix(parent, ndiff);
                }
                else if(static_cast<AVLNode<Key, Value>*>(taller_child)->getBalance() == 0)
                {
                    RotateRight(taller_child);
                    static_cast<AVLNode<Key, Value>*>(current)->setBalance(-1);
                    static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(1);
                    if(taller_child->getParent() == NULL)
                    {
                        this->root_ = taller_child;
                    }
                    return; 
                }
                else
                {
                   AVLNode<Key,Value>* grandchild = taller_child->getRight();
                   RotateLeft(grandchild);
                   RotateRight(grandchild);
                   if(static_cast<AVLNode<Key, Value>*>(grandchild)->getBalance() == 0)
                   {
                        static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandchild)->setBalance(0);
                   
                   } 
                   else if(static_cast<AVLNode<Key, Value>*>(grandchild)->getBalance() == 1)
                   {
                        static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(-1);
                        static_cast<AVLNode<Key, Value>*>(grandchild)->setBalance(0);
                   }
                   else
                   {
                        static_cast<AVLNode<Key, Value>*>(current)->setBalance(1);
                        static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandchild)->setBalance(0);
                   }
                   if(grandchild->getParent() == NULL)
                   {
                        this->root_ = grandchild;
                   }
                   removeFix(parent, ndiff);
                }
            }
            else if(static_cast<AVLNode<Key, Value>*>(current)->getBalance()+diff == -1)
            {
                static_cast<AVLNode<Key, Value>*>(current)->setBalance(-1);
                return;
            }
            else
            {
                static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                removeFix(parent, ndiff);
            }
        }
        else if(diff == 1)
        {
            if(static_cast<AVLNode<Key, Value>*>(current)->getBalance()+diff == 2)
            {
                AVLNode<Key,Value>* taller_child = current->getRight();
                if(static_cast<AVLNode<Key, Value>*>(taller_child)->getBalance() == 1)
                {
                    RotateLeft(taller_child);
                    static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                    static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(0);
                    if(taller_child->getParent() == NULL)
                    {
                        this->root_ = taller_child;
                    }
                    removeFix(parent, ndiff);
                }
                else if(static_cast<AVLNode<Key, Value>*>(taller_child)->getBalance() == 0)
                {
                    RotateLeft(taller_child);
                    static_cast<AVLNode<Key, Value>*>(current)->setBalance(1);
                    static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(-1);
                    if(taller_child->getParent() == NULL)
                    {
                        this->root_ = taller_child;
                    }
                    return; 
                }
                else
                {
                   AVLNode<Key,Value>* grandchild = taller_child->getLeft();
                   RotateRight(grandchild);
                   RotateLeft(grandchild);
                   if(static_cast<AVLNode<Key, Value>*>(grandchild)->getBalance() == 0)
                   {
                        static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandchild)->setBalance(0);
                   
                   } 
                   else if(static_cast<AVLNode<Key, Value>*>(grandchild)->getBalance() == -1)
                   {
                        static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(1);
                        static_cast<AVLNode<Key, Value>*>(grandchild)->setBalance(0);
                   }
                   else
                   {
                        static_cast<AVLNode<Key, Value>*>(current)->setBalance(-1);
                        static_cast<AVLNode<Key, Value>*>(taller_child)->setBalance(0);
                        static_cast<AVLNode<Key, Value>*>(grandchild)->setBalance(0);
                   }
                   if(grandchild->getParent() == NULL)
                    {
                        this->root_ = grandchild;
                    }
                   removeFix(parent, ndiff);
                }
            }
            else if(static_cast<AVLNode<Key, Value>*>(current)->getBalance()+diff == 1)
            {
                static_cast<AVLNode<Key, Value>*>(current)->setBalance(1);
                return;
            }
            else
            {
                static_cast<AVLNode<Key, Value>*>(current)->setBalance(0);
                removeFix(parent, ndiff);
            }
        }
    }
}


template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    char tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}


#endif
