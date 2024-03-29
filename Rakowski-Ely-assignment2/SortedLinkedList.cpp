#include <iostream>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"
#include <string.h>
#include <stdio.h>

using namespace std;

/*
 * SortedLinkedList constructor. Initialized the head pointed and sets it to NULL.
 */
SortedLinkedList::SortedLinkedList() {
    head = NULL;
} // SortedLinkedList constructor

/*
 * SortedLinked List destructor. Deletes each node individually until the list is empty.
 * @param
 * @return
*/
SortedLinkedList::~SortedLinkedList() {
    ListNode *curr;
    while (head != NULL) { // Deletes nodes until it reaches the end of the list
        curr = head;
        head = head -> next; // moves to next node
        delete curr; // deletes the last node
    } // while
} // SortedLinkedList destructor

/*
 * length prints the length of the list.
 * @return len is the length of the list
*/
int SortedLinkedList::length() const {
    int len = 0;
    ListNode *leng = head;
    while (leng != NULL) { // counts all nodes until it reaches null
        leng = leng -> next;
        len++;
    } // while
    return len;
} // length

/*
 * deleteItem deletes the item from a list. If the list is not found in this list, the user is
 * notified the item is not found.
 * @param item is the item that is being deleted from the list if it exists in the list
*/
void SortedLinkedList::deleteItem(ItemType item) {
    if (head == NULL) { // Special case: Empty List
        cout << "You cannot delete from an empty list.";
        return;
    } // if

    bool keepSearching = true;
    ListNode *curr = head; // Searching Node
    ListNode *beh = head; // Previous Node
    while (keepSearching) {
        if (curr -> item.compareTo(item) == Comparison::EQUAL) { // Handles cases when the searching node equals the item
            if (curr == head) { // if the first node is equal to the item being searched for
                head = head -> next; // moves head to the next node
            } else {
                beh -> next = curr -> next;
            } // if
            delete curr; // delete the node once the pointers are moved
            keepSearching = false;
        } else {
            if (curr -> next == NULL) { // Special Case: Item was not found in the list
                keepSearching = false;
                cout << "Item not found." << endl;
            } else {
                if (curr != head) { // keeps iterating through the array until it reaches the end
                    beh = beh -> next;
                } // if
                curr = curr -> next;
            } // if
        } // if
    } // while
} // deleteItem

/*
 * searchItem uses a given item to search for another item in the list. If the equivalent item is
 * found then the item is returned.
 * @param item contains the value that is being searched for
 * @return int index contains the position of the item that is being searched for
*/
int SortedLinkedList::searchItem(ItemType item) {
    ListNode *curr = head;
    bool keepSearch = true;
    int index = -1;
    int len = length() - 2;
    while (keepSearch) {
        if (index > len) { // If the index is equal to the length the index has been found
            index = -1;
            keepSearch = false;
        } else { // Else if index not found
            index++;
            if (item.compareTo(curr -> item) == Comparison::EQUAL) { // Finds Index
                keepSearch = false;
            } else { // Keep iterating to find item
                curr = curr -> next;
            } // if
        } // if
    } // while
    return index;
} // searchItem

/*
 * insertItem takes in an item with a value. This function inserts the value in the sorted list
 * regardless of the place. This function checks for duplicate items.
 * @param item contains the value that is being compared
*/
void SortedLinkedList::insertItem(ItemType item) {
    ListNode* newNode = new ListNode(); // creates node
    newNode -> item = item; // sets item in node equal to param item
    newNode -> next = NULL;

    if (head == NULL) { // Special Case: If the node is empty
        head = newNode; // pointing head toward out new node
        currentPos = head;
        return;
    } // if
    bool keepSearching = true;
    ListNode *curr = head; // Searching node
    ListNode *beh = head; // Node following the Searching node
    while (keepSearching) {
        if (newNode -> item.compareTo(curr -> item) == Comparison::EQUAL) { // Special Case: No Duplicates
            cout << "Sorry. You cannot insert the duplicate item.\n";
            keepSearching = false;
        } else if (newNode -> item.compareTo(curr -> item) == Comparison::LESS) { //
            if (curr == head) { // Special Case: Insert at beginning of List
                newNode -> next = head;
                head = newNode;
                currentPos = head;
                keepSearching = false;
            } else { // General Case for insertion
                beh -> next = newNode;
                newNode -> next = curr;
                keepSearching = false;
            } // if
        } else {
            if (curr -> next == NULL) { // End of the list is found
                curr -> next = newNode;
                keepSearching = false;
            } else { // If the current item is greater the node keeps iterating
                if (curr != head) {
                    beh = beh -> next;
                } // if
                curr = curr -> next;
            } // if
        } // if
    } // while
} // insertItem

