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
template<class T>
void doDeleteSub(DoublyLinkedList<T> &t);                   // performs deleting a subsection of a list

// write Makefile that calls input files from a separate files folder ./main /path/to/input.txt /path/to/input2.txt ...
// TEST TEST TEST TEST TEST
// comments

/*
 * main passes in three seperate arguments, and starts the startUp function.
 * @param argc contains the amount of text files
 * @param argv[] passes in the text files
 * @return 0 exits program successfully
 */
int main(int argc, char *argv[]) { // pass 3 arg files
    startUp(argc, argv);
    return 0;
} // main

/*
 * startUp asks the user what type of list they are using. Then creates the list with the
 * corresponding type.
 * @param argc contains the amount of text files
 * @param argv passes in the text files
 */
void startUp(int argc, char *argv[]) {
//    if (argc < 4) {
    if (argc < 1) {
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
    while (1 > 0) {
        char op;
        cout << "Enter list type (i - int, f - float, s - std::string):  ";
        cin >> op;
        if (op == 'i') { // sets a list of type int
            DoublyLinkedList<int> d;
            createList(d, argv[1]);
        } else if (op == 'f') { // sets a list of type float
            DoublyLinkedList<float> d;
            createList(d, argv[1]);
        } else if (op == 's') { // sets a list of type string
            DoublyLinkedList<std::string> d;
            createList(d, argv[1]);
        } else {
            cout << "Invalid list type, try again!\n\n";
        } // if
    } // while
} // startUp

/*
 * printCmd prints to the user the commands the user can use on the list.
 */
void printCmd() {
    cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m),\n";
    cout << "printReverse (r), swapAlt (s), quit (q)\n";
} // printCmd

/*
 * options is responsible for flow control of the commands. The user is prompted to enter a command.
 * Each command entered correpsonds to a function that alters the list in some way.
 * @param the doubly linked list is t is passed by reference
 */
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
            doDeleteSub(t);
            break;
        case 'm': // mode of list
            t.print();
            cout << "Mode: " << t.mode() << "\n";
            break;
        case 'r': // print reverse of list
            t.printReverse();
            break;
        case 's': // swapAlternate items
            cout << "original list: ";
            t.print();
            t.swapAlternate();
            cout << "Swapped list: ";
            t.print();
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

/*
 * createList this takes the numbers from the file and puts them into a list.
 * @param the doubly linked list t is passed by reference to be changed
 * @argv the text files that are created into a list
 */
template<class T>
void createList(DoublyLinkedList<T> &t, char argv[]) { // works for ints
    T num;
    ifstream input(argv);
    while (input >> num) {
        t.insertItem(num);
    } // while
    options(t);
} // createList

/*
 * doInsert inserts a single item specified by the user.
 * @param the list t is passed by reference into the function
 */
template<class T>
void doInsert(DoublyLinkedList<T> &t) {
    T input;
    cout << "Item to insert:  ";
    cin >> input;
    t.insertItem(input);
    t.print();
} // doInsert

/*
 * doDelete deletes a single item in the list as specified by the user.
 * @param the list t is passed by reference into the function
 */
template<class T>
void doDelete(DoublyLinkedList<T> &t) {
    T input;
    cout << "Item to delete:  ";
    cin >> input;
    if (t.lengthIs() > 0) {
        t.deleteItem(input);
        t.print();
    } else {
        cout << "You cannot delete from an empty list." << endl;
    } // else
} // doDelete

/*
 * doDeleteSubsitution deletes every item not in the subsection of the user specified
 * bounds.
 * @param the list t is passed by reference into the function
 */
template<class T>
void doDeleteSub(DoublyLinkedList<T> &t) {
    T upper;
    T lower;
    cout << "Enter lower bound: ";
    cin >> lower;
    cout << "Enter upper bound: ";
    cin >> upper;
    cout << "Original list: ";
    t.print();
    t.deleteSubsection(upper, lower);
    cout << "Modified list: ";
    t.print();
} // doDeleteSub
