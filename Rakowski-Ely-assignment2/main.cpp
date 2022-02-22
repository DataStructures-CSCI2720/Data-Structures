#include "ItemType.h"
#include "SortedLinkedList.h"
#include "ListNode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void createList(int argc, char* argv[]);    // creates list using file input and starts program
void printCmd();                            // prints list of commands
void promptUser(SortedLinkedList &s);       // prompts user for command input
void doSearch(SortedLinkedList &s);         // performs searching a list
void doInsert(SortedLinkedList &s);         // perfroms inserting item
void doDelete(SortedLinkedList &s);         // performs deleting item
void newMerge(SortedLinkedList &s);         // performs merging two lists
void doInter(SortedLinkedList &s);          // performs finding common items

int main(int argc, char *argv[]) {
    createList(argc, argv);
} // main

void createList(int argc, char* argv[]) {
    SortedLinkedList s;
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
    printCmd();
    promptUser(s);
} // createList

void printCmd() {
    cout << "Commands:\n";
    cout << "(i) - Insert value\n(d) - Delete value\n(s) - Search value\n";
    cout << "(n) - Print next iterator value\n(r) - Reset iterator\n(a) - Delete alternate nodes\n";
    cout << "(m) - Merge two lists\n(t) - Intersection\n(p) - Print list\n(l) - Print length\n(q) - Quit program\n";
} // printCmd

void promptUser(SortedLinkedList &s) {
    while (1 > 0) {
        char cmd;
        cout << "Enter a command:  ";
        cin >> cmd;
        switch (cmd) {
        case 'i': // insert item
            doInsert(s);
            break;
        case 'd': // delete item
            doDelete(s);
            break;
        case 's': // search for item
            doSearch(s);
            break;
        case 'n': // iterate to next item
            cout << "\n"<< s.GetNextItem().getValue() << "\n\n";
            break;
        case 'r': // reset iterator to beginning
            s.ResetList();
            cout << "Iterator reset.\n";
            break;
        case 'a': // delete alternate nodes
            s.deleteAltNodes();
            break;
        case 'm': // merge two lists
            newMerge(s);
            break;
        case 't': // intersection of two lists
            doInter(s);
            break;
        case 'p': // print list
            s.printLink();
            break;
        case 'l': // length of list
            cout << "Length: " << s.length() << endl;
            break;
        case 'q': // quit
            cout << "Quitting program...\n";
            exit(0);
            break;
        case 'c': // reprints commands // we can delete this later just kind of a tool for now
            printCmd();
            break;
        default: // bad input
            cout << "Invalid command, try again!\n";
        } // switch
    } // while
} // promptUser

void doSearch(SortedLinkedList &s) {
    ItemType search;
    int val;
    int index;
    cout << "Enter a value to search:  ";
    cin >> val;
    search.initialize(val);
    index = s.searchItem(search);
    if (index != -1) {
        cout << "Index " << index << endl;
    } else {
        cout << "Item not found.\n";
    } // if
} // doSearch

void doInsert(SortedLinkedList &s) {
    s.printLink();
    cout << "Enter a number: ";
    int ans;
    ItemType localNum;
    cin >> ans;
    localNum.initialize(ans);
    s.insertItem(localNum);
    s.printLink();
} // doInsert

void doDelete(SortedLinkedList &s) {
    s.printLink();
    cout << "Enter value to delete:  ";
    int ans;
    cin >> ans;
    ItemType temp;
    temp.initialize(ans);
    s.deleteItem(temp);
    s.printLink();
} // doDelete

void newMerge(SortedLinkedList &s) {
    SortedLinkedList compList = SortedLinkedList();
    cout << "Length of list to merge: ";
    int length;
    cin >> length;
    cout << "" << endl; // ?
    cout << "List elements separated by spaces in order: ";
    int values;
    ItemType item;
    for (int i = 0; i < length; i++) { // i see how length helps. but do we handle if you enter wrong amt of #s?
        cin >> values;
        item.initialize(values);
        compList.insertItem(item);
        cin.clear();
    } // for
    cout << "List 1: ";
    s.printLink();
    cout << "List 2: ";
    compList.printLink();
    s.mergeList(compList);
    s.printLink();
} // newMerge

void doInter(SortedLinkedList &s) {
    SortedLinkedList t = SortedLinkedList();
    cout << "Length of list to find intersection:  ";
    int length;
    cin >> length;
    cout << "List elements separated by spaces in order:  ";
    int values;
    ItemType item;
    for (int i = 0; i < length; i++) {
        cin >> values;
        item.initialize(values);
        t.insertItem(item);
        cin.clear();
    } // for
    cout << "List 1: ";
    s.printLink();
    cout << "List 2: ";
    t.printLink();
    s.intersection(t);
} // doInter