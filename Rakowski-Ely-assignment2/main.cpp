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

/**
 * @brief Main method to execute the SortedLinkedList interface.
 * 
 * @param argc number of file arguments
 * @param argv file argument
 * @return int 
 */
int main(int argc, char *argv[]) {
    createList(argc, argv); // creates list and starts interface
} // main

/**
 * @brief Creates the SortedLinkedList from file input. Then prints available
 * commands and then beings the promptUser loop.
 * 
 * @param argc number of args from main
 * @param argv file argument from main
 */
void createList(int argc, char* argv[]) {
    SortedLinkedList s; // new SortedLinkedList
    if (argc <= 1) { // must be valid file argument
        cout << "Invalid file argument! Exiting...\n";
        exit(0);
    } // if
    int num;
    ifstream input(argv[1]);
    while (input >> num) { // reads input and creates new ItemType to add to list
        ItemType t;
        t.initialize(num);
        s.insertItem(t); // adds item to list
    } // while
    printCmd(); // prints commands
    promptUser(s); // starts promptUser loop
} // createList

/**
 * @brief Prints available commands to interact with SortedLinkedList.
 * 
 */
void printCmd() {
    cout << "\nCommands:\n";
    cout << "\n(i) - Insert value\n\n(d) - Delete value\n\n(s) - Search value\n";
    cout << "\n(n) - Print next iterator value\n\n(r) - Reset iterator\n\n(a) - Delete alternate nodes\n";
    cout << "\n(m) - Merge two lists\n\n(t) - Intersection\n\n(p) - Print list\n\n(l) - Print length\n\n(q) - Quit program\n\n";
} // printCmd

/**
 * @brief Loop that gets user input and modifies or views items in the SortedLinkedList.
 * 
 * @param s reference to SortedLinkedList created in createList.
 */
void promptUser(SortedLinkedList &s) {
    while (1 > 0) { // keeps loop running
        char cmd;
        cout << "Enter a command:  "; // user prompt
        cin >> cmd;
        switch (cmd) { // available commands
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
            if (s.length() != 0) { // only returns next if length is > 0
                cout << "\n"<< s.GetNextItem().getValue() << "\n\n";
            } else {
                cout << "List is empty!" << endl;
            } // if
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
        case 'c': // reprints commands
            printCmd();
            break;
        default: // bad input
            cout << "Invalid command, try again!\n";
        } // switch
    } // while
} // promptUser

/**
 * @brief Performs the search function and includes user interface prompts.
 * 
 * @param s reference to SortedLinkedList from promptUser
 */
void doSearch(SortedLinkedList &s) {
    ItemType search;
    int val;
    int index;
    cout << "Enter a value to search:  "; // prompt
    cin >> val;
    search.initialize(val);
    index = s.searchItem(search); // searches for item
    if (index != -1) {
        cout << "Index " << index << endl;
    } else {
        cout << "Item not found.\n";
    } // if
} // doSearch

/**
 * @brief Performs inserting an item into the list and includes interface prompts.
 * 
 * @param s reference to SortedLinkedList from promptUser
 */
void doInsert(SortedLinkedList &s) {
    s.printLink();
    cout << "Enter a number: "; // prompt
    int ans;
    ItemType localNum;
    cin >> ans;
    localNum.initialize(ans);
    s.insertItem(localNum); // inserts item into list
    s.printLink(); // reprints list
} // doInsert

/**
 * @brief Performs deleting item from SortedLinkedList and includes interface prompts.
 * 
 * @param s reference to SortedLinkedList from promptUser
 */
void doDelete(SortedLinkedList &s) {
    s.printLink();
    cout << "Enter value to delete:  "; // prompt
    int ans;
    cin >> ans;
    ItemType temp;
    temp.initialize(ans);
    s.deleteItem(temp); // deletes item from list
    s.printLink(); // reprints list
} // doDelete

/**
 * @brief Performs merging two SortedLinkedLists, the second one being created in this method.
 * Includes the user interface prompt as well.
 * 
 * @param s reference to SortedLinkedList from promptUser
 */
void newMerge(SortedLinkedList &s) {
    SortedLinkedList compList = SortedLinkedList(); // create new list
    cout << "Length of list to merge: "; // prompt
    int length;
    cin >> length;
    cout << "List elements separated by spaces in order: ";
    int values;
    ItemType item;
    for (int i = 0; i < length; i++) { // add items to new list
        cin >> values;
        item.initialize(values);
        compList.insertItem(item);
        cin.clear();
    } // for
    cout << "List 1: ";
    s.printLink(); // print old list
    cout << "List 2: ";
    compList.printLink(); // print new list
    s.mergeList(compList);
    s.printLink(); // print merged list
} // newMerge

/**
 * @brief Performs printing the common items between two SortedLinkedLists, the second
 * one being created in this method. Includes the user prompt as well.
 * 
 * @param s reference to SortedLinkedList from promptUser
 */
void doInter(SortedLinkedList &s) {
    SortedLinkedList t = SortedLinkedList(); // new list created
    cout << "Length of list to find intersection:  "; // prompt
    int length;
    cin >> length;
    cout << "List elements separated by spaces in order:  ";
    int values;
    ItemType item;
    for (int i = 0; i < length; i++) { // insert items into list
        cin >> values;
        item.initialize(values);
        t.insertItem(item);
        cin.clear();
    } // for
    cout << "List 1: ";
    s.printLink(); // print old list
    cout << "List 2: ";
    t.printLink(); // print new list
    s.intersection(t); // prints common items
} // doInter
