#include <iostream>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;
// did not delete your code but for some reason it wasnt adding anything to a list at all.
SortedLinkedList::SortedLinkedList() {
    head = NULL;
}

SortedLinkedList::~SortedLinkedList() {} // unsure but needed to compile

int SortedLinkedList::length() const { // done
    int len = 0;
    ListNode *leng = head;
    while (leng != NULL) {
        leng = leng -> next;
        len++;
    }
    return len;
}

void SortedLinkedList::deleteItem(ItemType item) { // not done

}

int SortedLinkedList::searchItem(ItemType item) {
    ListNode *curr = head;
    bool keepSearch = true;
    int index = -1;
    int len = length() - 2;
    while (keepSearch) {
        if (index > len) {
            index = -1;
            keepSearch = false;
        } else {
            index++;
            if (item.compareTo(curr -> item) == Comparison::EQUAL) {
                keepSearch = false;
            } else {
                curr = curr -> next;
            }
        }
    }
    return index;
}

void SortedLinkedList::insertItem(ItemType item) { // i know inserting in the middle doesnt work for some reason rn
    ListNode* newNode = new ListNode; // creates node
    newNode -> item = item; // sets item in node equal to param item
    newNode -> next = NULL;
    ListNode *last = head;
    if (head == NULL) { // IF EMPTY
        head = newNode; // pointing head toward out new node
        currentPos = head;
        //cout << "head created" << endl;
        return;
    }
    /*while (last -> next != NULL) {  //UNSORTED for testing
        last = last -> next;
    }
    last -> next = newNode;
    cout << "added node to end\n";*/
/*
    if (item.compareTo(head -> item) == Comparison::LESS) { // ITEM FIRST IN LIST
        newNode -> next = head; // pointing temp node to head
        head = newNode; // then make head point to tempNode
        //currentPos = head; // forgot
        cout << "inserted before first node" << endl;
        return;
    }

    ListNode* locTemp = head; // pointing to head
//    ListNode* previousTemp = head; // onlines says head here

    //ListNode* locTemp = new ListNode;
    ListNode* previousTemp;
    locTemp = head;
    previousTemp = locTemp;
    locTemp = locTemp -> next;

//    previousTemp = NULL;

    while (locTemp != NULL) { //was locTemp != NULL // need to use get next item maybe
        cout << "Inside While" << endl;

        if (item.compareTo(locTemp->item) == Comparison::GREATER) { // or equal
            previousTemp -> next = newNode;
            newNode -> next = locTemp;
            cout << "Insert in middle" << endl;
            break;
        }
        previousTemp = locTemp; // move prev forward
        locTemp = locTemp -> next; // iterate to next node
        cout << "Moved on" << endl;
    } // while

    previousTemp -> next = newNode;
    previousTemp = previousTemp -> next;
    cout << "Inserted at end" << endl;


    if (locTemp == NULL) { // if at the end
        previousTemp -> next = newNode;
        previousTemp = previousTemp -> next; // should be null
        cout << "Inserted at end" << endl;
        } // if
    // this works and I hope isnt aids to read
    */

    bool keepSearching = true;
    ListNode *curr = head;
    while (keepSearching) {
        if (newNode -> item.compareTo(curr -> item) == Comparison::LESS) {
            if (curr == head) {
                newNode -> next = head;
                head = newNode;
                currentPos = head;
                keepSearching = false;
            } else {
                newNode -> next = curr; // right here i need to link behind
                keepSearching = false;
            }
        } else if (newNode -> item.compareTo(curr -> item) == Comparison::EQUAL) {
            cout << "Sorry. You cannot insert the duplicate item.\n";
            keepSearching = false;
        } else {
            if (curr -> next == NULL) {
                curr -> next = newNode;
                keepSearching = false;
            } else {
                curr = curr -> next;
            }
        }
    } // while
} // insert item

ItemType SortedLinkedList::GetNextItem() { // works
    if (length() == 0) {
        cout << "List is empty!" << endl;
        return head -> item;
    }
    if (currentPos == NULL) {
        cout << "End of the list has been reached!" << endl;
        currentPos = head;
    }
    ItemType local;
    local = currentPos -> item;
    currentPos = currentPos -> next;

    return local;
}

void SortedLinkedList::ResetList() { // dont we need to deallocate nodes?
    currentPos = NULL;
}

void SortedLinkedList::mergeList() {

}

void SortedLinkedList::deleteAltNodes() {

}

void SortedLinkedList::intersection() {

}

void SortedLinkedList::printLink() { // DONE
    ListNode *temp = head;
    //cout << "Sort Linked List: \n" << endl;
    while (temp) {
        cout << temp -> item.getValue() << " ";
        temp = temp -> next;
    } // while
    cout << "" << endl;
}
