#ifndef LISTNODE_H
#define LISTNODE_H
#include "ItemType.h"

/*
 * ListNode is a struct that created a node with two varaibles. ItemType and a ListNode pointer.
 */
struct ListNode {
    public:
        ItemType item;      // item associated with pointer
        ListNode *next;     // pointer to next item in list
}; // ListNode

#endif
