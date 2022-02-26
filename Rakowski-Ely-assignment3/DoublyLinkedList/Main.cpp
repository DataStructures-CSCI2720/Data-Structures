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

int main(int argc, char *argv[]) { // pass 3 arg files
    startUp(argc, argv);
    return 0;
} // main

void startUp(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
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
    } else { // bad list type should probably reprompt user but 2 lazy for now
        cout << "Invalid list type!\n";
        exit(0);
    } // if
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
        cout << "Enter a command:  ";
        cin >> cmd;
        switch (cmd) {
        case 'i': // insert item
            // insert written but not implemented yet
            break;
        case 'd': // delete item

            break;
        case 'l': // length of list
            cout << "The length is: " << t.lengthIs() << endl;
            break;
        case 'p': // print list
            t.print();
            break;
        case 'b': // deleteSubsection of list

            break;
        case 'm': // mode of list

            break;
        case 'r': // print reverse of list
            t.printReverse();
            break;
        case 's': // swapAlternate items

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