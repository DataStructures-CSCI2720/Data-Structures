#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void printCmd();
void startUp(int argc, char *argv[]);
void options(Sorting &s);

int main (int argc, char *argv[]) {
    startUp(argc, argv);
    return 0;
} // main

void printCmd() {
    cout << "selection-sort (s)  merge-sort (m)  heap-sort (h)\n";
    cout << "quick-sort-fp (q)  quick-sort-rp (r)\n";
} // printCmd


void startUp(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Invalid file input! Exiting...\n";
        exit(0);
    } // if
    char op;
    cout << "Read file or custom array?\n";
    cout << "\tr - read file\tc - custom array: ";
    cin >> op;
    if (op == 'r') {
        Sorting s(10000);
        s.createList(argv[1]);
        printCmd();
        options(s);
    } else if (op == 'c') {
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

void options(Sorting &s) {
    char op;
    cout << "Enter the algorithm: ";
    cin >> op;
    switch (op) {
    case 's': // works I believe
        s.sSort();
        break;
    case 'm': // works i believe
        s.mSort(s.values, 0, s.getLength()-1);
        s.printList();
        cout << "\t#Merge-sort comparisons: " << s.getCom() << endl;
        break;
    case 'h':
        s.hSort(s.values, s.getLength());
        s.printList();
        cout << "\t#Heap-sort comparisons: " << s.getCom() << endl;
        break;
    case 'q':
        s.qSortf(s.values, 0, 9999);
        s.printList();
        cout << "\t#Quick-sort-fp comparisons: " << s.getCom() << endl;
        break;
    case 'r':
        s.qSortr(s.values, 0, 9999);
        s.printList();
        cout << "\t#Quick-sort-rp comparisons: " << s.getCom() << endl;
        break;
    default:
        cout << "Command not recognized. Exiting...\n";
        exit(0);
        break;
    } // switch
} // options
