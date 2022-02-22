#include "ItemType.h"
#include "SortedLinkedList.h"
#include "ListNode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

void createList(int argc, char* argv[]);
void printCmd();
void promptUser(SortedLinkedList &s);
void doSearch(SortedLinkedList &s);
void doInsert(SortedLinkedList &s);
void doDelete(SortedLinkedList &s);
void doMerge(SortedLinkedList &s);
void newMerge(SortedLinkedList &s);

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
        case 'i':
            doInsert(s);
            break;
        case 'd':
            doDelete(s);
            break;
        case 's':
            doSearch(s);
            break;
        case 'n':
            cout << "\n"<< s.GetNextItem().getValue() << "\n\n";
            break;
        case 'r':
            s.ResetList();
            cout << "Iterator reset.\n";
            break;
        case 'a':
            s.deleteAltNodes();
            break;
        case 'm':
            newMerge(s);
            break;
        case 't': // intersection
            cout << "nothing yet\n";
            break;
        case 'p': // DONE
            s.printLink();
            break;
        case 'l':
            cout << "Length: " << s.length() << endl;
            break;
        case 'q': // DONE
            cout << "Quitting program...\n";
            exit(0);
            break;
        default: // DONE
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
    }
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
}

void newMerge(SortedLinkedList &s) {
    SortedLinkedList compList = SortedLinkedList();
    cout << "Length of list to merge: ";
    int length;
    cin >> length;
    cout << "" << endl; // ?
    cout << "List elements separated by spaces in order: ";
    int values;
    ItemType item;
    for(int i = 0; i < length; i++) { // i see how length helps. but do we handle if you enter wrong amt of #s?
        cin >> values;
        item.initialize(values);
        compList.insertItem(item);
        cin.clear();
    } // while
    cout << "List 1: ";
    s.printLink();
    cout << "List 2: ";
    compList.printLink();
    s.mergeList(compList);
    s.printLink();
    //compList.~SortedLinkedList(); //?? i think it deallocates maybe
} // new Merge
