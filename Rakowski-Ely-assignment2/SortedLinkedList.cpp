#include <iostream>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;
// did not delete your code but for some reason it wasnt adding anything to a list at all.
SortedLinkedList::SortedLinkedList() { // done i think
//    head -> next = NULL;
    head = NULL;
    currentPos = NULL;
}

SortedLinkedList::~SortedLinkedList() {} // unsure but needed to compile

int SortedLinkedList::length() const { // done
    int len = 0;
    ListNode *leng = head;
    while (leng -> next != NULL) {
        leng = leng -> next;
        len++;
    }
    return len;
}

/*
void SortedLinkedList::insertItem(ItemType item) { // Unfinished I think
    ListNode *n; // bro this does not work
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
    ListNode *newNode = new ListNode();
    ListNode *end = head;
    newNode -> item = item;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    while (end -> next != NULL) {
        end = end -> next;
    }
    end -> next = newNode;
}
*/
void SortedLinkedList::deleteItem(ItemType item) { // not done

}

int SortedLinkedList::searchItem(ItemType item) {
    return 0;
}


void SortedLinkedList::insertItem(ItemType item) { // COLLINS TEST
    ListNode* tempNode = new ListNode; // creates node
    tempNode -> item = item; // sets item in node equal to param item

    if (head == NULL) { // IF EMPTY
        head = tempNode; // pointing head toward out new node
        currentPos = tempNode; // forgot
        cout << "inserted in empty" << endl;
        return;
    }

    if (item.compareTo(head -> item) == Comparison::LESS) { // ITEM FIRST IN LIST
        tempNode -> next = head; // pointing temp node to head
        head = tempNode; // then make head point to tempNode
        currentPos = head; // forgot
        cout << "inserted before first node" << endl;
        return;
    }


//    ListNode* locTemp = head; // pointing to head
//    ListNode* previousTemp = head; // onlines says head here

    ListNode* locTemp = new ListNode;
    ListNode* previousTemp;
    locTemp = head;
    previousTemp = locTemp;
    locTemp = locTemp -> next;

//    previousTemp = NULL;

    while (locTemp != NULL) { //was locTemp != NULL // need to use get next item maybe
        cout << "Inside While" << endl;

        if (item.compareTo(locTemp->item) == Comparison::GREATER) { // or equal
            previousTemp -> next = tempNode;
            tempNode -> next = locTemp;
            cout << "Insert in middle" << endl;
            break;
        }
        previousTemp = locTemp; // move prev forward
        locTemp = locTemp -> next; // iterate to next node
        cout << "Moved on" << endl;
    } // while

    previousTemp -> next = tempNode;
    previousTemp = previousTemp -> next;
    cout << "Inserted at end" << endl;

    /*
    if (locTemp == NULL) { // if at the end
        previousTemp -> next = tempNode;
        previousTemp = previousTemp -> next; // should be null
        cout << "Inserted at end" << endl;
        } // if */

} // insert item



ItemType SortedLinkedList::GetNextItem() { // I think the return types were wrong
    ItemType localItem;
    if (head -> next == NULL) { // works I think
        cout << "List is empty\n";
        return head -> item;
    }
    if (currentPos -> next != NULL) {
        currentPos = currentPos -> next;
        localItem = currentPos -> item;
        // return localItem; // I think this could also work
        cout << localItem.getValue() << endl;
        return currentPos -> item;
    } else {
        cout << "The end of the list has reached\n";
        currentPos = head; // verified Correct
        return head -> item; // Unsure if this is the correct way to do this
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

void SortedLinkedList::printLink() {
    ListNode *temp = head;
//    temp = head; // head is point to null and i dont know why
    cout << "PRINT" << endl;
    ItemType printer;
    printer = temp -> item;
    while(printer.getValue() != 100) {
        cout << "inside" << endl;
        printer = temp -> item;
        cout << printer.getValue() << " ";
        temp = temp -> next;
    } // while
    cout << "end" << endl;
}
