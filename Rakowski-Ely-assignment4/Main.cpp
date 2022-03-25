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
            BinaryTree<std::string> b;
            createList(b, argv[1]);
        } else {
            cout << "Invalid list type, try again!\n\n";
        } // if
    } // while
} // startUp

void printCmd() {
    cout << "Commands:\ninsert (i), delete (d), retrieve (r), length (l), ";
    cout << "in-order (n), pre-order (p), post-order (o), getNumberSingleParent (s), ";
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
            cout << "nothing\n";
            break;
        case 'r': // retrieve item
            cout << "nothing\n";
            break;
        case 'l': // get length
            cout << "Tree Length: " << b.getLength() << "\n";
            break;
        case 'n': // in-order
            cout << "In-Order: ";
            b.inOrder();
            break;
        case 'p': // pre-order
            cout << "Pre-Order: ";
            b.preOrder();
            break;
        case 'o': // post-order
            cout << "Post-Order: ";
            b.postOrder();
            break;
        case 's': // single parent
            cout << "nothing\n";
            break;
        case 'f': // leaf nodes
            cout << "nothing\n";
            break;
        case 't': // sub trees
            cout << "nothing\n";
            break;
        case 'q': // quit
            cout << "Quitting program...\n";
            exit(0);
            break;
        default:
            cout << "Invalid command, try again!\n";
            break;
        } // switch
    } // while
} // options

template<class T>
void createList(BinaryTree<T> &b, char argv[]) {
    T num;
    ifstream input(argv);
    while (input >> num) { // hangs here
        b.insert(num);
    } // while
    cout << "here2";
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
} // doInsert