#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
} // Binary Tree constructor

template<class T>
BinaryTree<T>::~BinaryTree() {

} // Binary Tree destructor

template<class T>
void BinaryTree<T>::insert(T &key) {
    insertItem(root, key);
} // insert

template<class T>
void insertItem(NodeType<T>*& root, T &key) {
    if (root == NULL) {
        NodeType<T> *node;
        root = node;
        root -> right = NULL;
        root -> left = NULL;
        root -> key = key;
    } else if (key == root -> key) {
        cout << "Item already in tree.\n";
    } else if (key < root -> key) {
        insertItem(root -> left, key);
    } else {
        insertItem(root -> right, key);
    } // if
} // insertItem

template<class T>
void BinaryTree<T>::deleteItem(T &key) {

} // deleteItem

template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {

} // retrieve

template<class T>
void BinaryTree<T>::preOrder() const {
    doPreOrder(root);
} // preOrder

template<class T>
void doPreOrder(NodeType<T> *root) {
    cout << "nothing yet...\n\n";
} // doPreOrder

template<class T>
void BinaryTree<T>::inOrder() const {
    doInOrder(root);
} // inOrder

template<class T>
void doInOrder(NodeType<T> *root) {
    if (root != NULL) {
        doInOrder(root -> left);
        cout << root -> key << " ";
        doInOrder(root -> right);
    } // if
} // doInOrder

template<class T>
void BinaryTree<T>::postOrder() const {
    doPostOrder(root);
} // postOrder

template<class T>
void doPostOrder(NodeType<T> *root) {
    cout << "nothing yet...\n\n";
} // doPostOrder

template<class T>
int BinaryTree<T>::getLength() const {
    return length(root);
} // getLength

template<class T>
int length(NodeType<T> *root) {
    if (root == NULL) {
        return 0;
    } else {
        return length(root -> left) + length(root -> right) + 1;
    } // if
} // length

template<class T>
int BinaryTree<T>::getNumSingleParent() const {
    return 0;
} // getNumSingleParent

template<class T>
int BinaryTree<T>::getNumLeafNodes() const {
    return 0;
} // getNumLeafNodes

template<class T>
int BinaryTree<T>::getSumOfSubtrees(NodeType<T> &node) const {
    return 0;
} // getSumOfSubtrees

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;