#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void startUp(int argc, char *argv[]);                         // starts the program
void printCmd();                                              // print available commands
template<class T>
void options(DoublyLinkedList<T> &t);                       // prompts with options
template<class T>
void createList(DoublyLinkedList<T> &t, char argv[]);      // creates list, should be generically
template<class T>
void doInsert(DoublyLinkedList<T> &t);                      // performs inserting into the list
template<class T>
void doDelete(DoublyLinkedList<T> &t);                      // performs deleting from list

// TO DO: add swap alt and delete subsection
// write Makefile that calls input files from a separate files folder ./main /path/to/input.txt /path/to/input2.txt ...
// TEST TEST TEST TEST TEST
// comments
int main(int argc, char *argv[]) { // pass 3 arg files
    startUp(argc, argv);
    return 0;
} // main

void startUp(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
    while (1 > 0) {
        char op;
        cout << "Enter list type (i - int, f - float, s - std::string):  ";
        cin >> op;
        if (op == 'i') {
            DoublyLinkedList<int> d;
            createList(d, argv[1]);
        } else if (op == 'f') {
            DoublyLinkedList<float> d;
            createList(d, argv[2]);
        } else if (op == 's') {
            DoublyLinkedList<std::string> d;
            createList(d, argv[3]);
        } else {
            cout << "Invalid list type, try again!\n\n";
        } // if
    } // while
} // startUp

void printCmd() {
    cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m),\n";
    cout << "printReverse (r), swapAlt (s), quit (q)\n";
} // printCmd

template<class T>
void options(DoublyLinkedList<T> &t) {
    printCmd();
    while (1 > 0) {
        char cmd;
        cout << "\nEnter a command:  ";
        cin >> cmd;
        switch (cmd) {
        case 'i': // insert item
            doInsert(t);
            break;
        case 'd': // delete item
            doDelete(t);
            break;
        case 'l': // length of list
            cout << "The length is: " << t.lengthIs() << endl;
            break;
        case 'p': // print list
            t.print();
            break;
        case 'b': // deleteSubsection of list
            cout << "nothing yet chief:):):):):):)\n";
            break;
        case 'm': // mode of list
            t.print();
            cout << "Mode: " << t.mode() << "\n";
            break;
        case 'r': // print reverse of list
            t.printReverse();
            break;
        case 's': // swapAlternate items
            cout << "nothing yet chief:):):):):):)\n";
            break;
        case 'q': // quit
            cout << "Quitting...\n";
            exit(0);
            break;
        default:
            cout << "Invalid command, try again!\n";
            break;
        } // switch
    } // while
    // case switcher 
} // options

template<class T>
void createList(DoublyLinkedList<T> &t, char argv[]) { // works for ints
    T num;
    ifstream input(argv);
    while (input >> num) {
        t.insertItem(num);
    } // while
    options(t);
} // createList

template<class T>
void doInsert(DoublyLinkedList<T> &t) {
    T input;
    cout << "Item to insert:  ";
    cin >> input;
    t.insertItem(input);
    t.print();
} // doInsert

template<class T>
void doDelete(DoublyLinkedList<T> &t) {
    T input;
    cout << "Item to delete:  ";
    cin >> input;
    t.deleteItem(input);
    t.print();
} // doDelete