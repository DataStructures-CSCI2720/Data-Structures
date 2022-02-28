#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>
#include <stdio.h>

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
} // DoublyLinkedList constructor

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeType<T> *curr;
    while (lengthIs() > 0) {
        curr = head;
        head = head -> next;
        delete curr;
    } // while
} // DoublyLinkedList destructor

template<class T>
void DoublyLinkedList<T>::insertItem(T &item) {
    NodeType<T> *newNode = new NodeType<T>;
    newNode -> data = item;

    if (head == NULL) { // if empty
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
            if (curr == head) { // greatest item in group
                newNode -> next = curr -> next;
                newNode -> last = curr;
                curr -> next -> last = newNode;
                curr -> next = newNode;
                head = newNode;
                keepSeaching = false;
            } else {
                curr = curr -> next;
                keepSeaching = true;
            } // if
        } // if
    } // while
} // insertItem

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
    NodeType<T> *temp = head -> next;
    bool keepSeaching = true;
    int counter = 0;

    if (head == NULL) {
        cout << "You cannot delete from an empty list.\n";
        return;
    } // if

    while (keepSeaching) {
        counter++;
        if (temp -> data == item) {
            if (temp == head) { // if item is last in list
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
            if (counter > lengthIs()) {
                cout << "Item not in list!\n";
                keepSeaching = false;
            } else {
                temp = temp -> next; // keep iterating
            } // if
        } // if
    } // while
} // deleteItem

template<class T>
int DoublyLinkedList<T>::lengthIs() const {
    int len = 0;
    if (head == NULL) { // if empty
        return len;
    } // if
    NodeType<T> *start = head -> next;
    while (start != head) {
        len++;
        start = start -> next;
    } // while
    return len + 1;
} // lengthIs

template<class T>
void DoublyLinkedList<T>::print() {
    if (head == NULL) { // if empty
        cout << "List is empty!\n";
        return;
    } // if
    NodeType<T> *start = head -> next;
    while (start != head) {
        cout << start -> data << " ";
        start = start -> next;
    } // while
    cout << start -> data << "\n";
} // print

template<class T>
void DoublyLinkedList<T>::printReverse() {
    if (head == NULL) { // if empty
        cout << "List is empty!\n";
        return;
    } // if
    NodeType<T> *end = head;
    cout << end -> data << " ";
    end = end -> last;
    while (end != head) {
        cout << end -> data << " ";
        end = end -> last;
    } // while
    cout << "\n";
} // printReverse

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
            deleteItem(curr -> last -> data);
        } // if
    } // while
} // deleteSubsection

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
            count++;
        } else {
            if (count > modeCount) {
                modeCount = count;
                mode = value;
            } // if
            count = 1;
            value = curr -> data;
        } // if
        curr = curr -> next;
        counter++;
    } // while
    return mode;
} // mode

template<class T>
void DoublyLinkedList<T>::swapAlternate() {
    NodeType<T> *curr = head -> next;
    int interate = 0;
    bool keepSearching = true;
    bool isOdd = false;
    if (head == NULL) {
        return;
    } // if
    if ((lengthIs() % 2) > 0) {
        isOdd == true;
    }
    // swapping beginning case
    // swapping last case
    while (keepSearching) {
/*
        if ((curr -> next -> next == NULL)&&(isOdd == true)) {
            // this is where we put the odd case stuff, aka do nothing
            keepSearching = false;
        }

        if (curr -> next = NULL) {
            // reached the end of the list done
            keepSearching = false;
        }
*/
        curr -> last -> next = curr -> next;
        curr -> next = curr -> next -> next;
        curr -> next -> last -> next = curr;
        curr -> next -> last -> last = curr -> last;
        curr -> next -> last = curr;
        curr -> last = curr -> last -> next;
        // keep iterating and switch them

        keepSearching = false;
    }
    // swap alternate nodes
} // swapAlternate

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
