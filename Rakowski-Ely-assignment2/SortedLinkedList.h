#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ListNode.h"

class SortedLinkedList {

    private:
        ListNode *head;
        ListNode *currentPos;

    public:
        SortedLinkedList();

        ~SortedLinkedList();

        int length() const;

        void insertItem(ItemType item);

        void deleteItem(ItemType item);

        int searchItem(ItemType item);

        ItemType GetNextItem();

        void ResetList();

        void mergeList(SortedLinkedList &s2); // pass by ref works!

        void deleteAltNodes();

        void printLink();

        void intersection(SortedLinkedList &t); // find command elements func

};

#endif
