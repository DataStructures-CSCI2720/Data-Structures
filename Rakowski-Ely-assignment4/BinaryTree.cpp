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
    destroy(root);
} // Binary Tree destructor

template<class T>
void destroy(NodeType<T> *root) {
    if (root != NULL) {
        destroy(root -> left);
        destroy(root -> right);
        delete root;
    } // if
} // destroy

template<class T>
void BinaryTree<T>::insert(T &key) {
    bool f = false;
    doRetrieve(root, key, f);
    if (f) {
        cout << "Item already in tree.\n";
    } else {
        insertItem(root, key);
    } // if
} // insert

template<class T>
void insertItem(NodeType<T>*& root, T &key) {
    if (root == NULL) {
        NodeType<T> *node = new NodeType<T>;
        node -> right = NULL;
        node -> left = NULL;
        node -> key = key;
        root = node;
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
    doDelete(root, key);
} // deleteItem

template<class T>
void doDelete(NodeType<T> *&root, T &key) { // changed from * to *&
    if (key < root -> key) {
        doDelete(root -> left, key);
    } else if (key > root -> key) {
        doDelete(root -> right, key);
    } else {
        deleteNode(root);
    } // if
} // doDelete

template<class T>
void deleteNode(NodeType<T> *&root) { // changed from * to *&
    T key;
    NodeType<T> *temp = new NodeType<T>;
    temp = root;
    if (root -> left == NULL) {
        root = root -> right;
        delete temp;
    } else if (root -> right == NULL) {
        root = root -> left;
        delete temp;
    } else {
        getLast(root -> left, key);
        root -> key = key;
        doDelete(root -> left, key);
    } // if
} // deleteNode

template<class T>
void getLast(NodeType<T> *root, T &key) { // HELPER FOR DELETE ALSO DOES NOT WORK LOL
    while (root -> right != NULL) {
        root = root -> right;
    } // while
    key = root -> key;
} // getLast

template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {
    bool f = found;
    doRetrieve(root, item, f);
    if (f) {
        cout << "Item found in tree.\n";
    } else {
        cout << "Item not in tree.\n";
    } // if
} // retrieve

template<class T>
void doRetrieve(NodeType<T> *root, T &item, bool &found) {
    if (root == NULL) {
        found = false;
    } else if (item < root -> key) {
        doRetrieve(root -> left, item, found);
    } else if (item > root -> key) {
        doRetrieve(root -> right, item, found);
    } else {
        found = true;
    } // if
} // doRetrieve

template<class T>
void BinaryTree<T>::preOrder() const {
    doPreOrder(root);
} // preOrder

template<class T>
void doPreOrder(NodeType<T> *root) {
    if (root != NULL) {
        cout << root -> key << " ";
        doPreOrder(root -> left);
        doPreOrder(root -> right);
    } // if
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
    if (root != NULL) {
        doPostOrder(root -> left);
        doPostOrder(root -> right);
        cout << root -> key << " ";
    } // if
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
    return doSingle(root);
} // getNumSingleParent

template<class T>
int doSingle(NodeType<T> *root) {
    int count = 0;
    if (root != NULL) {
        count += doSingle(root -> left);
        count += doSingle(root -> right);
        if (!(root -> left == NULL) != !(root -> right == NULL)) {
            count += 1;
        } // if
    } // if
    return count;
} // doSingle

template<class T>
int BinaryTree<T>::getNumLeafNodes() const {
    if (root == NULL) {
        return 1;
    } else {
        return doLeaf(root);
    } // if
} // getNumLeafNodes

template<class T>
int doLeaf(NodeType<T> *root) {
    int count = 0;
    if (root != NULL) {
        count += doLeaf(root -> left);
        count += doLeaf(root -> right);
        if ((root -> left == NULL) && (root -> right == NULL)) {
            count += 1;
        } // if
    } // if
    return count;
} // doLeaf

template<class T>
int BinaryTree<T>::getSumOfSubtrees(NodeType<T> *&node) const { // not done
    bool f = false;
    doRetrieve(root, node -> key, f);
    if (f) {
        return doSub(root, node, false);
    } else {
        cout << "Item not in tree.\n";
        return -1;
    } // if
} // getSumOfSubtrees

template<class T>
int doSub(NodeType<T> *root, NodeType<T> *&node, bool b) {
    int count = 0;
    if (root != NULL) {
        if ((root -> key == node -> key) || (b)) {
            count += doSub(root -> left, node, true);
            count += doSub(root -> right, node, true);
            if (root -> left != NULL) {
                count += root -> left -> key;
            } // if
            if (root -> right != NULL) {
                count += root -> right -> key;
            } // if
        } else {
            count += doSub(root -> left, node, false);
            count += doSub(root -> right, node, false);
        } // if
    } // if
    return count;
} // doSub

template class BinaryTree<int>;
template class BinaryTree<float>;
//template class BinaryTree<std::string>;
