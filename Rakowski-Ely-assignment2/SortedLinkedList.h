#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ListNode.h"

/**
 * @brief SortedLinkedList class that stores Nodes in ascending integer
 * order. Various functions allow to iterate through list, add or delete
 * Nodes, merge lists, etc.
 * 
 */
class SortedLinkedList {

    private:
        ListNode *head;                         // points to head node
        ListNode *currentPos;                   // points to current iterator position

    public:
        SortedLinkedList();                     // constructor

        ~SortedLinkedList();                    // destructor

        int length() const;                     // returns length of list

        void insertItem(ItemType item);         // inserts item into list

        void deleteItem(ItemType item);         // deletes item from list

        int searchItem(ItemType item);          // returns index of item in list

        ItemType GetNextItem();                 // returns next item in the list

        void ResetList();                       // resets currentPos pointer to head

        void mergeList(SortedLinkedList &s2);   // merges two lists together

        void deleteAltNodes();                  // deletes every other node in list

        void printLink();                       // prints items in list

        void intersection(SortedLinkedList &t); // prints common items of two lists

}; // SortedLinkedList

#endif
