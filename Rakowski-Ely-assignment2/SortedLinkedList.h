#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ListNode.h"

class SortedLinkedList {

    private:
        ListNode *head;
        ListNode *currentPos;
        int len;
    
    public:
        SortedLinkedList();

        ~SortedLinkedList();

        int length() const;

        void insertItem(ItemType item);

        void deleteItem(ItemType item);

        int searchItem(ItemType item);

        ItemType GetNextItem();

        void ResetList();

        void mergeList();

        void deleteAltNodes();

        void intersection();
};

#endif