#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

/**
 * @brief Initialization of class methods listed below main method.
 *
 */
void startUp(int argc, char *argv[]);
void printCmd();
template<class T>
void options(BinaryTree<T> &b);
template<class T>
void createList(BinaryTree<T> &b, char argv[]);
template<class T>
void doInsert(BinaryTree<T> &b);
template<class T>
void doRetrieve(BinaryTree<T> &b);
template<class T>
void doDelete(BinaryTree<T> &b);
template<class T>
void doSubtree(BinaryTree<T> &b);

/**
 * @brief Main method that starts program, creates the binary tree,
 * and allows the user to interface with the tree.
 *
 * @param argc number of command line arguments
 * @param argv list of command line arguments
 * @return int
 */
int main(int argc, char *argv[]) {
    startUp(argc, argv); // starts program
    return 0;
} // main

/**
 * @brief Verifies the file input and creates a list depending on file type.
 *
 * @param argc number of command line arguments
 * @param argv list of command line arguments
 */
void startUp(int argc, char *argv[]) {
    if (argc < 2) { // verifies number of command line arguments
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
    while (true) { // prompts user to define list type and creates list
        char op;
        cout << "Enter list type (i - int, f - float, s - std::string): ";
        cin >> op;
        if (op == 'i') { // int list
            BinaryTree<int> b;
            createList(b, argv[1]);
        } else if (op == 'f') { // float list
            BinaryTree<float> b;
            createList(b, argv[1]);
        } else if (op == 's') { // string list
            BinaryTree<std::string> b;
            createList(b, argv[1]);
        } else { // invalid option
            cout << "Invalid list type, try again!\n\n";
        } // if
    } // while
} // startUp

/**
 * @brief Prints the available user commands.
 *
 */
void printCmd() {
    cout << "\nCommands:\ninsert (i), delete (d), retrieve (r), length (l), ";
    cout << "in-order (n), pre-order (p), post-order (o),\ngetNumberSingleParent (s), ";
    cout << "getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)\n";
} // prindCmd

/**
 * @brief Prints user commands and prompts the user to enter a command to interact
 * with the list.
 *
 * @tparam T
 * @param b Binary Tree reference
 */
template<class T>
void options(BinaryTree<T> &b) {
    printCmd();
    while (true) {
        char cmd;
        cout << "\nEnter a command: ";
        cin >> cmd;
        switch (cmd) {
        case 'i': // insert item
            doInsert(b);
            break;
        case 'd': // delete item
            doDelete(b);
            break;
        case 'r': // retrieve item
            doRetrieve(b);
            break;
        case 'l': // get length
            cout << "Tree Length: " << b.getLength() << "\n";
            break;
        case 'n': // in-order
            cout << "In-Order: ";
            b.inOrder();
            cout << "\n";
            break;
        case 'p': // pre-order
            cout << "Pre-Order: ";
            b.preOrder();
            cout << "\n";
            break;
        case 'o': // post-order
            cout << "Post-Order: ";
            b.postOrder();
            cout << "\n";
            break;
        case 's': // single parent
            cout << "Number of Single Parents: " << b.getNumSingleParent() << endl;
            break;
        case 'f': // leaf nodes
            cout << "Number of leaf nodes: " << b.getNumLeafNodes() << endl;
            break;
        case 't': // sub trees
            doSubtree(b);
            break;
        case 'q': // quit
            cout << "Quitting program...\n";
            exit(0);
            break;
        default: // invalid command
            cout << "Command not recognized. Try again\n";
            break;
        } // switch
    } // while
} // options

/**
 * @brief Creates a BinaryTree object and inserts items from file
 * into the list.
 *
 * @tparam T
 * @param b Binary Tree reference
 * @param argv file input
 */
template<class T>
void createList(BinaryTree<T> &b, char argv[]) {
    T num;
    ifstream input(argv);
    while (input >> num) {
        b.insert(num);
    } // while
    options(b);
} // createList

/**
 * @brief Prompts the user for a value to insert and inserts it into the
 * list as long as it is not a duplicate. Then prints list in-order style.
 *
 * @tparam T
 * @param b Binary Tree reference
 */
template<class T>
void doInsert(BinaryTree<T> &b) {
    T item;
    cout << "Item to insert: ";
    cin >> item;
    b.insert(item);
    cout << "In-Order: ";
    b.inOrder();
    cout << "\n";
} // doInsert

/**
 * @brief Prompts the user for a value to retrieve and verifies if the item is
 * in the list or not.
 *
 * @tparam T
 * @param b Binary Tree reference
 */
template<class T>
void doRetrieve(BinaryTree<T> &b) {
    T item;
    bool found = false;
    cout << "Item to be retrieved: ";
    cin >> item;
    b.retrieve(item, found);
} // doRetrieve

/**
 * @brief Prompts the user for a value to delete from the list and deletes
 * it as long the item already existed in the list. Then prints the list
 * in-order style.
 *
 * @tparam T
 * @param b Binary Tree reference
 */
template<class T>
void doDelete(BinaryTree<T> &b) {
    T item;
    bool test = false;
    cout << "Item to delete: ";
    cin >> item;
    if (b.helpRetrieve(item, test) == false) {

    } else {
        b.deleteItem(item);
    }
    cout << "In-Order: ";
    b.inOrder();
} // doDelete

/**
 * @brief Prompts the user for a value in the list and returns the summation of
 * all children below the value.
 *
 * @tparam T
 * @param b Binary Tree reference
 */
template<class T>
void doSubtree(BinaryTree<T> &b) {
    T item;
    cout << "Item to get sum of subtrees: ";
    cin >> item;
    NodeType<T> *node = new NodeType<T>;
    node -> key = item;
    b.getSumOfSubtrees(node);
} // doSubtree
