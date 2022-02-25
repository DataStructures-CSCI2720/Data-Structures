#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void startUp(int argc, char *argv[]);                         // starts the program
void printCmd();                                              // print available commands
template<class T>
void options(DoublyLinkedList<T> &t);                       // prompts with options
template<class T>
void createList(DoublyLinkedList<T> &t, char argv[]);      // creates list, should be generically

// tbh have not even tried to compile but stuff seems okay so far
int main(int argc, char *argv[]) { // pass 3 arg files
    cout << "main lol\n";
    startUp(argc, argv);
    return 0;
} // main

void startUp(int argc, char *argv[]) {
    if (argc < 2) { // later will be less than 4
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
        DoublyLinkedList<string> d;
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
    cout << "here. this is where options should go.\n";
    // case switcher 
} // options

template<class T>
void createList(DoublyLinkedList<T> &t, char argv[]) {
    // adds items to list
    // ZERO clue if this works yet, but right idea
    int num; // also probably needs to be generic or overloaded
    ifstream input(argv);
    while (input >> num) {
        t.insertItem(num);
    } // while
    options(t);
} // createList