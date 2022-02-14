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

int SortedLinkedList::length() const {
    return len;
}

void SortedLinkedList::insertItem(ItemType item) {
    len++;
    ListNode *n;
    ListNode *l = head;
    n -> item = item;
    n -> next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }
    while (l -> next != NULL) {
        l = l -> next;
    }
    l -> next = n;
}

ItemType SortedLinkedList::GetNextItem() {
    if (head = NULL) {
        cout << "List is empty\n";
        return;
    }
    if (currentPos -> next != NULL) {
        return currentPos -> next -> item;
    } else {
        cout << "The end of the list has reached\n";
        return;
    }
}

void SortedLinkedList::ResetList() {
    currentPos = NULL;
}