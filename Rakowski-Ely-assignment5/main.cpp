#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void printCmd();                            // prints user commands
void startUp(int argc, char *argv[]);       // starts the program and creates list of #s
void options(Sorting &s);                   // prompts user with commands to sort list

/**
 * @brief Main method that starts the program.
 * 
 * @param argc number of file arguments
 * @param argv list of file arguments
 * @return int 
 */
int main (int argc, char *argv[]) {
    startUp(argc, argv);                    // begins program
    return 0;
} // main

/**
 * @brief Prints the user commands.
 * 
 */
void printCmd() {
    cout << "selection-sort (s)  merge-sort (m)  heap-sort (h)\n";
    cout << "quick-sort-fp (q)  quick-sort-rp (r)\n";
} // printCmd

/**
 * @brief Prompts user to create a list from the file provided or a random list
 * and then prompts user with options.
 * 
 * @param argc number of file arguments
 * @param argv file arguments
 */
void startUp(int argc, char *argv[]) {
    if (argc < 2) {                                     // must provide file argument
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
    char op;
    cout << "Read file or custom array?\n";
    cout << "\tr - read file\tc - custom array: ";
    cin >> op;
    if (op == 'r') {                                    // creates list from file
        Sorting s(10000);
        s.createList(argv[1]);
        printCmd();
        options(s);
    } else if (op == 'c') {                             // creates random list
        int num;
        cout << "Number of items in the list: ";
        cin >> num;
        Sorting s(num);
        s.createRList();
        printCmd();
        options(s);
    } else {
        cout << "Command not recognized. Exiting...\n";
        exit(0);
    } // if
} // startUp

/**
 * @brief Takes user input and performs a sorting algorithm on the list
 * 
 * @param s Sorting object contains list of numbers
 */
void options(Sorting &s) {
    char op;
    cout << "Enter the algorithm: ";                    // prompts user for input
    cin >> op;
    switch (op) {
    case 's': // Selection Sort
        s.sSort();
        break;
    case 'm': // Merge Sort
        s.mSort(s.values, 0, s.getLength()-1);
        s.printList();
        cout << "\t#Merge-sort comparisons: " << s.getCom() << endl;
        break;
    case 'h': // Heap Sort
        s.hSort(s.values, s.getLength());
        s.printList();
        cout << "\t#Heap-sort comparisons: " << s.getCom() << endl;
        break;
    case 'q': // Quick Sort
        s.qSortf(s.values, 0, s.getLength()-1);
        s.printList();
        cout << "\t#Quick-sort-fp comparisons: " << s.getCom() << endl;
        break;
    case 'r': // Quick Sort with a random pivot value
        s.qSortr(s.values, 0, s.getLength()-1);
        s.printList();
        cout << "\t#Quick-sort-rp comparisons: " << s.getCom() << endl;
        break;
    default: // invalid
        cout << "Command not recognized. Exiting...\n";
        exit(0);
        break;
    } // switch
} // options
