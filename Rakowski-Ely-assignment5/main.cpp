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
    Sorting s;
    s.createList(argv[1]);
    printCmd();
    options(s);
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
        s.mSort(s.values, 0, 9999);
        s.printList();
        break;
    case 'h':
        s.hSort();
        break;
    case 'q':
        s.qSortf();
        break;
    case 'r':
        s.qSortr();
        break;
    default:
        cout << "Command not recognized. Exiting...\n";
        exit(0);
        break;
    } // switch
} // options
