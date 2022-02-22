#ifndef LISTNODE_H
#define LISTNODE_H
#include "ItemType.h"

struct ListNode {
    public:
        ItemType item;      // item associated with pointer
        ListNode *next;     // pointer to next item in list
}; // ListNode

#endif