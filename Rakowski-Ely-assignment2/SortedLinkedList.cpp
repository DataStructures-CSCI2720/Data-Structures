#include <iostream>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    head -> next = NULL;
    len = 0;
    currentPos = head;
}

SortedLinkedList::~SortedLinkedList() {}

int SortedLinkedList::length() const {
    return len;
}

void SortedLinkedList::insertItem(ItemType item) {
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

// Collins understanding
/*void SortedLinkedList::insertItem(ItemType item) {
    ListNode *predLoc = NULL;
    ListNode *location = head;

    }*/


ItemType SortedLinkedList::GetNextItem() {
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

void SortedLinkedList::ResetList() {
    currentPos = NULL;
}
