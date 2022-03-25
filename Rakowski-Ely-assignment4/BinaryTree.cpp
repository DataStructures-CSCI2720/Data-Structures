#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

template<class T>
BinaryTree<T>::BinaryTree() {

} // Binary Tree constructor

template<class T>
BinaryTree<T>::~BinaryTree() {

} // Binary Tree destructor

template<class T>
void BinaryTree<T>::insert(T &key) {

} // insert

template<class T>
void BinaryTree<T>::deleteItem(T &key) {

} // deleteItem

template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {

} // retrieve

template<class T>
void BinaryTree<T>::preOrder() const {

} // preOrder

template<class T>
void BinaryTree<T>::inOrder() const {

} // inOrder

template<class T>
void BinaryTree<T>::postOrder() const {

} // postOrder

template<class T>
int BinaryTree<T>::getLength() const {

} // getLength

template<class T>
int BinaryTree<T>::getNumSingleParent() const {

} // getNumSingleParent

template<class T>
int BinaryTree<T>::getNumLeafNodes() const {

} // getNumLeafNodes

template<class T>
int BinaryTree<T>::getSumOfSubtrees(NodeType<T> &node) const {

} // getSumOfSubtrees

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;