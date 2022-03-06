#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
struct NodeType {
    T data;
    NodeType<T> *next;                              // stores pointer of next node
    NodeType<T> *last;                              // stores pointer of last node
};

template<class T>
class DoublyLinkedList {

    private:
    NodeType<T> *head;                              // stores head pointer

    public:
    DoublyLinkedList();                             // constructor

    ~DoublyLinkedList();                            // destructor

    void insertItem(T &item);                       // inserts item into list

    void deleteItem(T &item);                       // deletes item from list

    int lengthIs() const;                           // returns length of list

    void print();                                   // prints list

    void printReverse();                            // prints list in reverse order

    void deleteSubsection(T upper, T lower);        // deletes a subsection defined by the upper/lower bounds

    T mode();                                       // returns object of most occuring item

    void swapAlternate();                           // swaps alternate items in a list

}; // DoublyLinkedList
#endif
