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

} // deleteSubsection

template<class T>
int DoublyLinkedList<T>::mode() {
    return 100;
} // mode

template<class T>
void DoublyLinkedList<T>::swapAlternate() {

} // swapAlternate

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;