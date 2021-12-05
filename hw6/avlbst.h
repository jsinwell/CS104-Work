#ifndef AVLBST_H
#define AVLBST_H

#include "bst.h"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>

struct KeyError {};

/**
 * A special kind of node for an AVL tree, which adds the height as a data member, plus
 * other additional helper functions. You do NOT need to implement any functionality or
 * add additional data members or helper functions.
 */
template<typename Key, typename Value>
class AVLNode : public Node<Key, Value> {
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int getHeight() const;
    void setHeight(int height);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int height_;
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
 * An explicit constructor to initialize the elements by calling the base class constructor.
 */
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent)
        : Node<Key, Value>(key, value, parent), height_(1) {}

/**
 * A destructor which does nothing.
 */
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode() {}

/**
 * A getter for the height of a AVLNode.
 */
template<class Key, class Value>
int AVLNode<Key, Value>::getHeight() const {
    return height_;
}

/**
 * A setter for the height of a AVLNode.
 */
template<class Key, class Value>
void AVLNode<Key, Value>::setHeight(int height) {
    height_ = height;
}

/**
 * An overridden function for getting the parent since a static_cast is necessary to make sure
 * that our node is a AVLNode.
 */
template<class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getParent() const {
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
 * Overridden for the same reasons as above.
 */
template<class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getLeft() const {
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
 * Overridden for the same reasons as above.
 */
template<class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getRight() const {
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}

/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/

template<class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value> {
public:
    virtual void insert(const std::pair<const Key, Value>& new_item);  // TODO
    virtual void remove(const Key& key);                               // TODO
protected:
    virtual void nodeSwap(AVLNode<Key, Value>* n1, AVLNode<Key, Value>* n2);

    // Add helper functions here
    int checkHeight(Node<Key, Value>* n);
    int balanceFactor(AVLNode<Key, Value>* n);
    void rotateLeft(AVLNode<Key, Value>* n);
    void rotateRight(AVLNode<Key, Value>* n);
    void rotateLeftRight(AVLNode<Key, Value>* n);
    void rotateRightLeft(AVLNode<Key, Value>* n);
    void fixBalance(AVLNode<Key, Value>* n);
};

template<class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value>& new_item) {
    if (this->root_ == NULL) {
        this->root_ = new AVLNode<Key, Value>(new_item.first, new_item.second, NULL);
        return;
    }

    // Same initial BST algorithm
    else {
        Node<Key, Value>* curr = this->root_;
        while (curr != NULL) {
            if (curr->getKey() == new_item.first) {
                curr->setValue(new_item.second);
                break;
            } else if (curr->getKey() > new_item.first) {
                if (curr->getLeft() == NULL) {
                    curr->setLeft(new AVLNode<Key, Value>(
                            new_item.first, new_item.second, static_cast<AVLNode<Key, Value>*>(curr)));
                } else {
                    curr = curr->getLeft();
                }
            } else if (curr->getKey() < new_item.first) {
                if (curr->getRight() == NULL) {
                    curr->setRight(new AVLNode<Key, Value>(
                            new_item.first, new_item.second, static_cast<AVLNode<Key, Value>*>(curr)));
                } else {
                    curr = curr->getRight();
                }
            }
        }

        // Now we need to fix the balance factor of each node and perform rotations if needed
        fixBalance(static_cast<AVLNode<Key, Value>*>(curr));
    }
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::fixBalance(AVLNode<Key, Value>* n) {

    n->setHeight(balanceFactor(n));

    if (checkHeight(n) == 3 && checkHeight(n->getRight()) == 2) {
        rotateLeft(n);
    }

    if (n->getParent()) {  // We need to fix the balances of all the parent nodes
        fixBalance(n->getParent());
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::remove(const Key& key) {
    // TODO
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap(AVLNode<Key, Value>* n1, AVLNode<Key, Value>* n2) {
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int tempH = n1->getHeight();
    n1->setHeight(n2->getHeight());
    n2->setHeight(tempH);
}

// Check heights of a node
template<class Key, class Value>
int AVLTree<Key, Value>::checkHeight(Node<Key, Value>* n) {
    if (n == NULL) {
        return 0;
    } else {
        return 1 + BinarySearchTree<Key, Value>::maxVal(checkHeight(n->getLeft()), checkHeight(n->getRight()));
    }
}

// Left rotatoin
template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key, Value>* n) {}

// Right rotation
template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key, Value>* n) {}

// Left-right rotation
template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeftRight(AVLNode<Key, Value>* n) {
    if (n == NULL)
        return;
    if (n->getLeft() == NULL)
        return;
    rotateLeft(n->getLeft());
    rotateRight(n);
}

// Right-left rotation
template<class Key, class Value>
void AVLTree<Key, Value>::rotateRightLeft(AVLNode<Key, Value>* n) {
    if (n == NULL)
        return;
    if (n->getRight() == NULL)
        return;
    rotateRight(n->getRight());
    rotateLeft(n);
}

// Balance factor (difference between height of left and right subtrees)
template<typename Key, typename Value>
int AVLTree<Key, Value>::balanceFactor(AVLNode<Key, Value>* n) {
    int lh = 0;
    int rh = 0;

    if (n == NULL) {
        return 0;
    }

    else {
        if (n->getLeft() != NULL) {
            lh = checkHeight(n->getLeft());
        }
        if (n->getRight() != NULL) {
            rh = checkHeight(n->getRight());
        }
    }

    return lh - rh;
}

#endif
