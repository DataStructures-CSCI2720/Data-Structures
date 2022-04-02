#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

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

// THINGS TO DO: not allow strings for getsubtrees, test for edge cases, test test test
int main(int argc, char *argv[]) {
    startUp(argc, argv);
    return 0;
} // main

void startUp(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
    while (true) {
        char op;
        cout << "Enter list type (i - int, f - float, s - std::string): ";
        cin >> op;
        if (op == 'i') {
            BinaryTree<int> b;
            createList(b, argv[1]);
        } else if (op == 'f') {
            BinaryTree<float> b;
            createList(b, argv[1]);
        } else if (op == 's') {
            //BinaryTree<std::string> b;
            //createList(b, argv[1]);
            exit(0);
        } else {
            cout << "Invalid list type, try again!\n\n";
        } // if
    } // while
} // startUp

void printCmd() {
    cout << "\nCommands:\ninsert (i), delete (d), retrieve (r), length (l), ";
    cout << "in-order (n), pre-order (p), post-order (o),\ngetNumberSingleParent (s), ";
    cout << "getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)\n";
} // prindCmd

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
        default:
            cout << "Command not recognized. Try again\n";
            break;
        } // switch
    } // while
} // options

template<class T>
void createList(BinaryTree<T> &b, char argv[]) {
    T num;
    ifstream input(argv);
    while (input >> num) {
        b.insert(num);
    } // while
    options(b);
} // createList

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

template<class T>
void doRetrieve(BinaryTree<T> &b) {
    T item;
    bool found = false;
    cout << "Item to be retrieved: ";
    cin >> item;
    b.retrieve(item, found);
} // doRetrieve

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

template<class T>
void doSubtree(BinaryTree<T> &b) { // doesnt work with strings gotta limit types
    T item;
    cout << "Item to get sum of subtrees: ";
    cin >> item;
    NodeType<T> *node = new NodeType<T>;
    node -> key = item;
    int sum = b.getSumOfSubtrees(node);
    if (sum != -1) {
        cout << "Sum of Subtrees: " << sum << endl;
    } // if
} // doSubtree
