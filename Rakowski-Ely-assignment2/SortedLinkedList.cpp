#include <iostream>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;

SortedLinkedList::SortedLinkedList() { // done i think
    head -> next = NULL;
    len = 0;
    currentPos = head;
}

SortedLinkedList::~SortedLinkedList() {} // unsure but needed to compile

int SortedLinkedList::length() const { // done
    return len;
}

void SortedLinkedList::insertItem(ItemType item) { // Unfinished I think
    len++;
    ListNode *n; //
    ListNode *l = head; // location
    n -> item = item;
    n -> next = NULL;

    if (head == NULL) { // inserts into empty list
        head = n;
        return;
    }
    while (l -> next != NULL) {
        l = l -> next;
    }
    l -> next = n;
}

void SortedLinkedList::deleteItem(ItemType item) { // not done

}

int SortedLinkedList::searchItem(ItemType item) {

}

// Collins understanding.check it out
/*
void SortedLinkedList::insertItem(ItemType item) {
    ListNode* tempNode = new ListNode; // creates node
    tempNode -> item = item; // sets item in node equal to param item
    if (head == NULL) { // if empty
        head = tempNode;
    } else if (item < head -> item) { // first in the list
        tempNode -> next = head;
        head = tempNode;
    } else {
        ListNode* locTemp = head;
        ListNode* previousTemp = NULL; // onlines says head here

        while (locTemp != NULL) {
            if (locTemp->item > item) { // I think we need to use get next time here
                previousTemp -> next = tempNode;
                tempNode -> next = locTemp;
                break;
            }
            previousTemp = temp; // move prev forward
            locTemp = locTemp -> next; // iterate to next node
        } // while

        if (locTemp == NULL) { // if at the end
            previousTemp -> next = tempNode;
            previousTemp = previousTemp -> next; // should be null
        }
    }
}
*/


ItemType SortedLinkedList::GetNextItem() { // I think the return types were wrong
    if (head == NULL) { // didnt have == only =
        cout << "List is empty\n";
        return head -> next -> item;
    }
    if (currentPos -> next != NULL) {
        return currentPos -> next -> item;
    } else {
        cout << "The end of the list has reached\n";
        currentPos = head; // shouldnt this reset to the top like it says
        return currentPos -> item; // added current pos to return
    }
}

void SortedLinkedList::ResetList() { // done but what about head?
    currentPos = NULL;
}

void SortedLinkedList::mergeList() {

}

void SortedLinkedList::deleteAltNodes() {

}

void SortedLinkedList::intersection() {

}
