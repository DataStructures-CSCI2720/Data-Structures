#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void printCmd();
void startUp(int argc, char *argv[]);
//void options(Sorting &s);

// needs comments but probably pretty close to done lol
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
    //Sorting s; //constructor yet to be done
    printCmd();
    //options(s);
} // startUp