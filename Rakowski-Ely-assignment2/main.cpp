#include "ItemType.h"
#include "SortedLinkedList.h"
#include "ListNode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void createList(int argc, char* argv[], SortedLinkedList s);
void printCmd();
void promptUser(SortedLinkedList s);

int main(int argc, char *argv[]) {
    SortedLinkedList s;
    createList(argc, argv, s);
    printCmd();
    promptUser(s);
} // main

void createList(int argc, char* argv[], SortedLinkedList s) {
    if (argc <= 1) {
        cout << "Invalid file argument! Exiting...\n";
        exit(0);
    } // if
    int num;
    ifstream input(argv[1]);
    while (input >> num) {
        ItemType t;
        t.initialize(num);
        s.insertItem(t);
    } // while
    cout << "Successfully read file!\n"; // temp
} // createList

void printCmd() {
    cout << "Commands:\n";
    cout << "(i) - Insert value\n(d) - Delete value\n(s) - Search value\n";
    cout << "(n) - Print next iterator value\n(r) - Reset iterator\n(a) - Delete alternate nodes\n";
    cout << "(m) - Merge two lists\n(t) - Intersection\n(p) - Print list\n(l) - Print length\n(q) - Quit program\n";
} // printCmd

void promptUser(SortedLinkedList s) {
    while (1 > 0) {
        char cmd;
        cout << "Enter a command:  ";  
        cin >> cmd;
        switch (cmd) {
            case 'i':
                cout << "nothing yet\n";
                // call SortedLinkedList item.func()
                break;
            case 'd':
                cout << "nothing yet\n";
                break;
            case 's':
                cout << "nothing yet\n";
                break;
            case 'n':
                cout << "nothing yet\n";
                break;
            case 'r':
                cout << "nothing yet\n";
                break;
            case 'a':
                cout << "nothing yet\n";
                break;
            case 'm':
                cout << "nothing yet\n";
                break;
            case 't':
                cout << "nothing yet\n";
                break;
            case 'p':
                cout << "nothing yet\n";
                break;
            case 'l':
                cout << "nothing yet\n";
                break;
            case 'q':
                cout << "Quitting program...\n";
                exit(0);
                break;
            default:
                cout << "Invalid command, try again!\n";
        } // switch
    } // while
} // promptUser