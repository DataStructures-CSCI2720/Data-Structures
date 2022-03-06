#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>
#include <stdio.h>

using namespace std;

/*
 * Double linked list contructor the sets the head to null.
 */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
} // DoublyLinkedList constructor

/*
 * Destructor function that deallocates all memory in the linked list.
 */
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeType<T> *curr;
    while (lengthIs() > 0) {
        curr = head;
        head = head -> next;
        delete curr;
    } // while
} // DoublyLinkedList destructor

/*
 * insertItem inserts an item specified by the user into the list.
 * @param item is the item that is being compared to and inserted into the list
 */
template<class T>
void DoublyLinkedList<T>::insertItem(T &item) {
    NodeType<T> *newNode = new NodeType<T>;
    newNode -> data = item;

    if (head == NULL) { // Special Case: Inserts item at the beginning of the list.
        head = newNode;
        newNode -> next = head;
        newNode -> last = head;
        return;
    } // if
    bool keepSeaching = true;
    NodeType<T> *curr = head -> next;
    while (keepSeaching) {
        if ((newNode -> data) <= (curr -> data)) { // not generic for strings yet
            newNode -> next = curr;
            newNode -> last = curr -> last;
            curr -> last -> next = newNode;
            curr -> last = newNode;
            keepSeaching = false;
        } else {
            if (curr == head) { // Special Case: Inserts item at the beginning of the list/
                newNode -> next = curr -> next;
                newNode -> last = curr;
                curr -> next -> last = newNode;
                curr -> next = newNode;
                head = newNode;
                keepSeaching = false;
            } else { // Iterates through the array if the item place is not found
                curr = curr -> next;
                keepSeaching = true;
            } // if
        } // if
    } // while
} // insertItem

/*
 * deleteItem takes in an item by reference and if the item is in the list it deletes the item.
 * @param item is passed by reference to be inserted into the list
 */
template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
    NodeType<T> *temp = head -> next;
    bool keepSeaching = true;
    int counter = 0;

    if (head == NULL) { // checks to see if the list is empty
        cout << "You cannot delete from an empty list.\n";
//        return;
        keepSeaching = false;
    } // if

    while (keepSeaching) {
        counter++;
        if (temp -> data == item) {
            if (temp == head) { // Special case: checks if the item is the last in the list
                head = head -> last;
            } // if
            if (lengthIs() == 1) { // works but prints 'list is empty' which might be okay
                delete temp;
                head = NULL;
                return;
            } // if
            temp -> last -> next = temp -> next;
            temp -> next -> last = temp -> last;
            delete temp;
            keepSeaching = false;
        } else {
            if (counter > lengthIs()) { // Special case: if the item is not found in the list.
                cout << "Item not in list!\n";
                keepSeaching = false;
            } else {
                temp = temp -> next; // Keeps iterating if the item to be deleted is not found yet.
            } // if
        } // if
    } // while
} // deleteItem

/*
 * lengthIs checks the length of the list.
 * @return the length of the list in ints.
 */
template<class T>
int DoublyLinkedList<T>::lengthIs() const {
    int len = 0;
    if (head == NULL) { // prints the length of the array is zero if there is no items in the array.
        return len;
    } // if
    NodeType<T> *start = head -> next;
    while (start != head) { // increments len until the end of the list is found.
        len++;
        start = start -> next;
    } // while
    return len + 1;
} // lengthIs

/*
 * print() individually prints every item in the list.
 */
template<class T>
void DoublyLinkedList<T>::print() {
    if (head == NULL) { // if empty
        cout << "List is empty!\n";
        return;
    } // if
    NodeType<T> *start = head -> next;
    while (start != head) { // prints every item in the list individually until the end is found.
        cout << start -> data << " ";
        start = start -> next;
    } // while
    cout << start -> data << "\n";
} // print

/*
 * printReverse prints the list in reverse.
 */
template<class T>
void DoublyLinkedList<T>::printReverse() {
    if (head == NULL) { // if empty
        cout << "List is empty!\n";
        return;
    } // if
    NodeType<T> *end = head;
    cout << end -> data << " ";
    end = end -> last;
    while (end != head) { // prints the list backwards using 'last' to iterate through the list.
        cout << end -> data << " ";
        end = end -> last;
    } // while
    cout << "\n";
} // printReverse

/*
 * deleteSubsection uses bounds specified by the user to create a subsection of a list.
 * @param upper is the upper bound of the subsection
 * @param lower is the lower bound of the subsection
 */
template<class T>
void DoublyLinkedList<T>::deleteSubsection(T upper, T lower) {
    if (head == NULL) { // if empty list
        return;
    } // if
    NodeType<T> *curr = head;
    int counter = 0;
    int length = lengthIs();
    while (counter < length) {
        counter++;
        curr = curr -> next;
        if ((curr -> last -> data <= upper)&&(curr -> last -> data >= lower)) {
            deleteItem(curr -> last -> data); // if the list is not in the subsection, delete item.
        } // if
    } // while
} // deleteSubsection

/*
 * finds the mode of the list.
 * @return the mode of using Type T
 */
template<class T>
T DoublyLinkedList<T>::mode() {
    NodeType<T> *curr = head -> next -> next; // assumes first value is mode so skips to second
    T value = head -> next -> data;
    T mode = value;
    int count = 1;
    int modeCount = 1;
    int counter = 0;

    while (lengthIs() > counter) {
        if (curr -> data == value) {
            count++; // incremented the counter if the value is found within the list
        } else {
            if (count > modeCount) {
                modeCount = count; // the mode count is stored if a new mode is found
                mode = value; // mode is stored if a new mode is found
            } // if
            count = 1;
            value = curr -> data;
        } // if
        curr = curr -> next;
        counter++;
    } // while
    return mode;
} // mode

/*
 * swapAlternate swaps the nodes in pairs until the end is found.
 */
template<class T>
void DoublyLinkedList<T>::swapAlternate() {
    NodeType<T> *curr = head -> next -> next;
    NodeType<T> *beh = head -> next;
    int interate = 0;
    bool keepSearching = true;
    int length = lengthIs();
    if ((head == NULL) || (lengthIs() == 1)) { // checks if the list is empty or for one item
        return;
    } // if
    if ((lengthIs() % 2) > 0) { // calculates if the length is odd or even
        length = length - 1;
    }
    length = length / 2;
    cout << length << endl;
    // swapping beginning case
    // swapping last case

    for (int i = length; i > 0; i--) {
        curr -> next -> last = curr -> last;
        beh -> last -> next = beh -> next;
        curr -> last = beh -> last;
        beh -> next = curr -> next;
        curr -> next = beh;
        beh -> last = curr;

        curr = beh; // beh was current so we must set current equal to beh to remain consistent
        curr = curr -> next -> next; // iterates to the next pair of variables to be swapped
        beh = curr -> last;
    } // for

} // swapAlternate

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
