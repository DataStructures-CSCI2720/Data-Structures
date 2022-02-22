#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>

using namespace std;

enum class Comparison {GREATER, LESS, EQUAL};   // Comparison values

/*
 * ItemType class that has 4 public methods, and one private variable to store the values of the
 * items values.
 */
class ItemType {

    private:
        int value;                              // value of item

    public:
        ItemType();                             // ItemType constructor

        Comparison compareTo(ItemType item);    // compares two items and returns a Comparison value

        int getValue() const;                   // gets value of item

        void initialize(int num);               // initializes the value of the item
};

#endif
