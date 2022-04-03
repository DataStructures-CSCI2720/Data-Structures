#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/**
 * @brief Binary Tree constructor sets the root value to NULL
 * 
 * @tparam T 
 */
template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
} // Binary Tree constructor

/**
 * @brief Binary Tree destructor deletes all of the items from the list
 * 
 * @tparam T 
 */
template<class T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
} // Binary Tree destructor

/**
 * @brief Performs deleting items from the list by deleting the left side
 * items, then the right side items, then the root node.
 * 
 * @tparam T 
 * @param root pointer to root node
 */
template<class T>
void destroy(NodeType<T> *root) {
    if (root != NULL) {
        destroy(root -> left);
        destroy(root -> right);
        delete root;
    } // if
} // destroy

/**
 * @brief Determines if item is already in the list and calls to insert
 * if item is unique.
 * 
 * @tparam T 
 * @param key item to insert into the list
 */
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

/**
 * @brief Performs inserting the item into the list.
 * 
 * @tparam T 
 * @param root pointer to root node
 * @param key item to insert into the list
 */
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

/**
 * @brief add this
 * 
 * @tparam T 
 * @param key item to delete from list
 */
template<class T>
void BinaryTree<T>::deleteItem(T &key) {
    doDelete(root, key);
} // deleteItem

/**
 * @brief add this
 * 
 * @tparam T 
 * @param root pointer to root node
 * @param key item to delete from list
 */
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

/**
 * @brief add this
 * 
 * @tparam T 
 * @param root pointer to root node
 */
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

/**
 * @brief add this
 * 
 * @tparam T 
 * @param root pointer to root node
 * @param key item to delete from list
 */
template<class T>
void getLast(NodeType<T> *root, T &key) { // HELPER FOR DELETE ALSO DOES NOT WORK LOL
    while (root -> right != NULL) {
        root = root -> right;
    } // while
    key = root -> key;
} // getLast

/**
 * @brief Calls method to verify if an item is already in the list.
 * 
 * @tparam T 
 * @param item item to retrieve from list
 * @param found bool value to determine if item has been found
 */
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

/**
 * @brief add this
 * 
 * @tparam T 
 * @param item item to retrieve from list
 * @param found bool value to determine if item has been found
 * @return true if item is in list
 * @return false if item is not in the list
 */
template<class T>
bool BinaryTree<T>::helpRetrieve(T &item, bool &found) {
    bool f = found;
    doRetrieve(root,item, f);
    if (f) {
        return true;
    } else {
        cout << "Item not in tree.\n";
        return false;
    } // if
} // helpRetrieve

/**
 * @brief Searches through the list to determine if the item 
 * already exists in the list.
 * 
 * @tparam T 
 * @param root pointer to root node
 * @param item item to be retrieved
 * @param found bool value to determine if item has been found
 */
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

/**
 * @brief Calls method to print in pre-order style.
 * 
 * @tparam T 
 */
template<class T>
void BinaryTree<T>::preOrder() const {
    doPreOrder(root);
} // preOrder

/**
 * @brief Prints list in pre-order style with root node
 * first, then left items, then right items.
 * 
 * @tparam T 
 * @param root pointer to root node
 */
template<class T>
void doPreOrder(NodeType<T> *root) {
    if (root != NULL) {
        cout << root -> key << " ";
        doPreOrder(root -> left);
        doPreOrder(root -> right);
    } // if
} // doPreOrder

/**
 * @brief Calls method to print in in-order style.
 * 
 * @tparam T 
 */
template<class T>
void BinaryTree<T>::inOrder() const {
    doInOrder(root);
} // inOrder

/**
 * @brief Prints list in in-order style with items in ascending order.
 * 
 * @tparam T 
 * @param root pointer to root node
 */
template<class T>
void doInOrder(NodeType<T> *root) {
    if (root != NULL) {
        doInOrder(root -> left);
        cout << root -> key << " ";
        doInOrder(root -> right);
    } // if
} // doInOrder

/**
 * @brief Calls method to print list in post-order style.
 * 
 * @tparam T 
 */
template<class T>
void BinaryTree<T>::postOrder() const {
    doPostOrder(root);
} // postOrder

/**
 * @brief Prints list in post-order style with left items first,
 * then right side items, then root node.
 * 
 * @tparam T 
 * @param root pointer to root node
 */
template<class T>
void doPostOrder(NodeType<T> *root) {
    if (root != NULL) {
        doPostOrder(root -> left);
        doPostOrder(root -> right);
        cout << root -> key << " ";
    } // if
} // doPostOrder

/**
 * @brief Calls method to get length of list.
 * 
 * @tparam T 
 * @return int length of list
 */
template<class T>
int BinaryTree<T>::getLength() const {
    return length(root);
} // getLength

/**
 * @brief Returns the number of items currently in the list.
 * 
 * @tparam T 
 * @param root pointer to the root node
 * @return int length of list
 */
template<class T>
int length(NodeType<T> *root) {
    if (root == NULL) {
        return 0;
    } else {
        return length(root -> left) + length(root -> right) + 1;
    } // if
} // length

/**
 * @brief Calls a method to return number of nodes with one child.
 * 
 * @tparam T 
 * @return int number of nodes with one child
 */
template<class T>
int BinaryTree<T>::getNumSingleParent() const {
    return doSingle(root);
} // getNumSingleParent

/**
 * @brief Performs iteration to determine how many nodes have only one child.
 * 
 * @tparam T 
 * @param root pointer to root node
 * @return int number of nodes with one child
 */
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

/**
 * @brief Calls method to determine the number of leaf nodes.
 * 
 * @tparam T 
 * @return int number of leaf nodes
 */
template<class T>
int BinaryTree<T>::getNumLeafNodes() const {
    if (root == NULL) {
        return 1;
    } else {
        return doLeaf(root);
    } // if
} // getNumLeafNodes

/**
 * @brief Performs iteration to determine how many leaf nodes are in the list
 * or nodes with zero children.
 * 
 * @tparam T 
 * @param root pointer to root node
 * @return int number of leaf nodes
 */
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

/**
 * @brief Calls method to get the sum of all subtrees of the node.
 * 
 * @tparam T 
 * @param node pointer to node in list
 * @return T summation of subtrees
 */
template<class T>
T BinaryTree<T>::getSumOfSubtrees(NodeType<T> *&node) const { // not done
    bool f = false;
    doRetrieve(root, node -> key, f);
    if (f) {
        return doSub(root, node, false);
    } else {
        cout << "Item not in tree.\n";
        return -1;
    } // if
} // getSumOfSubtrees

/**
 * @brief Performs the iteration to sum all of the subtrees below the desired
 * node.
 * 
 * @tparam T 
 * @param root pointer to root node
 * @param node pointer to node in list
 * @param b 
 * @return T summation of subtrees
 */
template<class T>
T doSub(NodeType<T> *root, NodeType<T> *&node, bool b) {
    T count;
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