/*
 * GetNextItem gets the value of the next item node in list. If there is no nodes in the list
 * or the value was not found then the user is notified.
 * @return ItemType local contains the item value
*/
ItemType SortedLinkedList::GetNextItem() {
    if (currentPos == NULL) { // Special Case: Checks for the end of the list
        currentPos = head;
    } // if
    ItemType local;
    local = currentPos -> item; // iterates one step through the list
    currentPos = currentPos -> next;

    return local; // returns the value
} // GetNextItem

/*
 * ResetList resets the currentPos pointed to the head position, or the top of the
 * list.
*/
void SortedLinkedList::ResetList() {
    currentPos = head; // Sets the local variable currentPos to the top of the list
} // ResetList

/*
 * mergeList takes in one list and compares it to the constructed list. mergeLists tests for
 * duplicates. If the user inputted list contains duplicates then no merge is done.
 * Otherwise, a new list is created and printed.
 * @param s2 is passed by reference to be used as the list to be merged
*/
void SortedLinkedList::mergeList(SortedLinkedList &s2) {
    ListNode *l1 = head;

    while (l1 != NULL) { // supposed to check for matching first // does check for matching tho!
        ListNode *l2 = s2.head;
        while (l2 != NULL) { // checks to the that the list is not empty or to the end of the list
            if (l1 -> item.compareTo(s2.GetNextItem()) == Comparison::EQUAL) { // Checks for duplicate items  in the array
                cout << "Sorry. You cannot insert the duplicate item.\n";
                return;
            } // if
            l2 = l2 -> next; // Iterates through the list until the end
        } // while
        s2.ResetList();
        l1 = l1 -> next;
    } // while

    ListNode *curr = s2.head;
    while (curr != NULL) { // this needed to be curr not s2.head but now works
        insertItem(curr -> item); // Inserts item all items in the second array if there were no duplicates
        curr = curr -> next;
    } // while
} // mergeList

/*
 * deleteAltNodes deletes every other node in the list using deleteItem().
 * The code then prints the new list.
*/
void SortedLinkedList::deleteAltNodes() {
    if (head == NULL) { // Special Case: No Nodes in the List
        cout << "You cannot delete from an empty list.\n";
        return;
    } // if
    cout << "List before alternate delete: ";
    printLink();

    ListNode *del = head -> next;
    while (del != NULL) { // gets every other item in the list and deletes it using deleteItem()
        ItemType t = del -> item;
        if (del -> next != NULL) {
            del = del -> next;
        } // if
        del = del -> next;
        deleteItem(t); // Method puts every other node in this method to be deleted
    } // while

    cout << "List after alternate delete: ";
    printLink();
}

/*
 * intersection prints any nodes in which the values are the same.
 * @param t a new list is passed by reference to check if there are equal nodes.
 */
void SortedLinkedList::intersection(SortedLinkedList &t) {
    cout << "Intersection: ";
    ListNode *l1 = head;

    while (l1 != NULL) { // supposed to check for matching first // does check for matching tho!
        ListNode *l2 = t.head;
        while (l2 != NULL) { // checks to the that the list is not empty or to the end of the list
            if (l1 -> item.compareTo(t.GetNextItem()) == Comparison::EQUAL) { // Checks for duplicate items  in the array
                cout << l1 -> item.getValue() << " ";
            } // if
            l2 = l2 -> next; // Iterates through the list until the end
        } // while
        t.ResetList();
        l1 = l1 -> next;
    } // while
    cout << "\n";
} // intersection

/*
 * printLink prints each item value at each node in node in the list.
*/
void SortedLinkedList::printLink() {
    ListNode *temp = head;
    while (temp) { // Loops through the list until the end it found
        cout << temp -> item.getValue() << " "; // prints the value of the item in the node
        temp = temp -> next;
    } // while
    cout << "" << endl;
} // printLink
