#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
struct NodeType {
    T data;
    NodeType<T> *next;
    NodeType<T> *last;
};

template<class T>
class DoublyLinkedList {

    private:
        NodeType<T> *head;

    public:
        DoublyLinkedList();                 // constructor

        ~DoublyLinkedList();                // destructor

        void insertItem(T &item);           // inserts item into list

        void deleteItem(T &item);           // deletes item from list

        int lengthIs() const;               // returns length of list

        void print();                       // prints list

        void printReverse();               // prints list in reverse order

        void deleteSubsection(T upper, T lower);

        int mode();

        void swapAlternate();

}; // DoublyLinkedList
#endif
